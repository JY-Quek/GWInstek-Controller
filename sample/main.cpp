#include "MultimeterController.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const char *portName = "\\\\.\\COM6";

MultimeterController *MMeter;

int main(void)
{
  cout << "Method #1 of using" << endl;
  MMeter = new MultimeterController(portName);
  cout << MMeter->MeasureFromDisplay(1, "Voltage:AC") << endl;
  cout << MMeter->MeasureFromDisplay(1, "Current:DC") << endl;
  delete MMeter;
  
  cout << "Method #2 of using" << endl;
  MultimeterController MMeter2(portName);
  cout << MMeter2.MeasureFromDisplay(2, "Current:DC") << endl;
  
  
  
  return 0;
}

