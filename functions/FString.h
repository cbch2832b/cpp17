#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include "../Global.h"

using namespace std;

class FString {
   public:
      static string replaceTokens(string sString, vector< pair<string, string> > * oStringTokens);
      
      static string getFromLastToken(string sString, string sToken, bool bAddToken = false);
      static string getUntilLastToken(string sString, string sToken, bool bAddToken = false);
};
