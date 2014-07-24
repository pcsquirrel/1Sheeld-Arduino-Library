/*

  Project:       1Sheeld Library 
  File:          DataLogger.cpp
                 
  Version:       1.0.1

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.7

*/
#include "OneSheeld.h"
#include "DataLoggerShield.h"


//Start Logging Data
void DataLoggerShield::startLogging()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,START_LOG,0);
}
//Start Logging Data giving name to file created 
void DataLoggerShield::startLogging(char * fileName)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,START_LOG,1,new FunctionArg(strlen(fileName),(byte *)fileName));
}

//Stop Logging Data
void DataLoggerShield::stopLogging()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,STOP_LOG,0);
}

//Set File Format whether JSON or CSV
void DataLoggerShield::setFileFormat(byte format)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,SET_FORMAT,1,new FunctionArg(1,&format));
}

//Log Data
void DataLoggerShield::log(int key,float value,int decimalAfterPoint)
{
	char floattostring[10]={0};
	char inttostring [5]={0};
	dtostrf(value,10,decimalAfterPoint,floattostring);
	itoa(key,inttostring,10);

	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOG_DATA,2,new FunctionArg(5,(byte *)inttostring),new FunctionArg(10,(byte*)floattostring));
}
//Log Data
void DataLoggerShield::log(char * key,float value,int decimalAfterPoint)
{
	char floattostring[10]={0};
	dtostrf(value,10,decimalAfterPoint,floattostring);

	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOG_DATA,2,new FunctionArg(strlen(key),(byte *)key),new FunctionArg(10,(byte*)floattostring));
}
//Instantiating Object
DataLoggerShield Logger;