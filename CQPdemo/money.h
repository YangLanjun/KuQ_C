#pragma once
#ifndef MONEY_H
#define MONEY_H
#include"cfg_file.h"
#include"FunctionConvert.h"
using namespace std;
int readmoney(int64_t fromQQ, int64_t fromGroup)
{
	int m = 0;
	string qq = setqq_str(fromQQ);
	string path = "files\\usersmoney" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), qq, m);
	return m;
}
void getmoney(int64_t fromQQ, int64_t fromGroup, int addm)
{
	int currentmoney=0;
	string qq = setqq_str(fromQQ);
	string path = "files\\usersmoney" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), qq, currentmoney);
	string m = To_Str(currentmoney + addm);
	writeConfigFile(path.c_str(), qq, m);
}
void losemoney(int64_t fromQQ, int64_t fromGroup,int subm)
{
	int currentmoney=0;
	string qq = setqq_str(fromQQ);
	string path = "files\\usersmoney" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), qq, currentmoney);
	int aftersubm = currentmoney - subm;
	if (aftersubm < 0)
		aftersubm = 0;
	string m = To_Str(aftersubm);
	writeConfigFile(path.c_str(), qq, m);
}
#endif // !MONEY_H