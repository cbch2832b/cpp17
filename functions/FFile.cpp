#include "FFile.h"

bool FFile::fileExists(string sPathFilename) {
   struct stat oFileInfo;

   return (stat(sPathFilename.c_str(), &oFileInfo) == 0);    
}
