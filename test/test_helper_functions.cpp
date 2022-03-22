#pragma once
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "HelperFunctions.h"

TEST(HelperFunctionTest, SplitTextTest)
{
	string input_text = "a,b,c,d";
	vector<string> splitted_text = split(input_text, ",");
	vector<string> expected_text = {"a","b","c","d"};
	
	ASSERT_EQ(expected_text, splitted_text);
}

TEST(HelperFunctionTest, SpliTextTestInvalid)
{
	string input_text = "abcd";
	vector<string> splitted_text = split(input_text, ",");
	vector<string> expected_text = {"abcd"};
	
	ASSERT_EQ(expected_text, splitted_text);
}


TEST(HelperFunctionTest, ConvertUpperTest)
{
	string upper_text = convertUpper("abcd", 4);	
	ASSERT_EQ("ABCD", upper_text);
}

TEST(HelperFunctionTest, ConvertUpperTest2)
{
	vector<string> data = {"abcdefgh","abcdeFGH", "ABCDEFGH"};
    for (vector<string>::iterator t=data.begin(); t!=data.end(); ++t) 
    {
        string upper_text = convertUpper(*t, 4);	
		EXPECT_EQ("ABCDefgh", upper_text);
    }
}


TEST(HelperFunctionTest, ConvertStrScNotation)
{
	vector<string> data = {"1.0E-10","1.0E-9","+1.0E-9","-1.0E-9","-5.23E-9"};
	vector<double> expected_data = {0.0000000001,0.000000001,0.000000001,-0.000000001,-0.00000000523};
	
	for (unsigned int i = 0; i < data.size(); i++) {
		double doubleValueObtained = convertStringScNotationToDouble(data[i]);
		EXPECT_EQ(doubleValueObtained, expected_data[i]);
	}
}