#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// gestion du hub
#include <M5_PbHub.h>
M5_PbHub myPbHub;

// channel du hub où il est utilisé
// angle units
#define KEY_CHANNEL_ANGLE1 0
#define KEY_CHANNEL_ANGLE2 1
#define KEY_CHANNEL_ANGLE3 2
// light unit
#define KEY_CHANNEL_LIGHT5 5

//CRGB keyPixel;
CRGB atomPixel;

// algorithme d'intervalle
unsigned long monChronoDepart ; 

void setup() {
  // NE JAMAIS OUBLIER !!!
  Serial.begin(115200);

  // PBHUB
  Wire.begin();
  myPbHub.begin();

  // TEMPS DE DÉPART
  monChronoDepart = millis(); 
}

void loop() {
  if ( millis() - monChronoDepart >= 20 ) { 
    monChronoDepart = millis(); 

    // oscslip rotation Angle Unit
    int valueAngle1 = myPbHub.analogRead(KEY_CHANNEL_ANGLE1);
    monOsc.sendInt("/angle1", valueAngle1);

    int valueAngle2 = myPbHub.analogRead(KEY_CHANNEL_ANGLE2);
    monOsc.sendInt("/angle2", valueAngle2);

    int valueAngle3 = myPbHub.analogRead(KEY_CHANNEL_ANGLE3);
    monOsc.sendInt("/angle3", valueAngle3);

    int valueLight = myPbHub.analogRead(KEY_CHANNEL_LIGHT5);
    monOsc.sendInt("/light", valueLight);
  }
}
