#define Pulse 7
#define Pulsen 6
#define Dir 5
#define Dirn 4
#define En 3
#define Enn 2


char a;
long delay_Micros =1800; // Set value
long currentMicros = 0; long previousMicros = 0;

void setup()

{
  pinMode(Pulse,OUTPUT);
  pinMode(Dir,OUTPUT);
  pinMode(En,OUTPUT);
  pinMode(Enn,OUTPUT);
  pinMode(Dirn,OUTPUT);
  pinMode(Pulsen,OUTPUT);
  
  Serial.begin(9600); 
  digitalWrite(En,LOW);
  digitalWrite(Dir,LOW);//8 microstep
  digitalWrite(Enn,LOW);
  digitalWrite(Dirn,HIGH);
  digitalWrite(Pulsen,LOW);
  digitalWrite(Pulse,HIGH);
}

void loop()

{   
    
    analogWrite(Pulse,150);    
    delayMicroseconds(1000); //Set Value
    digitalWrite(Pulse,LOW);
    a=Serial.read();
    if(a=='a')
    {
      Serial.println('a');
      digitalWrite(Pulse,HIGH);
    }
    else if(a=='s')
    {
      Serial.println('s');
      digitalWrite(Pulse,LOW);
    }
    
} 
