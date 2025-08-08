//
// Created by abav on 08.08.2025.
//

#ifndef FINGERPRINTMOCK_HH
#define FINGERPRINTMOCK_HH

enum Status {
  FINGERPRINT_OK,
  FINGERPRINT_ERROR
};

class SoftwareSerial {
  int pin1;
  int pin2;
public:
  SoftwareSerial(int pin1, int pin2):
    pin1(pin1), pin2(pin2) {}
};

class Adafruit_Fingerprint {
  unsigned char reference[255];
  unsigned char image[255];
public:
  Adafruit_Fingerprint(SoftwareSerial* serial) {
    for (int i = 0; i < 255; i++) {reference[i] = 0xFF;}
    for (int i = 0; i < 255; i++) {image[i] = 0;}
  }
  void begin(int port) {}
  bool verifyPassword() {
    return true;
  }

  void setImage(unsigned char image[255]) {
    for (int i = 0; i < 255; i++) {
      this->image[i] = image[i];
    }
  }

  Status getImage() {
    for (int i = 0; i < 255; i++) {
      if (reference[i] != image[i]) {
        return FINGERPRINT_ERROR;
      }
    }

    return FINGERPRINT_OK;

  }
};
#endif //FINGERPRINTMOCK_HH
