//Скопируй данный файл и переименуй его копию в config.h

//И разкоментируй вот эту строчку в копии
// #define config_found true

 //Дожили, geniusLAT пишет комментарии на русском

namespace config_example
{

// Настройки Wi-Fi
const char* ssid = "1";          // Замените на имя вашей сети
const char* password = "2";  // Замените на пароль вашей сети



// MAC-адрес ПК, который вы хотите 
byte macAddress[6] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06 }; // Замените на MAC-адрес вашего ПК
}