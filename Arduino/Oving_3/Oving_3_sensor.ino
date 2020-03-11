int trigger_pin = 2;

int echo_pin = 3;

int time;

int distance; 

void setup() {
        Serial.begin (9600);
  // put your setup code here, to run once:
   pinMode (trigger_pin, OUTPUT); 
   pinMode (echo_pin, INPUT);

}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite (trigger_pin, HIGH);
    
    delayMicroseconds (10);
    
    digitalWrite (trigger_pin, LOW);
    
    time = pulseIn (echo_pin, HIGH);
    
    distance = (time * 0.034) / 2;
  
    if (distance <= 10) {
    
      Serial.write(1); 
      //Serial.println("ON");
      delay (100);
    }

    else {
      Serial.write(0);
      //Serial.println("OFF");
      delay(100);
    }
  
  }
