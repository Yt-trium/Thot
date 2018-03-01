// SSD1306 : I2C OLED Display Module 128x64

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

extern byte SSD1306_ADDR;

Adafruit_SSD1306 display(4);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
