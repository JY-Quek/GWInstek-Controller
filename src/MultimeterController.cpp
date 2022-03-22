#pragma once
#include "MultimeterController.h"
#include <iostream>
#include <sstream>
#include <string>

#include "HelperFunctions.h"

using namespace std;


MultimeterController::MultimeterController(const char *portName)
:SerialCommunication(portName)
{

}


double MultimeterController::MeasureFromDisplay(int displayNumber, string parameterToMeasure)
{
	string str_displayNumber = to_string(displayNumber);
	string parameterToSend = "";
	
	if (str_displayNumber == "1")
		str_displayNumber = "";
	
	// If ":" is in parameterToMeasure
	if (parameterToMeasure.find(":") != string::npos) {
		vector<string> vectorParameters = split(parameterToMeasure, ":");
		
		if (vectorParameters.size() == 2) {
			string valueToMeasure = convertUpper(vectorParameters[0], 4);
			string valueDescription;
			valueDescription = vectorParameters[1];
			parameterToSend = valueToMeasure + ":" + valueDescription;
		}
	} else {
		parameterToSend = convertUpper(parameterToMeasure, 4);
	} 
	string command_measure = "MEASure" + str_displayNumber + ":" + parameterToSend + "? 5;";
	
	
	char* char_arr = &command_measure[0]; // convert string to char
	MultimeterController::writeSerialPort(char_arr);
	
	string receivedString = MultimeterController::readSerialPort(5);
	double doubleValueObtained = convertStringScNotationToDouble(receivedString);
	return doubleValueObtained;
}