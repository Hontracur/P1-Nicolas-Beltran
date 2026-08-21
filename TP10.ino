#include <Servo.h>

#define PIR_ENTRADA 8
#define PIR_SALIDA 9
#define BUZZER 12
#define SERVO_1 5
#define SERVO_2 6
#define FOCO 13
#define LDR A0

Servo servo1;
Servo servo2;

int limiteLuz = 400;
int puertasAbiertas = 0;

void prenderFoco(int pin, int estado)
{
  digitalWrite(pin, estado);
}

void abrirPuertas(int posicion1, int posicion2)
{
  servo1.write(posicion1);
  servo2.write(posicion2);
  puertasAbiertas = 1;
}

void cerrarPuertas(int posicion1, int posicion2)
{
  servo1.write(posicion1);
  servo2.write(posicion2);
  puertasAbiertas = 0;
}

void detectarMovimiento(int pin, int &movimiento)
{
  movimiento = digitalRead(pin);
}

void detectarLuz(int pin, int limite, int &oscuro)
{
  int valor = analogRead(pin);

  if (valor < limite)
  {
    oscuro = 1;
  }
  else
  {
    oscuro = 0;
  }
}

void cancionAbrir(int pin) {
  tone(pin, 262, 150);
  delay(180);
  tone(pin, 330, 150);
  delay(180);
  tone(pin, 392, 150);
  delay(180);
  tone(pin, 523, 400);
  delay(450);
}

void cancionCerrar(int pin) {
  tone(pin, 523, 120);
  delay(150);
  tone(pin, 440, 120);
  delay(150);
  tone(pin, 392, 120);
  delay(150);
  tone(pin, 262, 350);
  delay(400);
}

void cambiarPuertas()
{
  if (puertasAbiertas == 0)
  {
    abrirPuertas(0, 180);
    cancionAbrir(BUZZER);
  }
  else
  {
    cerrarPuertas(90, 90);
    cancionCerrar(BUZZER);
  }
}

void setup()
{
  pinMode(PIR_ENTRADA, INPUT);
  pinMode(PIR_SALIDA, INPUT);
  pinMode(FOCO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  servo1.attach(SERVO_1);
  servo2.attach(SERVO_2);

  cerrarPuertas(90, 90);
}

void loop()
{
  int movimientoEntrada;
  int movimientoSalida;

  detectarMovimiento(PIR_ENTRADA, movimientoEntrada);
  detectarMovimiento(PIR_SALIDA, movimientoSalida);

  if (movimientoEntrada == HIGH || movimientoSalida == HIGH)
  {
    prenderFoco(FOCO, HIGH);
    cambiarPuertas();
    delay(500);
  }
  else
  {
    prenderFoco(FOCO, LOW);
  }
}
