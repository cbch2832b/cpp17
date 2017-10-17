#include "FCrypt.h"
           
string FCrypt::cryptBase64(string sString) {
   string sCryptBase64 = GLOBAL_STRING_EMPTY;
   int j = 0, k = 0;
   unsigned char oArray3[3];
   unsigned char oArray4[4];

   for(int i = 0; i < sString.length(); i++) {
      oArray3[j++] = sString[i];
      
      if (j == 3) {
         oArray4[0] = (oArray3[0] & 0xfc) >> 2;
         oArray4[1] = ((oArray3[0] & 0x03) << 4) + ((oArray3[1] & 0xf0) >> 4);
         oArray4[2] = ((oArray3[1] & 0x0f) << 2) + ((oArray3[2] & 0xc0) >> 6);
         oArray4[3] = oArray3[2] & 0x3f;

         for(j = 0; (j < 4) ; j++) sCryptBase64 += FCRYPT_BASE64_ALPHABET[oArray4[j]];
         
         j = 0;
      }
   }

   if (j) {
      for(k = j; k < 3; k++) oArray3[k] = '\0';

      oArray4[0] = (oArray3[0] & 0xfc) >> 2;
      oArray4[1] = ((oArray3[0] & 0x03) << 4) + ((oArray3[1] & 0xf0) >> 4);
      oArray4[2] = ((oArray3[1] & 0x0f) << 2) + ((oArray3[2] & 0xc0) >> 6);
      oArray4[3] = oArray3[2] & 0x3f;

      for(k = 0; (k < j + 1); k++) sCryptBase64 += FCRYPT_BASE64_ALPHABET[oArray4[k]];
      
      while(j++ < 3) sCryptBase64 += '=';
   }

   return sCryptBase64;
}
