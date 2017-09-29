#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include "../Global.h"

using namespace std;

class FString {
   private:
      static string getFromToken(string sString, string sToken, bool bAddToken = false, bool bLastToken = false);
      static string getUntilToken(string sString, string sToken, bool bAddToken = false, bool bLastToken = false);
      
   public:
      static string replaceTokens(string sString, vector< pair<string, string> > * oStringTokens);
      
      static string trimLeft(string sString);
      static string trimRight(string sString);
      static string trim(string sString);
      
      static vector<string> * split(string sString, string sDelimiter = GLOBAL_STRING_SPACE, bool bAddEmptyToken = false);
      
      static string getToken(string sString, unsigned int nToken, string sDelimiter = GLOBAL_STRING_SPACE, bool bAddEmptyToken = false);
      static string getFirstToken(string sString, string sDelimiter = GLOBAL_STRING_SPACE, bool bAddEmptyToken = false);
      
      static string getFromFirstToken(string sString, string sToken, bool bAddToken = false);
      static string getFromLastToken(string sString, string sToken, bool bAddToken = false);
      static string getUntilFirstToken(string sString, string sToken, bool bAddToken = false);
      static string getUntilLastToken(string sString, string sToken, bool bAddToken = false);
};
