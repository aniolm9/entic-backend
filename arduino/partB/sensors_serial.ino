/*
ENTIC - UPC 2018
*/

const int pressure_sensor = A0;
const int ph_sensor = A2;
const int temp_sensor = A4;

float depth_out, temp_out, ph_out;

void setup() {
  Serial.begin(9600);
}

// loop routine runs over and over again forever
void loop() {
  depth_out = depth();
  ph_out = ph();
  temp_out = temperature();
  delay(20);
  String outstr = String(depth_out) + ";" + String(ph_out) + ";" + String(temp_out);
  Serial.println(outstr);
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
