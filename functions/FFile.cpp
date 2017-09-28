#include "FFile.h"

bool FFile::fileExists(string sPathFilename) {
   struct stat oFileInfo;

   return (stat(FCast::castStringToConstChar(sPathFilename), &oFileInfo) == 0);    
}

void FFile::fileWriteLine(ofstream * oOutputFileStream, string sWriteLine) {
   *oOutputFileStream << sWriteLine;
}

string FFile::fileReadLine(ifstream * oInputFileStream) {
   string sFileReadLine = GLOBAL_STRING_EMPTY;
   
   getline(*oInputFileStream, sFileReadLine);
   
   return sFileReadLine;
}
