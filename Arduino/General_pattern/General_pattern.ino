#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

Adafruit_NeoPixel pixels(88, 6, NEO_GRB + NEO_KHZ800); //(NUMPIXELS, PIN).

#define DELAYVAL 50 // Time (in milliseconds) to pause between pixels

//Lists for rows:
int pixel[] = {0,2,4,6,8,10,11,13,15,17,19,21,22,24,26,28,30,32,33,35,37,39,41,43,44,46,48,50,52,54,55,57,59,61,63,65,66,68,70,72,74,76,77,79,81,83,85,87};


void randomize_pixels(){
  int pixel_list[] = {0,2,4,6,8,10,11,13,15,17,19,21,22,24,26,28,30,32,33,35,37,39,41,43,44,46,48,50,52,54,55,57,59,61,63,65,66,68,70,72,74,76,77,79,81,83,85,87};
  const int pixelCount = sizeof pixel_list / sizeof pixel_list[0];
  for (int i=0; i < pixelCount; i++) {
     int n = random(0, pixelCount);  // Integer from 0 to questionCount-1
     int temp = pixel_list[n];
     pixel_list[n] =  pixel_list[i];
     pixel_list[i] = temp;
  }
}

//int rand_pixel[48] = {0};
//
//for (int i = 1; i < sizeof(pixel_list)/sizeof(pixel_list[0]); i++) {
//  int n = random(0,sizeof(pixel_list);
//  rand_pixel[i] = pixel_list[n];
//  
//}

int row[][6] = {{0, 2, 4, 6, 8, 10}, 
                {11, 13, 15, 17, 19, 21}, 
                {22, 24, 26, 28, 30, 32}, 
                {33, 35, 37, 39, 41, 43}, 
                {44, 46, 48, 50, 52, 54}, 
                {55, 57, 59, 61, 63, 65}, 
                {66, 68, 70, 72, 74, 76}, 
                {77, 79, 81, 83, 85, 87}};

//List for circles (starting from the outside).
int circle[][8] = {{pixel[5], pixel[6], pixel[17], pixel[18], pixel[29], pixel[30], pixel[41], pixel[42]}, 
                   {pixel[4], pixel[7], pixel[16], pixel[19], pixel[28], pixel[31], pixel[40], pixel[43]}, 
                   {pixel[3], pixel[8], pixel[15], pixel[20], pixel[27], pixel[32], pixel[39], pixel[44]},
                   {pixel[2], pixel[9], pixel[14], pixel[21], pixel[26], pixel[33], pixel[38], pixel[45]}, 
                   {pixel[1], pixel[10], pixel[13], pixel[22], pixel[25], pixel[34], pixel[37], pixel[46]},
                   {pixel[0], pixel[11], pixel[12], pixel[23], pixel[24], pixel[35], pixel[36], pixel[47]}};                 

//List of colours.
uint32_t none = pixels.Color(0,0,0);

uint32_t red = pixels.Color(255,0,0);
uint32_t green = pixels.Color(0,255,0);
uint32_t blue = pixels.Color(0,0,255);
uint32_t pink = pixels.Color(255,0,144);
uint32_t white = pixels.Color(255,255,255);

//Variable for single leds.
int led;

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
  Serial.println("test");
}

void loop() {
  
  //pixels.clear(); // Set all pixel colors to 'off'
  //pixels.show();
  //lightSpiral(blue);
  //lightSpiral(none);
  lightCircle(green);
  lightCircle(none);
  //flashAll(green);
  //flashAll(none);
  //int rand_led = pixel[random(0,48)];
  //chooseLed(rand_led,green);
  //chooseLed(rand_led,none);
}

void flashAll(uint32_t color){
  for (int i=0; i < sizeof(pixel)/sizeof(pixel[0]); i++){
    chooseLed(pixel[i],color);
    delay(DELAYVAL);
    }
  }


  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
  void chooseLed(int index, uint32_t color){ 
    //Chooses an led by index and changes variable "led" to that spesific led-index.
    //Turns light on.
    led = index;
    pixels.setPixelColor(led, color);
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }

  void colorAll(uint32_t color){ //lights all by turn.
    for(int i=0; i<88; i= i+2) { // For each pixel...
       // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
       // Here we're using a moderately bright green color:
       pixels.setPixelColor(i, color);
  
       pixels.show();   // Send the updated pixel colors to the hardware.

       delay(DELAYVAL); // Pause before next pass through loop
    }
  }

  void lightSpiral(uint32_t color){
    for (int i = 0; i < sizeof(row)/sizeof(row[0]); i = i+1){
      for (int j = 0; j < sizeof(row[i])/sizeof(row[i][0]); j = j+1){
         pixels.setPixelColor(row[i][j], color);
         //delay(DELAYVAL); // Pause before next pass through loop
         //pixels.show();
         Serial.print(sizeof(row[i])/sizeof(row[i][0]));
         Serial.println(" " + (String)i + " " + (String)j);
         pixels.show();
      }
         // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
    }
  }

  void lightCircle(uint32_t color){
    for (int i = 0; i < sizeof(circle)/sizeof(circle[0]); i ++){
      for (int j = 0; j < sizeof(circle[i])/sizeof(circle[i][0]); j ++){
          
         pixels.setPixelColor(circle[i][j], color);
         //delay(DELAYVAL); // Pause before next pass through loop
         //pixels.show();
         Serial.print(sizeof(circle[i])/sizeof(circle[i][0]));
         Serial.println(" " + (String)i + " " + (String)j);
      }
      pixels.setBrightness(50);
      pixels.show();   // Send the updated pixel colors to the hardware.
      delay(DELAYVAL); // Pause before next pass through loop
    }
  }


  
