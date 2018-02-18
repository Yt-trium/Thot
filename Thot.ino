/*
 * Thot
 * 
 * 4 RGB Leds (with 3 states)
 * Red    (nothing validated)
 * Orange (1/2 validated)
 * Green  (validated)
 * 
 * 1 Keypad
 * Assigned Keys :
 * '*' -> Switch page (you can use up to 255 pages, but we only use 2)
 * '#' -> Validation
 * 
 * 1 MFRC522 13.56Mhz RFID Reader
 * 
 * 1 SSD1306 Display
 */

#include <Keypad.h>
extern Keypad keypad;


extern const byte challengesSize[9][2];
extern const char challenges[9][2][8];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();
  
  if (key != NO_KEY)
  {
    Serial.println(key);
  }
}
