void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:



}

void loop() {
  // put your main code here, to run repeatedly:
  int count = 0;
  
  while(count < 10){
    Serial.println(count);
    count++;
  }

}
