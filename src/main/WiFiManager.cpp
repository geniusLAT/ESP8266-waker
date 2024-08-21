#include <Arduino.h>
#include "waker.h"
#include <ESP8266WiFi.h>

void WiFiManager::Connect() 
{
	WiFi.begin(waker_ssid, waker_password);

	// �������� ����������� � Wi-Fi
	while (WiFi.status() != WL_CONNECTED) 
	{ 
	    delay(1000);
	    Serial.println("Подключение к  Wi-Fi "+(String)waker_ssid +" ...");
	}
	Serial.println("Подключено к Wi-Fi");
}