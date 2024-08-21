#include <Arduino.h>
#include "WebServer.h"
#include "MagicPacketer.h"
#include "config.h"

ESP8266WebServer server(80); // Создаем объект веб-сервера на порту 80
MagicPacketer magicPacketer;

WOLmac


void handleRoot()
{
	String html = "<html><body>";
	html += "<h1>Waker ESP8266!</h1>";

	int arrayLength = sizeof(macAddresses) / sizeof(macAddresses[0]);
	for (size_t i = 0; i < arrayLength; i++)
	{
		html += "<p><a href=\"/pc?n=" + String(i) + "\">Turn on PC-"+ String(i) +"</a></p>";
	}
	html += "<p><a href=\"https://github.com/geniusLAT/ESP8266-waker\" git</a></p>";
	html += "</body></html>";

	server.send(200, "text/html", html); // Отправляем HTML-код
}
void handlePC()
{
	if (!server.hasArg("n")) 
	{
		server.send(404, "text/html", "Wrong PC number");
		return;
	}

	int	counter = server.arg("n").toInt();
	int arrayLength = sizeof(macAddresses) / sizeof(macAddresses[0]);

	if (counter >= arrayLength) 
	{
		server.send(400, "text/html", "PC number too big");
		return;
	}

	if (counter <0)
	{
		server.send(400, "text/html", "PC number is negative");
		return;
	}

	String html = "<html><body>";
	html += "<h1>Signal sent</h1>";
	html += "</body></html>";

	magicPacketer.sendWOLPacket(macAddresses[counter]);

	server.send(200, "text/html", html); // Отправляем HTML-код
}

void WebServer::StartServer() 
{
	Serial.print("IP адрес: ");
	Serial.println(WiFi.localIP());

	// Определяем маршруты
	server.on("/", handleRoot); // Обрабатываем корневой путь "/"
	server.on("/pc", handlePC); // Обрабатываем корневой путь "/"

	// Запускаем сервер
	server.begin();
	Serial.println("HTTP сервер запущен");
}
void WebServer::LoopServer()
{
	server.handleClient(); // Обрабатываем входящие запросы
}