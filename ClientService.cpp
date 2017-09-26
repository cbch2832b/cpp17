#include "ClientService.h"

ClientService::ClientService(unsigned int nRecvSecTimeout) {
   this->initializeClientService();
                                      
   this->nRecvSecTimeout = nRecvSecTimeout;
}

void ClientService::initializeClientService() {
   this->sTargetHostnameIP = GLOBAL_STRING_EMPTY;
   this->sCryptographicSecurityProtocol = GLOBAL_CRYPTOGRAPHIC_SECURITY_PROTOCOL_VALUE_NONE;
   this->sLoginUsername = GLOBAL_STRING_EMPTY;
   this->sLoginPassword = GLOBAL_STRING_EMPTY;
	
   this->bAuthCryptographicSecurity = false;
   this->bAuthLoginUser = false;
}

bool ClientService::connectSocket(string sTargetHostnameIP, unsigned int nTargetPort, string sCryptographicSecurityProtocol) {
   bool bConnectSocket = false;
   struct hostent * oHostent;
   struct sockaddr_in oSocketAddressIn;
   DWORD oSocketTimeout = this->nRecvSecTimeout * 1000;
   
   this->disconnectSocket();
   
	this->nSocketId = socket(AF_INET, SOCK_STREAM, 0);
	
   if (this->nSocketId != INVALID_SOCKET) {
      setsockopt(this->nSocketId, SOL_SOCKET, SO_RCVTIMEO, (char *) &oSocketTimeout, sizeof(oSocketTimeout));
      
      oHostent = gethostbyname(sTargetHostnameIP.c_str());
		if (oHostent != NULL) {
         if (nTargetPort == 0) {
            if (sCryptographicSecurityProtocol == GLOBAL_CRYPTOGRAPHIC_SECURITY_PROTOCOL_VALUE_SSL) nTargetPort = this->nDefaultPortSSL;
            else if (sCryptographicSecurityProtocol == GLOBAL_CRYPTOGRAPHIC_SECURITY_PROTOCOL_VALUE_TLS) nTargetPort = this->nDefaultPortTLS;
            else nTargetPort = this->nDefaultPort;
         }
         
		   oSocketAddressIn.sin_family = AF_INET;
         oSocketAddressIn.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *) oHostent->h_addr)));
         oSocketAddressIn.sin_port = htons(nTargetPort);
         memset(&(oSocketAddressIn.sin_zero), '0', 8);
         
         if (connect(this->nSocketId, (struct sockaddr *) &oSocketAddressIn, sizeof(struct sockaddr)) != SOCKET_ERROR) {
            if (this->authCryptographicSecurity()) {
               this->sTargetHostnameIP = sTargetHostnameIP;
               this->nTargetPort = nTargetPort;
               this->sCryptographicSecurityProtocol = sCryptographicSecurityProtocol;
               
               this->bAuthCryptographicSecurity = true;
               
   				bConnectSocket = true;	
            }
            else this->disconnectSocket();
			}
		}
	}
	
	return bConnectSocket;
}

bool ClientService::disconnectSocket() {
   bool bDisconnectSocket = false;
   
   this->initializeClientService();
   
	if (closesocket(this->nSocketId) == 0) bDisconnectSocket = true;
	
	return bDisconnectSocket;
}

bool ClientService::sendSocketData(string sSocketData) {
   bool bSendSocketData = false;
   
   return (send(this->nSocketId, sSocketData.c_str(), sSocketData.size(), 0) == sSocketData.size());

   return bSendSocketData;
}

string ClientService::recvSocketData() {
   unsigned long nTotalBytesRecvSocketData = 0;
   char oRecvSocketData[CLIENT_SERVICE_RECV_BUFFER_SIZE];
   string sRecvSocketData = GLOBAL_STRING_EMPTY;
   
   for(;(recv(this->nSocketId, oRecvSocketData, CLIENT_SERVICE_RECV_BUFFER_SIZE, 0) > 0);) {
      sRecvSocketData += oRecvSocketData;
   }
   
   return sRecvSocketData;
}

void ClientService::setLoginCredentials(string sLoginUsername, string sLoginPassword) {
   this->sLoginUsername = sLoginUsername;
   this->sLoginPassword = sLoginPassword;
}
	
string ClientService::getTargetHostnameIP() { return this->sTargetHostnameIP; }
string ClientService::getCryptographicSecurityProtocol() { return this->sCryptographicSecurityProtocol; }
string ClientService::getLoginUsername() { return this->sLoginUsername; }
string ClientService::getLoginPassword() { return this->sLoginPassword; }

unsigned int ClientService::getTargetPort() { return this->nTargetPort; }
unsigned int ClientService::getDefaultPort() { return this->nDefaultPort; }
unsigned int ClientService::getDefaultPortSSL() { return this->nDefaultPortSSL; }
unsigned int ClientService::getDefaultPortTLS() { return this->nDefaultPortTLS; }

bool ClientService::isConnectionKeepAlive() { 
   char cSocketData; 
	
	return (recv(this->nSocketId, &cSocketData, 1, MSG_PEEK) == 1); 
}

bool ClientService::isAuthCryptographicSecurity() { return this->bAuthCryptographicSecurity; }
bool ClientService::isAuthLoginUser() { return this->bAuthLoginUser; }
