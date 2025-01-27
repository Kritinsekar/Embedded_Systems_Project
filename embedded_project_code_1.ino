import processing.serial.*;
Serial myPort;  // The serial port
int lf = 10;    // Linefeed in ASCII
String myString = null;
float x,y,angle;
float num;
float num2;
int i = 0;

void setup() {
  // List all the available serial ports
  printArray(Serial.list());
  // Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[0], 9600);
  
  size(820, 820);
  noSmooth();
  background(0);
  translate(410, 410);
  stroke(255);
  strokeWeight(3);  // Default
}

void draw() {
  
  while (myPort.available() > 0) {
    myString = myPort.readStringUntil(10);
    if (myString != null) {
    String[] q = splitTokens(myString, ",");   
    
    
    num=float(q[0]);  // Converts and prints float
    num2 = float(q[1]);  // Converts and prints float
    
    //Pass from polars to cartesians adna dd 410 to be in the middle of the 820 by 820 screen. 
    angle = num * 0.0174533;
    x = (sin(angle)*num2 + 410);
    y = (cos(angle)*num2 + 410);
   
    }
    if(num == 0 )
    {
      background(0);    
      translate(410, 410);
    }
    point(x, y);
    
  }
  myPort.clear();
}