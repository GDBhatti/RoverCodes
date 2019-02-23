#define mL1 50
#define mL2 52
#define mR1 48
#define mR2 46

#define pwmL1 8
#define pwmL2 9
#define pwmR1 7
#define pwmR2 6

#define mL1b 30
#define mL2b 34
#define mR1b 32
#define mR2b 28

unsigned int H=120;
unsigned int L=60;
unsigned int N=50;

void forward()
{
  analogWrite(pwmL1,N);
  analogWrite(pwmL2,N);
  digitalWrite(mL1, LOW);
  digitalWrite(mL2, LOW);

      
  analogWrite(pwmR1,N);
  analogWrite(pwmR2,N);
  digitalWrite(mR1, LOW);
  digitalWrite(mR2, LOW);
}

void backward()
{
  analogWrite(pwmL1,N);
  analogWrite(pwmL2,N);
  digitalWrite(mL1, HIGH);
  digitalWrite(mL2, HIGH);

  analogWrite(pwmR1,N);
  analogWrite(pwmR2,N);
  digitalWrite(mR1, HIGH);
  digitalWrite(mR2, HIGH);
}

void right()
{
  analogWrite(pwmL1,H);
  analogWrite(pwmL2,H);
  analogWrite(pwmL1,100);
  digitalWrite(mL1, LOW);
  digitalWrite(mL2, LOW);

  analogWrite(pwmR1,L);
  analogWrite(pwmR2,L);
  digitalWrite(mR1, HIGH);
  digitalWrite(mR2, HIGH);
}

void left()
{
  analogWrite(pwmL1,L);
  analogWrite(pwmL2,L);
  digitalWrite(mL1, HIGH);
  digitalWrite(mL2, HIGH);

  analogWrite(pwmR1,H);
  analogWrite(pwmR2,H);
  digitalWrite(mR1, LOW);
  digitalWrite(mR2, LOW);
}

void halt()
{
  analogWrite(pwmL1,5);
  analogWrite(pwmL2,5);
  digitalWrite(mL1, LOW);
  digitalWrite(mL2, LOW);

  analogWrite(pwmR1,5);
  analogWrite(pwmR2,5);
  digitalWrite(mR1, LOW);
  digitalWrite(mR2, LOW);
}

void low()
{
  N=50;
  H=70;
  L=30;
}

void med()
{
  N=100;
  H=140;
  L=60;
}
void high()
{
  N=200;
  H=255;
  L=150;
}

void setup()
{
  pinMode(mL1, OUTPUT);
  pinMode(mL2, OUTPUT);
  pinMode(mR1, OUTPUT);
  pinMode(mR2, OUTPUT);
  pinMode(pwmL1, OUTPUT);
  pinMode(pwmR1, OUTPUT);
  pinMode(pwmL2, OUTPUT);
  pinMode(pwmR2, OUTPUT);

  pinMode(mL1b, OUTPUT);
  pinMode(mL2b, OUTPUT);
  pinMode(mR1b, OUTPUT);
  pinMode(mR2b, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available())
  {
    int In=Serial.read();
    switch (In)
    {
      case 0:   
          halt();
          break;
      case 8:
          forward(); 
          break;
      case 6:
          right();
          break;
      case 4:
          left();
          break;
      case 1:
          low();
          break;
      case 2:
          med();
      case 3:
          high();
      case 5:
          backward();
    }
  }
}
