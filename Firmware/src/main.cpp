#include <Arduino.h>
#include <bluefruit.h>

const uint8_t BUTTON_PINS[] = {
  D0,
  D1,
  D2,
  D3,
  D4, 
  D5,
  D6,
  D7,
  D8,
  D9
};

const uint8_t NUM_BUTTONS = 10;

bool buttonStates[NUM_BUTTONS] = {false};
bool lastButtonStates[NUM_BUTTONS] = {false};
unsigned long lastDebounceTime[NUM_BUTTONS] = {0};
const unsigned long DEBOUNCE_DELAY = 50;

BLEDis bledis;
BLEHidAdafruit blehid;

BLEBas blebas;

const int LED_PIN = LED_BUILTIN;

void setup() {
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
    lastButtonStates[i] = digitalRead(BUTTON_PINS[i]);
  }
    
  Bluefruit.begin();
  Bluefruit.setTxPower(4);
  Bluefruit.setName("Spacey Mouse");
  
  bledis.setManufacturer("Spacey");
  bledis.setModel("Space Mouse!");
  bledis.begin();
  blehid.begin();
  
  blebas.begin();
  blebas.write(100);
  
  startAdv();
}

void startAdv(void) {
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);
  
  Bluefruit.Advertising.addService(blehid);
  
  Bluefruit.Advertising.addName();
  
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);
  Bluefruit.Advertising.setFastTimeout(30);
  Bluefruit.Advertising.start(0);
}

void sendOnshapeCommand(uint8_t buttonIndex) {
  if (!Bluefruit.connected()) {
    return;
  }
    
  switch(buttonIndex) {
    case 0:
      blehid.keyboardReport(0, HID_KEY_R);
      delay(10);
      blehid.keyRelease();
      break;
      
    case 1:
      blehid.keyboardReport(KEYBOARD_MODIFIER_LEFTSHIFT, HID_KEY_R);
      delay(10);
      blehid.keyRelease();
      break;
      
    case 2: 
      blehid.keyboardReport(0, HID_KEY_Z);
      delay(10);
      blehid.keyRelease();
      break;
      
    case 3:
      blehid.keyboardReport(0, HID_KEY_F);
      delay(10);
      blehid.keyRelease();
      break;
      
    case 4:
      blehid.keyboardReport(0, HID_KEY_SPACE);
      delay(10);
      blehid.keyRelease();
      delay(50);
      blehid.keyboardReport(0, HID_KEY_2);
      delay(10);
      blehid.keyRelease();
      break;
      
    case 5:
      blehid.keyboardReport(0, HID_KEY_SPACE);
      delay(10);
      blehid.keyRelease();
      delay(50);
      blehid.keyboardReport(0, HID_KEY_1);
      delay(10);
      blehid.keyRelease();
      break;
      
    case 6:
      blehid.keyboardReport(0, HID_KEY_SPACE);
      delay(10);
      blehid.keyRelease();
      delay(50);
      blehid.keyboardReport(0, HID_KEY_3);
      delay(10);
      blehid.keyRelease();
      break;
      
    case 7: 
      blehid.keyboardReport(0, HID_KEY_SPACE);
      delay(10);
      blehid.keyRelease();
      delay(50);
      blehid.keyboardReport(0, HID_KEY_7);
      delay(10);
      blehid.keyRelease();
      break;
      
    case 8:
      blehid.keyboardReport(0, HID_KEY_V);
      delay(10);
      blehid.keyRelease();
      break;
      
    case 9:
      blehid.keyboardReport(KEYBOARD_MODIFIER_LEFTCTRL | KEYBOARD_MODIFIER_LEFTSHIFT, HID_KEY_R);
      delay(10);
      blehid.keyRelease();
      break;
  }
}

void loop() {
  static bool ledState = false;
  static unsigned long lastBlink = 0;
  
  if (Bluefruit.connected()) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    if (millis() - lastBlink > 500) {
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      lastBlink = millis();
    }
  }
  
  for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
    bool reading = !digitalRead(BUTTON_PINS[i]);
    
    if (reading != lastButtonStates[i]) {
      lastDebounceTime[i] = millis();
    }
    
    if ((millis() - lastDebounceTime[i]) > DEBOUNCE_DELAY) {
      if (reading != buttonStates[i]) {
        buttonStates[i] = reading;
        
        if (buttonStates[i]) {
          sendOnshapeCommand(i);
        }
      }
    }
    lastButtonStates[i] = reading;
  }
  delay(1);
}
