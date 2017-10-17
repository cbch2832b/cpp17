#pragma once

#include "ClientService.h"
#include "functions/FCast.h"
#include "functions/FCrypt.h"
#include "functions/FString.h"
#include "Global.h"

#define POP3_CLIENT_SERVICE_DEFAULT_PORT                                  110
#define POP3_CLIENT_SERVICE_SSL_DEFAULT_PORT                              995
#define POP3_CLIENT_SERVICE_TLS_DEFAULT_PORT                              110

#define POP3_CLIENT_SERVICE_AUTH_COMMAND                                  "AUTH LOGIN"
#define POP3_CLIENT_SERVICE_AUTH_COMMAND_USER                             "<login-username>"
#define POP3_CLIENT_SERVICE_AUTH_COMMAND_PASSWORD                         "<login-password>"
#define POP3_CLIENT_SERVICE_AUTH_SUCCESS_REPLY_CODE                       "+OK"

#define POP3_CLIENT_SERVICE_END_COMMAND_LINE                              "\r\n"

using namespace std;

class POP3ClientService: public ClientService {
   private:
      bool authCryptographicSecurity();
      bool authLoginUser();
      
   public:
      POP3ClientService(unsigned int nRecvSecTimeout = CLIENT_SERVICE_RECV_DEFAULT_SECONDS_TIMEOUT);
      ~POP3ClientService();
};
