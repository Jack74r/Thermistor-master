/*
//---------------Simple Example------------------//
Library : thermistor-master.h
SimpleThermistor.ino Arduino library for Thermistor
Created by Raphael Vittoz 
V1.0  26/04/2017
// Released to the public domain
//------------------------------------------------//
Sensor    |    Reference |    Operating
Type      |   Resistance  | Range (recommanded)
1.8K      |   1.8 KΩ    | 25 °C -55 to 150 °C
2.2K      |   2.2 KΩ    | 25 °C -55 to 150 °C
3K*       |   3 KΩ      | 25 °C -55 to 150 °C
3.3K      |   3.3 KΩ    | 25 °C -55 to 150 °C
10K     |   10 KΩ     | 25 °C -55 to 150 °C
20K       |   20 KΩ     | 25 °C -55 to 150 °C
47K       |   47 KΩ     | 25 °C -55 to 150 °C
50K       |   50 KΩ     | 25 °C -80 to 150 °C
100K      |   100 KΩ    | 25 °C -55 to 150 °C
//------------------------------------------------//
Simple Example

Example 100k Sensor -> 100k resistance reference and my datasheet 100k=25°C
With library -> At 25.00°C = 100k = 2.50V  => DONE ;)
! VCC = 5V !
Help : https://www.worldofgz.com/electronique/recuperer-une-temperature-avec-un-arduino/ (fr)
     : https://learn.adafruit.com/thermistor/using-a-thermistor (en)
//--------------look your datasheet----------------//
double A_1 = 3.354016E-3;
double B_1 = 2.569850E-4;
double C_1 = 2.620131E-6;
double D_1 = 6.383091E-8;
//------------------------------------------------//
*/

#include <thermistor-master.h>


double A_1 = 3.354016E-3;
double B_1 = 2.569850E-4;
double C_1 = 2.620131E-6;
double D_1 = 6.383091E-8;
//
uint8_t ANALOG_INPIN = A0;
double TypeOfThermoresistor = 100000.0; //For example 100k Sensor , Choose your sensor.
//
CThermistor myFirstThermo(A_1, B_1, C_1, D_1);


void setup()
{
  Serial.begin(9600); 
  myFirstThermo.begin(ANALOG_INPIN, TypeOfThermoresistor);

}

void loop()
{
  double V = myFirstThermo.readVoltage();
  double R = myFirstThermo.readResistance();
  double Tc = myFirstThermo.readTemperatureC(); 
  double Tk = myFirstThermo.readTemperatureK();
  Serial.println("----------------------");
  Serial.print("Voltage: ");
  Serial.print(V);
  Serial.println("V");

  Serial.print("Resistance: ");
  Serial.print(R);
  Serial.println(" Omh");

  Serial.print("TemperatureC: ");
  Serial.print(Tc); 
  Serial.println("*C");

  Serial.print("TemperatureK: ");
  Serial.print(Tk);
  Serial.println("K");

  delay(1000);
}

