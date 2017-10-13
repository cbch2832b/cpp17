#include "FCast.h"

string FCast::castUnsignedNumberToString(unsigned long long int nNumber) {
   stringstream oStringStream;
   oStringStream << nNumber;
	 
   return (oStringStream.str()); 	
}

string FCast::castSignedNumberToString(long long int nNumber) {
   stringstream oStringStream;
   oStringStream << nNumber;
	 
   return (oStringStream.str()); 	
}

string FCast::castNumberToString(unsigned short int nNumber) { return FCast::castUnsignedNumberToString(nNumber); }
string FCast::castNumberToString(unsigned int nNumber) { return FCast::castUnsignedNumberToString(nNumber); }
string FCast::castNumberToString(unsigned long int nNumber) { return FCast::castUnsignedNumberToString(nNumber); }
string FCast::castNumberToString(unsigned long long int nNumber) { return FCast::castUnsignedNumberToString(nNumber); }

string FCast::castNumberToString(short int nNumber) { return FCast::castSignedNumberToString(nNumber); }
string FCast::castNumberToString(int nNumber) { return FCast::castSignedNumberToString(nNumber); }
string FCast::castNumberToString(long int nNumber) { return FCast::castSignedNumberToString(nNumber); }
string FCast::castNumberToString(long long int nNumber) { return FCast::castSignedNumberToString(nNumber); }

const char * FCast::castStringToConstChar(string sString) { return sString.c_str(); }
