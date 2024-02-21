// Copyright 2016 The Arken Platform Authors.
// All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <QDebug>
#include <QFile>
#include <QJsonObject>

#include <mirandaserver.h>
#include <mirandatask.h>
#include <arken/base>
//#include <arken/net/config.h>

//using arken::net::Config;

MirandaServer::MirandaServer(QCoreApplication *app)
{
  /*
  Config config("config/miranda.json");
  std::cout << "start miranda " << config.address() << ":" << config.port() <<
    " (" << config.threads() << ") threads..." << std::endl;
  m_address        = config.address().c_str();
  m_pid            = config.pid().c_str();
  m_port           = config.port();
  m_maxThreadCount = config.threads();
  */
}


void MirandaServer::setPort(quint16  port)
{
  m_port = port;
}

void MirandaServer::setAddress(QString address)
{
  m_address = address;
}

void MirandaServer::setThreads(int threads)
{
  m_maxThreadCount = threads;
}

void MirandaServer::start()
{
  m_pool = new QThreadPool(this);
  m_pool->setMaxThreadCount(m_maxThreadCount);

  if(! this->listen(QHostAddress(m_address), m_port)) {
    qDebug() << "fail start miranda ... address " << m_address << " port " << m_port;
    throw;
  }
}

void MirandaServer::incomingConnection(qintptr descriptor)
{
  m_pool->start(new MirandaTask(descriptor));
}
