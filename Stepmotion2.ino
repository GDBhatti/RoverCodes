word  X;
word NX;
int D=0;
int MoveSpeed=2000; //step in Microseconds
String     inputString = "help\n"; // a string to hold incoming data
boolean stringComplete = true;     // whether the string is completet
boolean        ComData = false;    // whether com data is on when motors are moving will slow them down

# define X_ENgnd  2 //ENA-(ENA) stepper motor enable , active low     Gray 
# define X_EN_5v  3 //ENA+(+5V) stepper motor enable , active low     Orange
# define X_DIRgnd 4 //DIR-(DIR) axis stepper motor direction control  Blue
# define X_DIR_5v 5 //DIR+(+5v) axis stepper motor direction control  Brown
# define X_STPgnd 6 //PUL-(PUL) axis stepper motor step control       Black
# define X_STP_5v 7 //PUL+(+5v) axis stepper motor step control       RED


void serialEvent()// ********************************************************      Serial in
{ while (Serial.available()) 
  {
    char inChar = (char)Serial.read();            // get the new byte:
    if (inChar > 0)     {inputString += inChar;}  // add it to the inputString:
    if (inChar == '\n') { stringComplete = true;} // if the incoming character is a newline, set a flag so the main loop can do something about it: 
  }
}

void MoveX(){

 inputString.setCharAt(0,' ');
 NX=inputString.toInt();
 Serial.print("NX=");
 Serial.println(NX);
 inputString="";
 int xt=1;
 if (D==1)
 {digitalWrite (X_DIR_5v,LOW);}
 else if (D==0)
 {digitalWrite (X_DIR_5v,HIGH);}
 X=0;
 for (X=0; X != NX; X=X+xt)
 {    digitalWrite (X_STP_5v, HIGH);
      delayMicroseconds (MoveSpeed);
      digitalWrite (X_STP_5v, LOW);
      delayMicroseconds (MoveSpeed);
      Serial.println(X);
      Serial.println(NX);
 }
 Serial.print("X=");
 Serial.println(X);
 //X=NX;

 inputString="";
}

void ENAXON(){ // *************************************************************   ENAXON
 Serial.println("ENAXON");
 digitalWrite (X_EN_5v, LOW);//ENA+(+5V) low=enabled
 inputString="";
}
void ENAXOFF(){  // ***********************************************************   ENAXOFF
 Serial.println("ENAXOFF");
 digitalWrite (X_EN_5v, HIGH);//ENA+(+5V) low=enabled
 inputString="";
}

void DIRC(){
  if (D==1)
  {
    D=0;
  }
  else{
    D=1;
  }
  Serial.print("D=");
  Serial.println(D);
}
void Help(){ // **************************************************************   Help
 Serial.println("Commands step by step guide");
 Serial.println("Type hello -sends TB6600 Tester Ready ");
 Serial.println("Type xon  -turns TB6600 on");
 Serial.println("Type x+Number(0-60000) eg x1904 -to set next move steps");
 Serial.println("Type mx -to make motor move to next postion");
 Serial.println("Type cdon -turns on postion data when moving will increase time of step");
 Serial.println("Type x0");
 Serial.println("Type mx");
 Serial.println("Type s+Number(0-2000) eg s500 -to set Microseconds betwean steps");
 Serial.println("Type s2000");
 Serial.println("Type x300");
 Serial.println("Type mx");
 Serial.println("Type xoff -turns TB6600 off");
 Serial.println("Type cdoff -turns off postion data when moving");
 
 

 inputString="";
}

void setup() {
pinMode (X_ENgnd ,OUTPUT); //ENA-(ENA)
pinMode (X_EN_5v ,OUTPUT); //ENA+(+5V)
pinMode (X_DIRgnd,OUTPUT); //DIR-(DIR)
pinMode (X_DIR_5v,OUTPUT); //DIR+(+5v)
pinMode (X_STPgnd,OUTPUT); //PUL-(PUL)
pinMode (X_STP_5v,OUTPUT); //PUL+(+5v)
pinMode (13,OUTPUT);
digitalWrite (X_ENgnd,  LOW); //ENA-(ENA)
digitalWrite (X_EN_5v, HIGH); //ENA+(+5V) low=enabled
digitalWrite (X_DIRgnd, LOW); //DIR-(DIR)
digitalWrite (X_DIR_5v, LOW); //DIR+(+5v)
digitalWrite (X_STPgnd, LOW); //PUL-(PUL)000000000214111111111p
digitalWrite (X_STP_5v, LOW); //PUL+(+5v)

Serial.begin(115200);
}


void loop() {
 serialEvent(); 
 if (stringComplete) 
 {
  if (inputString=="dx\n")       {DIRC();} 
  if (inputString=="xon\n")       {ENAXON();}   
  if (inputString=="xoff\n")      {ENAXOFF();}
  if (inputString=="help\n")      {Help();}
  if (inputString.charAt(0)=='x')   {MoveX();}     
  inputString = ""; stringComplete = false; // clear the string:
 } }
