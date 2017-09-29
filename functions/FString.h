#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include "../Global.h"

using namespace std;

class FString {
   public:
      static string replaceTokens(string sString, vector< pair<string, string> > * oStringTokens);
      
      static vector<string> * split(string sString, string sDelimiter = GLOBAL_STRING_SPACE, bool bAddEmptyToken = false);
      
      static string getToken(string sString, unsigned int nToken, string sDelimiter = GLOBAL_STRING_SPACE, bool bAddEmptyToken = false);
      static string getFirstToken(string sString, string sDelimiter = GLOBAL_STRING_SPACE, bool bAddEmptyToken = false);
      
      static string getFromLastToken(string sString, string sToken, bool bAddToken = false);
      static string getUntilLastToken(string sString, string sToken, bool bAddToken = false);
};
