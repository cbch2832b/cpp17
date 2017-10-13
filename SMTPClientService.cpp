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
   vector< pair<string, string> > * oStringTokens = new vector< pair<string, string> >();
   string sRecvSocketData = GLOBAL_STRING_EMPTY;
   this->bAuthLoginUser = false;
   
   if (FString::trim(this->sLoginUsername).length() > 0) {
      if (this->sendSocketData(SMTP_CLIENT_SERVICE_AUTH_COMMAND + this->getEndCommandLine())) {
         sRecvSocketData = this->recvSocketData();
         
         if (sRecvSocketData.find(SMTP_CLIENT_SERVICE_AUTH_ASK_CREDENTIALS_REPLY_CODE) != string::npos) {
            oStringTokens->push_back(pair<string, string>(GLOBAL_STF_FILE_ENCODE_NOTATION_LOGIN_USERNAME, FCrypt::cryptBase64(this->sLoginUsername)));
            if (this->sendSocketData(FString::replaceTokens(SMTP_CLIENT_SERVICE_AUTH_COMMAND_USER, oStringTokens) + this->getEndCommandLine())) {
               sRecvSocketData = this->recvSocketData();
               
               if (sRecvSocketData.find(SMTP_CLIENT_SERVICE_AUTH_ASK_CREDENTIALS_REPLY_CODE) != string::npos) {
                  oStringTokens->clear();
                  oStringTokens->push_back(pair<string, string>(GLOBAL_STF_FILE_ENCODE_NOTATION_LOGIN_PASSWORD, FCrypt::cryptBase64(this->sLoginPassword)));
                  
                  if (this->sendSocketData(FString::replaceTokens(SMTP_CLIENT_SERVICE_AUTH_COMMAND_PASSWORD, oStringTokens) + this->getEndCommandLine())) {
                     sRecvSocketData = this->recvSocketData();
                     
                     if (sRecvSocketData.find(SMTP_CLIENT_SERVICE_AUTH_ASK_CREDENTIALS_REPLY_CODE) != string::npos) this->bAuthLoginUser = true;
                  }
               }   
            }
         }
      }
   }
   
   return this->bAuthLoginUser;
}
