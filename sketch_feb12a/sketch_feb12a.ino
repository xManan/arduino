#include <IRremote.hpp>

#define POW 0xE0E040BF
#define VOL_UP 0xE0E0E01F
#define VOL_DOWN 0xE0E0D02F

#define POW_INP 2
#define VOL_UP_INP 5
#define VOL_DOWN_INP 8
#define IR_OUT 12

#define N_BITS 32

void setup() {
  pinMode(POW_INP, INPUT);
  pinMode(VOL_UP_INP, INPUT);
  pinMode(VOL_DOWN_INP, INPUT);
  pinMode(IR_OUT, OUTPUT);
}

IRsend irsend = IRsend(IR_OUT);

bool powSigSent = false;
bool volUpSigSent = false;
bool volDownSigSent = false;
void loop() {
  if (digitalRead(POW_INP) == HIGH) {
    if(!powSigSent) {
      irsend.sendSAMSUNG(POW, N_BITS);
      powSigSent = true;
    }
  } else {
    powSigSent = false;
  }
  if (digitalRead(VOL_UP_INP) == HIGH) {
    if(!volUpSigSent) {
      irsend.sendSAMSUNG(VOL_UP, N_BITS);
      volUpSigSent = true;
    }
  } else {
    volUpSigSent = false;
  }
  if(digitalRead(VOL_DOWN_INP) == HIGH) {
    if(!volDownSigSent) {
      irsend.sendSAMSUNG(VOL_DOWN, N_BITS);
      volDownSigSent = true;
    }
  } else {
    volDownSigSent = false;
  }
}