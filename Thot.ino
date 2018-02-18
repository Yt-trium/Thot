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

extern byte challengesStatus[8];
extern const byte challengesSize[8][2];
extern const char challenges[8][2][8];

byte currentPage = 1;

byte currentPassSize = 0;
byte currentPass[8] = {'.','.','.','.','.','.','.','.'};

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();
  
  if (key != NO_KEY)
  {
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
    }

    setChallengesStatus();
  }
}

void clearInput()
{
  byte currentPassSize = 0;
  byte i;
  
  for(i=0;i<8;i++)
    currentPass[i] = '.';
}

void checkChallenges()
{
  byte i;
  for(i=0;i<8;i++)
  {
    if(currentPassSize == challengesSize[i][0])
      checkChallenge(i,0);
    if(currentPassSize == challengesSize[i][1])
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

