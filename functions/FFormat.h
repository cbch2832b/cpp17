#pragma once

#include <string>
#include <winsock.h>
#include "FCast.h"
#include "../Global.h"

using namespace std;

class FFormat {
   public:
      static bool isFormatHostname(string sString);
};
