// Copyright 2016 The Charon Platform Authors.
// All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <mirandaserver.h>
#include <mirandatask.h>
#include <charon/base>
#include <QDebug>
#include <QFile>
#include <QJsonObject>

using charon::service;
using charon::Log;
using charon::net::Config;

MirandaServer::MirandaServer(QCoreApplication *app)
{
  Config config("config/miranda.json");
  std::cout << "start miranda " << config.address() << ":" << config.port() <<
    " (" << config.threads() << ") threads..." << std::endl;
  m_address        = config.address().c_str();
  m_pid            = config.pid().c_str();
  m_port           = config.port();
  m_maxThreadCount = config.threads();
  m_service        = config.service();

  QFileInfo dispatch = QFileInfo("dispatch.lua");

  if( ! dispatch.exists() ) {
    if( app->arguments().size() == 1 ) {
      qDebug() << "where the dispatch.lua file ???";
      throw;
    }
    QString file_name = app->arguments().at(1);
    dispatch = QFileInfo(file_name);
    if( dispatch.exists() ) {
      qDebug() << "work dir is: " << dispatch.absoluteDir().absolutePath();
      QDir::setCurrent( dispatch.absoluteDir().absolutePath() );
    } else {
      qDebug() << "file dispatch.lua not found exit... ";
      throw;
    }
  }

  // SERVICES
  if( m_service && os::exists("app/services")) {
    charon::service::load("app/services");
  }

  if( os::exists("logs") ) {
    Log log = Log("logs/miranda.log");
    log.info("iniciando miranda");
    if( m_service ) {
      if( os::exists("app/services") ) {
        log.info("services started");
      } else {
        log.info("services dir not exists");
      }
    } else {
      log.info("services not enable");
    }
    log.dump();
  }

}

void MirandaServer::start()
{
  m_pool = new QThreadPool(this);
  m_pool->setMaxThreadCount(m_maxThreadCount);

  if(! this->listen(QHostAddress(m_address), m_port)) {
    qDebug() << "fail start miranda ...";
    throw;
  }
  QFile log(m_pid);
  if ( log.open(QIODevice::WriteOnly) ) {
    log.write(QByteArray::number((qint64) os::pid()));
    log.close();
  } else {
    qDebug() << m_pid << " not open";
    throw;
  }
}

void MirandaServer::incomingConnection(qintptr descriptor)
{
  m_pool->start(new MirandaTask(descriptor));
}
