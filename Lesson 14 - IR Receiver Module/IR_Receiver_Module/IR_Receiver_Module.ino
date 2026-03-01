//www.elegoo.com
//2016.12.9

//Update By Thomas Wright -  2026.03.01 - Notes Version 4 compatible
#include <IRremote.hpp>

const int receiverPin = 11; // Connect IR receiver signal pin here

void setup() {
  Serial.begin(9600);
  Serial.println("=== IR Remote Test ===");

  // Initialize the IR sender and receiver
  //IrSender.begin();  // no pin needed unless sending
  IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t rawValue = IrReceiver.decodedIRData.command; // safer than decodedRawData

    // Print raw value in HEX
    Serial.print("Raw HEX: 0x");
    Serial.println(rawValue, HEX);

    // Print human-readable button name
    printButtonName(rawValue);

    IrReceiver.resume(); // ready for next signal
  }
}

// Function to print button name for known NEC codes
void printButtonName(uint32_t value) {
  switch (value) {
    case 0x45: Serial.println("Button: POWER"); break;
    case 0x46: Serial.println("Button: FUNC/STOP"); break;
    case 0x47: Serial.println("Button: VOL+"); break;
    case 0x44: Serial.println("Button: FAST BACK"); break;
    case 0x40: Serial.println("Button: PLAY/PAUSE"); break;
    case 0x43: Serial.println("Button: FAST FORWARD"); break;
    case 0x7: Serial.println("Button: DOWN"); break;
    case 0x15: Serial.println("Button: VOL-"); break;
    case 0x9: Serial.println("Button: UP"); break;
    case 0x19: Serial.println("Button: EQ"); break;
    case 0xD: Serial.println("Button: ST/REPT"); break;
    case 0x16: Serial.println("Button: 0"); break;
    case 0xC: Serial.println("Button: 1"); break;
    case 0x18: Serial.println("Button: 2"); break;
    case 0x5E: Serial.println("Button: 3"); break;
    case 0x8: Serial.println("Button: 4"); break;
    case 0x1C: Serial.println("Button: 5"); break;
    case 0x5A: Serial.println("Button: 6"); break;
    case 0x42: Serial.println("Button: 7"); break;
    case 0x52: Serial.println("Button: 8"); break;
    case 0x4A: Serial.println("Button: 9"); break;
    //case 0x0: Serial.println("Button: REPEAT"); break; // not required kept in case as repeat now repeats the button pressed

    default:
      Serial.print("Button: Unknown (0x");
      Serial.print(value, HEX);
      Serial.println(")");
  }
}
