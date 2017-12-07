// charger class for WiFiMiniSolarCharger
// file created 13 Nov 2017 by farmerkeith

class charger{
  public:
  // constructor
  charger();
  // functions
  void run();
  // variables
  unsigned long time=0;
  unsigned long period = 100;
};

charger charger; // instantiates class as object charger 

// constructor
charger::charger(){
  while(millis()>time) time+=period;
  pinMode(wemosPin.D4,OUTPUT); 
   
}

// functions
void charger::run(){
  if((long)(millis() - time) >= 0){ // time is expired
    time += period; // ms, set time for the following execution
    Serial.print ("time expired ");
    Serial.print ((float)millis()/1000,3);
    int flag = (time/period)%20;
    if (flag<3) {
      digitalWrite(wemosPin.D4, 0);
      connect.on();
      Serial.print(" ON ");
    }else{
      digitalWrite(wemosPin.D4, 1);
      connect.off();
      Serial.print(" OFF ");
    }
    Serial.print(" Solar Pin=");
    Serial.print(digitalRead(solarPin));
    Serial.print(" Flag=");
    Serial.print(flag);
    
    Serial.println();
  }
}


