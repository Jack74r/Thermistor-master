/*
//------------------------------------------------//
Thermistor-master.h Arduino library for Thermistor
Created by Raphael Vittoz
V1.0  26/04/2017
// Released to the public domain
//------------------------------------------------//
Thank to :
https://www.worldofgz.com/electronique/recuperer-une-temperature-avec-un-arduino 
https://github.com/p-v-o-s
*/
#ifndef Thermistor.h
#define Thermistor.h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define V_IN  5.0 //Tension du pont diviseur 


class CThermistor
{
public:
	CThermistor(double A, double B, double C, double D);
	void begin(uint8_t InputPin, double TypeOfThermoresistor);
	double readVoltage();
	double readResistance();
	double readTemperatureC();
	double readTemperatureK();
	
private:
	double m_A;
	double m_B;
	double m_C;
	double m_D;
	double m_Rref;
	uint8_t m_Type;
	uint8_t m_analogPin;
};

#endif

