#include <Arduino.h>
#include "WebServer.h"

ESP8266WebServer server(80); // Создаем объект веб-сервера на порту 80

void handleRoot()
{
	String html = "<html><body>";
	html += "<h1>Waker ESP8266!</h1>";

	html += "<p><a href=\"/pc1\">Turn on PC-1</a></p>";
	html += "<p><a href=\"/pc2\">Turn on PC-2</a></p>";
	html += "<p><a href=\"https://github.com/geniusLAT/ESP8266-waker\" git</a></p>";
	html += "</body></html>";

	server.send(200, "text/html", html); // Отправляем HTML-код
}
void handlePC1()
{
	String html = "<html><body>";
	html += "<h1>Signal sent</h1>";
	html += "</body></html>";

	server.send(200, "text/html", html); // Отправляем HTML-код
}
void handlePC2()
{
	String html = "<html><body>";
	html += "<h1>Signal sent</h1>";
	html += "</body></html>";

	server.send(200, "text/html", html); // Отправляем HTML-код	
}

void WebServer::StartServer() 
{
	Serial.print("IP адрес: ");
	Serial.println(WiFi.localIP());

	// Определяем маршруты
	server.on("/", handleRoot); // Обрабатываем корневой путь "/"
	server.on("/pc1", handlePC1); // Обрабатываем корневой путь "/"
	server.on("/pc2", handlePC2); // Обрабатываем корневой путь "/"

	// Запускаем сервер
	server.begin();
	Serial.println("HTTP сервер запущен");
}
void WebServer::LoopServer()
{
	server.handleClient(); // Обрабатываем входящие запросы
}