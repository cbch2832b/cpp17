#pragma once

#include <string>
#include <sys/stat.h>
#include "../Global.h"

using namespace std;

class FFile {
   public:
      static bool fileExists(string sPathFilename);
};
