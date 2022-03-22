#pragma once
#include <gtest/gtest.h>
#include <iostream>

#include "MultimeterController.h"

#include "SerialConfig.h"
#include <windows.h>


class Multimeter : public ::testing::Test
{
protected:
	MultimeterController *MMeter;
	virtual void SetUp()
	{   
		MMeter = new MultimeterController(SerialConfig::portName);
	}

	virtual void TearDown()
	{
		delete MMeter;
	}
};

/*
struct MyTest: ::testing::Test {
    static void SetUpTestSuite() {
        
    }

    static void TearDownTestSuite() {
        
    }
};
*/


TEST_F(Multimeter, TakeMeasurement)
{
	for (int i = 0; i < 5; i++) {
		testing::internal::CaptureStderr();
		double current_measured = MMeter->MeasureFromDisplay(1, "Current:DC");
		std::string ErrorMsgOutput = testing::internal::GetCapturedStderr();
		
		std::string ErrorMsgCheck = "Warning";
		std::string ErrorMsgCheck2 = "ERROR";
		
		bool foundmsg = ((ErrorMsgOutput.find(ErrorMsgCheck) != std::string::npos) || (ErrorMsgOutput.find(ErrorMsgCheck2) != std::string::npos));

		EXPECT_TRUE(!foundmsg) << "Error Message is showing: "<< ErrorMsgOutput << endl;
		EXPECT_NEAR(current_measured, 0, 0.05);
		Sleep(3000);
		
		
	}
}

