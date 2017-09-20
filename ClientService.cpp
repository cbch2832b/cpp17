#include "ClientService.h"

ClientService::ClientService() {

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
   
}

string ClientService::getTargetHostnameIP() { return this->sTargetHostnameIP; }
string ClientService::getCryptographicSecurityProtocol() { return this->sCryptographicSecurityProtocol; }
string ClientService::getLoginUsername() { return this->sLoginUsername; }
string ClientService::getLoginPassword() { return this->sLoginPassword; }

unsigned int ClientService::getTargetPort() { return this->nTargetPort; }
unsigned int ClientService::getDefaultPort() { return this->nDefaultPort; }
unsigned int ClientService::getDefaultPortSSL() { return this->nDefaultPortSSL; }
unsigned int ClientService::getDefaultPortTLS() { return this->nDefaultPortTLS; }

bool ClientService::isAuthCryptographicSecurity() { return this->bAuthCryptographicSecurity; }
bool ClientService::isAuthLoginUser() { return this->bAuthLoginUser; }
