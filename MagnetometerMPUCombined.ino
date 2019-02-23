#include <QMC5883L.h>
#include<Wire.h>
const int MPU6050_addr=0x68;
int16_t AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;
int16_t AccXf,AccYf,AccZf,Tempf,GyroXf,GyroYf,GyroZf;

QMC5883L compass;

void setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  compass.init();
  compass.setSamplingRate(50);
  Serial.begin(9600);
}

void loop()
{
  
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  AccX=Wire.read()<<8|Wire.read();
  AccY=Wire.read()<<8|Wire.read();
  AccZ=Wire.read()<<8|Wire.read();
  Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
  AccXf=AccX/16384;
  AccYf=AccY/16384;
  AccZf=AccZ/16384;
  GyroXf=GyroX/131;
  GyroYf=GyroY/131;
  GyroZf=GyroZ/131;
  Serial.print("AccX = "); Serial.print(AccX);
  Serial.print(" || AccY = "); Serial.print(AccY);
  Serial.print(" || AccZ = "); Serial.print(AccZ);
  Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
  Serial.print(" || GyroX = "); Serial.print(GyroX);
  Serial.print(" || GyroY = "); Serial.print(GyroY);
  Serial.print(" || GyroZ = "); Serial.println(GyroZ);

  Serial.print("AccX = "); Serial.print(AccXf);
  Serial.print(" || AccY = "); Serial.print(AccYf);
  Serial.print(" || AccZ = "); Serial.print(AccZf);
  Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
  Serial.print(" || GyroX = "); Serial.print(GyroXf);
  Serial.print(" || GyroY = "); Serial.print(GyroYf);
  Serial.print(" || GyroZ = "); Serial.println(GyroZf);
  delay(100);
  int heading = compass.readHeading();
  Serial.println(heading);
  delay(500);
}
