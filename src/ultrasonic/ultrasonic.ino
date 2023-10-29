const int buzzer = 4;
const int led = 2;
const int trigger = 8;
const int echo = 10;
const int note = 1000;
bool sleep = false;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

int distance(){
  digitalWrite(trigger, HIGH);
  // delayMicroseconds(10);
  delay(10);
  digitalWrite(trigger, LOW);
  int duration = pulseIn(echo, HIGH);
  Serial.print("dinstance: ");
  int cm = duration / 58;
  Serial.print(cm);
  Serial.println("cm");

  if(cm < 120 && cm > 60 || cm == 120){
    return 5;
  };
  if(cm < 60 && cm > 30 || cm == 60){
    return 4;
  };
  if(cm < 30 && cm > 20 || cm == 30){
    return 3;
  };
  if(cm < 20 && cm > 10 || cm == 20){
    return 2;
  };
  if(cm < 10 && cm > 1 || cm == 10){
    return 1;
  };
  if(cm > 120){
    return 0;
  }
}

void loop() {
  digitalWrite(led, LOW);

  if(distance() == 0 && sleep){
    sleep = false;
  }

  if(!sleep){

    if(distance() == 5){
      digitalWrite(led, HIGH);
      tone(buzzer, note, 100);
      delay(100);
      digitalWrite(led, LOW);
      delay(1000);
    };

    if(distance() == 4){
      digitalWrite(led, HIGH);
      tone(buzzer, note, 100);
      delay(100);
      digitalWrite(led, LOW);
      delay(500);
    };

    if(distance() == 3){
      digitalWrite(led, HIGH);
      tone(buzzer, note, 100);
      delay(100);
      digitalWrite(led, LOW);
      delay(250);
    };

    if(distance() == 2){
      digitalWrite(led, HIGH);
      tone(buzzer, note, 100);
      delay(100);
      digitalWrite(led, LOW);
      delay(100);
    };

    if(distance() == 1){
      digitalWrite(led, HIGH);
      tone(buzzer, note, 5000);
      delay(5000);
      sleep = true;
    };
  }
}
