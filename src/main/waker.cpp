#include <Arduino.h>
#include "waker.h"

WiFiManager wifiManager;

void Waker::start() {
	Serial.begin(9600);
	Serial.println("waker start");
	wifiManager.Connect();
}


void Waker::loop() {
	//Serial.println("waker loop");
}