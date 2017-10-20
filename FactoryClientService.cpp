#include "FactoryClientService.h"

ClientService * FactoryClientService::createClientService(string sApplicationLayerProtocol) {
   ClientService * oClientService;
	
   if (sApplicationLayerProtocol == GLOBAL_APPLICATION_LAYER_PROTOCOL_FTP) oClientService = new FTPClientService();
   else if (sApplicationLayerProtocol == GLOBAL_APPLICATION_LAYER_PROTOCOL_IMAP) oClientService = new IMAPClientService();
   else if (sApplicationLayerProtocol == GLOBAL_APPLICATION_LAYER_PROTOCOL_POP3) oClientService = new POP3ClientService();
   else if (sApplicationLayerProtocol == GLOBAL_APPLICATION_LAYER_PROTOCOL_SMTP) oClientService = new SMTPClientService();
   
   return oClientService;
}
