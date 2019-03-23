#pragma once
#ifndef WEREWOLVESOFMILLERSHOLLOW_H
#define WEREWOLVESOFMILLERSHOLLOW_H
#include"Games.h"
using namespace std;
 
void set_game2(int64_t fromGroup)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "狼人杀游戏", "是");
}

bool game2(int64_t fromGroup)
{
	string x = "否";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "狼人杀游戏", x);
	if (x == "是")
		return true;
	else
		return false;
}
int getwerewolves_numbers(int64_t fromGroup)
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "狼人数量", x);
	return x;
}
void setwerewolves(int64_t fromGroup, int x)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "狼人数量", To_Str(x));
}
void subwerewolves(int64_t fromGroup)
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "狼人数量", x);
	writeConfigFile(path.c_str(), "狼人数量", To_Str(x - 1));

}
int getvillager_numbers(int64_t fromGroup)
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "村民数量", x);
	return x;
}
void setvillager(int64_t fromGroup, int x)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "村民数量", To_Str(x));
}
void subvillager(int64_t fromGroup)
{
	int x = 0;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "村民数量", x);
	writeConfigFile(path.c_str(), "村民数量", To_Str(x - 1));
}

bool hunter_live(int64_t fromGroup)
{
	string str="是";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "猎人存活", str);
	if (str=="否")
		return true;
	else
		return false;
}
void sethunter_die(int64_t fromGroup, string s)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "猎人存活", s);
}

bool witch_live(int64_t fromGroup)
{
	string str="是";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "女巫存活", str);
	if (str == "否")
		return true;
	else
		return false;
}
void setwitch_die(int64_t fromGroup, string s)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "女巫存活", s);
}


bool seer_live(int64_t fromGroup)
{
	string str="是";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "预言家存活", str);
	if (str == "否")
		return true;
	else
		return false;
}
void setseer_die(int64_t fromGroup,string s)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "预言家存活", s);
}


void setSheriff(int64_t fromGroup,string qq)
{
	
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "警长", qq);
}

bool judge_haveSheriff(int64_t fromGroup)
{
	string have = "空";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "警长",have);
	if (have != "空")
		return true;
	else
		return false;
}
bool judgeSheriff(int64_t fromQQ, int64_t fromGroup)
{
	string QQ;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "警长", QQ);
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
	writeConfigFile(path.c_str(), "女巫Buff", "否");
}

bool judgeWitch_buff(int64_t fromGroup)
{
	string judge="是";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "女巫Buff", judge);
	if (judge == "是")
		return true;
	else
		return false;
}

int getcreattime_2(int64_t fromGroup,int sendtime)
{
	int time = sendtime;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "游戏创建时间_2", time);
	return time;
}
void setcreattime_2(int64_t fromGroup, int time)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "游戏创建时间_2", To_Str(time));
}

bool judge_Whoseturn(int64_t fromGroup, const string whose)
{
	string turn;
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "当前回合", turn);
	if (turn == whose)
		return true;
	else
		return false;
}

void setWhoseturn(int64_t fromGroup, string str)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "当前回合", str);
}


//狼人杀分配角色
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

//狼人晚上杀人函数,保存,读取被杀玩家
string judge_Wusebuff(int64_t fromQQ, int64_t fromGroup,int killnumber)
{
	string result;
		if (judge_Whoseturn(fromGroup, "狼人杀人") && judge_roles(fromQQ, fromGroup, "狼人")&&!Judge_votes(fromQQ,fromGroup))
		{
			int num = getplayer_numbers(fromGroup);
			string players[18];
			string path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);
			if (killnumber <= num)
			{
				setvotes(To_Int64(players[killnumber - 1]), fromGroup);
				setvotes_total(fromGroup);
				setJudge_vote(fromQQ, fromGroup,"是");
				result = "[CQ:emoji,id=9989]投票成功";
				return result;
			}
			else return "error";
		}
		else
		{
			result = "[CQ:emoji,id=8252]不在狼人回合内或玩家身份不符,error!";
			return result;
		}
}
void set_killed(int64_t fromGroup,string player)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "被杀玩家", player);
}
string get_killed(int64_t fromGroup)
{
	string who="0";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "被杀玩家", who);
	return who;
}

//狼人杀游戏投票
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

	std::wstring regString(_T("^(\\d+)(?:号|)$"));

	// 表达式选项 - 忽略大小写  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

	// 编译一个正则表达式语句  
	std::wregex regExpress(regString, fl);

	// 保存查找的结果  
	std::wsmatch ms;
	// 查找  

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
			reply = "[CQ:emoji,id=9989]投票成功";
			setJudge_vote(fromQQ, fromGroup, "是");
		}
		else
			reply = "[CQ:emoji,id=128683]error";
	}
	else
		reply = "[CQ:emoji,id=127937]--请继续发言,全体发言完毕后请投票--[CQ:emoji,id=127937]";
	int votes_total = getvotes_total(fromGroup);
	if (votes_total == num)
	{
		int max = 0;
		int result = 0;
		int temp = 0;
		 reply = "[CQ:emoji,id=128200]投票结果: \n";
		int checkSame = 0;
		for (int i = 0; i < num; i++)
		{

			result = getvotes(To_Int64(players[i]), fromGroup);
			reply += players[i] + "  " + To_Str(result) + "票\n";
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
			reply += "[CQ:emoji,id=128201]本轮投票因具有相同票数玩家而无效\n,请重新发言并投票.....";
			
			resetvotes(fromGroup);
		}
		else
		{
			if (!judge_haveSheriff(fromGroup))
			{
				reply += players[temp] + "[CQ:emoji,id=128202]因获得最高票数被而当选为警长\n  其将拥有一票等两票的特权\n  请警长发言后投票票出狼人\n";
				reply += "[CQ:emoji,id=128113]玩家编号列表: \n";
				for (int i = 0; i < num; i++)
					reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "号\n";
				setSheriff(fromGroup, players[temp]);
				resetvotes(fromGroup);
			}
			else
			{
				reply += players[temp] + "[CQ:emoji,id=128202]因获得最高票数被投出杀死\n";

				resetvotes(fromGroup);

				int64_t killedQQ = To_Int64(players[temp]);
				string killedrole = getroles(killedQQ, fromGroup);
				if (killedrole == "村民")
					subvillager(fromGroup);
				else if (killedrole == "狼人")
					subwerewolves(fromGroup);
				else if (killedrole == "预言家")
					setseer_die(fromGroup, "是");

				else if (killedrole == "女巫")
					setwitch_die(fromGroup, "是");
                if (killedrole == "猎人")
				{
					reply += "[CQ:emoji,id=128299]其身份为猎人\n猎人请选择带走一个人";
				}
				if (judgeSheriff(killedQQ, fromGroup))
					reply += "[CQ:emoji,id=128110]警长已被杀死,请尽快选择玩家传承---\n";
				path = "files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
				delcontent(path.c_str(), players[temp]);
				delcontent("files\\Player_Group.cfg", players[temp]);
				subplayer(fromGroup);
				resetvotes(fromGroup);
				num = getplayer_numbers(fromGroup);
				getkey(path.c_str(), players, num);		
				reply += "[CQ:emoji,id=128113]玩家编号列表: \n";
				for (int i = 0; i < num; i++)
					reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "号\n";
				if (killedrole == "猎人")
				{
					reply += "[CQ:emoji,id=128299]猎人: 死亡后可发送 带走 带走一名玩家(带走1)\n猎人请在50s内选择带走玩家,超时将失去技能";
					hunterdie = 1;
				}	
				setWhoseturn(fromGroup, "狼人回合");
			}
			
		}
	}
	
	return reply;
}

//狼人杀游戏结束
string over(int64_t fromGroup)
{
	int num = getplayer_numbers(fromGroup);
	string reply;
	
		reply = "[CQ:emoji,id=10062]本轮游戏结束\n";
		string werewolves[4];
		string villagers[11];
		string seer;
		string witch="无";
		string hunter="无";
		string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
		int num1=4;
		int num2=11;
		getkey_withStr(path.c_str(), werewolves,num1 , "狼人");
		getkey_withStr(path.c_str(), villagers, num2, "村民");
		seer=getplayers(fromGroup, "预言家");
		witch=getplayers(fromGroup, "女巫");
		hunter=getplayers(fromGroup, "猎人");
		reply += "[CQ:emoji,id=128127]本轮的狼人有: \n";

		for (int i = 0; i < num1; i++)
		{
			reply += getNickname(werewolves[i]) + "(" + werewolves[i] + ")\n";
			delcontent("files\\Player_Group.cfg", werewolves[i]);
		}
		reply += "[CQ:emoji,id=128124]本轮的预言家为: \n"+ getNickname(seer) + "(" + seer + ")\n";
		delcontent("files\\Player_Group.cfg", seer);
		if (witch != "无")
		{
			reply += "[CQ:emoji,id=128120]本轮的女巫为: \n" + getNickname(witch) + "(" + witch + ")\n";
			delcontent("files\\Player_Group.cfg", witch);
		}
		else
			reply += "[CQ:emoji,id=128120]本轮的女巫为:  无\n";

		if (hunter != "无")
		{
			reply += "[CQ:emoji,id=128299]本轮的猎人为: \n" + getNickname(hunter) + "(" + hunter + ")\n";
			delcontent("files\\Player_Group.cfg", hunter);
		}
		else
			reply += "[CQ:emoji,id=128299]本轮的猎人为: 无\n";

		for (int j = 0; j < num2; j++)
		{
			reply += "[CQ:emoji,id=128104]本轮的村民为: \n" + getNickname(villagers[j]) + "(" + villagers[j] + ")\n";
			delcontent("files\\Player_Group.cfg", villagers[j]);
		}

		if (getwerewolves_numbers(fromGroup) == 0)
		{
			// 好人阵营获胜
			reply += "[CQ:emoji,id=128111]最终结果: 好人阵营获胜,狼人失败\n[CQ:emoji,id=128694]获胜方将获得80经验奖励";
			for (int m = 0; m < num2; m++)
				getexp(To_Int64(villagers[m]), fromGroup, 80);
			getexp(To_Int64(seer), fromGroup, 80);
			getexp(To_Int64(hunter), fromGroup, 80);
			getexp(To_Int64(witch), fromGroup, 80);

		}
		else if (getwerewolves_numbers(fromGroup)>num - getwerewolves_numbers(fromGroup))
		{
			//狼人获胜
			reply += "[CQ:emoji,id=128127]最终结果: 狼人获胜,好人阵营失败\n[CQ:emoji,id=128694]狼人将获得100经验奖励";
			for (int m = 0; m <num1; m++)
				getexp(To_Int64(werewolves[m]), fromGroup, 100);
		}
		reset(fromGroup);
		resetvotes(fromGroup);
		return reply;
 }

//判断玩家是否在其他群里进行游戏,设置玩家所在游戏的群,获取玩家游戏所在的群........
bool in_Group(int64_t fromQQ)
{
	string str="空";
	 string path = "files\\Player_Group.cfg";
	 readConfigFile(path.c_str(), setqq_str(fromQQ), str);
	 if (str == "空")
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
	string str = "空";
	readConfigFile("files\\Player_Group.cfg", setqq_str(fromQQ), str);
	int64_t fromGroup = To_Int64(str);
	return fromGroup;
}

//女巫毒药使用判断,设置,毒杀玩家保存,读取..........
bool judege_poison(int64_t fromGroup)
{
	string str = "是";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "女巫毒药", str);
	if (str == "是")
		return 1;
	else
		return 0;
}
void set_poison(int64_t fromGroup)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "女巫毒药","否");
}
void set_poisonKilled(int64_t fromGroup, string QQ)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "毒杀", QQ);
}
string get_poisonKilled(int64_t fromGroup)
{
	string str = "空";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "毒杀", str);
	return str;
}

//投票结束本轮游戏,设置投票开始
void setVote_to_end(int64_t fromGroup)
{
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	writeConfigFile(path.c_str(), "投票结束", "是");
}
bool Vote_to_end(int64_t fromGroup)
{
	string str = "否";
	string path = "files\\Game_status" + setqq_str(fromGroup) + ".cfg";
	readConfigFile(path.c_str(), "投票结束", str);
	if (str == "是")
		return true;
	else
		return false;
}



#endif 

