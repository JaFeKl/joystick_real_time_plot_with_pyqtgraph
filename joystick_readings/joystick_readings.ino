/*
  Simple Joystick analog reading

  This simple arduino code reads the analog x and y values of a Joystick modules
  and print them using the serial port

  List of components:
  * Arduino board + serial cabel
  * Joystick module (e.g. KY-023)
  * 5 x Jumper Wires M/F

  Last modified 06/10/18
  By Jan-Felix Klein

  For the full project description, please refer to:
  https://github.com/JaFeKl/Joystick-analog-readings-real-time-plot-with-pyqtgraph/blob/master/README.md

*/

const int switchPin = 11;         //SW Pin is connected to pin 11
const int yAxisPin = A1;          //VRy pin is connected to analog pin A1
const int xAxisPin = A0;          //VRx pin is connected to analog pin A0


void setup() {
  Serial.begin(115200);             //Turn on the serial port with desired baud rate
  pinMode(switchPin, INPUT);        //Set the switchPin to be an input
  pinMode(xAxisPin, INPUT);         //Set the xAxisPin to be an input
  pinMode(yAxisPin, INPUT);         //Set the yAxisPin to be an input
  digitalWrite(switchPin, HIGH);    //write HIGH to switchPin
}


void loop() {
  // For the purpose of this project, we only need to read the x and y value from the joystick
  Serial.print(analogRead(xAxisPin));
  Serial.print(",");
  Serial.println(analogRead(yAxisPin));

  delay(5); //5 ms delay --> reading with 200Hz
}
