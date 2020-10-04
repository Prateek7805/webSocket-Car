Websockets car uses websocket to set up a realtime communication from the client to the server, here I have made use of a esp8266 01 module (As they have a small footprint and low cost)
I've used the WebSocketsServer.h library and general libraries like ESP8266WiFi.h and ESP8266WebServer.h 
The basic operation is: Whne the car is powered on the esp-01 module works in AP mode (can be changed to STA if we want the ESP8266 to connect to any other network)
We connect to the ESP8266's network and go IP 192.168.4.1, on doing so the ESP8266 responds with the Webpage to control the car.
The Webpage has 5 touch/mouse controlled buttons and a range input for controlling the speed of the motors.
On pressing one of the buttons, the websocket sends the event data to the esp8266 and the esp8266 handles that data in a general switch-case manner.
The webpage supports multitouch, hence we could For ex tap 'forward' and 'right' buttons simultaneously and the car will move in a curve following a circular path.
The range input can be used to controll the speed of the motors which has a range from 0 - 1023.
The connections can be further minimized by using an esp8266 - 12E or esp8266 - 12F module and avoiding the 74hct164 shift register.
The real-time nature of websockets provide a low latency and improve the experience.
