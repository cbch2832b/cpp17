#pragma once

#include "ClientService.h"
#include "Global.h"

#define FTP_CLIENT_SERVICE_DEFAULT_PORT                                   21
#define FTP_CLIENT_SERVICE_SSL_DEFAULT_PORT                               21
#define FTP_CLIENT_SERVICE_TLS_DEFAULT_PORT                               21

#define FTP_CLIENT_SERVICE_END_COMMAND_LINE                               "\r\n"

using namespace std;

class FTPClientService: public ClientService {
   private:
      bool authCryptographicSecurity();
      bool authLoginUser();
      
   public:
      FTPClientService(unsigned int nRecvSecTimeout = CLIENT_SERVICE_RECV_DEFAULT_SECONDS_TIMEOUT);
      ~FTPClientService();
};
