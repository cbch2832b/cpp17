#include "FTPClientService.h"

FTPClientService::FTPClientService(unsigned int nRecvSecTimeout) : ClientService(nRecvSecTimeout) { 
   this->nDefaultPort = FTP_CLIENT_SERVICE_DEFAULT_PORT;
   this->nDefaultPortSSL = FTP_CLIENT_SERVICE_SSL_DEFAULT_PORT;
   this->nDefaultPortTLS = FTP_CLIENT_SERVICE_TLS_DEFAULT_PORT;

   this->sEndCommandLine = FTP_CLIENT_SERVICE_END_COMMAND_LINE;
}

bool FTPClientService::authCryptographicSecurity() {
	this->bAuthCryptographicSecurity = true;
	
   return this->bAuthCryptographicSecurity;
}

bool FTPClientService::authLoginUser() {
	this->bAuthLoginUser = true;
	
   return this->bAuthLoginUser;
}
