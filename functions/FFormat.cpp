#include "FFormat.h"

bool FFormat::isFormatHostname(string sString) {
   struct hostent * oHostent;
   bool bIsFormatHostname = false;
   
   oHostent = gethostbyname(FCast::castStringToConstChar(sString));
   if (oHostent != NULL) {
      if (inet_ntoa(*((struct in_addr *) oHostent->h_addr)) != sString) bIsFormatHostname = true;
   }
	
   return bIsFormatHostname;   
}
