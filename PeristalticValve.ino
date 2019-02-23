
const int motor= 13; //LED connected to digital pin 10
char inputi='0';

void setup()
{
pinMode(motor, OUTPUT); //sets the digital pin as output
Serial.begin(9600);
Serial.println("Ready");
}

void loop()
{
  while(Serial.available())
  {
  inputi=(char)Serial.read();
  if(inputi=='a')
  {
    Serial.println("Drip Drip");
    digitalWrite(motor,HIGH);
    delay(1000);
    digitalWrite(motor,LOW);
  }
  }
  delay(100);
}
  
