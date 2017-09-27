#include "FString.h"

string FString::replace(string sString, map<string, string> * oStringTokens) {
   string sReplaceString = sString;
   
   for (map<string, string>::iterator oIterator = oStringTokens->begin(); oIterator != oStringTokens->end(); oIterator++) {
      size_t nReplaceStringStartPosition = sReplaceString.find(oIterator->first);
	   
      if (nReplaceStringStartPosition != string::npos) {
         sReplaceString.replace(nReplaceStringStartPosition, oIterator->first.length(), oIterator->second);
      } 
   }
   
   return sReplaceString;   
}
