#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

//TODO перенести в конфиг //Дожили, geniusLAT пишет комментарии на русском
// Настройки Wi-Fi
const char* ssid = "1";          // Замените на имя вашей сети
const char* password = "2";  // Замените на пароль вашей сети

// MAC-адрес ПК, который вы хотите 
byte macAddress[6] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 }; // Замените на MAC-адрес вашего ПК

// Параметры для UDP
WiFiUDP Udp;
const char* broadcastAddress = "255.255.255.255"; // Широковещательный адрес
const int port = 9; // Порт для WoL

void setup() {
    Serial.begin(9600);
    WiFi.begin(ssid, password);

    // Ожидание подключения к Wi-Fi
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Подключение к Wi-Fi...");
    }
    Serial.println("Подключено к Wi-Fi");
    
    // Отправка пакета WoL
    sendWOLPacket();
}

void loop() {
    // Здесь можно добавить дополнительный код
}

void sendWOLPacket() {
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
