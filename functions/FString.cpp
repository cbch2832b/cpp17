#include "FString.h"

string FString::replaceTokens(string sString, vector< pair<string, string> > * oStringTokens) {
   string sReplaceTokensString = sString;
   
   for (vector< pair <string, string> >::iterator oIterator = oStringTokens->begin(); oIterator != oStringTokens->end(); oIterator++) {
      size_t nReplaceTokensStringStartPosition = sReplaceTokensString.find(oIterator->first);
	   
      if (nReplaceTokensStringStartPosition != string::npos) {
         sReplaceTokensString.replace(nReplaceTokensStringStartPosition, oIterator->first.length(), oIterator->second);
      } 
   }
   
   return sReplaceTokensString;   
}

string FString::getFromLastToken(string sString, string sToken, bool bAddToken) {
   string sFromLastTokenString = sString;
	
   size_t nFromLastTokenStringStartPosition = sFromLastTokenString.rfind(sToken);
	
   if (nFromLastTokenStringStartPosition != string::npos) {
      if (bAddToken) sFromLastTokenString = sFromLastTokenString.substr(nFromLastTokenStringStartPosition, sFromLastTokenString.length());
      else sFromLastTokenString = sFromLastTokenString.substr(nFromLastTokenStringStartPosition + sToken.length(), sFromLastTokenString.length());
   }
	
   return sFromLastTokenString;
}

string FString::getUntilLastToken(string sString, string sToken, bool bAddToken) {
   string sUntilLastTokenString = sString;
	
   size_t nUntilLastTokenStringStartPosition = sUntilLastTokenString.rfind(sToken);
	
   if (nUntilLastTokenStringStartPosition != string::npos) {
      if (bAddToken) sUntilLastTokenString = sUntilLastTokenString.substr(0, nUntilLastTokenStringStartPosition + sToken.length());
      else sUntilLastTokenString = sUntilLastTokenString.substr(0, nUntilLastTokenStringStartPosition);
   }
	
   return sUntilLastTokenString;
}
