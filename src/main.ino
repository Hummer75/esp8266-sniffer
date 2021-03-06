#include <main.h>

const int led = 16;

void setup() {
  USE_SERIAL.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  delay(100);
  digitalWrite(led, 1);

  USE_SERIAL.println("");
  USE_SERIAL.println("");
  USE_SERIAL.println(" ___  _  _  ____  ____  ____  ____  ____ ");
  USE_SERIAL.println("/ __)( \\( )(_  _)( ___)( ___)( ___)(  _ \\");
  USE_SERIAL.println("\\__ \\ )  (  _)(_  )__)  )__)  )__)  )   /");
  USE_SERIAL.println("(___/(_)\\_)(____)(__)  (__)  (____)(_)\\_)");
  USE_SERIAL.println("");
  USE_SERIAL.printf(" Version: %s:%d\n", SNIFFER_VERSION_NAME, SNIFFER_VERSION_CODE);
  USE_SERIAL.println(" ©2017 Gitai.me");
  USE_SERIAL.println("");
  USE_SERIAL.println("");

  USE_SERIAL.println("AIR CONFIG START\n");
  airconfig_start();
  USE_SERIAL.print("AIR CONFIG END\n");
}

void loop() {
  delay(10);
  ota_loop();
  httpserver_loop();
  autoupdate_loop();
}