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
Options: -ap --application-layer-protocol &ltprotocol&gt<br>
Accepted values: FTP, POP3 or SMTP
<h3>Target Hostname IP</h3>
Description: Specifies host / ip address to be tested<br>
Required: Yes<br>
Options: -th --target-hostname-ip &lthostname&gt<br>
Accepted values: Any valid host / ip address.
<h3>Target Port</h3>
Description: Specifies the destination port of the service.<br>
Required: No<br>
Options: -tp --target-port &ltport&gt<br>
Accepted values: 1 - 65535<br> 
If the user does not enter this parameter the application will automatically try to connect to the default 
destination port according to the service and the type of encryption.<br>
For example for POP3 service and SSL encryption the default port would be 995.
<h3>Cryptographic Security Protocol</h3>
Description: Specifies the type of service encryption.<br> 
Required: No<br> 
Options: -cp --cryptographic-security-protocol &ltcrypt protocol&gt<br>  
Accepted values: SSL, TLS<br>  
Note: No support yet.
<h3>Login Username</h3>
Description: Specifies the user of the credentials.<br>
Required: No<br>
Options: -lu --login-username &ltusername&gt<br> 
Accepted values: Alphanumeric value.<br> 
This parameter allows to customize the authentication mechanism of the protocol.<br> 
The application will initiate the authentication protocol through user / password as soon as it reads the 
#AUTH macro within the STF file associated with the protocol. If the authentication by user / password fails, 
the program will cancel its execution.<br>
Every time the application reads the keyword &ltlogin-username&gt inside the STF file, it will be replaced by the 
value of this parameter. 
<h3>Login Password</h3>
Description: Specifies the password of the credentials.<br> 
Required: No<br>
Options: -lu --login-password &ltpassword&gt<br>
Accepted values: Alphanumeric value.<br>
This parameter allows to customize the authentication mechanism of the protocol.<br> 
Every time the application reads the keyword &ltlogin-password&gt inside the STF file, it will be replaced by the 
value of this parameter. 
<h3>Buffer Size Length</h3>
Description: Specifies the buffer size.<br> 
Required: No<br>
Options: -bs --buffer-size-length &ltsize&gt<br>
Accepted values: Numeric value greater than 0.<br> 
Default value: 1024<br>
This parameter allows to customize the size of the buffer to send.<br>
Every time the application reads the keyword &ltbuffer&gt inside the STF file, it will be replaced by the sentence 
{ --buffer-character } * { --buffer- size-length }, in this case for example A*1024. 
<h3>Buffer Character</h3>
Description: Specifies the buffer character.<br> 
Required: No<br>
Options: -bc --buffer-character &ltcharacter&gt<br> 
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
<h2>STF Files</h2>
The STF files could be considered as a template, these are simply plain text files, which accept some kind of 
special words, these files are stored in the <services> folder with a direct association between the protocol 
and the template and with the extension STF (Service Tester File).<br>
For example for the FTP protocol there is an STF file in the <services> folder called FTP.stf, for SMTP there is 
an STF file called SMTP.stf and so on.<br> 
Once the connection to the remote host is established, the application begins to read the corresponding STF 
file, later it’ll read line by line until finalizing the file or until it finds an error.<br>
Each line of the file represents a command to send to the remote host, with the particularity that it accepts 
a series of keywords that will be translated at runtime, these keywords are as follows:
<ul>
   <li><login-username>: Each time the application finds this tag inside the file STF, this will be replaced by 
the value of the parameter -lu --login-username entered by the user.</li>
   <li><login-password>: Each time the application finds this tag inside the file STF, this will be replaced by 
the value of the parameter -lp --login-password entered by the user.</li>
   <li><buffer >: Each time the application finds this tag inside the file STF, this will be replaced by the 
values of the parameters { --buffer-character } * { --buffer- size-length } entered by the user.</li>
   <li><remote-domain>: Each time the application finds this tag inside the file STF, this will be replaced by 
the domain value of the parameter -th --target-hostname-ip entered by the user.</li>
</ul>
These files also accept a series of macros that allow to change the behavior of the testing mechanism, These 
macros are as follows: 
<ul>
   <li>#AUTH: Must be entered without further information, implies that all the sentences that follow will 
be executed only if the process of authentication has been satisfactory. The authentication process 
is automatic, for this it is important that the user has entered the user and password as parameters 
in the application.<br>
Its use is not obligatory, but in case of applying it we could send commands to the remote server 
where only the authenticated users can have access</li>
   <li>#RETURN <VALUE> : <COMMAND>: The command <COMMAND> will be sent only if a return value 
<VALUE> has been returned in the last send process, otherwise the test program will stop, could be 
considered as a conditional command, in case the remote host has answered in its last command a 
certain value, the system continues with the test.</li>
</ul>
