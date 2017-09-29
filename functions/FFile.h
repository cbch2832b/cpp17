#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include "FCast.h"
#include "../Global.h"

#define FFILE_READ_LINE_EOF                                   "FFILE::EOF"

using namespace std;

class FFile {
   public:
      static bool fileExists(string sPathFilename);
      static void fileWriteLine(ofstream * oOutputFileStream, string sWriteLine);
      static string fileReadLine(ifstream * oInputFileStream);
};
