#include <QDebug>
#include <QtCore>
#include <QCoreApplication>
#include "mirandaserver.h"

#include <arken/base>
#include <arken/mvm.h>
#include <arken/net/httpserver.h>

using HttpServer = arken::net::HttpServer;
using mvm    = arken::mvm;


//-----------------------------------------------------------------------------
// HTTP SERVER RUN
//-----------------------------------------------------------------------------

void HttpServer::run()
{
  std::cout << "start arken.net.HttpServer (miranda) " << m_address <<
    ":" << m_port << " (" << m_threads << ") threads..." << std::endl;

   QCoreApplication *app = new QCoreApplication(mvm::s_argc, mvm::s_argv);
   MirandaServer server(app);
   server.start();


   app->exec();
}

