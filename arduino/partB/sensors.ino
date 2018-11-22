/*
  ENTIC - UPC 2018
*/

const int pressure_sensor = A0;
const int ph_sensor = A1;
const int temp_sensor = A2;

int outValue = 0;

void setup() {
  Serial.begin(9600);
}

// loop routine runs over and over again forever
void loop() {

}

float depth() {
  int pressure_value = analogRead(pressure_sensor);
  float depth = (pressure_value-682)/-71;
  return (depth);
}

float temperature() {

}
