/*

	  Implements the circusofthings.com API in ESP32 boards.

  	Created by Jaume Miralles Isern, April 10, 2019.
*/


#ifndef CircusESP32Lib_h
#define CircusESP32Lib_h

#include "Arduino.h"
#include "WiFi.h"
#include <HTTPClient.h>
#include <WiFiClientSecure.h>


class CircusESP32Lib
{
  public:
		CircusESP32Lib(char *server, char *ssid, char *pass);
		void begin();
		void write(char *key, double value, char *token);
    double read(char *key, char *token);
		void getCertificate();
	private:
		char* parseServerResponse(char *r, char *label, int offset);
    char* waitResponse(int timeout, WiFiClientSecure *client);
		int count(char *text);
		char _charBuf_rootCA[1250];
		char *_server;
		char *_ssid;
    char *_pass;
};

#endif
