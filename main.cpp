#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Global.h"
#include "ClientService.h"

/* #############################################################################################################
   #####                                                                                                   #####
   #####                                  BOVSTT - VERSION 1.0 Beta                                        ##### 
   #####                                                                                                   #####
   #####                     BOVSTT: Buffer-Overflow Vulnerability Services Tester Tool                    #####
   #####                                                                                                   #####
   #####  DESCRIPTION: Program to detect the existence of remote/local stack-based buffer-overflow         #####
   #####               vulnerabilities using the standard communication protocol for each service.         #####
   #####                                                                                                   #####	
   #####               The application classifies the different services using configurable .stf files     #####            
   #####               (Service Tester File) and thus allow to perform the own tests.                      #####
   #####                                                                                                   #####
   #####  USE: BOVSTT.exe APPLICATION_LAYER_PROTOCOL TARGET_HOSTNAME_IP [options]                          #####
   #####                                                                                                   #####
   #####  EXAMPLES: BOVSTT.exe FTP ftp.bost.com                                                            #####
   #####            BOVSTT.exe -ap FTP -th ftp.bost.com                                                    #####
   #####            BOVSTT.exe -ap FTP -th ftp.bost.com -lu <username> -lp <password>                      #####
   #####                                                                                                   ##### 
   #####  OPTIONS:                                                                                         #####
   #####            -ap --application-layer-protocol <protocol> FTP                                        #####
   #####            -th --target-hostname-ip <hostname>                                                    #####
   #####            -tp --target-port <port>                                                               #####
   #####            -cp --cryptographic-security-protocol <crypt protocol> SSL | TLS                       #####
   #####            -lu --login-username <username>                                                        #####
   #####            -lp --login-password <password>                                                        #####
   #####            -bs --buffer-size-length <size>                                                        #####
   #####            -bc --buffer-character <character>                                                     #####
   #####            -c --credits                                                                           #####
   #####            -v --version                                                                           #####
   #####                                                                                                   ##### 
   #####  AUTOR: Ivan Ricart Borges - Syscode                                                              #####
   #####  IDE: Dev-C ver-4.9.9.2                                                                           #####
   #####  COMPILER: MinGW                                                                                  #####
   #####  DEPENDENCES: Linker -> libwsock32.a                                                              #####
   #####  MAIL: iricartb@gmail.com                                                                         #####
   #####                                                                                                   ##### 
   ############################################################################################################# */
   
#define APP_BOVSTT_TITLE                                                      "BOVSTT: Buffer-Overflow Vulnerability Services Tester Tool"

#define APP_BOVSTT_DEFAULT_USER_INPUT_PARAMETER_BUFFER_SIZE_LENGHT            4096
#define APP_BOVSTT_DEFAULT_USER_INPUT_PARAMETER_BUFFER_CHARACTER              'A'

#define APP_BOVSTT_PARAMETER_APPLICATION_LAYER_PROTOCOL_ID                    "application-layer-protocol"
#define APP_BOVSTT_PARAMETER_APPLICATION_LAYER_PROTOCOL_NAME_VALUE            "protocol"
#define APP_BOVSTT_PARAMETER_APPLICATION_LAYER_PROTOCOL_ALIAS_1               "-ap"
#define APP_BOVSTT_PARAMETER_APPLICATION_LAYER_PROTOCOL_ALIAS_2               "--application-layer-protocol"

#define APP_BOVSTT_PARAMETER_CRYPTOGRAPHIC_SECURITY_PROTOCOL_ID               "cryptographic-security-protocol"
#define APP_BOVSTT_PARAMETER_CRYPTOGRAPHIC_SECURITY_PROTOCOL_NAME             "crypt protocol"
#define APP_BOVSTT_PARAMETER_CRYPTOGRAPHIC_SECURITY_PROTOCOL_ALIAS_1          "-cp"
#define APP_BOVSTT_PARAMETER_CRYPTOGRAPHIC_SECURITY_PROTOCOL_ALIAS_2          "--cryptographic-security-protocol"

#define APP_BOVSTT_PARAMETER_TARGET_HOSTNAME_IP_ID                            "target-hostname-ip"
#define APP_BOVSTT_PARAMETER_TARGET_HOSTNAME_IP_NAME_VALUE                    "hostname"
#define APP_BOVSTT_PARAMETER_TARGET_HOSTNAME_IP_ALIAS_1                       "-th"
#define APP_BOVSTT_PARAMETER_TARGET_HOSTNAME_IP_ALIAS_2                       "--target-hostname-ip"

#define APP_BOVSTT_PARAMETER_TARGET_PORT_ID                                   "target-port"
#define APP_BOVSTT_PARAMETER_TARGET_PORT_NAME_VALUE                           "port"
#define APP_BOVSTT_PARAMETER_TARGET_PORT_ALIAS_1                              "-tp"
#define APP_BOVSTT_PARAMETER_TARGET_PORT_ALIAS_2                              "--target-port"

#define APP_BOVSTT_PARAMETER_LOGIN_USERNAME_ID                                "login-username"
#define APP_BOVSTT_PARAMETER_LOGIN_USERNAME_NAME_VALUE                        "username"
#define APP_BOVSTT_PARAMETER_LOGIN_USERNAME_ALIAS_1                           "-lu"
#define APP_BOVSTT_PARAMETER_LOGIN_USERNAME_ALIAS_2                           "--login-username"

#define APP_BOVSTT_PARAMETER_LOGIN_PASSWORD_ID                                "login-password"
#define APP_BOVSTT_PARAMETER_LOGIN_PASSWORD_NAME_VALUE                        "password"
#define APP_BOVSTT_PARAMETER_LOGIN_PASSWORD_ALIAS_1                           "-lp"
#define APP_BOVSTT_PARAMETER_LOGIN_PASSWORD_ALIAS_2                           "--login-password"

#define APP_BOVSTT_PARAMETER_BUFFER_SIZE_LENGTH_ID                            "buffer-size-length"
#define APP_BOVSTT_PARAMETER_BUFFER_SIZE_LENGTH_NAME_VALUE                    "size"
#define APP_BOVSTT_PARAMETER_BUFFER_SIZE_LENGTH_ALIAS_1                       "-bs"
#define APP_BOVSTT_PARAMETER_BUFFER_SIZE_LENGTH_ALIAS_2                       "--buffer-size-length"

#define APP_BOVSTT_PARAMETER_BUFFER_CHARACTER_ID                              "buffer-character"
#define APP_BOVSTT_PARAMETER_BUFFER_CHARACTER_NAME_VALUE                      "character"
#define APP_BOVSTT_PARAMETER_BUFFER_CHARACTER_ALIAS_1                         "-bc"
#define APP_BOVSTT_PARAMETER_BUFFER_CHARACTER_ALIAS_2                         "--buffer-character"

#define APP_BOVSTT_PARAMETER_CREDITS_ALIAS_1                                  "-c"
#define APP_BOVSTT_PARAMETER_CREDITS_ALIAS_2                                  "--credits"

#define APP_BOVSTT_PARAMETER_VERSION_ALIAS_1                                  "-v"
#define APP_BOVSTT_PARAMETER_VERSION_ALIAS_2                                  "--version"

#define APP_BOVSTT_APP_USER_INPUT_PARAMETERS_STATUS_MAPPING_VALUE_OK          "STATUS_MAPPING_OK"
#define APP_BOVSTT_APP_USER_INPUT_PARAMETERS_STATUS_MAPPING_VALUE_FAIL        "STATUS_MAPPING_FAIL"
#define APP_BOVSTT_APP_USER_INPUT_PARAMETERS_STATUS_MAPPING_VALUE_PRINT       "STATUS_MAPPING_PRINT"

#define APP_BOVSTT_PARAMETER_TYPE_FIXED                                       "PARAMETER_TYPE_FIXED"
#define APP_BOVSTT_PARAMETER_TYPE_PORT                                        "PARAMETER_TYPE_PORT"
#define APP_BOVSTT_PARAMETER_TYPE_HOSTNAME                                    "PARAMETER_TYPE_HOSTNAME"
#define APP_BOVSTT_PARAMETER_TYPE_ALPHA                                       "PARAMETER_TYPE_ALPHA"
#define APP_BOVSTT_PARAMETER_TYPE_NUMERIC                                     "PARAMETER_TYPE_NUMERIC"
#define APP_BOVSTT_PARAMETER_TYPE_ALPHANUMERIC                                "PARAMETER_TYPE_ALPHANUMERIC"

#define APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_STRING                           "USER_INPUT_PARAMETER_TYPE_STRING"
#define APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_CHAR                             "USER_INPUT_PARAMETER_TYPE_CHAR"
#define APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_INT                              "USER_INPUT_PARAMETER_TYPE_INT"
#define APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_UNSIGNED_INT                     "USER_INPUT_PARAMETER_TYPE_UNSIGNED_INT"
#define APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_UNSIGNED_LONG_INT                "USER_INPUT_PARAMETER_TYPE_UNSIGNED_LONG_INT"
#define APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_BOOL                             "USER_INPUT_PARAMETER_TYPE_BOOL"

#define APP_BOVSTT_PARAMETER_TYPE_PORT_VALUE_MIN                              1
#define APP_BOVSTT_PARAMETER_TYPE_PORT_VALUE_MAX                              65535

#define APP_BOVSTT_CREDITS                                                    "Ivan Ricart Borges (iricartb@gmail.com)"
#define APP_BOVSTT_VERSION                                                    "1.0 Beta"
   
using namespace std;

typedef void (* cTypePointerFunction)(void);
typedef void (* cTypePointerUserInputParameter);

struct cTypeParameter {
   string sId;
   vector<string> oAliases;
   vector<string> oValues;
   string sNameValue;
   string sTypeValue;
   string sTypeUserInputValue;
   int nLengthValue;
   bool bAlone;
   bool bRequiredValue;
   bool bRequiredUserInput;
   bool bUserInput;
   cTypePointerFunction pFunction;
   cTypePointerUserInputParameter pUserInputParameter;
};

struct cTypeUserInputParameters {
   string sApplicationLayerProtocol;
   string sTargetHostnameIP;
   unsigned int nTargetPort;
   string sCryptographicSecurityProtocol;
   string sLoginUsername;
   string sLoginPassword;
   unsigned long int nBufferSizeLenght;
   char cBufferCharacter;
};

void initializeAppUserInputParameters(cTypeUserInputParameters &oAppUserInputParameters);
void initializeAppParameters(vector<cTypeParameter *> &oAppParameters, cTypeUserInputParameters &oAppUserInputParameters);

string mappingAppUserInputParameters(int nAppInputParameters, char** oAppInputParameters, cTypeUserInputParameters &oAppUserInputParameters, vector<cTypeParameter *> oAppParameters);
bool mappingAppUserInputParameter(char* oAppInputParameter, cTypeParameter * oAppParameter);

bool isValidAppParameterKeyWord(char* pAppUserInputParameter, bool checkIsAlone, vector<cTypeParameter *> oAppParameters);
bool isValidAppParameterValue(string sAppUserInputParameter, cTypeParameter * oAppParameter);

bool containAppParameters(int nAppUserInputParameters, char** oAppUserInputParameters, vector<cTypeParameter *> oAppParameters);
bool containAppAloneParameters(int nAppUserInputParameters, char** oAppUserInputParameters, vector<cTypeParameter *> oAppParameters);

cTypeParameter * getAppParameterByAlias(string sAlias, vector<cTypeParameter *> oAppParameters);

void printScreenAppInformation(string sAppName, vector<cTypeParameter *> oAppParameters);
void printScreenAppVersion();
void printScreenAppCredits();

int main(int argc, char** argv) {
   cTypeUserInputParameters oAppUserInputParameters;
   vector<cTypeParameter *> oAppParameters;
   string sAppUserInputParametersStatusMapping;
   
   initializeAppUserInputParameters(oAppUserInputParameters);	
   initializeAppParameters(oAppParameters, oAppUserInputParameters);
       
   sAppUserInputParametersStatusMapping = mappingAppUserInputParameters(argc, argv, oAppUserInputParameters, oAppParameters);
   
   if (sAppUserInputParametersStatusMapping == APP_BOVSTT_APP_USER_INPUT_PARAMETERS_STATUS_MAPPING_VALUE_OK) {

   }
   else if (sAppUserInputParametersStatusMapping == APP_BOVSTT_APP_USER_INPUT_PARAMETERS_STATUS_MAPPING_VALUE_FAIL) printScreenAppInformation(argv[0], oAppParameters);
	
   return 0;
}

/* -------------------------------- FUNCTIONS -------------------------------- */

void initializeAppUserInputParameters(cTypeUserInputParameters &oAppUserInputParameters) {
   oAppUserInputParameters.nBufferSizeLenght = APP_BOVSTT_DEFAULT_USER_INPUT_PARAMETER_BUFFER_SIZE_LENGHT;
   oAppUserInputParameters.cBufferCharacter = APP_BOVSTT_DEFAULT_USER_INPUT_PARAMETER_BUFFER_CHARACTER;
}

void initializeAppParameters(vector<cTypeParameter *> &oAppParameters, cTypeUserInputParameters &oAppUserInputParameters) {
   /* Parameter: --application-layer-protocol */
   cTypeParameter * oAppParameter1 = new cTypeParameter();
   
   oAppParameter1->sId = APP_BOVSTT_PARAMETER_APPLICATION_LAYER_PROTOCOL_ID;
   
   oAppParameter1->oAliases.push_back(APP_BOVSTT_PARAMETER_APPLICATION_LAYER_PROTOCOL_ALIAS_1);
   oAppParameter1->oAliases.push_back(APP_BOVSTT_PARAMETER_APPLICATION_LAYER_PROTOCOL_ALIAS_2);
   
   oAppParameter1->oValues.push_back(GLOBAL_APPLICATION_LAYER_PROTOCOL_FTP);
   
   oAppParameter1->sNameValue = APP_BOVSTT_PARAMETER_APPLICATION_LAYER_PROTOCOL_NAME_VALUE;
   oAppParameter1->sTypeValue = APP_BOVSTT_PARAMETER_TYPE_FIXED;
   oAppParameter1->sTypeUserInputValue = APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_STRING;
   
   oAppParameter1->bAlone = false;
   oAppParameter1->bRequiredValue = true;
   oAppParameter1->bRequiredUserInput = true;
   oAppParameter1->bUserInput = false;
   
   oAppParameter1->pUserInputParameter = &oAppUserInputParameters.sApplicationLayerProtocol;
   
   /* Parameter: --target-hostname-ip */
   cTypeParameter * oAppParameter2 = new cTypeParameter();
   
   oAppParameter2->sId = APP_BOVSTT_PARAMETER_TARGET_HOSTNAME_IP_ID;
   
   oAppParameter2->oAliases.push_back(APP_BOVSTT_PARAMETER_TARGET_HOSTNAME_IP_ALIAS_1);
   oAppParameter2->oAliases.push_back(APP_BOVSTT_PARAMETER_TARGET_HOSTNAME_IP_ALIAS_2);
   
   oAppParameter2->sNameValue = APP_BOVSTT_PARAMETER_TARGET_HOSTNAME_IP_NAME_VALUE;
   oAppParameter2->sTypeValue = APP_BOVSTT_PARAMETER_TYPE_HOSTNAME;
   oAppParameter2->sTypeUserInputValue = APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_STRING;
   
   oAppParameter2->bAlone = false;
   oAppParameter2->bRequiredValue = true;
   oAppParameter2->bRequiredUserInput = true;
   oAppParameter2->bUserInput = false;
   
   oAppParameter2->pUserInputParameter = &oAppUserInputParameters.sTargetHostnameIP;
   
   /* Parameter: --target-port */
   cTypeParameter * oAppParameter3 = new cTypeParameter();
   
   oAppParameter3->sId = APP_BOVSTT_PARAMETER_TARGET_PORT_ID;
   
   oAppParameter3->oAliases.push_back(APP_BOVSTT_PARAMETER_TARGET_PORT_ALIAS_1);
   oAppParameter3->oAliases.push_back(APP_BOVSTT_PARAMETER_TARGET_PORT_ALIAS_2);
   
   oAppParameter3->sNameValue = APP_BOVSTT_PARAMETER_TARGET_PORT_NAME_VALUE;
   oAppParameter3->sTypeValue = APP_BOVSTT_PARAMETER_TYPE_PORT;
   oAppParameter3->sTypeUserInputValue = APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_UNSIGNED_INT;
   
   oAppParameter3->bAlone = false;
   oAppParameter3->bRequiredValue = true;
   oAppParameter3->bRequiredUserInput = false;
   oAppParameter3->bUserInput = false;
   
   oAppParameter3->pUserInputParameter = &oAppUserInputParameters.nTargetPort;
	 
   /* Parameter: --cryptographic-security-protocol */
   cTypeParameter * oAppParameter4 = new cTypeParameter();
   
   oAppParameter4->sId = APP_BOVSTT_PARAMETER_CRYPTOGRAPHIC_SECURITY_PROTOCOL_ID;
  
   oAppParameter4->oAliases.push_back(APP_BOVSTT_PARAMETER_CRYPTOGRAPHIC_SECURITY_PROTOCOL_ALIAS_1);
   oAppParameter4->oAliases.push_back(APP_BOVSTT_PARAMETER_CRYPTOGRAPHIC_SECURITY_PROTOCOL_ALIAS_2);
   
   oAppParameter4->oValues.push_back(GLOBAL_CRYPTOGRAPHIC_SECURITY_PROTOCOL_VALUE_SSL);
   oAppParameter4->oValues.push_back(GLOBAL_CRYPTOGRAPHIC_SECURITY_PROTOCOL_VALUE_TLS);
   
   oAppParameter4->sNameValue = APP_BOVSTT_PARAMETER_CRYPTOGRAPHIC_SECURITY_PROTOCOL_NAME;
   oAppParameter4->sTypeValue = APP_BOVSTT_PARAMETER_TYPE_FIXED;
   oAppParameter4->sTypeUserInputValue = APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_STRING;
   
   oAppParameter4->bAlone = false;
   oAppParameter4->bRequiredValue = true;
   oAppParameter4->bRequiredUserInput = false;
   oAppParameter4->bUserInput = false;
   
   oAppParameter4->pUserInputParameter = &oAppUserInputParameters.sCryptographicSecurityProtocol;
   
   /* Parameter: --login-username */
   cTypeParameter * oAppParameter5 = new cTypeParameter();
   
   oAppParameter5->sId = APP_BOVSTT_PARAMETER_LOGIN_USERNAME_ID;
   
   oAppParameter5->oAliases.push_back(APP_BOVSTT_PARAMETER_LOGIN_USERNAME_ALIAS_1);
   oAppParameter5->oAliases.push_back(APP_BOVSTT_PARAMETER_LOGIN_USERNAME_ALIAS_2);
   
   oAppParameter5->sNameValue = APP_BOVSTT_PARAMETER_LOGIN_USERNAME_NAME_VALUE;
   oAppParameter5->sTypeValue = APP_BOVSTT_PARAMETER_TYPE_ALPHANUMERIC;
   oAppParameter5->sTypeUserInputValue = APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_STRING;
    
   oAppParameter5->bAlone = false;
   oAppParameter5->bRequiredValue = true;
   oAppParameter5->bRequiredUserInput = false;
   oAppParameter5->bUserInput = false;
   
   oAppParameter5->pUserInputParameter = &oAppUserInputParameters.sLoginUsername;
   
   /* Parameter: --login-password */
   cTypeParameter * oAppParameter6 = new cTypeParameter();
   
   oAppParameter6->sId = APP_BOVSTT_PARAMETER_LOGIN_PASSWORD_ID;
   
   oAppParameter6->oAliases.push_back(APP_BOVSTT_PARAMETER_LOGIN_PASSWORD_ALIAS_1);
   oAppParameter6->oAliases.push_back(APP_BOVSTT_PARAMETER_LOGIN_PASSWORD_ALIAS_2);
   
   oAppParameter6->sNameValue = APP_BOVSTT_PARAMETER_LOGIN_PASSWORD_NAME_VALUE;
   oAppParameter6->sTypeValue = APP_BOVSTT_PARAMETER_TYPE_ALPHANUMERIC;
   oAppParameter6->sTypeUserInputValue = APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_STRING;
   
   oAppParameter6->bAlone = false;
   oAppParameter6->bRequiredValue = true;
   oAppParameter6->bRequiredUserInput = false;
   oAppParameter6->bUserInput = false;
   
   oAppParameter6->pUserInputParameter = &oAppUserInputParameters.sLoginPassword;
   
   /* Parameter: --buffer-size-length */
   cTypeParameter * oAppParameter7 = new cTypeParameter();
   
   oAppParameter7->sId = APP_BOVSTT_PARAMETER_BUFFER_SIZE_LENGTH_ID;
   
   oAppParameter7->oAliases.push_back(APP_BOVSTT_PARAMETER_BUFFER_SIZE_LENGTH_ALIAS_1);
   oAppParameter7->oAliases.push_back(APP_BOVSTT_PARAMETER_BUFFER_SIZE_LENGTH_ALIAS_2);
   
   oAppParameter7->sNameValue = APP_BOVSTT_PARAMETER_BUFFER_SIZE_LENGTH_NAME_VALUE;
   oAppParameter7->sTypeValue = APP_BOVSTT_PARAMETER_TYPE_NUMERIC;
   oAppParameter7->sTypeUserInputValue = APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_UNSIGNED_LONG_INT;
   
   oAppParameter7->bAlone = false;
   oAppParameter7->bRequiredValue = true;
   oAppParameter7->bRequiredUserInput = false;
   oAppParameter7->bUserInput = false;
   
   oAppParameter7->pUserInputParameter = &oAppUserInputParameters.nBufferSizeLenght;
   
   /* Parameter: --buffer-character */
   cTypeParameter * oAppParameter8 = new cTypeParameter();
   
   oAppParameter8->sId = APP_BOVSTT_PARAMETER_BUFFER_CHARACTER_ID;
   
   oAppParameter8->oAliases.push_back(APP_BOVSTT_PARAMETER_BUFFER_CHARACTER_ALIAS_1);
   oAppParameter8->oAliases.push_back(APP_BOVSTT_PARAMETER_BUFFER_CHARACTER_ALIAS_2);
   
   oAppParameter8->sNameValue = APP_BOVSTT_PARAMETER_BUFFER_CHARACTER_NAME_VALUE;
   oAppParameter8->sTypeValue = APP_BOVSTT_PARAMETER_TYPE_ALPHANUMERIC;
   oAppParameter8->sTypeUserInputValue = APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_CHAR;
   oAppParameter8->nLengthValue = 1;
   
   oAppParameter8->bAlone = false;
   oAppParameter8->bRequiredValue = true;
   oAppParameter8->bRequiredUserInput = false;
   oAppParameter8->bUserInput = false;

   oAppParameter8->pUserInputParameter = &oAppUserInputParameters.cBufferCharacter;
   
   /* Parameter: --credits */
   cTypeParameter * oAppParameter9 = new cTypeParameter();
	
   oAppParameter9->oAliases.push_back(APP_BOVSTT_PARAMETER_CREDITS_ALIAS_1);
   oAppParameter9->oAliases.push_back(APP_BOVSTT_PARAMETER_CREDITS_ALIAS_2);
   
   oAppParameter9->bAlone = true;
   oAppParameter9->bRequiredValue = false;
   oAppParameter9->bRequiredUserInput = false;
   oAppParameter9->bUserInput = false;
   
   oAppParameter9->pFunction = printScreenAppCredits;
   
   /* Parameter: --version */
   cTypeParameter * oAppParameter10 = new cTypeParameter();
	
   oAppParameter10->oAliases.push_back(APP_BOVSTT_PARAMETER_VERSION_ALIAS_1);
   oAppParameter10->oAliases.push_back(APP_BOVSTT_PARAMETER_VERSION_ALIAS_2);
   
   oAppParameter10->bAlone = true;
   oAppParameter10->bRequiredValue = false;
   oAppParameter10->bRequiredUserInput = false;
   oAppParameter10->bUserInput = false;
   
   oAppParameter10->pFunction = printScreenAppVersion;
   
   oAppParameters.push_back(oAppParameter1);	
   oAppParameters.push_back(oAppParameter2);	
   oAppParameters.push_back(oAppParameter3);	
   oAppParameters.push_back(oAppParameter4);
   oAppParameters.push_back(oAppParameter5);
   oAppParameters.push_back(oAppParameter6);
   oAppParameters.push_back(oAppParameter7);
   oAppParameters.push_back(oAppParameter8);
   oAppParameters.push_back(oAppParameter9);
   oAppParameters.push_back(oAppParameter10);
}
     
cTypeParameter * getAppParameterByAlias(string sAlias, vector<cTypeParameter *> oAppParameters) {
   cTypeParameter * oAppParameter = NULL;
   bool bFindAppParameter = false;
   
   for(int i = 0; ((i < oAppParameters.size()) && (!bFindAppParameter)); i++) {
      for(int j = 0; ((j < oAppParameters[i]->oAliases.size()) && (!bFindAppParameter)); j++) {
         if (sAlias == oAppParameters[i]->oAliases[j]) {
            oAppParameter = oAppParameters[i];
            bFindAppParameter = true;
         }  
      }   
   }
   
   return oAppParameter;   
}
               
string mappingAppUserInputParameters(int nAppInputParameters, char** oAppInputParameters, cTypeUserInputParameters &oAppUserInputParameters, vector<cTypeParameter *> oAppParameters) {
   string sMappingAppUserInputParameters = APP_BOVSTT_APP_USER_INPUT_PARAMETERS_STATUS_MAPPING_VALUE_FAIL;
	
   /* Case 1: 2 parameters with one alone option */
   if ((nAppInputParameters == 2) && (containAppAloneParameters(nAppInputParameters, oAppInputParameters, oAppParameters))) {
      cTypeParameter * oAppAloneParameter = getAppParameterByAlias(oAppInputParameters[1], oAppParameters);
      
      oAppAloneParameter->pFunction();
      
      oAppAloneParameter->bUserInput = true;
      
      sMappingAppUserInputParameters = APP_BOVSTT_APP_USER_INPUT_PARAMETERS_STATUS_MAPPING_VALUE_PRINT; 
   }
   /* Case 2: Variable number of parameters */
   else {
      bool bError = false;
      bool bNextParameter = true;
      cTypeParameter * oAppParameter;
      
      for(int i = 1; ((i < nAppInputParameters) && (!bError)); i++) {
         if (bNextParameter) {
            if ((isValidAppParameterKeyWord(oAppInputParameters[i], false, oAppParameters)) && (!isValidAppParameterKeyWord(oAppInputParameters[i], true, oAppParameters))) {
               oAppParameter = getAppParameterByAlias(oAppInputParameters[i], oAppParameters);
               
               if (oAppParameter->bRequiredValue) bNextParameter = false;
               else oAppParameter->bUserInput = true;    
            }
            else if ((!isValidAppParameterKeyWord(oAppInputParameters[i], true, oAppParameters)) && ((i == 1) || (i == 2))) {
               cTypeParameter * oAppParameterApplicationLayerProtocol = getAppParameterByAlias(APP_BOVSTT_PARAMETER_APPLICATION_LAYER_PROTOCOL_ALIAS_1, oAppParameters);
               cTypeParameter * oAppParameterTargetHostnameIP = getAppParameterByAlias(APP_BOVSTT_PARAMETER_TARGET_HOSTNAME_IP_ALIAS_1, oAppParameters);
               
               if (((i == 1) && (isValidAppParameterValue(oAppInputParameters[i], oAppParameterApplicationLayerProtocol))) || ((i == 2) && (isValidAppParameterValue(oAppInputParameters[i], oAppParameterTargetHostnameIP)))) {
                  if (i == 1) {
                     oAppParameterApplicationLayerProtocol->bUserInput = true; 
                     mappingAppUserInputParameter(oAppInputParameters[i], oAppParameterApplicationLayerProtocol);	
                  } 
                  else {
                     oAppParameterTargetHostnameIP->bUserInput = true; 
                     mappingAppUserInputParameter(oAppInputParameters[i], oAppParameterTargetHostnameIP);
                  } 
					            
                  bNextParameter = true;   	
              }
            }
            else bError = true;
         }
         else {
            if ((!isValidAppParameterKeyWord(oAppInputParameters[i], false, oAppParameters)) && (isValidAppParameterValue(oAppInputParameters[i], oAppParameter))) {
               oAppParameter->bUserInput = true;
               
               mappingAppUserInputParameter(oAppInputParameters[i], oAppParameter);
               
               bNextParameter = true;   
            }
            else bError = true;      
         }         	
      }
      
      /* check if all required parameters are inserted */
      for(int i = 0; ((i < oAppParameters.size()) && (!bError)); i++) {
         if ((oAppParameters[i]->bRequiredUserInput) && (!oAppParameters[i]->bUserInput)) bError = true;
      }
      
      if ((!bError) && (bNextParameter)) sMappingAppUserInputParameters = APP_BOVSTT_APP_USER_INPUT_PARAMETERS_STATUS_MAPPING_VALUE_OK; 
   }
	
   return sMappingAppUserInputParameters;	
}

bool mappingAppUserInputParameter(char* oAppInputParameter, cTypeParameter * oAppParameter) {
   bool bMappingAppUserInputParameter = false;
   
   if (oAppParameter->pUserInputParameter != NULL) {
      bMappingAppUserInputParameter = true;
		
      if (oAppParameter->sTypeUserInputValue == APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_STRING) *((string *) oAppParameter->pUserInputParameter) = oAppInputParameter;
      else if (oAppParameter->sTypeUserInputValue == APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_CHAR) *((char *) oAppParameter->pUserInputParameter) = *oAppInputParameter;
      else if (oAppParameter->sTypeUserInputValue == APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_INT) *((int *) oAppParameter->pUserInputParameter) = (int) strtoull(oAppInputParameter, NULL, 0);
      else if (oAppParameter->sTypeUserInputValue == APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_UNSIGNED_INT) *((unsigned int *) oAppParameter->pUserInputParameter) = (unsigned int) strtoull(oAppInputParameter, NULL, 0);
      else if (oAppParameter->sTypeUserInputValue == APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_UNSIGNED_LONG_INT) *((unsigned long int *) oAppParameter->pUserInputParameter) = (unsigned long int) strtoull(oAppInputParameter, NULL, 0);
      else if (oAppParameter->sTypeUserInputValue == APP_BOVSTT_USER_INPUT_PARAMETER_TYPE_BOOL) *((bool *) oAppParameter->pUserInputParameter) = (bool) strtoull(oAppInputParameter, NULL, 0);
      else bMappingAppUserInputParameter = false;
   }
	
   return bMappingAppUserInputParameter;
}

bool isValidAppParameterKeyWord(char* pAppUserInputParameter, bool checkIsAlone, vector<cTypeParameter *> oAppParameters) {
   bool bValidAppParameterKeyWord = false;
   
   for(int i = 0; ((i < oAppParameters.size()) && (!bValidAppParameterKeyWord)); i++) {
      for(int j = 0; ((j < oAppParameters[i]->oAliases.size()) && (!bValidAppParameterKeyWord)); j++) {
         if (pAppUserInputParameter == oAppParameters[i]->oAliases[j]) {
            bValidAppParameterKeyWord = true;
            
            if ((checkIsAlone) && (!oAppParameters[i]->bAlone)) bValidAppParameterKeyWord = false;
         }   
      }   
   }
 
   return bValidAppParameterKeyWord; 
}
     
bool isValidAppParameterValue(string sAppUserInputParameter, cTypeParameter * oAppParameter) {
   bool bValidAppParameterValue = false;
   bool bError = false;
   
   if (oAppParameter != NULL) {
      if (oAppParameter->sTypeValue == APP_BOVSTT_PARAMETER_TYPE_FIXED) {
         for(int i = 0; ((i < oAppParameter->oValues.size()) && (!bValidAppParameterValue)); i++) {
            if (sAppUserInputParameter == oAppParameter->oValues[i]) bValidAppParameterValue = true;
         }
      }
      else if (oAppParameter->sTypeValue == APP_BOVSTT_PARAMETER_TYPE_PORT) {
         if ((atoi(sAppUserInputParameter.c_str()) >= APP_BOVSTT_PARAMETER_TYPE_PORT_VALUE_MIN) && (atoi(sAppUserInputParameter.c_str()) <= APP_BOVSTT_PARAMETER_TYPE_PORT_VALUE_MAX)) bValidAppParameterValue = true;
      }
      else if (oAppParameter->sTypeValue == APP_BOVSTT_PARAMETER_TYPE_HOSTNAME) {
         for(int i = 0; ((i < sAppUserInputParameter.size()) && (!bError)); i++) {
            if (!(((sAppUserInputParameter[i] == 45) && ((i > 0) && (i < (sAppUserInputParameter.size() - 1)))) || ((sAppUserInputParameter[i] == 46) && ((i > 0) && (i < (sAppUserInputParameter.size() - 1)))) || ((sAppUserInputParameter[i] >= 48) && (sAppUserInputParameter[i] <= 57)) || ((sAppUserInputParameter[i] >= 97) && (sAppUserInputParameter[i] <= 122)))) bError = true;
         }
   
         if (!bError) bValidAppParameterValue = true;    
      }
      else if (oAppParameter->sTypeValue == APP_BOVSTT_PARAMETER_TYPE_ALPHA) {
         for(int i = 0; ((i < sAppUserInputParameter.size()) && (!bError)); i++) {
            if (!(((sAppUserInputParameter[i] >= 65) && (sAppUserInputParameter[i] <= 90)) || ((sAppUserInputParameter[i] >= 97) && (sAppUserInputParameter[i] <= 122)))) bError = true;     
         }
   
         if ((oAppParameter->nLengthValue > 0) && (sAppUserInputParameter.length() != oAppParameter->nLengthValue)) bError = true; 
         
         if (!bError) bValidAppParameterValue = true;    
      }
      else if (oAppParameter->sTypeValue == APP_BOVSTT_PARAMETER_TYPE_NUMERIC) {
         for(int i = 0; ((i < sAppUserInputParameter.size()) && (!bError)); i++) {
            if (!((sAppUserInputParameter[i] >= 48) && (sAppUserInputParameter[i] <= 57))) bError = true;
         }
         
         if ((oAppParameter->nLengthValue > 0) && (sAppUserInputParameter.length() != oAppParameter->nLengthValue)) bError = true; 
   
         if (!bError) bValidAppParameterValue = true;    
      }
      else if (oAppParameter->sTypeValue == APP_BOVSTT_PARAMETER_TYPE_ALPHANUMERIC) {
         for(int i = 0; ((i < sAppUserInputParameter.size()) && (!bError)); i++) {
            if (!(((sAppUserInputParameter[i] >= 65) && (sAppUserInputParameter[i] <= 90)) || ((sAppUserInputParameter[i] >= 97) && (sAppUserInputParameter[i] <= 122)) || ((sAppUserInputParameter[i] >= 48) && (sAppUserInputParameter[i] <= 57)))) bError = true;     
         }

         if ((oAppParameter->nLengthValue > 0) && (sAppUserInputParameter.length() != oAppParameter->nLengthValue)) bError = true; 

         if (!bError) bValidAppParameterValue = true;    
      }
   }
        
   return bValidAppParameterValue;
}
     
bool containAppParameters(int nAppUserInputParameters, char** oAppUserInputParameters, vector<cTypeParameter *> oAppParameters) {
   bool bContainAppParameters = false;
   
   for(int i = 0; ((i < nAppUserInputParameters) && (!bContainAppParameters)); i++) {
      if (isValidAppParameterKeyWord(oAppUserInputParameters[i], false, oAppParameters)) bContainAppParameters = true;
   } 
   
   return bContainAppParameters;     
}

bool containAppAloneParameters(int nAppUserInputParameters, char** oAppUserInputParameters, vector<cTypeParameter *> oAppParameters) {
   bool bContainAppAloneParameters = false;
   
   for(int i = 0; ((i < nAppUserInputParameters) && (!bContainAppAloneParameters)); i++) {
      if (isValidAppParameterKeyWord(oAppUserInputParameters[i], true, oAppParameters)) bContainAppAloneParameters = true;
   } 
   
   return bContainAppAloneParameters;    
}
     
void printScreenAppInformation(string sAppName, vector<cTypeParameter *> oAppParameters) {
   system("cls");
   
   cout << endl << "\t    " << APP_BOVSTT_TITLE << endl;	
   cout << "   ____________________________________________________________________________   " << endl << endl;
   cout << "   Use: " << sAppName << " APPLICATION_LAYER_PROTOCOL TARGET_HOSTNAME_IP [options]" << endl << endl;
   cout << "   Examples: " << sAppName << GLOBAL_STRING_SPACE << GLOBAL_APPLICATION_LAYER_PROTOCOL_FTP << " ftp.bost.com" << endl;
   cout << "             " << sAppName << " -ap " << GLOBAL_APPLICATION_LAYER_PROTOCOL_FTP << " -th ftp.bost.com" << endl;
   cout << "             " << sAppName << " -ap " << GLOBAL_APPLICATION_LAYER_PROTOCOL_FTP << " -th ftp.bost.com -lu <username> -lp <password>" << endl << endl;

   cout << "   Options:" << endl;
   for(int i = 0; i < oAppParameters.size(); i++) {
      cout << "             ";
      string sOption = GLOBAL_STRING_EMPTY;
      
      for(int j = 0; j < oAppParameters[i]->oAliases.size(); j++) {
         sOption += oAppParameters[i]->oAliases[j];
      	
      	 if ((j + 1) < oAppParameters[i]->oAliases.size()) sOption += GLOBAL_STRING_SPACE;
      }
		
      if (oAppParameters[i]->bRequiredValue) {
         sOption += GLOBAL_STRING_SPACE;
         sOption += "<" + oAppParameters[i]->sNameValue + ">"; 
      }
        
      for(int j = 0; j < oAppParameters[i]->oValues.size(); j++) {
         sOption += GLOBAL_STRING_SPACE + oAppParameters[i]->oValues[j];
      	
         if ((j + 1) < oAppParameters[i]->oValues.size()) {
            sOption += GLOBAL_STRING_SPACE;
            sOption += "|";
         }
      }
                                           
      cout << sOption << endl;
   }
   
   cout << endl << "   ____________________________________________________________________________   " << endl << endl;
}

void printScreenAppVersion() {
   system("cls");
   
   cout << endl << "\t\t     " << APP_BOVSTT_TITLE << endl;	
   cout << "   __________________________________________________________________________   " << endl << endl;
   cout << "   Version: " << APP_BOVSTT_VERSION << endl << endl;  
   cout << "   __________________________________________________________________________   " << endl << endl;
}

void printScreenAppCredits() {
   system("cls");
   
   cout << endl << "\t\t     " << APP_BOVSTT_TITLE << endl;	
   cout << "   __________________________________________________________________________   " << endl << endl;
   cout << "   Credits: " << APP_BOVSTT_CREDITS << endl << endl;
   cout << "   __________________________________________________________________________   " << endl << endl;
}
