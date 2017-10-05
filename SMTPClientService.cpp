#include "SMTPClientService.h"

SMTPClientService::SMTPClientService(unsigned int nRecvSecTimeout) : ClientService(nRecvSecTimeout) { 
   this->nDefaultPort = SMTP_CLIENT_SERVICE_DEFAULT_PORT;
   this->nDefaultPortSSL = SMTP_CLIENT_SERVICE_SSL_DEFAULT_PORT;
   this->nDefaultPortTLS = SMTP_CLIENT_SERVICE_TLS_DEFAULT_PORT;

   this->sEndCommandLine = SMTP_CLIENT_SERVICE_END_COMMAND_LINE;
   
   this->bReceiveOnConnect = true;
}

bool SMTPClientService::authCryptographicSecurity() {
   this->bAuthCryptographicSecurity = true;
	
   return this->bAuthCryptographicSecurity;
}

bool SMTPClientService::authLoginUser() {
   this->bAuthLoginUser = true;
  
   return this->bAuthLoginUser;
}
