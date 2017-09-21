#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Global.h"

using namespace std;

class ClientService {
   protected:
      string sTargetHostnameIP, sCryptographicSecurityProtocol, sLoginUsername, sLoginPassword;
      
      int nSocketId;
      unsigned int nTargetPort;
      unsigned int nDefaultPort, nDefaultPortSSL, nDefaultPortTLS;
      
      bool bAuthCryptographicSecurity, bAuthLoginUser;
		 
   private:
      void initializeClientService();
      //virtual bool authCryptographicSecurity() = 0;
      //virtual bool authLoginUser() = 0;
      
   public:
      ClientService();
      ~ClientService();
      
      bool connectSocket(string sTargetHostnameIP, unsigned int nTargetPort = 0, string sCryptographicSecurityProtocol = GLOBAL_CRYPTOGRAPHIC_SECURITY_PROTOCOL_VALUE_NONE);
      bool disconnectSocket();
      
      bool sendSocketData(string sSocketData);
      bool recvSocketData();
      
      string getTargetHostnameIP();
      string getCryptographicSecurityProtocol();
      string getLoginUsername();
      string getLoginPassword();
      
      unsigned int getTargetPort();
      unsigned int getDefaultPort();
      unsigned int getDefaultPortSSL();
      unsigned int getDefaultPortTLS();
      
      bool isAuthCryptographicSecurity();
      bool isAuthLoginUser();
};
