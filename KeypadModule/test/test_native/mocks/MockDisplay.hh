//
// Created by amsakan on 17.08.25.
//

#ifndef MOCKDISPLAY_HH
#define MOCKDISPLAY_HH
class LCDI2C_Latin {
    char displayedMessage[16] = "";
public:
    LCDI2C_Latin(int address, int cols, int rows) {}
    void init() {}
    void backlight() {}
    void clear() {}
    void setCursor(int col, int row) {}
    void print(const char message[16]) {
        for (int i = 0; i < 16; i++) {
            displayedMessage[i] = message[i];
        }
    }

    bool hasDisplayed(const char message[16]) {
        for (int i = 0; i < 16; i++) {
            if (displayedMessage[i] != message[i]) {
                return false;
            }
        }

        return true;
    }

    char* getDisplayedMessage() {
        return this->displayedMessage;
    }
};
#endif //MOCKDISPLAY_HH
