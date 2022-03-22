#pragma once
#include "SerialCommunication.h"

class MultimeterController: public SerialCommunication
{

public:
	MultimeterController(const char *portName);
	double MeasureFromDisplay(int displayNumber, string parameterToMeasure);
};