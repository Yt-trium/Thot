// Keypad : 16 Key Membrane Switch Keypad 4x4

#include <Keypad.h>

extern byte KeypadRowPins[4];
extern byte KeypadColPins[4];

char keys[4][4] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad keypad = Keypad( makeKeymap(keys), KeypadRowPins, KeypadColPins, 4, 4);
