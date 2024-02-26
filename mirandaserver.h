// Copyright 2016 The Arken Platform Authors.
// All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef MIRANDASERVER_H
#define MIRANDASERVER_H

#include <QCoreApplication>
#include <QThreadPool>
#include <QTcpServer>

class MirandaServer : public QTcpServer
{

public:
  explicit MirandaServer(QCoreApplication *app);
  void incomingConnection(qintptr descriptor);
  void start();
  void setPort(quint16  port);
  void setAddress(QString m_address);
  void setThreads(int threads);

private:
  QThreadPool * m_pool;
  quint16       m_port;
  QString       m_address;
  QString       m_pid;
  int           m_maxThreadCount;

};

#endif // MIRANDASERVER_H
