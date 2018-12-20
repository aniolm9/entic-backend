#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;
//int state = 0;

// Sensors
const int pressure_sensor = A0;
const int ph_sensor = A2;
const int temp_sensor = A4;

float depth_out, temp_out, ph_out;
int d, p, t;

void setup() {
  //pinMode(13, OUTPUT);
  Serial.begin(9600); // start serial for output
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  //Wire.onRequest(sendData);

  Serial.println("Ready!");
}

void loop() {
  delay(100);
}

float depth() {
  float pressure_value = analogRead(pressure_sensor);
  float depth = (pressure_value-671)/-71;
  return (depth);
}

float temperature() {
  int sensorValue = 0;
  unsigned long int avgValue;
  float b;
  int buf[10], temp;

  for(int i = 0;i < 10;i++) {
    buf[i] = analogRead(temp_sensor);
    delay(10);
  }

  for(int i = 0;i < 9;i++) {
    for(int j=i+1;j<10;j++) {
      if(buf[i]>buf[j]) {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }

  avgValue = 0;
  for(int i = 2;i < 8;i++) avgValue += buf[i];
  float TVol=(float)avgValue*500.0/1024/6;

  return (TVol);
}

float ph() {
  int sensorValue=0;
  unsigned long int avgValue;
  float b;
  int buf[10],temp;

  for(int i=0;i<10;i++) {
    buf[i]=analogRead(ph_sensor);
    delay(10);
  }

  for(int i=0;i<9;i++) {
    for(int j=i+1;j<10;j++) {
      if(buf[i]>buf[j]) {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }

  avgValue=0;
  for(int i=2;i<8;i++) avgValue+=buf[i];
  float pHVol=(float)avgValue*5.0/1024/6;
  float phValue = -5.70 * pHVol + 21.34;

  return (phValue);
}

void receiveData(int byteCount) {
  while (Wire.available()) {
    number = Wire.read();
    if (number == 1) {
      depth_out = depth();
      d = depth_out/(4/254);
      Serial.println("D: ");
      Serial.println(d);
      sendData(d);
    }
    else if (number == 2) {
      ph_out = ph();
      p = ph_out/(14/254);
      Serial.println("P: ");
      Serial.println(p);
      sendData(p);
    }
    else if (number == 3) {
      temp_out = temperature();
      t = temp_out/(25/254);
      Serial.println("T: ");
      Serial.println(t);
      sendData(t);
    }
  }
}

void sendData(int value) {
  Wire.write(value);
}
