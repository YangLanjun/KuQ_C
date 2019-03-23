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
void resetvotes(int64_t fromGroup)  //��������Ʊ��
{
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	ofstream fileout(path.c_str(), ios::trunc);
	if (!fileout) {
		exit(0);
	}
	fileout.close();
}
void reset(int64_t fromGroup)//��������
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

int getvotes(int64_t fromQQ, int64_t fromGroup)//���һ����һ�õ���Ʊ��
{
	int x = 0;
	string QQ = setqq_str(fromQQ);
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), QQ, x);
	return x;
}
void setvotes(int64_t fromQQ, int64_t fromGroup)//����һ��Ʊ��+1
{
	string QQ = setqq_str(fromQQ);
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	int x = 0;
	readConfigFile(path.c_str(), QQ, x);
	writeConfigFile(path.c_str(), QQ, To_Str(x + 1));
}
int getvotes_total(int64_t fromGroup)//�����ͶƱ��,�ж��Ƿ�������Ҿ���ͶƱ
{
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	int x = 0;
	readConfigFile(path.c_str(), "��ͶƱ��", x);
	return x;
}
void setvotes_total(int64_t fromGroup)//����ͶƱ����1
{
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	int x = 0;
	readConfigFile(path.c_str(), "��ͶƱ��", x);
	writeConfigFile(path.c_str(), "��ͶƱ��", To_Str(x + 1));
}
bool Judge_votes(int64_t fromQQ, int64_t fromGroup)//�ж�����Ƿ�ͶƱ
{
	string QQ = setqq_str(fromQQ) + "�Ƿ�ͶƱ";
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	string s = "��";
	readConfigFile(path.c_str(), QQ, s);
	if (s == "��")
		return true;
	else
		return false;
}
void  setJudge_vote(int64_t fromQQ, int64_t fromGroup, string judge)//���������ͶƱ
{
	string QQ = setqq_str(fromQQ) + "�Ƿ�ͶƱ";
	string path = "files\\Game_votes" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), QQ, judge);
}

bool judgeplayers(int64_t fromQQ, int64_t fromGroup) //�ж�����Ƿ������Ϸ���Ƿ�����
{
	string QQ = setqq_str(fromQQ);
	string path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	if (findkey(path.c_str(), QQ))
		return true;
	else
		return false;
}

string getplayers(int64_t fromGroup, string CommonRoles)//ͨ����ɫ��ö�Ӧ��QQ��str)
{
	string QQ = "��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFileKey(path.c_str(), CommonRoles, QQ);
	return QQ;
}
void setroles(int64_t fromQQ, int64_t fromGroup, string roles)//������ҽ�ɫ
{
	string path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), setqq_str(fromQQ), roles);
}
string getroles(int64_t fromQQ, int64_t fromGroup)//ͨ��QQ��ȡ��ҽ�ɫ
{
	string path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	string roles = "��";
	readConfigFile(path.c_str(), setqq_str(fromQQ), roles);
	return roles;
}
int getplayer_numbers(int64_t fromGroup)//��ȡĿǰ�������
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "�������", x);
	return x;
}
void addplayer(int64_t fromGroup)//����һ�����
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "�������", x);
	writeConfigFile(path.c_str(), "�������", To_Str(x + 1));
}
void subplayer(int64_t fromGroup)//����һ�����
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "�������", x);
	writeConfigFile(path.c_str(), "�������", To_Str(x - 1));
}
bool Game_creat(int64_t fromGroup)//�ж��Ƿ����˴�������
{
	string status = "��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��Ϸ����", status);
	if (status == "��")
		return true;
	else
		return false;
}
bool Game_start(int64_t fromGroup)//�ж���Ϸ�Ƿ��Ѿ���ʼ
{
	string status = "��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��Ϸ��ʼ", status);
	if (status == "��")
		return true;
	else
		return false;
}

//ħ������Ϸ
void setmagicNumber_status(int64_t fromQQ, int64_t fromGroup,string str)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), setqq_str(fromQQ), str);
}

bool getmagicNumber_status(int64_t fromQQ, int64_t fromGroup)
{
	string status = "��";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), setqq_str(fromQQ), status);
	if (status == "��")
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
	writeConfigFile(path.c_str(), "��ս��", QQ);
}

void setBattle(int64_t fromGroup, string QQ)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "Ӧս��", QQ);
}
bool Is_challenger(int64_t fromQQ, int64_t fromGroup)
{
	string challenger = "0000";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��ս��",challenger);
	if (To_Int64(challenger)==fromQQ)
		return true;
	else
		return false;
}

bool Is_battle(int64_t fromQQ, int64_t fromGroup)
{
	string battle = "0000";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "Ӧս��", battle);
	if (To_Int64(battle) == fromQQ)
		return true;
	else
		return false;
}

string getChallenger(int64_t fromGroup)
{
	string challenger = "0000";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��ս��", challenger);
	return challenger;
}

string getBattle(int64_t fromGroup)
{
	string battle = "0000";
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "Ӧս��", battle);
	return battle;
}
//������Ϸ
void setNumberGuessing_status(int64_t fromQQ, int64_t fromGroup, string str)
{
	string path = "files\\NumberGuessing" + setqq_str(fromGroup) + ".cfg";;
	writeConfigFile(path.c_str(), setqq_str(fromQQ), str);
}

bool getNumberGuessing_status(int64_t fromQQ, int64_t fromGroup)
{
	string status = "��";
	string path = "files\\NumberGuessing" + setqq_str(fromGroup) + ".cfg";;
	readConfigFile(path.c_str(), setqq_str(fromQQ), status);
	if (status == "��")
		return true;
	else
		return false;
}

void setChallenger_time( int64_t fromGroup, int sendtime)
{
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "��սʱ��", To_Str(sendtime));
}

int getChallenger_time(int64_t fromGroup)
{
	int time = 0;
	string path = "files\\MagicNumber" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��սʱ��", time);
	return time;
}
#endif // ! Games_h

