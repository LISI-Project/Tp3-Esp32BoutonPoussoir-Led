#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(128, 64, &Wire, -1);

int led = 12;
int bouton = 13;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(bouton, INPUT_PULLUP);

  Wire.begin(21, 22);
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.setTextColor(WHITE);
}

void loop() {
  if (digitalRead(bouton) == LOW) {
    digitalWrite(led, HIGH);

    oled.clearDisplay();
    oled.setTextSize(3);
    oled.setCursor(30, 20);
    oled.println("ON");
    oled.display();
  } else {
    digitalWrite(led, LOW);

    oled.clearDisplay();
    oled.setTextSize(3);
    oled.setCursor(30, 20);
    oled.println("OFF");
    oled.display();
  }

  delay(50);
}