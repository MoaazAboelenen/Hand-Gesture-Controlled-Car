/*
  This program receives the message from
  the transmitter and moves the car
  accordingly.

  This program is made by Shreyas for
  Electronics Champ YouTube Channel.
  Please subscribe to this channel
  Thank You
*/

//Include the libraries
#include <SPI.h>
#include <NRFLite.h>

//Initializing the variables
boolean x = 0;
int directionOfMovement = 0;
int RMA = 2;
int RMB = 3;
int LMA = 4;
int LMB = 5;
String message;
const static uint8_t RADIO_ID = 1;       // Our radio's id.  The transmitter will send to this id.
const static uint8_t PIN_RADIO_CE = 7;
const static uint8_t PIN_RADIO_CSN = 8;

struct RadioPacket { // Any packet up to 32 bytes can be sent.

  uint8_t FromRadioId;
  uint32_t Data;
  uint32_t FailedTxCount;

};

//Create NRF object
NRFLite _radio;
RadioPacket _radioData;

void setup() {

  Serial.begin(9600);

  //Set the pin modes
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  if (!_radio.init(RADIO_ID, PIN_RADIO_CE, PIN_RADIO_CSN)) {

    Serial.println("Cannot communicate with radio");
    while (1); // Wait here forever.

  }

}

void loop() {

  while (_radio.hasData()) {

    _radio.readData(&_radioData); // Note how '&' must be placed in front of the variable name.

    message = _radioData.Data;
    Serial.println(message);
    directionOfMovement = message.toInt();
    moveAccordingly();

  }

}

//this function moves the car according to the message
void moveAccordingly() {

  if (directionOfMovement == 1) {

    front();
    Serial.println("front");

  }

  else if (directionOfMovement == 2) {

    back();
    Serial.println("back");

  }

  else if (directionOfMovement == 3) {

    left();
    Serial.println("left");

  }

  else if (directionOfMovement == 4) {

    right();
    Serial.println("right");

  }

  else if (directionOfMovement == 0) {

    none();
    Serial.println("none");

  }

}

void front() {
digitalWrite(LMA, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMA, HIGH);
  digitalWrite(RMB, LOW);
 

}

void back() {

  digitalWrite(LMA, LOW);
  digitalWrite(LMB, HIGH);
  digitalWrite(RMA, LOW);
  digitalWrite(RMB, HIGH);
}

void left() {
 digitalWrite(LMA, LOW);
  digitalWrite(LMB, HIGH);
  digitalWrite(RMA, HIGH);
  digitalWrite(RMB, LOW);
}
 

void right() {
  digitalWrite(LMA, HIGH);
  digitalWrite(LMB, LOW);
  digitalWrite(RMA, LOW);
  digitalWrite(RMB, HIGH);

  
}

void none() {

digitalWrite(LMA, LOW);
  digitalWrite(LMB, LOW);
  digitalWrite(RMA, LOW);
  digitalWrite(RMB, LOW);
}
