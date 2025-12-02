#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// gestion du hub
#include <M5_PbHub.h>
M5_PbHub myPbHub;


// channel du hub où il est utilisé
// Boutons rouges
#define KEY_CHANNEL_KEY1 0
#define KEY_CHANNEL_KEY2 1
#define KEY_CHANNEL_KEY3 2
#define KEY_CHANNEL_KEY4 3

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

    // oscslip Key Unit
    int valueBouton1 = myPbHub.digitalRead(KEY_CHANNEL_KEY1);
    monOsc.sendInt("/bouton1", valueBouton1);

    int valueBouton2 = myPbHub.digitalRead(KEY_CHANNEL_KEY2);
    monOsc.sendInt("/bouton2", valueBouton2);

    int valueBouton3 = myPbHub.digitalRead(KEY_CHANNEL_KEY3);
    monOsc.sendInt("/bouton3", valueBouton3);

    int valueBouton4 = myPbHub.digitalRead(KEY_CHANNEL_KEY4);
    monOsc.sendInt("/bouton4", valueBouton4);

  }
}
