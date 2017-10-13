#pragma once

#include "ClientService.h"
#include "functions/FCast.h"
#include "functions/FCrypt.h"
#include "functions/FString.h"
#include "Global.h"

#define SMTP_CLIENT_SERVICE_DEFAULT_PORT                                  25
#define SMTP_CLIENT_SERVICE_SSL_DEFAULT_PORT                              465
#define SMTP_CLIENT_SERVICE_TLS_DEFAULT_PORT                              587

#define SMTP_CLIENT_SERVICE_AUTH_COMMAND                                  "AUTH LOGIN"
#define SMTP_CLIENT_SERVICE_AUTH_COMMAND_USER                             "<username>"
#define SMTP_CLIENT_SERVICE_AUTH_COMMAND_PASSWORD                         "<password>"
#define SMTP_CLIENT_SERVICE_AUTH_ASK_CREDENTIALS_REPLY_CODE               "334"
#define SMTP_CLIENT_SERVICE_AUTH_SUCCESS_REPLY_CODE                       "235"

#define SMTP_CLIENT_SERVICE_END_COMMAND_LINE                              "\r\n"

using namespace std;

class SMTPClientService: public ClientService {
   private:
      bool authCryptographicSecurity();
      bool authLoginUser();
      
   public:
      SMTPClientService(unsigned int nRecvSecTimeout = CLIENT_SERVICE_RECV_DEFAULT_SECONDS_TIMEOUT);
      ~SMTPClientService();
};
