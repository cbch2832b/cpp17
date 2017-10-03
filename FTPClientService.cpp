#include "FTPClientService.h"

FTPClientService::FTPClientService(unsigned int nRecvSecTimeout) : ClientService(nRecvSecTimeout) { 
   this->nDefaultPort = FTP_CLIENT_SERVICE_DEFAULT_PORT;
   this->nDefaultPortSSL = FTP_CLIENT_SERVICE_SSL_DEFAULT_PORT;
   this->nDefaultPortTLS = FTP_CLIENT_SERVICE_TLS_DEFAULT_PORT;

   this->sEndCommandLine = FTP_CLIENT_SERVICE_END_COMMAND_LINE;
   
   this->bReceiveOnConnect = true;
}

bool FTPClientService::authCryptographicSecurity() {
   this->bAuthCryptographicSecurity = true;
	
   return this->bAuthCryptographicSecurity;
}

bool FTPClientService::authLoginUser() {
   vector< pair<string, string> > * oStringTokens = new vector< pair<string, string> >();
   this->bAuthLoginUser = false;

   if (FString::trim(this->sLoginUsername).length() > 0) {
      oStringTokens->push_back(pair<string, string>(GLOBAL_STF_FILE_ENCODE_NOTATION_LOGIN_USERNAME, this->sLoginUsername));
      
      if (this->sendSocketData(FString::replaceTokens(FTP_CLIENT_SERVICE_AUTH_COMMAND_USER, oStringTokens) + this->getEndCommandLine())) {
         this->recvSocketData();
         
         oStringTokens->clear();
         oStringTokens->push_back(pair<string, string>(GLOBAL_STF_FILE_ENCODE_NOTATION_LOGIN_PASSWORD, this->sLoginPassword));
         
         if (this->sendSocketData(FString::replaceTokens(FTP_CLIENT_SERVICE_AUTH_COMMAND_PASSWORD, oStringTokens) + this->getEndCommandLine())) {
            string sRecvSocketData = this->recvSocketData();
            
            if (sRecvSocketData.find(FTP_CLIENT_SERVICE_AUTH_SUCCESS_REPLY_CODE) != string::npos) this->bAuthLoginUser = true;
         }
      }     
   }
   
   return this->bAuthLoginUser;
}
