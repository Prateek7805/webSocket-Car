#include <ESP8266WiFi.h>
#include<WebSocketsServer.h>
#include<ESP8266WebServer.h>
#include "index.h"
#include "script.h"
#include "styles.h"

uint8_t DATA = 0;
uint8_t CLK = 2;
uint8_t ENA = 1;
uint8_t ENB = 3; 
uint16_t SPEED =0; 
byte BACKWARD = 0B00111001;
byte RIGHT = 0B00110101;
byte LEFT = 0B00111010;
byte FORWARD = 0B00110110;
byte STOP = 0B00000000;
byte inputFlag[4]={0,0,0,0};
byte output = 0;
const char* ssid = "socketCar";
const char* password = "12345678";
IPAddress apIP(192, 168, 4,1);  
IPAddress gateway(192, 168,12, 7);
IPAddress subnet(255, 255, 255, 0); 

ESP8266WebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);

void handleOtherFiles(){
  if(checkInFS(server.uri())){
    return;
  }
  server.send(404,"text.plain", "please restart the car");
  
}


bool checkInFS(String path){
  String dataType = "text/plain";
  const char* data;
  if(path.endsWith("/") || path.endsWith(".html")){
    dataType = "text/html";
    data = html;
  }else if(path.endsWith(".css")){
    dataType = "text/css";
    data = css;
  }else if(path.endsWith(".js")){
    dataType = "application/js";
    data = js;
  }else{
    return false;
  }
  server.send_P(200, dataType.c_str(), data);
  return true;
}


void setup() {
pinMode(DATA, OUTPUT);
pinMode(CLK, OUTPUT);
shiftOut(DATA, CLK, MSBFIRST, 0);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
analogWrite(ENA, 0);
analogWrite(ENB, 0);

WiFi.config(apIP, gateway, subnet);
WiFi.mode(WIFI_AP);
WiFi.disconnect();
delay(100);
      //changing softAP config and starting the Start AP
WiFi.softAPConfig(apIP, gateway, subnet);
WiFi.softAP(ssid, password);
server.onNotFound(handleOtherFiles);

server.begin();
webSocket.begin();
webSocket.onEvent(socketHandle);
}

void loop() {
  webSocket.loop();
  server.handleClient();
  wdt_reset();
}

void socketHandle(uint8_t num, WStype_t type, uint8_t * payload, size_t length){
  if(type == WStype_TEXT){
    //do all stuff here
    switch(payload[0]){
      case 's':
                inputFlag[0] = 0;
                inputFlag[1] = 0;
                inputFlag[2] = 0;
                inputFlag[3] = 0;
                
                carMotion();
                break;
      case 'f':
                inputFlag[0] = (byte)(payload[1]-48);
                carMotion();
                
                break;
      case 'b': 
                inputFlag[1] = (byte)(payload[1]-48);
                carMotion();
                break;
      case 'r': 
                inputFlag[2] = (byte)(payload[1]-48);
                carMotion();
                break;
      case 'l': 
                inputFlag[3] = (byte)(payload[1]-48);
                carMotion();
                break;
      case 'v':
                SPEED = (uint16_t) strtol((const char *)&payload[1], NULL, 10);
             
  }
}
}
void carMotion(){
  output = 0;
  output |= (inputFlag[0]) ?  FORWARD : 0;
  output |= (inputFlag[1]) ?  BACKWARD : 0;
  output |= (inputFlag[2]) ?  RIGHT : 0;
  output |= (inputFlag[3]) ?  LEFT : 0;
  shiftOut(DATA, CLK, MSBFIRST, output);
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);
  
}
