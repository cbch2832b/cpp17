#pragma once

#include "ClientService.h"
#include "functions/FCast.h"
#include "functions/FCrypt.h"
#include "functions/FString.h"
#include "Global.h"

#define IMAP_CLIENT_SERVICE_DEFAULT_PORT                                  143
#define IMAP_CLIENT_SERVICE_SSL_DEFAULT_PORT                              993
#define IMAP_CLIENT_SERVICE_TLS_DEFAULT_PORT                              143

#define IMAP_CLIENT_SERVICE_AUTH_COMMAND                                  "C0 AUTHENTICATE LOGIN"
#define IMAP_CLIENT_SERVICE_AUTH_COMMAND_USER                             "<login-username>"
#define IMAP_CLIENT_SERVICE_AUTH_COMMAND_PASSWORD                         "<login-password>"
#define IMAP_CLIENT_SERVICE_AUTH_SUCCESS_REPLY_CODE                       "OK"

#define IMAP_CLIENT_SERVICE_END_COMMAND_LINE                              "\r\n"

using namespace std;

class IMAPClientService: public ClientService {
   private:
      bool authCryptographicSecurity();
      bool authLoginUser();
      
   public:
      IMAPClientService(unsigned int nRecvSecTimeout = CLIENT_SERVICE_RECV_DEFAULT_SECONDS_TIMEOUT);
      ~IMAPClientService();
};
