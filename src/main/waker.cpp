#include <Arduino.h>
#include "waker.h"

WiFiManager wifiManager;
WebServer webServer;

void Waker::start() {
	Serial.begin(9600);
	Serial.println("waker start");
	wifiManager.Connect();
	webServer.StartServer();
}


void Waker::loop() {
	webServer.LoopServer();
}