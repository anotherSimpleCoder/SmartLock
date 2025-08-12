//
// Created by amsakan on 12.08.25.
//

#ifndef WIREMOCK_HH
#define WIREMOCK_HH

#define WIRE_BUFFER_SIZE 4

class _WireMock {
    int counter = 0;
    unsigned char buffer[WIRE_BUFFER_SIZE] = {};
public:
    void begin() {}
    void beginTransmission(int channel) {}
    void write(unsigned char data) {
        buffer[counter] = data;
        counter = (counter + 1) % WIRE_BUFFER_SIZE;
    }
    void endTransmission() {}

    bool contains(unsigned char data) {
        for (int i = 0; i < WIRE_BUFFER_SIZE; i++) {
            if (buffer[i] == data) {
                return true;
            }
        }

        return false;
    }
};

_WireMock WireMock;
#endif //WIREMOCK_HH
