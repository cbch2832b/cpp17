#pragma once

#include <string>
#include <sstream>
#include "../Global.h"

using namespace std;

class FCast {
   private:
      static string castUnsignedNumberToString(unsigned long long int nNumber);
      static string castSignedNumberToString(long long int nNumber);
	   
   public:
      static string castNumberToString(unsigned short int nNumber);
      static string castNumberToString(unsigned int nNumber);
      static string castNumberToString(unsigned long int nNumber);
      static string castNumberToString(unsigned long long int nNumber);
      static string castNumberToString(short int nNumber);
      static string castNumberToString(int nNumber);
      static string castNumberToString(long int nNumber);
      static string castNumberToString(long long int nNumber);
      
      static const char * castStringToConstChar(string sString);
};
