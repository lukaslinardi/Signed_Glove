#include <SoftwareSerial.h>

SoftwareSerial Ble(2, 3);

const int modePin = 10;
const int variantPin = 5;

// mode is an enum of "N" and "C"
String mode = "N";
String value = "";

void setup() {
  Serial.begin(9600);
  Ble.begin(115200);

  pinMode(modePin, INPUT);
  pinMode(variantPin, INPUT);
}

void loop() {
  int sensorValue0 = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  int sensorValue2 = analogRead(A2);
  int sensorValue3 = analogRead(A3);
  int sensorValue4 = analogRead(A4);
  
  int jempol = map(sensorValue0, 641, 758, 30, 90);
  int telunjuk = map(sensorValue1, 630, 820, 30, 90);
  int tengah = map(sensorValue2, 630, 820, 30, 90);
  int manis = map(sensorValue3, 630, 820, 30, 90);
  int pinky = map(sensorValue4, 630, 820, 30, 90);
 
  if (digitalRead(modePin) == HIGH) {
    newWord();
  }

  handleFlexSensorReading(
    jempol,
    telunjuk,
    tengah,
    manis,
    pinky
  );
}

void newWord(){
  mode = "N";
  value = "";
}

String makeJson(){
  String payload = "{\"md\":\"<mode>\", \"v\":\"<value>\"}";

  payload.replace("<mode>", String(mode));
  payload.replace("<value>", String(value));

  return payload;
}

void writeToBLE(const String newValue) {
  Serial.println(newValue);

  // send data
  if (value != newValue){
    value = newValue;
    String payload = makeJson();

    Ble.write(payload.c_str(), payload.length());
  }

  mode = "C";
}

void handleFlexSensorReading(int jempol, int telunjuk, int tengah, int manis, int pinky) {
  if (jempol <= 60 && jempol >= 50 && telunjuk <= 88 && telunjuk >= 78 && tengah <= 80 && tengah >= 70 && manis <= 79 && manis >= 69 && pinky <= 82 && pinky >= 72) {
    writeToBLE("A");

  } else if (jempol <= 119 && jempol >= 109 && telunjuk <= 35 && telunjuk >= 25 && tengah <= 33 && tengah >= 23 && manis <= 27 && manis >= 17 && pinky <= 26 && pinky >= 16) {
    writeToBLE("B");

  } else if (jempol <= 91 && jempol >= 81 && telunjuk <= 72 && telunjuk >= 62 && tengah <= 64 && tengah >= 54 && manis <= 64 && manis >= 54 && pinky <= 47 && pinky >= 37) {
    writeToBLE("C");

  } else if (jempol <= 117 && jempol >= 107 && telunjuk <= 35 && telunjuk >= 25 && tengah <= 83 && tengah >= 73 && manis <= 82 && manis >= 72 && pinky <= 87 && pinky >= 77) {
    writeToBLE("D");

  } else if (jempol <= 118 && jempol >= 108 && telunjuk <= 88 && telunjuk >= 78 && tengah <= 75 && tengah >= 65 && manis <= 76 && manis >= 66 && pinky <= 73 && pinky >= 63) {
    writeToBLE("E");

  } else if (jempol <= 100 && jempol >= 90 && telunjuk <= 89 && telunjuk >= 79 && tengah <= 33 && tengah >= 23 && manis <= 26 && manis >= 16 && pinky <= 30 && pinky >= 20) {
    writeToBLE("F");

  } else if (jempol <= 70 && jempol >= 60 && telunjuk <= 35 && telunjuk >= 25 && tengah <= 82 && tengah >= 72 && manis <= 77 && manis >= 67 && pinky <= 75 && pinky >= 65) {
    writeToBLE("G");

  } else if (jempol <= 79 && jempol >= 69 && telunjuk <= 31 && telunjuk >= 21 && tengah <= 29 && tengah >= 19 && manis <= 65 && manis >= 55 && pinky <= 58 && pinky >= 48) {
    writeToBLE("H");

  } else if (jempol <= 121 && jempol >= 111 && telunjuk <= 96 && telunjuk >= 86 && tengah <= 80 && tengah >= 70 && manis <= 73 && manis >= 63 && pinky <= 39 && pinky >= 29) {
    if (digitalRead(variantPin) == HIGH) {
      writeToBLE("J");
    } else {
      writeToBLE("I");
    }

  } else if (jempol <= 38 && jempol >= 28 && telunjuk <= 31 && telunjuk >= 21 && tengah <= 30 && tengah >= 20 && manis <= 79 && manis >= 69 && pinky <= 76 && pinky >= 66) {
    writeToBLE("K");

  } else if (jempol <= 33 && jempol >= 23 && telunjuk <= 35 && telunjuk >= 25 && tengah <= 88 && tengah >= 78 && manis <= 85 && manis >= 75 && pinky <= 88 && pinky >= 78) {
    writeToBLE("L");

  } else if (jempol <= 75 && jempol >= 65 && telunjuk <= 80 && telunjuk >= 70 && tengah <= 66 && tengah >= 56 && manis <= 65 && manis >= 55 && pinky <= 69 && pinky >= 59) {
    writeToBLE("M");

  } else if (jempol <= 40 && jempol >= 30 && telunjuk <= 78 && telunjuk >= 68 && tengah <= 62 && tengah >= 52 && manis <= 62 && manis >= 52 && pinky <= 66 && pinky >= 56) {
    writeToBLE("N");

  } else if (jempol <= 104 && jempol >= 94 && telunjuk <= 84 && telunjuk >= 74 && tengah <= 71 && tengah >= 61 && manis <= 71 && manis >= 61 && pinky <= 71 && pinky >= 61) {
    writeToBLE("O");

  } else if (jempol <= 30 && jempol >= 20 && telunjuk <= 34 && telunjuk >= 24 && tengah <= 35 && tengah >= 25 && manis <= 57 && manis >= 47 && pinky <= 55 && pinky >= 45) {
    writeToBLE("P");

  } else if (jempol <= 61 && jempol >= 51 && telunjuk <= 36 && telunjuk >= 26 && tengah <= 70 && tengah >= 60 && manis <= 72 && manis >= 62 && pinky <= 66 && pinky >= 56) {
    writeToBLE("Q");

  } else if (jempol <= 111 && jempol >= 101 && telunjuk <= 35 && telunjuk >= 25 && tengah <= 49 && tengah >= 39 && manis <= 68 && manis >= 58 && pinky <= 63 && pinky >= 53) {
    writeToBLE("R");

  } else if (jempol <= 111 && jempol >= 101 && telunjuk <= 99 && telunjuk >= 89 && tengah <= 90 && tengah >= 80 && manis <= 81 && manis >= 71 && pinky <= 82 && pinky >= 72) {
    writeToBLE("S");

  } else if (jempol <= 41 && jempol >= 31 && telunjuk <= 72 && telunjuk >= 62 && tengah <= 71 && tengah >= 61 && manis <= 61 && manis >= 51 && pinky <= 59 && pinky >= 49) {
    writeToBLE("T");

  } else if (jempol <= 100 && jempol >= 90 && telunjuk <= 36 && telunjuk >= 26 && tengah <= 33 && tengah >= 23 && manis <= 76 && manis >= 66 && pinky <= 82 && pinky >= 72) {
    if (digitalRead(variantPin) == HIGH) {
      writeToBLE("V");
    } else {
      writeToBLE("U");
    }

  } else if (jempol <= 102 && jempol >= 92 && telunjuk <= 32 && telunjuk >= 22 && tengah <= 31 && tengah >= 21 && manis <= 23 && manis >= 13 && pinky <= 70 && pinky >= 60) {
    writeToBLE("W");

  } else if (jempol <= 116 && jempol >= 106 && telunjuk <= 60 && telunjuk >= 50 && tengah <= 64 && tengah >= 54 && manis <= 59 && manis >= 49 && pinky <= 76 && pinky >= 66) {
    writeToBLE("X");

  } else if (jempol <= 35 && jempol >= 25 && telunjuk <= 85 && telunjuk >= 75 && tengah <= 72 && tengah >= 62 && manis <= 72 && manis >= 62 && pinky <= 31 && pinky >= 21) {
    writeToBLE("Y");

  } else if (jempol <= 99 && jempol >= 89 && telunjuk <= 43 && telunjuk >= 33 && tengah <= 83 && tengah >= 73 && manis <= 81 && manis >= 71 && pinky <= 79 && pinky >= 69) {
    writeToBLE("Z");

  } else {
    Serial.println("Not found");
  }
};
