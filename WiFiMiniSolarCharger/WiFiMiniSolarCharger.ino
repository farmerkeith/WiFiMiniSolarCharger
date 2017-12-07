// sketch for WiFiMiniSolarCharger by farmerkeith
// file created 12 Nov 2017
// initial draft to define and set directions for used pins
// using D3 to control charging MOSFETs - Low is OFF, Input (high due to on-board 10K resistor to 3.3V) is ON
// using A0 to measure battery voltage using 1.2M extension resistor
  // full scale is approximately 15,000 mV, calibration to be checked
// using D8 as digital input to sense whether solar panel has illumination
  // using 56K extension reistor together with on-board 10K resistor to ground
  // this gives maximum voltage of 21.8V before pin exceeds 3.3V.  
  // binary trigger point should be about half that, ie 10.9 V.  
// D0 connected to RST (reset) as provision for possible sleep mode

#include "wemosPinMap.h" // class for wemos pin names
const byte connectPin = wemosPin.D2;
const byte solarPin = wemosPin.D8;
#include "connect.h" // class to control the connection MOSFETS; see tab file
connect connect(connectPin); // instantiates connect object
  // connect is OFF when instantiated
#include "charger.h" // class to run the charge control functions; see tab file



enum {
  charger_off,
  charger_boost,
  charger_float
} chargerState;


void setup() {
  Serial.begin (115200);
  Serial.println ("\nWiFiMiniSolarCharger");
  Serial.print ("connect state is ");
  Serial.println (connect.state);
  pinMode (solarPin,INPUT); // digital input pin to sense panel output
}

void loop() {
  charger.run();
}

