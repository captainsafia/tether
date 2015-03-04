#include <Time.h>

const int xPin = 2;
const int yPin = 1;
const int zPin = 0;

double x, y, z; 

int minVal = ;
int maxVal = ;

int startTime = seconds();

int accumulatedXValues[20];
int accumulatedYValues[20];
int accumulatedZValues[20];
int count = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	int xRead = 	analogRead(xPin);
	int yRead = 	analogRead(yPin);
	int zRead = 	analogRead(zPin);

	accumulatedXValues[count] = xRead;
	accumulatedYValues[count] = yRead;
	accumulatedZValues[count] = zRead;
}

int calculateDelta(int previousValues, int timePeriod) {
	
}