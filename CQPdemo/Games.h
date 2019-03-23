#pragma once
#ifndef GAMES_H
#define GAMES_H
#include "cfg_file.h"
#include"FunctionConvert.h"
#include "money.h"
#include"exp.h"
using namespace std;
void setCommonRoles(int64_t fromQQ, int64_t fromGroup, string s)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	string QQ = setqq_str(fromQQ);
	writeConfigFile(path.c_str(), QQ, s);
}
void resetvotes(int64_t fromGroup)  //重置所有票数
{
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	ofstream fileout(path.c_str(), ios::trunc);
	if (!fileout) {
		exit(0);
	}
	fileout.close();
}
void reset(int64_t fromGroup)//重置所有
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	ofstream fileout(path.c_str(), ios::trunc);
	if (!fileout) {
		exit(0);
	}
	fileout.close();

	path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	ofstream eout(path.c_str(), ios::trunc);
	if (!eout) {
		exit(0);
	}
	eout.close();

	resetvotes(fromGroup);
}

int getvotes(int64_t fromQQ, int64_t fromGroup)//获得一个玩家获得的总票数
{
	int x = 0;
	string QQ = setqq_str(fromQQ);
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), QQ, x);
	return x;
}
void setvotes(int64_t fromQQ, int64_t fromGroup)//将玩家获得票数+1
{
	string QQ = setqq_str(fromQQ);
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	int x = 0;
	readConfigFile(path.c_str(), QQ, x);
	writeConfigFile(path.c_str(), QQ, To_Str(x + 1));
}
int getvotes_total(int64_t fromGroup)//获得总投票数,判断是否所有玩家均以投票
{
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	int x = 0;
	readConfigFile(path.c_str(), "总投票数", x);
	return x;
}
void setvotes_total(int64_t fromGroup)//将总投票数加1
{
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	int x = 0;
	readConfigFile(path.c_str(), "总投票数", x);
	writeConfigFile(path.c_str(), "总投票数", To_Str(x + 1));
}
bool Judge_votes(int64_t fromQQ, int64_t fromGroup)//判断玩家是否投票
{
	string QQ = setqq_str(fromQQ) + "是否投票";
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	string s = "否";
	readConfigFile(path.c_str(), QQ, s);
	if (s == "是")
		return true;
	else
		return false;
}
void  setJudge_vote(int64_t fromQQ, int64_t fromGroup, string judge)//设置玩家已投票
{
	string QQ = setqq_str(fromQQ) + "是否投票";
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), QQ, judge);
}

bool judgeplayers(int64_t fromQQ, int64_t fromGroup) //判断玩家是否参与游戏或是否死亡
{
	string QQ = setqq_str(fromQQ);
	string path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	if (findkey(path.c_str(), QQ))
		return true;
	else
		return false;
}

string getplayers(int64_t fromGroup, string CommonRoles)//通过角色获得对应的QQ（str)
{
	string QQ = "无";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFileKey(path.c_str(), CommonRoles, QQ);
	return QQ;
}
void setroles(int64_t fromQQ, int64_t fromGroup, string roles)//设置玩家角色
{
	string path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), setqq_str(fromQQ), roles);
}
string getroles(int64_t fromQQ, int64_t fromGroup)//通过QQ获取玩家角色
{
	string path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	string roles = "空";
	readConfigFile(path.c_str(), setqq_str(fromQQ), roles);
	return roles;
}
int getplayer_numbers(int64_t fromGroup)//获取目前玩家总数
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "玩家数量", x);
	return x;
}
void addplayer(int64_t fromGroup)//增加一个玩家
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "玩家数量", x);
	writeConfigFile(path.c_str(), "玩家数量", To_Str(x + 1));
}
void subplayer(int64_t fromGroup)//减少一个玩家
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "玩家数量", x);
	writeConfigFile(path.c_str(), "玩家数量", To_Str(x - 1));
}
bool Game_creat(int64_t fromGroup)//判断是否有人创建房间
{
	string status = "否";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "游戏创建", status);
	if (status == "是")
		return true;
	else
		return false;
}
bool Game_start(int64_t fromGroup)//判断游戏是否已经开始
{
	string status = "否";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "游戏开始", status);
	if (status == "是")
		return true;
	else
		return false;
}

//魔法数游戏
void setmagicNumber_status(int64_t fromQQ, int64_t fromGroup,string str)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), setqq_str(fromQQ), str);
}

bool getmagicNumber_status(int64_t fromQQ, int64_t fromGroup)
{
	string status = "否";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), setqq_str(fromQQ), status);
	if (status == "是")
		return true;
	else
		return false;
}
void setmagicNumber_time(int64_t fromQQ, int64_t fromGroup, int sendtime)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), setqq_str(fromQQ)+"time", To_Str(sendtime));
}

int getmagicNumber_time(int64_t fromQQ, int64_t fromGroup)
{
	int time = 0;
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), setqq_str(fromQQ) + "time", time);
	return time;
}

void setmagicNumber_num(int64_t fromQQ, int64_t fromGroup, int num)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), setqq_str(fromQQ) + "num", To_Str(num));
}

int getmagicNumber_num(int64_t fromQQ, int64_t fromGroup)
{
	int num = 0;
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), setqq_str(fromQQ) + "num", num);
	return num;
}

void setmagicNumber_times(int64_t fromQQ, int64_t fromGroup, int num)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), setqq_str(fromQQ) + "times", To_Str(num));
}

void submagicNumber_times(int64_t fromQQ, int64_t fromGroup)
{
	int num = 0;
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), setqq_str(fromQQ) + "times", num);
	writeConfigFile(path.c_str(), setqq_str(fromQQ) + "times", To_Str(num-1));
}
int getmagicNumber_times(int64_t fromQQ, int64_t fromGroup)
{
	int num = 0;
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), setqq_str(fromQQ) + "times", num);
	return num;
}

void setChallenger(int64_t fromGroup, string QQ)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "挑战者", QQ);
}

void setBattle(int64_t fromGroup, string QQ)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "应战者", QQ);
}
bool Is_challenger(int64_t fromQQ, int64_t fromGroup)
{
	string challenger = "0000";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "挑战者",challenger);
	if (To_Int64(challenger)==fromQQ)
		return true;
	else
		return false;
}

bool Is_battle(int64_t fromQQ, int64_t fromGroup)
{
	string battle = "0000";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "应战者", battle);
	if (To_Int64(battle) == fromQQ)
		return true;
	else
		return false;
}

string getChallenger(int64_t fromGroup)
{
	string challenger = "0000";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "挑战者", challenger);
	return challenger;
}

string getBattle(int64_t fromGroup)
{
	string battle = "0000";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "应战者", battle);
	return battle;
}
//猜数游戏
void setNumberGuessing_status(int64_t fromQQ, int64_t fromGroup, string str)
{
	string path = "files\\NumberGuessing" + setqq_str(fromGroup) + ".cfg";;
	writeConfigFile(path.c_str(), setqq_str(fromQQ), str);
}

bool getNumberGuessing_status(int64_t fromQQ, int64_t fromGroup)
{
	string status = "否";
	string path = "files\\NumberGuessing" + setqq_str(fromGroup) + ".cfg";;
	readConfigFile(path.c_str(), setqq_str(fromQQ), status);
	if (status == "是")
		return true;
	else
		return false;
}

void setChallenger_time( int64_t fromGroup, int sendtime)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "挑战时间", To_Str(sendtime));
}

int getChallenger_time(int64_t fromGroup)
{
	int time = 0;
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "挑战时间", time);
	return time;
}
#endif // ! Games_h

