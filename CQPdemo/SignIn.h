#pragma once
#ifndef SIGNIN_H
#define SIGNIN_H
#include <iostream>
#include<ctime>
#include"cfg_file.h"
#include "FunctionConvert.h"
using namespace std;
//CTime t = CTime::GetCurrentTime();
//int day = t.GetDay(); //获得签到日期 
bool Judge_SignIn(const int64_t fromqq, int64_t fromGroup, int today,int &times)
{
	string QQ = setqq_str(fromqq);
	int date = 0;
	string path = "files\\SignIn_Time" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), QQ, date);
	path = "files\\SignIntimes" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), QQ, times);
	if (date == today)
		return 0;
	else
	{
		string DATE = To_Str(today);
		path = "files\\SignIn_Time" + setqq_str(fromGroup) + ".cfg";
		writeConfigFile(path.c_str(), QQ, DATE);

		string Times = To_Str(times+1);
		path = "files\\SignIntimes" + setqq_str(fromGroup) + ".cfg";
		writeConfigFile(path.c_str(), QQ, Times);
		readConfigFile(path.c_str(), QQ, times);
		return 1;
	}
}
#endif