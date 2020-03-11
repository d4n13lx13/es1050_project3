#include <IRLibSendBase.h> // Frist include the send base
#include <IRLib_P01_NEC.h>
#include <IRLib_P02_Sony.h>
#include <IRLibCombo.h>

IRsend mySender; //declare a sender object

mySender.send(SONY,0xa8bca, 20); //Type of TV, ID

button=0x61a0f00f //This is the code of which button we want to signal
