/* #############################################################################################################
   #####                                                                                                   #####
   #####                                  BOVSTT - VERSION 1.0 Beta                                        ##### 
   #####                                                                                                   #####
   #####                     BOVSTT: Buffer Overflow Vulnerability Services Tester Tool                    #####
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
