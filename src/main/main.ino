#include "waker.h"

Waker waker;

void setup(){
  waker.start();
}

void loop(){
  waker.loop();
}


// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>
// #include <WiFiUdp.h>
// #include "test.h"
// const char* ssid = "PThome";          // Замените на имя вашей сети
// const char* password = "snail5566";  // Замените на пароль вашей сети

// // MAC-адрес ПК, который вы хотите 
// byte macAddress[6] = { 0x04, 0x7C, 0x16, 0xE8, 0x26, 0xDC }; // Замените на MAC-адрес вашего ПК


// // Параметры для UDP
// WiFiUDP Udp;
// const char* broadcastAddress = "255.255.255.255"; // Широковещательный адрес
// const int port = 9; // Порт для WoL

// ESP8266WebServer server(80); // Создаем объект веб-сервера на порту 80

// void setup() {
//     Serial.begin(9600);
//     WiFi.begin(ssid, password);

//     // Ожидание подключения к Wi-Fi
//     while (WiFi.status() != WL_CONNECTED) {
//         delay(1000);
//         Serial.println("Подключение к Wi-Fi "+(String)ssid+" ...");
//     }
//     Serial.println("Подключено к Wi-Fi");
    
//     // Отправка пакета WoL
//     //sendWOLPacket();
//      // Определяем маршруты
//     server.on("/", handleRoot); // Обрабатываем корневой путь "/"
    
//     // Запускаем сервер
//     server.begin();
//     Serial.println("HTTP сервер запущен");
//     test();
// }

// void loop() {
//     server.handleClient(); 
//     // Здесь можно добавить дополнительный код
// }

// void sendWOLPacket() {
//     byte magicPacket[102]; // Пакет WoL
//     // Заполнение пакета
//     for (int i = 0; i < 6; i++) {
//         magicPacket[i] = 0xFF; // Первые 6 байт - 0xFF
//     }
//     for (int i = 1; i <= 16; i++) {
//         for (int j = 0; j < 6; j++) {
//             magicPacket[i * 6 + j] = macAddress[j]; // Повторение MAC-адреса 16 раз
//         }
//     }

//     // Отправка пакета
//     Udp.beginPacket(broadcastAddress, port);
//     Udp.write(magicPacket, sizeof(magicPacket));
//     Udp.endPacket();



//     Serial.println("Wake-on-LAN пакет отправлен");
// }

// void handleRoot() {
//   String html = "<html><body>";
//   html += "<h1>Hello</h1>";
//   html += "<p>hellannie is the best seal.</p>";
//   html += "<p>I love you so much.</p>";
//   html += "</body></html>";
  
//   server.send(200, "text/html", html); // Отправляем HTML-код
//   }