#include <VirtualWire.h>

const int xPin = 2;
const int yPin = 1;
const int zPin = 0;

int steps = 0;

void setup() {
  // Initializations for RF transmitter
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_set_tx_pin(11);
}

// Helper function to get the length of an array of floats
int arrayLength(float numbers[]) {
  int size_ = sizeof(numbers) / sizeof(*numbers);
  return sizeof(numbers) / sizeof(*numbers);
}

// Helper function to return the sum of elements in a list
float sum(float numbers[]) {
  float sum = 0;
  for (int i = 0; i < 100; i++) {
    sum += numbers[i];
  }
  return float(sum);
}

// Helper function to return the average of elements in a list
float average(float numbers[]) {
  return sum(numbers) / 100;
}

// Function to find average values on each axis
void calibrate(float results[]) {
  Serial.print("Calibrating accelerometer...");
  Serial.print("\n");
  float xSum, ySum, zSum = 0.0;
  float xValues[100], yValues[100], zValues[100] = {0.0};

  for (int i = 0; i < 100; i++) {
    xValues[i] = float(analogRead(xPin));
    yValues[i] = float(analogRead(yPin));
    zValues[i] = float(analogRead(zPin));
  }
  results[0] = average(xValues);
  results[1] = average(yValues);
  results[2] = average(zValues);
}

// Function to transmit a message using RF transmitter
void send(char *msg) {
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx();
}

// Helper function to print out accelerometer data
void prettyPrintData(int x, int y, int z) {
  Serial.print("X: ");
  Serial.print(x);
  Serial.print("\n");
  Serial.print("Y: ");
  Serial.print(y);
  Serial.print("\n");
  Serial.print("Z: ");
  Serial.print(z);
  Serial.print("\n");
}

float distance(float numbers[]) {
  float sum = 0.0;
  for (int i = 0; i < 3; i++) {
    sum += numbers[i];
  }
  return sqrt(sum);
}

int isStep(float x, float y, float z) {

}

void loop() {
  float prevX = float(analogRead(xPin));
  float prevY = float(analogRead(yPin));
  float prevZ = float(analogRead(zPin));

  prettyPrintData(prevX, prevY, prevZ);
  
  float oldAverages[3];
  calibrate(oldAverages);

  prettyPrintData(oldAverages[0], oldAverages[1], oldAverages[2]);

  float xThreshold = oldAverages[0] * 0.05;
  float yThreshold = oldAverages[1] * 0.05;
  float zThreshold = oldAverages[2] * 0.05;

  float x = float(analogRead(xPin));
  float y = float(analogRead(yPin));
  float z = float(analogRead(zPin));

  prettyPrintData(x, y, z);

  if (abs(prevX - x) > xThreshold || abs(prevY - y) > yThreshold || abs(prevZ - z) > zThreshold) {
    steps++;
    Serial.println("Incremented step count to: ");
    Serial.println(steps);
  }

  if (steps >= 3) {
    send("1");
    Serial.print("Sucessfully sent movement indicator!\n");
    steps = 0;
  } else {
    send("0");
    Serial.print("Sucessfully sent no movement indicator!\n");
  }

  delay(1000);
}
