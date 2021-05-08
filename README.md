<h1>BOVSTT</h1>
<h2>Buffer Overflow Vulnerability Services Tester Tool</h2>
Program to detect the existence of remote / local stack-based buffer-overflow vulnerabilities using the 
standard communication protocol for each service.<br>
The application allows to customize the testing mechanism of each service through templates, these 
templates are simply plain text files, which accept some kind of special words (see STF section), these files 
are stored in the <services> folder with a direct association between the protocol and the template and with 
the extension STF (Service Tester File).<br>
Currently the application version 2.5 supports the FTP, IMAP, POP3 and SMTP protocol.<br>
To carry out this task the application allows to specify different types of parameters.
<h2>Parameters</h2>
<h3>Aplication Layer Protocol</h3>
Description: Specifies the type of protocol to be tested.<br>
Required: Yes<br>
Options: -ap --application-layer-protocol <protocol><br>
Accepted values: FTP, POP3 or SMTP
<h3>Target Hostname IP</h3>
Description: Specifies host / ip address to be tested<br>
Required: Yes<br>
Options: -th --target-hostname-ip <hostname><br>
Accepted values: Any valid host / ip address.
<h3>Target Port</h3>
Description: Specifies the destination port of the service.<br>
Required: No<br>
Options: -tp --target-port <port><br>
Accepted values: 1 - 65535<br> 
If the user does not enter this parameter the application will automatically try to connect to the default 
destination port according to the service and the type of encryption.<br>
For example for POP3 service and SSL encryption the default port would be 995.
<h3>Cryptographic Security Protocol</h3>
Description: Specifies the type of service encryption.<br> 
Required: No<br> 
Options: -cp --cryptographic-security-protocol <crypt protocol><br>  
Accepted values: SSL, TLS<br>  
Note: No support yet.
<h3>Login Username</h3>
Description: Specifies the user of the credentials.<br>
Required: No<br>
Options: -lu --login-username <username><br> 
Accepted values: Alphanumeric value.<br> 
This parameter allows to customize the authentication mechanism of the protocol.<br> 
The application will initiate the authentication protocol through user / password as soon as it reads the 
#AUTH macro within the STF file associated with the protocol. If the authentication by user / password fails, 
the program will cancel its execution.<br>
Every time the application reads the keyword <login-username> inside the STF file, it will be replaced by the 
value of this parameter. 
<h3>Login Password</h3>
Description: Specifies the password of the credentials.<br> 
Required: No<br>
Options: -lu --login-password <password><br>
Accepted values: Alphanumeric value.<br>
This parameter allows to customize the authentication mechanism of the protocol.<br> 
Every time the application reads the keyword <login-password> inside the STF file, it will be replaced by the 
value of this parameter. 
<h3>Buffer Size Length</h3>
Description: Specifies the buffer size.<br> 
Required: No<br>
Options: -bs --buffer-size-length <size><br>
Accepted values: Numeric value greater than 0.<br> 
Default value: 1024<br>
This parameter allows to customize the size of the buffer to send.<br>
Every time the application reads the keyword <buffer> inside the STF file, it will be replaced by the sentence 
{ --buffer-character } * { --buffer- size-length }, in this case for example A*1024. 
<h3>Buffer Character</h3>
Description: Specifies the buffer character.<br> 
Required: No<br>
Options: -bc --buffer-character <character><br> 
Accepted values: Alphanumeric value.<br>
Default value: ‘A’
<h3>Output Verbose</h3>
Description: Specifies whether the user wants to obtain more information during the negotiation process 
with the remote host.<br> 
Required: No<br>
Options: -ov --output-verbose<br>
Accepted values: none 
<h3>Credits</h3>
Description: View the author of the program.<br> 
Required: No<br>
Options: -c --credits<br>
Alone: Yes, cannot be combined with another parameter. 
<h3>Version</h3>
Description: View the version of the program.<br> 
Required: No<br>
Options: -v --version<br>
Alone: Yes, cannot be combined with another parameter.
