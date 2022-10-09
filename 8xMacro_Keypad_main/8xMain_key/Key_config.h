
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
      delay(150);
      break;
    case 2:
      Keyboard_press(KEY_LEFT_CTRL);         //Paste
      Keyboard_press('v');
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(150);
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


void Keypad1(int inp) {
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
      Keyboard_press(KEY_LEFT_SHIFT);
      Keyboard_press('c');
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(150);
      break;
    case 2:
      Keyboard_press(KEY_LEFT_CTRL);         //Paste
      Keyboard_press(KEY_LEFT_SHIFT);
      Keyboard_press('v');
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(150);
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
      Consumer_press(MEDIA_PREVIOUS);         //Previous
      Keyboard_releaseAll();
      Consumer_releaseAll();
      delay(250);
      break;
    case 7:
      Consumer_press(MEDIA_NEXT);         //Next
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
