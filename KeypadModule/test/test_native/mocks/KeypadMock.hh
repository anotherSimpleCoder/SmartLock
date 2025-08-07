//
// Created by abav on 07.08.2025.
//

#ifndef KEYPADMOCK_HH
#define KEYPADMOCK_HH
char * makeKeymap(const char(* keymap)[3]) {
  return nullptr;
}

class Keypad {
  char pressedKey;
public:
  Keypad(
    char* keymap,
    unsigned char rowPins[4],
    unsigned char colPins[4],
    int ROWS,
    int COLS
  ) {}

  char getKey() {
    return pressedKey;
  }

  void pressKey(char key) {
    pressedKey = key;
  }
};
#endif //KEYPADMOCK_HH
