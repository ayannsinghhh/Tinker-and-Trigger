//FanController.ino
//Switches a Motor on and off depending on the room temperature
const int sensorPin=A0; //  declare analog input pin A0 as sensorPin
const int motorPin = 8; //  declare digital I/O pin 8 as motorpin
float temp;

void setup() {
  pinMode(motorPin, OUTPUT);  //configure motorPin as output
  Serial.begin(9660);
}

void loop() {
  int sensorValue = analogRead(sensorPin);  //read sensor value at sensorPin (0-1023)
  float voltage = sensorValue * 5.0 /1023;  //convert sensor value to a voltage
  Serial.println("Voltage : ");
  Serial.println(voltage);
  Serial.println("Temperature : ");
  Serial.println(temp);
  delay(2000);                         // make the display delay
  temp = (voltage - 0.5) * 100;       //convert voltage to temperature

  if(temp > 22)
    digitalWrite(motorPin,HIGH);      //set motorPin High
  else
    digitalWrite(motorPin,LOW);      //otherwise set motorPin Low
}