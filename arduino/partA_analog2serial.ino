/*
  ENTIC - UPC 2018
*/

int outValue = 0;

void setup() {
  Serial.begin(9600);
  while (Serial.available() <= 0 || Serial.read() != 'S') {
    Serial.println("Send 'S' to start");
    delay(200); }
  Serial.println("Starting measurement");
}
// loop routine runs over and over again forever
void loop() {
  if (Serial.read() == 'E') {
    Serial.end();
    Serial.begin(9600);
    while (Serial.available() <= 0 || Serial.read() != 'S') {
      Serial.println("Send 'S' to start");
      delay(200);
    }
  }
  outValue = analogRead(A0);
  Serial.println(outValue);
  delay(200);
}
