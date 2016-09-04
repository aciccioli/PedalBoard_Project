/*
DataPin		-> 14		13
ClockPin	-> 12		9
LatchPin	-> 11		10
*/

int dataPIN = 13;
int clockPIN = 9;
int latchPIN = 10;


int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int index=0;
int aState[][4] = { {0,0,0,0}, {0,0,0,1},{0,0,1,1},{0,1,1,1},{1,1,1,1}};
int aNumbers[10] = { B11111100,B01100000,B11011010,B11110010,B01100110,B10110110,B00111110,B11100000,B11111110,B11100110 };

int currentProgram = 0;

bool waitForDebounce = false;


void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(latchPIN, OUTPUT);
  pinMode(dataPIN, OUTPUT);
  pinMode(clockPIN, OUTPUT);

  pinMode(2, INPUT);	// Boton Program Down
  pinMode(3, INPUT);	// Boton Program UP
  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  //Serial.println(index);
  index=map(sensorValue, 0,700,0,4);
  if (index > 0) {
	  digitalWrite(4, aState[index][0]);
	  digitalWrite(5, aState[index][1]);
	  digitalWrite(6, aState[index][2]);
	  digitalWrite(7, aState[index][3]);
  }

  if (!digitalRead(2) & !waitForDebounce)
  {
	  currentProgram++;
	  waitForDebounce == true;
  }
  if (digitalRead(2)) waitForDebounce == false;

  Serial.println(currentProgram);
  
}
