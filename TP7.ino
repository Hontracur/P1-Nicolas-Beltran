#include <Servo.h>

Servo servo1;
Servo servo2;

const int pinBoton = 2;
const int pinPIR = 3;
const int pinTemp = A0;

unsigned long tiempoCambio = 0;
unsigned long tiempoMovimiento = 0;

bool posicionAlta = false;
bool modoMovimiento = false;

int posicionActual = 90;

void setup() {
  servo1.attach(9);
  servo2.attach(10);

  pinMode(pinBoton, INPUT_PULLUP);
  pinMode(pinPIR, INPUT);

  servo1.write(45);
  servo2.write(45);
}

void loop() {

  bool botonPresionado = (digitalRead(pinBoton) == LOW);

  int lectura = analogRead(pinTemp);
  float voltaje = lectura * (5.0 / 1023.0);
  float temperatura = (voltaje - 0.5) * 100.0;

  if (!botonPresionado) {
    servo1.write(45);
    servo2.write(45);
    modoMovimiento = false;
    return;
  }

  if (temperatura > 35.0) {
    return;
  }

  if (digitalRead(pinPIR) == HIGH && !modoMovimiento) {
    modoMovimiento = true;
    tiempoMovimiento = millis();

    servo1.write(0);
    servo2.write(0);
  }

  if (modoMovimiento) {

    if (millis() - tiempoMovimiento >= 6000) {
      modoMovimiento = false;

      servo1.write(posicionActual);
      servo2.write(posicionActual);
    }

    return;
  }

  if (millis() - tiempoCambio >= 3000) {

    tiempoCambio = millis();

    if (posicionAlta) {
      posicionActual = 90;
    } else {
      posicionActual = 180;
    }

    posicionAlta = !posicionAlta;

    servo1.write(posicionActual);
    servo2.write(posicionActual);
  }
}