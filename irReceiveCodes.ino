#include <IRLibDecodeBase.h> 
#include <IRLib_P01_NEC.h>   
#include <IRLib_P02_Sony.h>  
#include <IRLib_HashRaw.h>  
#include <IRLibCombo.h>     
#include <IRLibRecv.h>

IRdecode decoder;
IRrecv receiver(16); //GPIO 16

void setup() {
  Serial.begin(115200);

  receiver.enableIRIn();
}

void loop() {
  if(receiver.getResults()) {
    decoder.decode();
    if(decoder.protocolNum == UNKNOWN) {
      Serial.print(F("Unknown protocol. Hash value is: 0x"));
      Serial.println(decoder.value, HEX);
    } else {
      decoder.dumpResults(false);
    }
    receiver.enableIRIn(); 
  }
}
