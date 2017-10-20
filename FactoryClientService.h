#pragma once

#include "ClientService.h"
#include "FTPClientService.h"
#include "IMAPClientService.h"
#include "POP3ClientService.h"
#include "SMTPClientService.h"
#include "Global.h"

using namespace std;

class FactoryClientService {
   public:
      static ClientService * createClientService(string sApplicationLayerProtocol);
};
