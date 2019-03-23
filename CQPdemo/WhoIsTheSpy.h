#pragma once
#ifndef WHOISTHESPY_H
#define WHOISTHESPY_H
#include"cfg_file.h"
#include "FunctionConvert.h"
#include"Games.h"
void set_game1(int64_t fromGroup)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "谁是卧底游戏", "是");
}

bool game1(int64_t fromGroup)
{
	string x = "否";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "谁是卧底游戏", x);
	if (x == "是")
		return true;
	else
		return false;
}
	void getWordGroup(int64_t fromGroup)
	{
		srand(time(NULL));
		int x = 1 + rand() % 600;
		string value;
		readConfigFileU_to_str("files\\WhoIsTheSpy.cfg", To_Str(x), value);
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		writeConfigFile(path.c_str(), "游戏词组", value);

	}
	
	
	int getciviliav_numbers(int64_t fromGroup)
	{
		int x = 0;
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		readConfigFile(path.c_str(), "平民数量", x);
		return x;
	}
	void setciviliav(int64_t fromGroup, int x)
	{
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		writeConfigFile(path.c_str(), "平民数量", To_Str(x ));
	}
	void subciviliavg(int64_t fromGroup)
	{
		int x = 0;
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		readConfigFile(path.c_str(), "平民数量", x);
		writeConfigFile(path.c_str(), "平民数量", To_Str(x -1));
	
	}
	int getspy_numbers(int64_t fromGroup)
	{
		int x = 0;
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		readConfigFile(path.c_str(), "卧底数量", x);
		return x;
	}
	void setspy(int64_t fromGroup,int x)
	{
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";	
		writeConfigFile(path.c_str(), "卧底数量", To_Str(x ));
	}
	void subspy(int64_t fromGroup)
	{
		int x = 0;
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		readConfigFile(path.c_str(), "卧底数量", x);
		writeConfigFile(path.c_str(), "卧底数量", To_Str(x - 1));
	}
	int getblank_numbers(int64_t fromGroup)
	{
		int x = 0;
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		readConfigFile(path.c_str(), "空白数量", x);
		return x;
	}
	void setblank(int64_t fromGroup, int x)
	{
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		writeConfigFile(path.c_str(), "空白数量", To_Str(x));
	}
	void subblank(int64_t fromGroup)
	{
		int x = 0;
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		readConfigFile(path.c_str(), "空白数量", x);
		writeConfigFile(path.c_str(), "空白数量", To_Str(x - 1));
	}
	
	
	int getcreattime_1(int64_t fromGroup,int sendtime)
	{
		int time=sendtime;
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		readConfigFile(path.c_str(), "游戏创建时间_1", time);
		return time;
	}
	void setcreattime_1(int64_t fromGroup,int time)
	{
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		writeConfigFile(path.c_str(), "游戏创建时间_1", To_Str (time));
	}



	

	
	

	string getCommonRoles(int64_t fromQQ,int64_t fromGroup)
	{
		string CommonRoles;
		string QQ = setqq_str(fromQQ);
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		readConfigFile(path.c_str(), QQ,CommonRoles );
		return CommonRoles;
	}
#endif // !SHUISHIWIDI_H
