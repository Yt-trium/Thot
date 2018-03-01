// KY016 : 3 Color RGB LED Module

extern const byte RGB[4][3];

/* setLedColor
 * set the n led to r,g,b color
 * 0 <= n <= 3
 */
void setLedColor(byte n, byte r, byte g, byte b)
{
  if(n >= 0 && n < 4)
  {
  analogWrite(RGB[n][0], r);
  analogWrite(RGB[n][1], g);
  analogWrite(RGB[n][2], b);
  }
}

/* setLedState
 * set the n led to the s state
 * 0 <= n <= 3
 * 0 <= s <= 2
 */
void setLedState(byte n, byte s)
{
  if(s==0)
    setLedColor(n,100,0,0);
  if(s==1)
    setLedColor(n,50,10,0);
  if(s==2)
    setLedColor(n,0,100,0);
  
}
