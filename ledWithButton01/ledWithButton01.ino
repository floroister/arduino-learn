int mode = 0;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
}

void loop() {
  int value = digitalRead(7);
  if (value == HIGH) {

    if (mode ==  1) {
      mode = 0;
    }
    else {
      mode = 1;
    }

    if (mode == 1) {
      digitalWrite(8, HIGH);
    } else {
      digitalWrite(8, LOW);
    }

    delay(500);
    
  }

  
}
