#define R 6
#define A 5
#define sensor 3
#define boton 
void setup()
{
  pinMode(R, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(boton, OUTPUT);
  pinMode(sensor, OUTPUT);
}

void loop()
{
    analogWrite(R, 255);
    analogWrite(A, 255);
}
}
