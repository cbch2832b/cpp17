#pragma once

#include <string>
#include "../Global.h"

#define FCRYPT_BASE64_ALPHABET                                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

using namespace std;

class FCrypt {
   public:
      static string cryptBase64(string sString);
};
