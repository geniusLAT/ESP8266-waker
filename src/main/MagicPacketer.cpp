#include <Arduino.h>
#include "MagicPacketer.h"
#include <WiFiUdp.h>

WiFiUDP Udp;
const char* broadcastAddress = "255.255.255.255"; // Широковещательный адрес
const int port = 9; // Порт для WoL

 void MagicPacketer::sendWOLPacket(byte macAddress[6]) 
 {
     byte magicPacket[102]; // Пакет WoL
     // Заполнение пакета
     for (int i = 0; i < 6; i++) {
         magicPacket[i] = 0xFF; // Первые 6 байт - 0xFF
     }
     for (int i = 1; i <= 16; i++) {
         for (int j = 0; j < 6; j++) {
             magicPacket[i * 6 + j] = macAddress[j]; // Повторение MAC-адреса 16 раз
         }
     }

     // Отправка пакета
     Udp.beginPacket(broadcastAddress, port);
     Udp.write(magicPacket, sizeof(magicPacket));
     Udp.endPacket();

     Serial.println("Wake-on-LAN пакет отправлен");
 }