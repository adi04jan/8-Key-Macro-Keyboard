/*
  HID Keyboard example


  created 2020
  by Deqing Sun for use with CH55xduino

  This example code is in the public domain.

*/

//For windows user, if you ever played with other HID device with the same PID C55D
//You may need to uninstall the previous driver completely


#ifndef USER_USB_RAM
#error "This example needs to be compiled with a USER USB setting"
#endif

#include "src/userUsbHidMediaKeyboard/USBHIDMediaKeyboard.h"

#include <TouchKey.h>
#include <WS2812.h>
#define NUM_LEDS 8
#define COLOR_PER_LEDS 3
#define NUM_BYTES (NUM_LEDS*COLOR_PER_LEDS)

#if NUM_BYTES > 255
#error "NUM_BYTES can not be larger than 255."
#endif

__xdata uint8_t ledData[NUM_BYTES];



__xdata uint8_t r, g, b;


bool B_1 = false;
bool B_2 = false;
bool B_3 = false;
bool B_4 = false;
bool T_1 = false;
bool T_2 = false;


#define BUTIN_1 11
#define BUTIN_2 33
#define BUTIN_3 16



#define BUTOUT_1 31
#define BUTOUT_2 30
#define BUTOUT_3 17

uint8_t prevSensorValue = 0;
bool button1PressPrev1 = false;
bool button1PressPrev2 = false;
bool button1PressPrev3 = false;
bool button1PressPrev4 = false;


bool button1PressPrev = false;


void setup() {
  USBInit();
  pinMode(BUTIN_1, INPUT_PULLUP);
  pinMode(BUTIN_2, INPUT_PULLUP);
  pinMode(BUTIN_3, INPUT_PULLUP);
  pinMode(BUTOUT_1, OUTPUT);
  pinMode(BUTOUT_2, OUTPUT);
  pinMode(BUTOUT_3, OUTPUT);

  digitalWrite(BUTOUT_1, HIGH);
  digitalWrite(BUTOUT_2, HIGH);
  digitalWrite(BUTOUT_3, HIGH);
  TouchKey_begin(  (1 << 2) | (1 << 3) ); //Enable all 6 channels: TIN0(P1.0), TIN1(P1.1), TIN2(P1.4), TIN3(P1.5), TIN4(P1.6), TIN5(P1.7)

  // In most cases you don't need to adjust parameters. But if you do, test with TouchKeyTuneParameter example

  //refer to AN3891 MPR121 Baseline System for more details
  TouchKey_SetMaxHalfDelta(25);      //increase if sensor value are more noisy
  TouchKey_SetNoiseHalfDelta(15);    //If baseline need to adjust at higher rate, increase this value
  TouchKey_SetNoiseCountLimit(15);  //If baseline need to adjust faster, increase this value
  TouchKey_SetFilterDelayLimit(4);  //make overall adjustment slopwer

  TouchKey_SetTouchThreshold(200);  //Bigger touch pad can use a bigger value
  TouchKey_SetReleaseThreshold(180); //Smaller than touch threshold

}



void Keypad(int inp) {
  delay(10);
  switch (inp) {
    case 0:
      Keyboard_press(KEY_HOME);             //Select Current line
      Keyboard_releaseAll();
      Keyboard_press(KEY_LEFT_SHIFT);
      Keyboard_press(KEY_END);
      Keyboard_releaseAll();
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(250);
    case 1:
      Keyboard_press(KEY_LEFT_CTRL);         //Copy
      Keyboard_press('c');
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(250);
      break;
    case 2:
      Keyboard_press(KEY_LEFT_CTRL);         //Paste
      Keyboard_press('v');
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(250);
      break;
    case 3:
      Consumer_press(MEDIA_PLAY_PAUSE);         //Play Pause
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(250);
      break;

    case 4:
      Consumer_press(MEDIA_VOL_UP);         //Volume UP

      Keyboard_releaseAll();
      Consumer_releaseAll();
      break;

    case 5:
      Consumer_press(MEDIA_VOL_DOWN);         //Volume DOWN
      Keyboard_releaseAll();
      Consumer_releaseAll();
      break;
    case 6:
      Consumer_press(MEDIA_NEXT);         //Next
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(250);
      break;
    case 7:
      Consumer_press(MEDIA_PREVIOUS);         //Previous
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(250);
      break;

    case 8:
      Keyboard_press(KEY_HOME);             //Select Current line
      Keyboard_releaseAll();
      Keyboard_press(KEY_LEFT_SHIFT);
      Keyboard_press(KEY_END);
      Keyboard_releaseAll();
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(250);
      break;
    case 9:
      Keyboard_press(KEY_LEFT_CTRL);             //Build Current
      Keyboard_press(KEY_LEFT_SHIFT);
      Keyboard_press('b');
      Keyboard_releaseAll();
      Keyboard_press(KEY_LEFT_CTRL);
      Keyboard_press('u');

      //Youtube
      //            Keyboard_press(KEY_LEFT_CTRL);
      //            Keyboard_press(KEY_LEFT_ALT);
      //            Keyboard_press('u');
      //            delay(4000);
      //            Keyboard_releaseAll();
      //            Keyboard_write('Y');
      //            Keyboard_press(KEY_LEFT_ALT);
      //            Keyboard_press( KEY_LEFT_ARROW);
      //            Keyboard_press( KEY_RETURN);
      Keyboard_releaseAll();
      Keyboard_releaseAll();
      Consumer_releaseAll();
      break;
    case 10:
      Consumer_press(MEDIA_PREVIOUS);
      Keyboard_releaseAll();
      Consumer_releaseAll();
      break;
    default:
      //Select Current line
      Keyboard_releaseAll();
      Consumer_releaseAll();
      break;

  }


}

void touch_routine() {
  /*
    TouchKey_Process();
    uint8_t touchResult = TouchKey_Get();

    if (touchResult & (1 << 2)) {
      T_1 = true;
      delay(1);
    }
    else {

      T_1 = false;
      delay(1);

    } if (touchResult & (1 << 3)) {

      T_2 = true;
      delay(1);
    }
    else {
      T_2 = false;
      delay(1);

    } if (touchResult & (1 << 4)) {

      T_3 = true;
      delay(1);
    }
    else {
      T_3 = false;
      delay(1);

    } if (touchResult & (1 << 5)) {
      T_4 = true;
      delay(1);

    }
    else {
      T_4 = false;
      delay(1);

    }

  */
}

void Button_Routine() {

  digitalWrite(BUTOUT_1, LOW);
  digitalWrite(BUTOUT_2, HIGH);
  digitalWrite(BUTOUT_3, HIGH);
  delay(1);

  if (digitalRead(BUTIN_1) != HIGH) {
    delay(25);
    if (digitalRead(BUTIN_1) != HIGH) {
      Keypad(3);
      //    while (digitalRead(BUTIN_1) != HIGH)delay(100);
    }
  }

  else if (digitalRead(BUTIN_2) != HIGH) {
    delay(25);
    if (digitalRead(BUTIN_2) != HIGH) {
      Keypad(2);
      //while (digitalRead(BUTIN_2) != HIGH)delay(100);
    }
  }

  else if (digitalRead(BUTIN_3) != HIGH) {
    delay(25);
    if (digitalRead(BUTIN_3) != HIGH) {
      Keypad(6);
      //     while (digitalRead(BUTIN_3) != HIGH)delay(100);
    }
  }
  ///***************end of 1 column


  digitalWrite(BUTOUT_1, HIGH);
  digitalWrite(BUTOUT_2, LOW);
  digitalWrite(BUTOUT_3, HIGH);
  delay(1);

  if (digitalRead(BUTIN_1) != HIGH) {
    delay(25);
    if (digitalRead(BUTIN_1) != HIGH) {
      Keypad(5);
      //    while (digitalRead(BUTIN_1) != HIGH)delay(100);
    }
  }

  else  if (digitalRead(BUTIN_2) != HIGH) {
    delay(25);
    if (digitalRead(BUTIN_2) != HIGH) {
      Keypad(4);
      //    while (digitalRead(BUTIN_2) != HIGH)delay(100);
    }
  }

  else  if (digitalRead(BUTIN_3) != HIGH) {
    delay(25);
    if (digitalRead(BUTIN_3) != HIGH) {
      Keypad(7);
      //   while (digitalRead(BUTIN_3) != HIGH)delay(100);
    }
  }
  ///***************end of 2 column


  digitalWrite(BUTOUT_1, HIGH);
  digitalWrite(BUTOUT_2, HIGH);
  digitalWrite(BUTOUT_3, LOW);
  delay(1);

  if (digitalRead(BUTIN_1) != HIGH) {
    delay(25);
    if (digitalRead(BUTIN_1) != HIGH) {
      Keypad(0);
      //   while (digitalRead(BUTIN_1) != HIGH)delay(100);
    }
  }

  else  if (digitalRead(BUTIN_2) != HIGH) {
    delay(25);
    if (digitalRead(BUTIN_2) != HIGH) {
      Keypad(1);
      //  while (digitalRead(BUTIN_2) != HIGH)delay(100);
    }
  }

  else  if (digitalRead(BUTIN_3) != HIGH) {
    delay(25);
    if (digitalRead(BUTIN_3) != HIGH) {
      Keypad(8);
      //  while (digitalRead(BUTIN_3) != HIGH)delay(100);
    }
  }
  ///***************end of 3 column

}
void ColorHSV1(__xdata uint16_t hue) {

  hue = (hue * 1530L + 32768) / 65536;

  if (hue < 510) { // Red to Green-1
    b = 0;
    if (hue < 255) { //   Red to Yellow-1
      r = 255;
      g = hue;       //     g = 0 to 254
    } else {         //   Yellow to Green-1
      r = 510 - hue; //     r = 255 to 1
      g = 255;
    }
  } else if (hue < 1020) { // Green to Blue-1
    r = 0;
    if (hue < 765) { //   Green to Cyan-1
      g = 255;
      b = hue - 510;  //     b = 0 to 254
    } else {          //   Cyan to Blue-1
      g = 1020 - hue; //     g = 255 to 1
      b = 255;
    }
  } else if (hue < 1530) { // Blue to Red-1
    g = 0;
    if (hue < 1275) { //   Blue to Magenta-1
      r = hue - 1020; //     r = 0 to 254
      b = 255;
    } else { //   Magenta to Red-1
      r = 255;
      b = 1530 - hue; //     b = 255 to 1
    }
  } else { // Last 0.5 Red (quicker than % operator)
    r = 255;
    g = b = 0;
  }

}
void rainbow(int wait) {

  for (__xdata long firstPixelHue = 0; firstPixelHue < 3 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < NUM_LEDS; i++) { // For each pixel in strip...

      int pixelHue = firstPixelHue + (i * 65536L / NUM_LEDS);
      ColorHSV1(pixelHue);
      // before assigning to each pixel:
      set_pixel_for_GRB_LED(ledData, i, r, g, b);

      Button_Routine();
      touch_routine();
    }
    neopixel_show_P3_4(ledData, NUM_BYTES); //Possible to use other pins.
    delay(wait);  // Pause for a moment
  }
}


void loop() {
  // put your main code here, to run repeatedly:AAA
  // touch_routine();
  // Button_Routine();
  //Keypad(0);
  rainbow(1);


}
