// connect class for WiFiMiniSolarCharger
// file created 12 Nov 2017 by farmerkeith

class connect{
  public:
  // constructor
  connect (byte _pin);
  // functions
  void on(); // connects the solar panel to the battery
  void off(); // disconnects the solar panel from the battery
  // variables
  enum {
    state_off = 0,
    state_on = 1
  } state;
  private: 
  // variables
  byte pin;
};


// constructor
connect::connect(byte _pin){
  pin = _pin;  
  pinMode(pin,OUTPUT);
  off(); // the charger object starts life in the off() state
}

// functions
void connect::off(){
//  pinMode(pin,OUTPUT);
  digitalWrite (pin, LOW); // 
  state = state_off;
}

void connect::on(){
  digitalWrite (pin, HIGH); // 
//  pinMode(pin,INPUT); // on-board resistor pulls the pin up 
                      // to turn on the NPN transistor
  state = state_on;
}

