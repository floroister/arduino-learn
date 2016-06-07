int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  while(millis() < 5000) {
    
    int sensorValue = analogRead(A0);

    if(sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }

    if(sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(13, LOW);
}

void loop() {
  int ligthValue = analogRead(A0);
  int maxPitch = random(1000, 4000);
  int pitch = map(ligthValue, sensorLow, sensorHigh, 50, maxPitch);

  if (pitch >= (maxPitch / 4 * 3)) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  } else if( pitch >= (maxPitch / 2)) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  } else if( pitch >= (maxPitch / 4)) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  } else {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }

  tone(8, pitch, 20);

  delay(10);
}
