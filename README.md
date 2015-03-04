# tether
## Summary of Device
The Tether design has two main components: one on the ankle, and one on the walker. If both the ankle and the walker component sense movement within one second of each other, this means that the user remembered his walker, and no cue will be given. However, if the ankle component moves, one-half second passes, and the walker component does not move, then this means that the user is standing up but not using his walker. The device will give a cue only if all three of these things happen.

## Summary of Software
The software for Tether is written using the Processing programming langauge and runs on an Arduino Micro. The code retrieves and checks data from the accelerometer on the anklet componenet and transmits a positive signal using the radio transmitter to the walker if it detects that the user has been walking based on an integration of the acceleration data from the accelerometer. The code on the walker component then checks for movement in the walker in a similar fashion and if it detects no movement will send a signal to the speaker to play an audio file to the user instructing them to pick up their walker. 

## Install Instructions
1. Ensure that the anklet component of the design is wired per the following diagram.
2. Ensure that the walker componenet of the design is wired per the following diagram.
3. Download the source code for each componenet by clicking the "Download ZIP" button to the right.
4. Connect the Arduino board on the anklet component to your computer using a standard USB to mini-B cable.
5. Open anklet_code.ino file in your Arduino IDE.
6. Select Arduino Micro under Tools > Board.
7. Select the proper communication port for your machine under Tools > Port.
8. Select File > Upload or press Cmd + U or Ctrl + U on your machine to upload the code to your arduino.
9. Connect the Arduino board on the walker component to your computer using a standard USB to mini-B cable.
10. Open walker_code.ino file in your Arduino IDE.
11. Select Arduino Micro under Tools > Board.
12. Select the proper communication port for your machine under Tools > Port.
13. Select File > Upload or press Cmd + U or Ctrl + U on your machine to upload the code to your arduino.
