#pragma once
#ifndef CALCULATE_H
#define CALCULATE_H
#include "FunctionConvert.h"
using namespace std;
int getOperator(string smsg)
{
	int choice = 0;
	size_t pos = string::npos;
	pos = smsg.find('+');
	choice = 1;

	if (pos == string::npos)
	{
		pos = string::npos;
		pos = smsg.find('-');
		choice = 2;	
		if (pos == string::npos)
		{
			pos = string::npos;
			pos = smsg.find('*');
			choice = 3;
			if (pos == string::npos)
			{
				pos = string::npos;
				pos = smsg.find('/');
				choice = 4;
				if (pos == string::npos)
					return 0;
			}
		}
	}
	return choice;
}

string calculateFunction(int choice,wsmatch ms)
{
	wstring wstr1(_T(""));
	wstring wstr2(_T(""));
	string str1;
	string str2;
	wstr1 = ms.str(1);
	wstr2 = ms.str(2);
	str1 = wstos(wstr1);
	str2 = wstos(wstr2);
	double num1 = stod(str1);
	double num2 = stod(str2);
	string result;
	if (choice == 1)
		result = To_Strd(num1 + num2);
	else if (choice == 2)
		result = To_Strd(num1 - num2);
	else if (choice == 3)
		result = To_Strd(num1 * num2);
	else if (choice == 4)
	{
		if (num2 == 0)
		{
			result = "error!";
				return result;
		}
		else
		{
			std::stringstream ss;
			ss << num1 / num2;
			result = ss.str();
		}
	}
	return result;
}
 
#endif // !CALCULATE_H

