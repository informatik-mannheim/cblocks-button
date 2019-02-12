#include "CBlocks.h"
#include "CBlocksMaker.h"
#include "Button.h"

#define BAUD_RATE 115200
#define OBJECT_ID 3302
#define INSTANCE_ID 0
#define BUTTON_PIN 21

CBlocks::CBlocks* cblocks;
CBlocks::CButton* button;

void initSerial(){
  Serial.begin(BAUD_RATE);
}

void initCBlocks(){
  cblocks = CBlocks::CBlocksMaker::make(OBJECT_ID, INSTANCE_ID);
  cblocks->begin();
}

void initSensor(){
  button = new CBlocks::CButton(BUTTON_PIN, cblocks);
  button->begin();
}

void setup(){
  initSerial();
  initCBlocks();
  initSensor();
}

void loop(){
  button->publishStatus();
}
