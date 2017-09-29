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

string FString::trimLeft(string sString) {
   size_t nTrimStringStartPosition = 0;
   
   nTrimStringStartPosition = sString.find_first_not_of(" \f\n\r\t\v");
   if (nTrimStringStartPosition == string::npos) nTrimStringStartPosition = 0;
   
	return (sString.substr(nTrimStringStartPosition));	
}

string FString::trimRight(string sString) {
	return (sString.substr(0, sString.find_last_not_of(" \f\n\r\t\v") + 1));	
}

string FString::trim(string sString) {
	return FString::trimLeft(FString::trimRight(sString));
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

string FString::getFromToken(string sString, string sToken, bool bAddToken, bool bLastToken) {
   string sFromTokenString = sString;
	size_t nFromTokenStringStartPosition;
	
	if (!bLastToken) nFromTokenStringStartPosition = sFromTokenString.find(sToken);
   else nFromTokenStringStartPosition = sFromTokenString.rfind(sToken);
	
   if (nFromTokenStringStartPosition != string::npos) {
      if (bAddToken) sFromTokenString = sFromTokenString.substr(nFromTokenStringStartPosition, sFromTokenString.length());
      else sFromTokenString = sFromTokenString.substr(nFromTokenStringStartPosition + sToken.length(), sFromTokenString.length());
   }
	
   return sFromTokenString;	
}

string FString::getUntilToken(string sString, string sToken, bool bAddToken, bool bLastToken) {
   string sUntilTokenString = sString;
   size_t nUntilTokenStringStartPosition;
	
	if (!bLastToken) nUntilTokenStringStartPosition = sUntilTokenString.find(sToken); 
	else nUntilTokenStringStartPosition = sUntilTokenString.rfind(sToken);
	
   if (nUntilTokenStringStartPosition != string::npos) {
      if (bAddToken) sUntilTokenString = sUntilTokenString.substr(0, nUntilTokenStringStartPosition + sToken.length());
      else sUntilTokenString = sUntilTokenString.substr(0, nUntilTokenStringStartPosition);
   }
	
   return sUntilTokenString;	
}

string FString::getFromFirstToken(string sString, string sToken, bool bAddToken) {
   return FString::getFromToken(sString, sToken, bAddToken, false);
}
   
string FString::getFromLastToken(string sString, string sToken, bool bAddToken) {
   return FString::getFromToken(sString, sToken, bAddToken, true);
}

string FString::getUntilFirstToken(string sString, string sToken, bool bAddToken) {
   return FString::getUntilToken(sString, sToken, bAddToken, false);
}

string FString::getUntilLastToken(string sString, string sToken, bool bAddToken) {
   return FString::getUntilToken(sString, sToken, bAddToken, true);
}
