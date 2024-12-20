int enablePin = 8;
void setup() {
  Serial.begin(9600);                   // initialize serial at baudrate 9600:
  pinMode(enablePin, OUTPUT);
  delay(10);
  digitalWrite(enablePin, LOW);        //  (Pin 8 always LOW to receive value from Master)
}

void loop() {
  while (Serial.available())                   //While have data at Serial port this loop executes
  {
    int pwmval = Serial.parseInt();            //Receive INTEGER value from Master throught RS-485
    int convert = map(pwmval, 0, 1023, 0, 255); //Map those value from (0-1023) to (0-255)
    Serial.println(convert);          

  }
}
