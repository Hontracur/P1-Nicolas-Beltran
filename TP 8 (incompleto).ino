#define ROJO 11
#define AZUL 10
#define VERDE 9
#define POT A0
#define FACTOR 3

int numeros[] = {10,20,30};
int resultado[3];

void setup()
{
  Serial.begin(9600);
  
  for (int i = 0; i < 3; i++)
  {
    resultado[i]+resultado[i]* FACTOR;
  }
  
  pinMode(ROJO, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(VERDE, OUTPUT);
}

void loop()
{
  
int valorPot = map(analogRead(POT), 0, 1023, 0, 100);

  if (valorPot >= 0 && valorPot <= 20) {

    for (int i = 0; i < 3; i++)
    {
      
      Serial.println(resultado[i]);
      
      analogWrite(ROJO, resultado[i]);
      analogWrite(VERDE, resultado[i]);
      analogWrite(AZUL, resultado[i]);

      delay(1000);

      analogWrite(ROJO, 0);
      analogWrite(VERDE, 0);
      analogWrite(AZUL, 0);

      delay(1000);
    }
  }
  else
  {
    analogWrite(ROJO, 0);
    analogWrite(VERDE, 0);
    analogWrite(AZUL, 0);
  }

  
}
