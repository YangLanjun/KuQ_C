#pragma once
#ifndef EXP_H
#define EXP_H
#include"cfg_file.h"
#include"FunctionConvert.h"
using namespace std;
int readexp(int64_t fromQQ, int64_t fromGroup)
{
	int e = 0;
	string qq = setqq_str(fromQQ);
	string path = "files\\usersexp" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), qq, e);
	return e;
}
void getexp(int64_t fromQQ,int64_t fromGroup, int adde)
{
	int currentexp=0;
	string qq = setqq_str(fromQQ);
	string path = "files\\usersexp" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), qq, currentexp);
	string e = To_Str(currentexp + adde);
	writeConfigFile(path.c_str(), qq, e);
}

#endif // !exp_H
