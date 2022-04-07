#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int trig = 5;
const int echo = 18;

#define SOUND_SPEED 0.034

long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
}

unsigned long startMillis;
unsigned long currentMillis;
unsigned long elapsedMillis;

bool startState = LOW;

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  display.setCursor(0, 10);
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  delay(1000);

  distance = duration *  SOUND_SPEED/2;

  if (distance <= 5){
    startMillis = millis();
    startState != startState;
    Serial.println("Car has passed");
    }
    
  if (startState){
    currentMillis = millis();
    elapsedMillis = (currentMillis - startMillis);

    Serial.print("elapsedMillis: ");
    Serial.print(elapsedMillis);
    Serial.println("");

    }
  delay(500);
}
