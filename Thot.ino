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

#include <Adafruit_SSD1306.h>
extern Adafruit_SSD1306 display;

extern byte challengesStatus[8];
extern const byte challengesSize[8][2];
extern const char challenges[8][2][8];

byte currentPage = 1;

byte currentPassSize = 0;
byte currentPass[8] = {'.','.','.','.','.','.','.','.'};

void setup()
{
  Serial.begin(9600);

  // Init Display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  
  setChallengesStatus();
}

void loop()
{
  byte i;
  char key = keypad.getKey();
  
  if (key != NO_KEY)
  {
    display.clearDisplay();
    display.setCursor(0,0);
    
    if(key == '*')
    {
      currentPage++;
      if(currentPage == 3)  // max + 1
        currentPage = 1;     // min
      // in our case, 1 -> 2 -> 1 -> 2 ...
    }
    else if(key == '#')
    {
      checkChallenges();
      clearInput();
    }
    else
    {
      currentPass[currentPassSize++] = key;
      if(currentPassSize >= 8)
      {
        checkChallenges();
        clearInput();
      }
    }

    setChallengesStatus();
    checkWin();

    for(i=0;i<currentPassSize;i++)
      display.print((char)currentPass[i]);
    display.print("\nPAGE ");
    display.print(currentPage);
    display.print("/2");
    display.display();

    Serial.print("Key : ");
    Serial.println(key);
    Serial.print("Current Page : ");
    Serial.println(currentPage);
    Serial.print("Current Pass : ");
    for(i=0;i<currentPassSize;i++)
      Serial.print((char)currentPass[i]);
    Serial.println("\n");
  }
}

void clearInput()
{
  byte i;
  
  for(i=0;i<8;i++)
    currentPass[i] = '.';
  currentPassSize = 0;
}

void checkChallenges()
{
  byte i;
  for(i=0;i<8;i++)
  {
    if(currentPassSize == challengesSize[i][0])
      checkChallenge(i,0);
    if(challengesStatus[i] == 1 && currentPassSize == challengesSize[i][1])
      checkChallenge(i,1);
  }
}

void checkChallenge(byte cn, byte cl)
{
  byte i;
  bool check = true;
  for(i=0;i<challengesSize[cn][cl];i++)
  {
    if(challenges[cn][cl][i] != currentPass[i])
      check = false;
  }
  if(check == true)
  {
    if(cl == 0)
      challengesStatus[cn] = 1;
    if(cl == 1)
      challengesStatus[cn] = 2;
  }
}

void setChallengesStatus()
{
  byte i;
  for(i=0;i<4;i++)
  {
    setLedState(i,challengesStatus[i+(currentPage-1)*4]);
  }
}

void checkWin()
{
  byte i;
  for(i=0;i<8;i++)
  {
    if(challengesStatus[i] != 2)
      return;
  }
  // win loop
  while(true)
  {
    setLedColor(0,random(0, 200),random(0, 200),random(0, 200));
    setLedColor(1,random(0, 200),random(0, 200),random(0, 200));
    setLedColor(2,random(0, 200),random(0, 200),random(0, 200));
    setLedColor(3,random(0, 200),random(0, 200),random(0, 200));
    delay(100);
  }
}

