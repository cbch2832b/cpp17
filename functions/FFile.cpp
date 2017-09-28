#include "FFile.h"

bool FFile::fileExists(string sPathFilename) {
   struct stat oFileInfo;

   return (stat(FCast::castStringToConstChar(sPathFilename), &oFileInfo) == 0);    
}

void FFile::fileWriteLine(ofstream oOutputFileStream, string sWriteLine) {
   oOutputFileStream << sWriteLine;
}
