#pragma once

#include <algorithm>
#include <map>
#include <string>
#include "../Global.h"

using namespace std;

class FString {
   public:
      static string replace(string sString, map<string, string> * oStringTokens);
};
