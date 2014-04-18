#include "SevenSegment.h"

//             A  B  C  D  E  F  G
int pins[] = { 2, 3, 4, 5, 6, 7, 8 };
int dotPin = 9;

SevenSegment sevenSeg(pins, dotPin);

void setup() {
	
}

void loop() {
	for (int i = 0; i < 10; i++) {
		delay(1000);
		sevenSeg.display(i);
	}
}
