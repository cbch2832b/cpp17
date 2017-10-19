#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <winsock.h>
#include "functions/FCast.h"
#include "Global.h"

#define CLIENT_SERVICE_CONNECTION_KEEP_ALIVE_SECONDS_DELAY    5
#define CLIENT_SERVICE_RECV_DEFAULT_SECONDS_TIMEOUT           3
#define CLIENT_SERVICE_RECV_BUFFER_SIZE                       256
#define CLIENT_SERVICE_CONNECTION_KEEP_ALIVE_PING             "::PING" 

using namespace std;

class ClientService {
   protected:
      string sTargetHostnameIP, sCryptographicSecurityProtocol, sLoginUsername, sLoginPassword, sEndCommandLine;
   	
      int nSocketId;
      unsigned int nRecvSecTimeout;
      unsigned int nTargetPort;
      unsigned int nDefaultPort, nDefaultPortSSL, nDefaultPortTLS;
      
      bool bAuthCryptographicSecurity, bAuthLoginUser, bReceiveOnConnect;
		 
   private:
      void initializeClientService();
      void setSocketTimeout(unsigned int nRecvSecTimeout);
      
      virtual bool authCryptographicSecurity() = 0;
      
   public:
      ClientService(unsigned int nRecvSecTimeout = CLIENT_SERVICE_RECV_DEFAULT_SECONDS_TIMEOUT);
      ~ClientService() { }
      
      virtual bool authLoginUser() = 0;
      
      bool connectSocket(string sTargetHostnameIP, unsigned int nTargetPort = 0, string sCryptographicSecurityProtocol = GLOBAL_CRYPTOGRAPHIC_SECURITY_PROTOCOL_VALUE_NONE);
      bool disconnectSocket();
      
      bool sendSocketData(string sSocketData);
      string recvSocketData();
      
      void setLoginCredentials(string sLoginUsername, string sLoginPassword);
      
      string getTargetHostnameIP();
      string getCryptographicSecurityProtocol();
      string getLoginUsername();
      string getLoginPassword();
      string getEndCommandLine();
      bool getReceiveOnConnect();
		     
      unsigned int getTargetPort();
      unsigned int getDefaultPort();
      unsigned int getDefaultPortSSL();
      unsigned int getDefaultPortTLS();
 
      bool isConnectionKeepAlive();
      bool isAuthCryptographicSecurity();
      bool isAuthLoginUser();
};
