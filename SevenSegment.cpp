/*
	SevenSegment.h - Arduino Library for SM41056 7 Segment Led Display
	Copyright (c) 2014 Salvatore Gentile

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#include "SevenSegment.h"

//         DIGIT               A    B    C    D    E    F    G
const byte ZERO[SEGMENTS]  = { ON,  ON,  ON,  ON,  ON,  ON,  OFF };
const byte ONE[SEGMENTS]   = { OFF, ON,  ON,  OFF, OFF, OFF, OFF };
const byte TWO[SEGMENTS]   = { ON,  ON, OFF,  ON,  ON,  OFF, ON  };
const byte THREE[SEGMENTS] = { ON,  ON,  ON,  ON,  OFF, OFF, ON  };
const byte FOUR[SEGMENTS]  = { OFF, ON,  ON,  OFF, OFF, ON,  ON  };
const byte FIVE[SEGMENTS]  = { ON, OFF,  ON,  ON,  OFF, ON,  ON  };
const byte SIX[SEGMENTS]   = { ON, OFF,  ON,  ON,  ON,  ON,  ON  };
const byte SEVEN[SEGMENTS] = { ON,  ON,  ON,  OFF, OFF, OFF, OFF };
const byte EIGHT[SEGMENTS] = { ON,  ON,  ON,  ON,  ON,  ON,  ON  };
const byte NINE[SEGMENTS]  = { ON,  ON,  ON,  ON,  OFF, ON,  ON  };
const byte A[SEGMENTS]     = { ON,  ON,  ON,  OFF, ON,  ON,  ON  };
const byte B[SEGMENTS]     = { OFF, OFF, ON,  ON,  ON,  ON,  ON  };
const byte C[SEGMENTS]     = { ON,  OFF, OFF, ON,  ON,  ON,  OFF };
const byte D[SEGMENTS]     = { OFF, ON,  ON,  ON,  ON, OFF,  ON  };
const byte E[SEGMENTS]     = { ON,  OFF, OFF, ON,  ON,  ON,  ON  };
const byte F[SEGMENTS]     = { ON,  OFF, OFF, OFF, ON,  ON,  ON  };
const byte DASH[SEGMENTS]  = { OFF, OFF, OFF, OFF, OFF, OFF, ON  };

SevenSegment::SevenSegment(int pins[], int dotPin)
{
	_pins = pins;
	for (int pin = 0; pin < SEGMENTS; pin++)
	{
		pinMode(_pins[pin], OUTPUT);
	}

	_dotPin = dotPin;
	pinMode(dotPin, OUTPUT);
}

void SevenSegment::display(int digit)
{
	display(digit, false);
}

void SevenSegment::display(int digit, bool dot)
{
	const byte *selectedDigit = select(digit);

	for (int segment = 0; segment < SEGMENTS; segment++)
	{
		digitalWrite(_pins[segment], selectedDigit[segment]);
	}

	if (dot)
	{
		setDot(ON);
	}
	else
	{
		setDot(OFF);
	}
}

const byte* SevenSegment::select(int digit)
{
	switch (digit)
	{
		case (0):
			return ZERO;
			break;

		case (1):
			return ONE;
			break;

		case (2):
			return TWO;
			break;

		case (3):
			return THREE;
			break;

		case (4):
			return FOUR;
			break;

		case (5):
			return FIVE;
			break;

		case (6):
			return SIX;
			break;

		case (7):
			return SEVEN;
			break;

		case (8):
			return EIGHT;
			break;

		case (9):
			return NINE;
			break;

		case (10):
			return A;
			break;

		case (11):
			return B;
			break;

		case (12):
			return C;
			break;

		case (13):
			return D;
			break;

		case (14):
			return E;
			break;

		case (15):
			return F;
			break;

		default:
			return DASH;
	}
}

void SevenSegment::setDot(byte status)
{
	digitalWrite(_dotPin, status);
}
