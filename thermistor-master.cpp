/*
//------------------------------------------------//
Thermistor-master.cpp Arduino library for Thermistor
Created by Raphael Vittoz
V1.0  26/04/2017
// Released to the public domain
//------------------------------------------------//
Thank to :
https://www.worldofgz.com/electronique/recuperer-une-temperature-avec-un-arduino
https://github.com/p-v-o-s
*/

#include "Thermistor-master.h"
#include <Arduino.h>
#include <math.h>

CThermistor::CThermistor(double A, double B, double C, double D) {
	m_A = A;
	m_B = B;
	m_C = C;
	m_D = D;
}

void CThermistor :: begin(uint8_t InputPin, double TypeOfThermoresistor) {
	m_Rref = TypeOfThermoresistor;
	m_analogPin = InputPin;
	pinMode(m_analogPin, INPUT);
}

double CThermistor::readVoltage() {
	//Calcul de la tension sur la borne analogique
	double V = 0;
	double valeurAnalog = analogRead(m_analogPin);
	return  V = (valeurAnalog / 1024)* V_IN;	 
}
double CThermistor::readResistance() {
	//Calcul de la résistance de la Thermistor
	double V = readVoltage();
	double Rth = (m_Rref * V) / (V_IN - V);
	return Rth;
}
double CThermistor::readTemperatureC() {
	//Calcul de la temperature en °C
	double TempC = 0;
	double R = readResistance();
	double logR = log(R / m_Rref);
	double TempK = pow(m_A + (m_B * logR) + (m_C * pow(logR, 2)) + (m_D * pow(logR, 3)),-1);
	return TempC = TempK - 273.15;
}

double CThermistor::readTemperatureK() {	
	//Calcul de la temperature en K

	double R = readResistance();
	double logR = log(R / m_Rref);
	double TempK = pow(m_A + (m_B * logR) + (m_C * pow(logR, 2)) + (m_D * pow(logR, 3)), -1);
	return TempK;
}

