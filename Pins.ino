// Pins : Pins Configuration
// The actual configuration fit for an Arduino MEGA 2560 R3 (in fact, a Chinese version)

/*
 * KY016 (RGB LED)
 */
 
const byte RGB[4][3] =  {{2,3,4}
                        ,{5,6,7}
                        ,{8,9,10}
                        ,{11,12,13}
                        };


/*
 * Keypad
 */
 
byte KeypadRowPins[4] = {22, 24, 26, 28};
byte KeypadColPins[4] = {30, 32, 34, 36};


/*
 * MFRC522
 *
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

byte MFRC522_RST  = 48;
byte MFRC522_MISO = 50;
byte MFRC522_MOSI = 51;
byte MFRC522_SCK  = 52;
byte MFRC522_SS   = 53;

/*
 * SSD1306
 */
byte SSD1306_ADDR = 0x3C;
