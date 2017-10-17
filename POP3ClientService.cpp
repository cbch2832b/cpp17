#include "POP3ClientService.h"

POP3ClientService::POP3ClientService(unsigned int nRecvSecTimeout) : ClientService(nRecvSecTimeout) { 
   this->nDefaultPort = POP3_CLIENT_SERVICE_DEFAULT_PORT;
   this->nDefaultPortSSL = POP3_CLIENT_SERVICE_SSL_DEFAULT_PORT;
   this->nDefaultPortTLS = POP3_CLIENT_SERVICE_TLS_DEFAULT_PORT;

   this->sEndCommandLine = POP3_CLIENT_SERVICE_END_COMMAND_LINE;
   
   this->bReceiveOnConnect = true;
}

bool POP3ClientService::authCryptographicSecurity() {
   this->bAuthCryptographicSecurity = true;
	
   return this->bAuthCryptographicSecurity;
}

bool POP3ClientService::authLoginUser() {
   vector< pair<string, string> > * oStringTokens = new vector< pair<string, string> >();
   string sRecvSocketData = GLOBAL_STRING_EMPTY;
   this->bAuthLoginUser = false;
   
   if (FString::trim(this->sLoginUsername).length() > 0) {
      if (this->sendSocketData(POP3_CLIENT_SERVICE_AUTH_COMMAND + this->getEndCommandLine())) {
         sRecvSocketData = this->recvSocketData();
         
         oStringTokens->push_back(pair<string, string>(GLOBAL_STF_FILE_ENCODE_NOTATION_LOGIN_USERNAME, FCrypt::cryptBase64(this->sLoginUsername)));
         
         if (this->sendSocketData(FString::replaceTokens(POP3_CLIENT_SERVICE_AUTH_COMMAND_USER, oStringTokens) + this->getEndCommandLine())) {
            sRecvSocketData = this->recvSocketData();
            
            oStringTokens->clear();
            oStringTokens->push_back(pair<string, string>(GLOBAL_STF_FILE_ENCODE_NOTATION_LOGIN_PASSWORD, FCrypt::cryptBase64(this->sLoginPassword)));
      
            if (this->sendSocketData(FString::replaceTokens(POP3_CLIENT_SERVICE_AUTH_COMMAND_PASSWORD, oStringTokens) + this->getEndCommandLine())) {
               sRecvSocketData = this->recvSocketData();

               if (sRecvSocketData.find(POP3_CLIENT_SERVICE_AUTH_SUCCESS_REPLY_CODE) != string::npos) this->bAuthLoginUser = true;
            } 
         }
      }
   }
   
   return this->bAuthLoginUser;
}
