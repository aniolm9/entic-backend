#include <Wire.h>

#define SLAVE_ADDRESS 0x04
int number = 0;

// Sensors
const int pressure_sensor = A0;
const int ph_sensor = A2;
const int temp_sensor = A1;

float depth_out, temp_out, ph_out;
int out = 0;

void setup() {
  Serial.begin(9600); // start serial for output
  
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDRESS);

  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Serial.println("Ready!");
}

void loop() {
  delay(20);
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
    Serial.println(number);
    if (number == 1) {
      depth_out = depth();
      //depth_out = 2.54;
      out = depth_out/(4.0/254.0);
    }
    else if (number == 2) {
      ph_out = ph
      //ph_out = 7.76;
      out = ph_out/(14.0/254.0);
    }
    else if (number == 3) {
      temp_out = temperature();
      //temp_out = 14.65;
      out = temp_out/(25.0/254.0);
    }
    Wire.onRequest(sendData);
  }
}

void sendData() {
  Serial.println(out);
  Wire.write(out);
}
