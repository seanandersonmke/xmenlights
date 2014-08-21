#include <SPI.h>
#include <Ethernet.h>
#include "pitches.h"


byte mac[] = {  
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };

EthernetClient client; //ethernet object from ethernet library
EthernetServer server(84);//port for server

//attach create variables
int led = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
String readString; 
int ledPins[] = {
  2, 3, 4, 5, 6, 7 ,8, 9}; 
 int pinCount = 8;
int timer = 500; 

void setup() {  //initial setup for arduino board
 
  //turn variables into pin outputs
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);  
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT); 
 for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);      
  }
  // Open serial communications and wait for port to open:
  Serial.begin(9600);//open serial port for debug
  
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("EPIC FAIL");
    // you failed miserably
    for(;;)
      ;
  }
  // print your local IP address...DCHP servers like UWM's assign devices an IP address
  //my first version of the program used a static IP address that I assigned myself
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) { //ip address is 32 bits = 4 bytes
    Serial.print(Ethernet.localIP()[thisByte], DEC); //print ip address in decimal form
    Serial.print("."); //needed to put . in printed serial address...not sure why...
  }
}
void loop(){ //the main program
  // Create a client connection
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        //read HTTP request
        if (readString.length() < 100) {
          

          //store HTTP to string 
          readString += c; 
        } 

        if (c == '\n') {
          Serial.println(readString); 
          //print the html
          client.println("HTTP/1.1 200 OK"); //send new page
          client.println("Content-Type: text/html");
          client.println();
          client.println("<HTML>");
          client.println("<HEAD>");
          client.println("<style type=\"text/css\">body{text-align:center; background:#fff0bc;}a{text-decoration:none;color:black;font-family:'Comic Sans MS', cursive, sans-serif;border:1px solid black;padding:10px; margin-top:10px; line-height: 60px;}h1{padding:0.25em 0.5em;color:black}a:hover{color:red; border:1px solid red;}#main{width:530px; margin-left:auto; margin-right:auto; border:10px solid black; color:red; background: -moz-linear-gradient(-45deg, #f1e767 0%, #feb645 100%);background: -webkit-gradient(linear, left top, right bottom, color-stop(0%,#f1e767), color-stop(100%,#feb645));}</style>");
          client.println("<TITLE>Super Amazing Class Project</TITLE>");
          client.println("</HEAD>");
          client.println("<BODY>");
          client.println("<div id='main'>");
          client.println("<H1>Amazing Web Light Show</H1>");    
          client.println("<a href=\"/?test\">Light Sequence 1</a>"); 
          client.println("<a href=\"/?lights\">Light Sequence 2</a></br>");
          client.println("<a href=\"/?hello\">Light Sequence 3</a>"); 
          client.println("<a href=\"/?whoa\">Light Sequence 4</a></br>");
          client.println("<a href=\"/?arrayforward\">For Statement loops ++ Each Pin</a></br>");
          client.println("<a href=\"/?arrayback\">For Statement loops -- Each Pin</a></br>"); 
          client.println("<a href=\"/?on\">Light On</a>");
          client.println("<a href=\"/?off\">Light Off</a>"); 
          client.println("</div>");
          client.println("</BODY>");
          client.println("</HTML>");
 
          delay(1);
          client.stop();
          // control pins

          if(readString.indexOf("test") >0)
          {
            digitalWrite(led3, HIGH);
            delay(100);
            digitalWrite(led3, LOW);
            delay(100);
             digitalWrite(led4, HIGH);
            delay(100);
            digitalWrite(led4, LOW);
            delay(100);
             digitalWrite(led5, HIGH);
            delay(100);
            digitalWrite(led5, LOW);
            delay(100);
             digitalWrite(led6, HIGH);
            delay(100);
            digitalWrite(led6, LOW);
            delay(100);
             digitalWrite(led7, HIGH);
            delay(100);
            digitalWrite(led7, LOW);
            delay(100);
             digitalWrite(led3, HIGH);
            delay(100);
            digitalWrite(led3, LOW);
            delay(100);
             digitalWrite(led4, HIGH);
            delay(100);
            digitalWrite(led4, LOW);
            delay(100);
             digitalWrite(led5, HIGH);
            delay(100);
            digitalWrite(led5, LOW);
            delay(100);
             digitalWrite(led6, HIGH);
            delay(100);
            digitalWrite(led6, LOW);
            delay(100);
             digitalWrite(led7, HIGH);
            delay(100);
            digitalWrite(led7, LOW);
            delay(100);
          }
          if(readString.indexOf("lights") >0){
            digitalWrite(led2, HIGH);
            delay(40);
            digitalWrite(led2, LOW);
            delay(40);
             digitalWrite(led3, HIGH);
            delay(40);
            digitalWrite(led3, LOW);
            delay(40);
            digitalWrite(led4, HIGH);
            delay(40);
            digitalWrite(led4, LOW);
            delay(40);
            digitalWrite(led2, HIGH);
            delay(40);
            digitalWrite(led2, LOW);
            delay(40);
             digitalWrite(led3, HIGH);
            delay(80);
            digitalWrite(led3, LOW);
            delay(80);
            digitalWrite(led4, HIGH);
            delay(80);
            digitalWrite(led4, LOW);
            delay(80);
            digitalWrite(led2, HIGH);
            delay(80);
            digitalWrite(led2, LOW);
            delay(80);
             digitalWrite(led3, HIGH);
            delay(80);
            digitalWrite(led3, LOW);
            delay(80);
            digitalWrite(led4, HIGH);
            delay(80);
            digitalWrite(led4, LOW);
            delay(80);
            digitalWrite(led2, HIGH);
            delay(100);
            digitalWrite(led2, LOW);
            delay(100);
             digitalWrite(led3, HIGH);
            delay(100);
            digitalWrite(led3, LOW);
            delay(100);
            digitalWrite(led4, HIGH);
            delay(100);
            digitalWrite(led4, LOW);
            delay(100);
            digitalWrite(led2, HIGH);
            delay(120);
            digitalWrite(led2, LOW);
            delay(120);
             digitalWrite(led3, HIGH);
            delay(120);
            digitalWrite(led3, LOW);
            delay(120);
            digitalWrite(led4, HIGH);
            delay(120);
            digitalWrite(led4, LOW);
            delay(120);
            digitalWrite(led2, HIGH);
            delay(140);
            digitalWrite(led2, LOW);
            delay(140);
             digitalWrite(led3, HIGH);
            delay(140);
            digitalWrite(led3, LOW);
            delay(140);
            digitalWrite(led4, HIGH);
            delay(140);
            digitalWrite(led4, LOW);
            delay(140);
            digitalWrite(led2, HIGH);
            delay(140);
            digitalWrite(led2, LOW);
            delay(140);
             digitalWrite(led3, HIGH);
            delay(160);
            digitalWrite(led3, LOW);
            delay(160);
            digitalWrite(led4, HIGH);
            delay(160);
            digitalWrite(led4, LOW);
            delay(160);
            digitalWrite(led2, HIGH);
            delay(160);
            digitalWrite(led2, LOW);
            delay(180);
             digitalWrite(led3, HIGH);
            delay(180);
            digitalWrite(led3, LOW);
            delay(180);
            digitalWrite(led4, HIGH);
            delay(180);
            digitalWrite(led4, LOW);
            delay(200);
            digitalWrite(led2, HIGH);
            delay(200);
            digitalWrite(led2, LOW);
            delay(200);
             digitalWrite(led3, HIGH);
            delay(240);
            digitalWrite(led3, LOW);
            delay(240);
            digitalWrite(led4, HIGH);
            delay(260);
            digitalWrite(led4, LOW);
            delay(260);
          }
          if(readString.indexOf("hello") >0){
             digitalWrite(led6, HIGH);
            delay(50);
            digitalWrite(led6, LOW);
            delay(50);
             digitalWrite(led7, HIGH);
            delay(50);
            digitalWrite(led7, LOW);
            delay(50);
            digitalWrite(led6, HIGH);
            delay(50);
            digitalWrite(led6, LOW);
            delay(50);
             digitalWrite(led7, HIGH);
            delay(50);
            digitalWrite(led7, LOW);
            delay(50);
            digitalWrite(led6, HIGH);
            delay(30);
            digitalWrite(led6, LOW);
            delay(30);
             digitalWrite(led7, HIGH);
            delay(30);
            digitalWrite(led7, LOW);
            delay(30);
            digitalWrite(led6, HIGH);
            delay(30);
            digitalWrite(led6, LOW);
            delay(30);
             digitalWrite(led7, HIGH);
            delay(30);
            digitalWrite(led7, LOW);
            delay(15);
            digitalWrite(led6, HIGH);
            delay(15);
            digitalWrite(led6, LOW);
            delay(15);
             digitalWrite(led7, HIGH);
            delay(15);
            digitalWrite(led7, LOW);
            delay(15);
            digitalWrite(led6, HIGH);
            delay(15);
            digitalWrite(led6, LOW);
            delay(15);
             digitalWrite(led7, HIGH);
            delay(15);
            digitalWrite(led7, LOW);
            delay(15);
            digitalWrite(led6, HIGH);
            delay(30);
            digitalWrite(led6, LOW);
            delay(30);
             digitalWrite(led7, HIGH);
            delay(30);
            digitalWrite(led7, LOW);
            delay(30);
            digitalWrite(led6, HIGH);
            delay(30);
            digitalWrite(led6, LOW);
            delay(30);
             digitalWrite(led7, HIGH);
            delay(60);
            digitalWrite(led7, LOW);
            delay(60);
            digitalWrite(led6, HIGH);
            delay(60);
            digitalWrite(led6, LOW);
            delay(60);
             digitalWrite(led7, HIGH);
            delay(60);
            digitalWrite(led7, LOW);
            delay(80);
            digitalWrite(led6, HIGH);
            delay(100);
            digitalWrite(led6, LOW);
            delay(120);
             digitalWrite(led7, HIGH);
            delay(140);
            digitalWrite(led7, LOW);
            delay(160);
          }
          if(readString.indexOf("whoa") >0){
             digitalWrite(led, HIGH);
            delay(100);
            digitalWrite(led, LOW);
            delay(100);
             digitalWrite(led7, HIGH);
            delay(100);
            digitalWrite(led7, LOW);
            delay(100);
            digitalWrite(led2, HIGH);
            delay(100);
            digitalWrite(led2, LOW);
            delay(100);
             digitalWrite(led6, HIGH);
            delay(100);
            digitalWrite(led6, LOW);
            delay(100);
            digitalWrite(led3, HIGH);
            delay(100);
            digitalWrite(led3, LOW);
            delay(100);
             digitalWrite(led5, HIGH);
            delay(100);
            digitalWrite(led5, LOW);
            delay(100);
            digitalWrite(led, HIGH);
            delay(200);
            digitalWrite(led, LOW);
            delay(200);
             digitalWrite(led7, HIGH);
            delay(200);
            digitalWrite(led7, LOW);
            delay(200);
          }
          
           if(readString.indexOf("arrayforward") >0){
           for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);  
    delay(timer);                  
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);    

  }
           }
           if(readString.indexOf("arrayback") >0){
             // loop from the highest pin to the lowest:
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }  
           }
            if(readString.indexOf("on") >0){
               digitalWrite(led4,HIGH);
            }
            if(readString.indexOf("off") >0){
               digitalWrite(led4, LOW);
            }
                       
     
          //clear string for next read
          readString="";
          

        }
      }
    }
  }
}
    
