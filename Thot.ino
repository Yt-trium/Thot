// Thot

#include <Keypad.h>

extern Keypad keypad;

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
