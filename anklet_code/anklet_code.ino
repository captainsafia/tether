const int xPin = 2;
const int yPin = 1;
const int zPin = 0;

double x, y, z; 

int minVal = 265;
int maxVal = 500;

int accumulatedXValues[20];
int accumulatedYValues[20];
int accumulatedZValues[20];
int count = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
  // This portion of code reads data from the 
  int xRead = analogRead(xPin);
  int yRead = analogRead(yPin);
  int zRead = analogRead(zPin);
  int xAng  = map(xRead, minVal, maxVal, -90, 90);
  int yAng  = map(yRead, minVal, maxVal, -90, 90);
  int zAng  = map(zRead, minVal, maxVal, -90, 90);
  
  // This portion of the code is for testing purposes and 
  // should be commented out in the production version
  Serial.print("X: ");
  Serial.print(xAng);
  Serial.print("Y: ");
  Serial.print(yAng);
  Serial.print("Z: ");
  Serial.print(zAng);
  delay(100);

  accumulatedXValues[count] = xAng;
  accumulatedYValues[count] = yAng;
  accumulatedZValues[count] = zAng;
}

int calculateDelta(int previousValues, int timePeriod) {
	
}
