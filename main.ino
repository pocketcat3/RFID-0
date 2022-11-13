#include <SPI.h>
#include <MFRC522.h>
MFRC522 mfrc522(10, 9);
String content = " ";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  if(!mfrc522.PICC_IsNewCardPresent()){
    return;
    Serial.println();
  }
    if(!mfrc522.PICC_ReadCardSerial()){
      return;
      Serial.println("");
    }
//    Serial.println("UID tag:");
   for(byte i=0; i<mfrc522.uid.size;i++){
    Serial.print(mfrc522.uid.uidByte[i],HEX);
    content.concat(String(mfrc522.uid.uidByte[i],HEX));
   }
  Serial.println("");
}
