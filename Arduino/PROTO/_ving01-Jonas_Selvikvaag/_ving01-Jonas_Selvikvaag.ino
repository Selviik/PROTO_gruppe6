int light01_red = 10;
int light01_yellow = 9;
int light01_green = 8;

int light02_red = 3;
int light02_green = 2;

int btn = 13;

void setup(){
    Serial.begin(9600);
    
    pinMode(light01_red, OUTPUT);
    pinMode(light01_yellow, OUTPUT);
    pinMode(light01_green, OUTPUT);

    pinMode(light02_red, OUTPUT);
    pinMode(light02_green, OUTPUT);

    pinMode(btn, INPUT);
}

void loop(){
//    testLights();
    if (digitalRead(btn)){
        delay(100); // software debounce
        if (digitalRead(btn) == HIGH && !digitalRead(light01_red)) {
          digitalWrite(light01_red, HIGH);
          digitalWrite(light01_yellow, 1);
          digitalWrite(light01_green, 1);
          digitalWrite(light02_red, 1);
          digitalWrite(light02_green, 1);
        }
        else if (digitalRead(btn) == HIGH && digitalRead(light01_red)) {
          digitalWrite(light01_red, 0);
          digitalWrite(light01_yellow, 0);
          digitalWrite(light01_green, 0);
          digitalWrite(light02_red, 0);
          digitalWrite(light02_green, 0);
        }
    }
}

void testLights(){
    digitalWrite(light01_red, 1);
    delay(1000);
    digitalWrite(light01_red, 0);
    digitalWrite(light01_yellow, 1);
    delay(1000);
    digitalWrite(light01_yellow, 0);
    digitalWrite(light01_green, 1);
    delay(1000);
    digitalWrite(light01_green, 0);
    delay(1000);
    digitalWrite(light02_red, 1);
    delay(1000);
    digitalWrite(light02_red, 0);
    digitalWrite(light02_green, 1);
    delay(1000);
    digitalWrite(light02_green, 0);
    delay(4000);
}
