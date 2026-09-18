#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>

#define boton 2
#define ROJO 13
#define VERDE 12
#define AZUL 8
#define buzzer 3

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220

const int midi1[10][3] = {
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 115},
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

Servo servo1;
Adafruit_LiquidCrystal lcd1(0);

void setup()
{
  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  servo.1(attach(servo1))
  servo1.write(0);
  lcd1.begin(16, 2);
  serial.begin(9600);
}


void abrir(){
  if (boton == HIGH)
  {
    servo1.write(90);
    lcd1.setCursor(0,0);
    lcd1.print("Servo moviendose");
    delay(1000);
    lcd1.clear();
    delay(1000)
    playMidi(buzzer, midi1, ARRAY_LEN(midi1));
    lcd1.print("Melodía");
  }
}
void cerrar(){
  if (boton == LOW)
  {
    servo1.write(0);
  }
}

void loop()
{
  digitalWrite(ROJO, HIGH);
  delay(1000);
  digitalWrite(ROJO, LOW);
  delay(1000);
}

