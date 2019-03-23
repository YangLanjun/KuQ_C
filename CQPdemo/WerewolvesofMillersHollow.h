#pragma once
#ifndef WEREWOLVESOFMILLERSHOLLOW_H
#define WEREWOLVESOFMILLERSHOLLOW_H
#include"Games.h"
using namespace std;
 
void set_game2(int64_t fromGroup)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "����ɱ��Ϸ", "��");
}

bool game2(int64_t fromGroup)
{
	string x = "��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "����ɱ��Ϸ", x);
	if (x == "��")
		return true;
	else
		return false;
}
int getwerewolves_numbers(int64_t fromGroup)
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��������", x);
	return x;
}
void setwerewolves(int64_t fromGroup, int x)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "��������", To_Str(x));
}
void subwerewolves(int64_t fromGroup)
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��������", x);
	writeConfigFile(path.c_str(), "��������", To_Str(x - 1));

}
int getvillager_numbers(int64_t fromGroup)
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��������", x);
	return x;
}
void setvillager(int64_t fromGroup, int x)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "��������", To_Str(x));
}
void subvillager(int64_t fromGroup)
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��������", x);
	writeConfigFile(path.c_str(), "��������", To_Str(x - 1));
}

bool hunter_live(int64_t fromGroup)
{
	string str="��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "���˴��", str);
	if (str=="��")
		return true;
	else
		return false;
}
void sethunter_die(int64_t fromGroup, string s)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "���˴��", s);
}

bool witch_live(int64_t fromGroup)
{
	string str="��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "Ů�״��", str);
	if (str == "��")
		return true;
	else
		return false;
}
void setwitch_die(int64_t fromGroup, string s)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "Ů�״��", s);
}


bool seer_live(int64_t fromGroup)
{
	string str="��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "Ԥ�ԼҴ��", str);
	if (str == "��")
		return true;
	else
		return false;
}
void setseer_die(int64_t fromGroup,string s)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "Ԥ�ԼҴ��", s);
}


void setSheriff(int64_t fromGroup,string qq)
{
	
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "����", qq);
}

bool judge_haveSheriff(int64_t fromGroup)
{
	string have = "��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "����",have);
	if (have != "��")
		return true;
	else
		return false;
}
bool judgeSheriff(int64_t fromQQ, int64_t fromGroup)
{
	string QQ;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "����", QQ);
	if (QQ == setqq_str(fromQQ))
		return true;
	else
		return false;
}
bool judge_roles(int64_t fromQQ, int64_t fromGroup, const string role)
{
	string QQ[4];
	int num = getwerewolves_numbers(fromGroup);
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	getkey_withStr(path.c_str(), QQ, num, role);
	for (int i = 0; i < num; i++)
	{
		if (QQ[i] == setqq_str(fromQQ))
			return true;
	}
		return false;
}



void setWitch_buff(int64_t fromGroup)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "Ů��Buff", "��");
}

bool judgeWitch_buff(int64_t fromGroup)
{
	string judge="��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "Ů��Buff", judge);
	if (judge == "��")
		return true;
	else
		return false;
}

int getcreattime_2(int64_t fromGroup,int sendtime)
{
	int time = sendtime;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��Ϸ����ʱ��_2", time);
	return time;
}
void setcreattime_2(int64_t fromGroup, int time)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "��Ϸ����ʱ��_2", To_Str(time));
}

bool judge_Whoseturn(int64_t fromGroup, const string whose)
{
	string turn;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��ǰ�غ�", turn);
	if (turn == whose)
		return true;
	else
		return false;
}

void setWhoseturn(int64_t fromGroup, string str)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "��ǰ�غ�", str);
}


//����ɱ�����ɫ
int choose_set_role2(int x,int &count0, int &count1, int &count2, int &count3, int &count4, int num ,int m,int n)
{
	
	if (x <= 9 && count1 < num - m)
	{
		count1++;
		return 1;
	}
	if (x > 9 && x <= 12 && count0 < n)
	{
		count0++;
		return 0;

	}
	if (x == 13 && count4 < 1)
	{
		count4++;
		return 4;
	}
	if (x == 14 && count2 < 1)
	{
		count2++;
		return 2;
	}
	if (x == 15 && count3 < 1)
	{
		count3++;
		return 3;
	}
	return 5;
}

//��������ɱ�˺���,����,��ȡ��ɱ���
string judge_Wusebuff(int64_t fromQQ, int64_t fromGroup,int killnumber)
{
	string result;
		if (judge_Whoseturn(fromGroup, "����ɱ��") && judge_roles(fromQQ, fromGroup, "����")&&!Judge_votes(fromQQ,fromGroup))
		{
			int num = getplayer_numbers(fromGroup);
			string players[18];
			string path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);
			if (killnumber <= num)
			{
				setvotes(To_Int64(players[killnumber - 1]), fromGroup);
				setvotes_total(fromGroup);
				setJudge_vote(fromQQ, fromGroup,"��");
				result = "[CQ:emoji,id=9989]ͶƱ�ɹ�";
				return result;
			}
			else return "error";
		}
		else
		{
			result = "[CQ:emoji,id=8252]�������˻غ��ڻ������ݲ���,error!";
			return result;
		}
}
void set_killed(int64_t fromGroup,string player)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "��ɱ���", player);
}
string get_killed(int64_t fromGroup)
{
	string who="0";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��ɱ���", who);
	return who;
}

//����ɱ��ϷͶƱ
string votes(int64_t fromQQ, int64_t fromGroup, string smsg,int &hunterdie)
{
	int num = getplayer_numbers(fromGroup);
	string players[18];
	string path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	getkey(path.c_str(), players, num);
	string reply="";

	wstring wstr1(_T(""));
	string str1;
	wstring text = stows(smsg);

	std::wstring regString(_T("^(\\d+)(?:��|)$"));

	// ���ʽѡ�� - ���Դ�Сд  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

	// ����һ��������ʽ���  
	std::wregex regExpress(regString, fl);

	// ������ҵĽ��  
	std::wsmatch ms;
	// ����  

	if (std::regex_search(text, ms, regExpress))
	{
		wstr1 = ms.str(1);
		str1 = wstos(wstr1);
		int num1;
		num1 = stoi(str1);

		if (num1 <= num && !Judge_votes(fromQQ, fromGroup)&&judgeplayers(fromQQ,fromGroup))
		{
			if (judgeSheriff(fromQQ, fromGroup))
			{
				setvotes(To_Int64(players[num1 - 1]), fromGroup);
				setvotes(To_Int64(players[num1 - 1]), fromGroup);
			}
			else
				setvotes(To_Int64(players[num1 - 1]), fromGroup);

			setvotes_total(fromGroup);
			reply = "[CQ:emoji,id=9989]ͶƱ�ɹ�";
			setJudge_vote(fromQQ, fromGroup, "��");
		}
		else
			reply = "[CQ:emoji,id=128683]error";
	}
	else
		reply = "[CQ:emoji,id=127937]--���������,ȫ�巢����Ϻ���ͶƱ--[CQ:emoji,id=127937]";
	int votes_total = getvotes_total(fromGroup);
	if (votes_total == num)
	{
		int max = 0;
		int result = 0;
		int temp = 0;
		 reply = "[CQ:emoji,id=128200]ͶƱ���: \n";
		int checkSame = 0;
		for (int i = 0; i < num; i++)
		{

			result = getvotes(To_Int64(players[i]), fromGroup);
			reply += players[i] + "  " + To_Str(result) + "Ʊ\n";
			if (result > max)
			{
				max = result;
				temp = i;
			}
		}
		for (int i = 0; i < num; i++)
		{
			result = getvotes(To_Int64(players[i]), fromGroup);
			if (i != temp&&result == max)
			{
				checkSame = 1;
				break;
			}
		}

		if (checkSame == 1)
		{
			reply += "[CQ:emoji,id=128201]����ͶƱ�������ͬƱ����Ҷ���Ч\n,�����·��Բ�ͶƱ.....";
			
			resetvotes(fromGroup);
		}
		else
		{
			if (!judge_haveSheriff(fromGroup))
			{
				reply += players[temp] + "[CQ:emoji,id=128202]�������Ʊ��������ѡΪ����\n  �佫ӵ��һƱ����Ʊ����Ȩ\n  �뾯�����Ժ�ͶƱƱ������\n";
				reply += "[CQ:emoji,id=128113]��ұ���б�: \n";
				for (int i = 0; i < num; i++)
					reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "��\n";
				setSheriff(fromGroup, players[temp]);
				resetvotes(fromGroup);
			}
			else
			{
				reply += players[temp] + "[CQ:emoji,id=128202]�������Ʊ����Ͷ��ɱ��\n";

				resetvotes(fromGroup);

				int64_t killedQQ = To_Int64(players[temp]);
				string killedrole = getroles(killedQQ, fromGroup);
				if (killedrole == "����")
					subvillager(fromGroup);
				else if (killedrole == "����")
					subwerewolves(fromGroup);
				else if (killedrole == "Ԥ�Լ�")
					setseer_die(fromGroup, "��");

				else if (killedrole == "Ů��")
					setwitch_die(fromGroup, "��");
                if (killedrole == "����")
				{
					reply += "[CQ:emoji,id=128299]�����Ϊ����\n������ѡ�����һ����";
				}
				if (judgeSheriff(killedQQ, fromGroup))
					reply += "[CQ:emoji,id=128110]�����ѱ�ɱ��,�뾡��ѡ����Ҵ���---\n";
				path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
				delcontent(path.c_str(), players[temp]);
				delcontent("files\\Player_Group.cfg", players[temp]);
				subplayer(fromGroup);
				resetvotes(fromGroup);
				num = getplayer_numbers(fromGroup);
				getkey(path.c_str(), players, num);		
				reply += "[CQ:emoji,id=128113]��ұ���б�: \n";
				for (int i = 0; i < num; i++)
					reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "��\n";
				if (killedrole == "����")
				{
					reply += "[CQ:emoji,id=128299]����: ������ɷ��� ���� ����һ�����(����1)\n��������50s��ѡ��������,��ʱ��ʧȥ����";
					hunterdie = 1;
				}	
				setWhoseturn(fromGroup, "���˻غ�");
			}
			
		}
	}
	
	return reply;
}

//����ɱ��Ϸ����
string over(int64_t fromGroup)
{
	int num = getplayer_numbers(fromGroup);
	string reply;
	
		reply = "[CQ:emoji,id=10062]������Ϸ����\n";
		string werewolves[4];
		string villagers[11];
		string seer;
		string witch="��";
		string hunter="��";
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		int num1=4;
		int num2=11;
		getkey_withStr(path.c_str(), werewolves,num1 , "����");
		getkey_withStr(path.c_str(), villagers, num2, "����");
		seer=getplayers(fromGroup, "Ԥ�Լ�");
		witch=getplayers(fromGroup, "Ů��");
		hunter=getplayers(fromGroup, "����");
		reply += "[CQ:emoji,id=128127]���ֵ�������: \n";

		for (int i = 0; i < num1; i++)
		{
			reply += getNickname(werewolves[i]) + "(" + werewolves[i] + ")\n";
			delcontent("files\\Player_Group.cfg", werewolves[i]);
		}
		reply += "[CQ:emoji,id=128124]���ֵ�Ԥ�Լ�Ϊ: \n"+ getNickname(seer) + "(" + seer + ")\n";
		delcontent("files\\Player_Group.cfg", seer);
		if (witch != "��")
		{
			reply += "[CQ:emoji,id=128120]���ֵ�Ů��Ϊ: \n" + getNickname(witch) + "(" + witch + ")\n";
			delcontent("files\\Player_Group.cfg", witch);
		}
		else
			reply += "[CQ:emoji,id=128120]���ֵ�Ů��Ϊ:  ��\n";

		if (hunter != "��")
		{
			reply += "[CQ:emoji,id=128299]���ֵ�����Ϊ: \n" + getNickname(hunter) + "(" + hunter + ")\n";
			delcontent("files\\Player_Group.cfg", hunter);
		}
		else
			reply += "[CQ:emoji,id=128299]���ֵ�����Ϊ: ��\n";

		for (int j = 0; j < num2; j++)
		{
			reply += "[CQ:emoji,id=128104]���ֵĴ���Ϊ: \n" + getNickname(villagers[j]) + "(" + villagers[j] + ")\n";
			delcontent("files\\Player_Group.cfg", villagers[j]);
		}

		if (getwerewolves_numbers(fromGroup) == 0)
		{
			// ������Ӫ��ʤ
			reply += "[CQ:emoji,id=128111]���ս��: ������Ӫ��ʤ,����ʧ��\n[CQ:emoji,id=128694]��ʤ�������80���齱��";
			for (int m = 0; m < num2; m++)
				getexp(To_Int64(villagers[m]), fromGroup, 80);
			getexp(To_Int64(seer), fromGroup, 80);
			getexp(To_Int64(hunter), fromGroup, 80);
			getexp(To_Int64(witch), fromGroup, 80);

		}
		else if (getwerewolves_numbers(fromGroup)>num - getwerewolves_numbers(fromGroup))
		{
			//���˻�ʤ
			reply += "[CQ:emoji,id=128127]���ս��: ���˻�ʤ,������Ӫʧ��\n[CQ:emoji,id=128694]���˽����100���齱��";
			for (int m = 0; m <num1; m++)
				getexp(To_Int64(werewolves[m]), fromGroup, 100);
		}
		reset(fromGroup);
		resetvotes(fromGroup);
		return reply;
 }

//�ж�����Ƿ�������Ⱥ�������Ϸ,�������������Ϸ��Ⱥ,��ȡ�����Ϸ���ڵ�Ⱥ........
bool in_Group(int64_t fromQQ)
{
	string str="��";
	 string path = "files\\Player_Group.cfg";
	 readConfigFile(path.c_str(), setqq_str(fromQQ), str);
	 if (str == "��")
		 return false;
	 else
		 return true;

}
void set_playergroup(int64_t fromQQ, int64_t fromGroup)
{
	string Group = To_Str(fromGroup);
	writeConfigFile("files\\Player_Group.cfg", setqq_str(fromQQ), Group);
}
int64_t get_playergroup(int64_t fromQQ)
{
	string str = "��";
	readConfigFile("files\\Player_Group.cfg", setqq_str(fromQQ), str);
	int64_t fromGroup = To_Int64(str);
	return fromGroup;
}

//Ů�׶�ҩʹ���ж�,����,��ɱ��ұ���,��ȡ..........
bool judege_poison(int64_t fromGroup)
{
	string str = "��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "Ů�׶�ҩ", str);
	if (str == "��")
		return 1;
	else
		return 0;
}
void set_poison(int64_t fromGroup)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "Ů�׶�ҩ","��");
}
void set_poisonKilled(int64_t fromGroup, string QQ)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "��ɱ", QQ);
}
string get_poisonKilled(int64_t fromGroup)
{
	string str = "��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "��ɱ", str);
	return str;
}

//ͶƱ����������Ϸ,����ͶƱ��ʼ
void setVote_to_end(int64_t fromGroup)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "ͶƱ����", "��");
}
bool Vote_to_end(int64_t fromGroup)
{
	string str = "��";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "ͶƱ����", str);
	if (str == "��")
		return true;
	else
		return false;
}



#endif 

