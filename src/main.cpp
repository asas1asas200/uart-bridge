#include <Arduino.h>


void setup() {
	// delay(2000);
	Serial.begin(9600);
	Serial1.begin(9600);
	Serial2.begin(9600);
}

void loop() {
	// if (Serial.available() >= 20) {
		// String data;
		while (Serial.available()) {
			// data += (char)Serial.read();
			auto data = Serial.read();
			Serial1.write(data);
			Serial2.write(data);
			delay(10);
		}
		// for (const auto &c : data) {
		// 	Serial1.write(c);
		// 	Serial2.write(c);
		// 	delay(3);
		// }
	// }
	delay(100);
	if (Serial1.available()) {
		while (Serial1.available()) {
			Serial.write(Serial1.read());
			delay(3);
		}
	} else if (Serial2.available()) {
		while (Serial2.available()) {
			Serial.write(Serial2.read());
			delay(3);
		}
	}
	while (Serial1.available()) {
		Serial1.read();
		delay(3);
	}
	while (Serial2.available()) {
		Serial2.read();
		delay(3);
	}
	delay(50);
}
