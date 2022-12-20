#include "esphome.h"

static const char *const TAG = "Su_03t_Sensor";

class Su_03t_Sensor : public Component, public Sensor, public UARTDevice {
 public:
  Su_03t_Sensor(UARTComponent *parent) : UARTDevice(parent) { }

    int incomeByte[2];
    int data;
    int start = 0;

  void setup() override {
    // nothing to do here
  }

  void loop() override {
    while(available()>0) {
      data = read();
      if( start == 0 ) {  
          start = 1;
          incomeByte[0] = data;
      } else if(start) {
        start = 0;
        incomeByte[1] = data;
        ESP_LOGD(TAG, "Got SU-03T data=0x%.2X%.2X", incomeByte[0], incomeByte[1]);
        const uint16_t result = encode_uint16(incomeByte[0], incomeByte[1]);
        publish_state(result); 
      }
    }
  }
};