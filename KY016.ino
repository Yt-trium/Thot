// KY016 : 3 Color RGB LED Module

extern const byte RGB[4][3];

/* setLedColor
 * set the n led to r,g,b color
 * 0 <= n <= 3
 */
void setLedColor(byte n, byte r, byte g, byte b)
{
  if(n > 0 && n < 4)
  {
  analogWrite(RGB[n][0], r);
  analogWrite(RGB[n][1], g);
  analogWrite(RGB[n][2], b);
  }
}
