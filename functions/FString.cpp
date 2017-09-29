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

vector<string> * FString::split(string sString, string sDelimiter, bool bAddEmptyToken) {
   string sSplitString = sString;
   vector<string> * oSplitString = new vector<string>();
   size_t nTokenStringStartPosition = 0;
   string sTokenString = GLOBAL_STRING_EMPTY;
   
   for(;(nTokenStringStartPosition = sSplitString.find(sDelimiter)) != string::npos;) {
      sTokenString = sSplitString.substr(0, nTokenStringStartPosition);
      
      if ((bAddEmptyToken) || ((!bAddEmptyToken) && (sTokenString.length() > 0))) oSplitString->push_back(sTokenString);
      
      sSplitString.erase(0, nTokenStringStartPosition + sDelimiter.length());
   }
   
   if ((bAddEmptyToken) || ((!bAddEmptyToken) && (sSplitString.length() > 0))) oSplitString->push_back(sSplitString);
   
   return oSplitString;
}

string FString::getToken(string sString, unsigned int nToken, string sDelimiter, bool bAddEmptyToken) {
   vector<string> * oSplitString = FString::split(sString, sDelimiter, bAddEmptyToken);
   
   if ((oSplitString->size()) && (nToken)) {
      if (nToken > oSplitString->size()) nToken = oSplitString->size();
      
      return oSplitString->at(nToken - 1);   
   }
   
   return sString;
}

string FString::getFirstToken(string sString, string sDelimiter, bool bAddEmptyToken) {
   return FString::getToken(sString, 1, sDelimiter, bAddEmptyToken);
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
