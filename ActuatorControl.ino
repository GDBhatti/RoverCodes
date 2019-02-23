const int relay1 = 6;   //Arduino pin that triggers relay #1
const int relay2 = 7;   //Arduino pin that triggers relay #2

void setup() {
  //Set pinMode to OUTPUT for the two relay pins
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
}

void extendActuator() {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
}

void retractActuator() {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, HIGH);
}

void stopActuator() {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
}

void loop() 
{
    extendActuator();
    delay(1000);

    stopActuator();
    delay(1000);

    retractActuator();
    delay(1000);

    stopActuator();
    delay(5000);
}
