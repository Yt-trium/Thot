// MFRC522 : RFID Module For Arduino SPI

#include <SPI.h>
#include <MFRC522.h>

extern byte MFRC522_RST;
extern byte MFRC522_MISO;
extern byte MFRC522_MOSI;
extern byte MFRC522_SCK;
extern byte MFRC522_SS;

MFRC522 mfrc522(MFRC522_SS, MFRC522_RST);

void MFRC522_setup()
{
  SPI.begin();
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
}
