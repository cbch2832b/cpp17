#include "FTPClientService.h"

FTPClientService::FTPClientService(unsigned int nRecvSecTimeout) : ClientService(nRecvSecTimeout) { 
   this->nDefaultPort = FTP_CLIENT_SERVICE_DEFAULT_PORT;
   this->nDefaultPortSSL = FTP_CLIENT_SERVICE_SSL_DEFAULT_PORT;
   this->nDefaultPortTLS = FTP_CLIENT_SERVICE_TLS_DEFAULT_PORT;
}

bool FTPClientService::authCryptographicSecurity() {
   return true;
}

bool FTPClientService::authLoginUser() {
   return true;
}
