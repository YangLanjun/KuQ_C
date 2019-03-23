/*
* CoolQ Demo for VC++ 
* Api Version 9
* Written by Coxxs & Thanks for the help of orzFly
*/

#include "stdafx.h"
#include <cstdlib>
#include "cqp.h"
#include "SignIn.h"
#include "FunctionConvert.h"
#include "cfg_file.h"
#include "idiom.h"
#include "orders.h"
#include"money.h"
#include"exp.h"
#include"time.h"
#include"QQfunctions.h"
#include"calculate.h"
#include"rank.h"
#include"WerewolvesofMillersHollow.h"
#include"WhoIsTheSpy.h"
#include"alibaba.h"
#include "appmain.h" //应用AppID等信息，请正确填写，否则酷Q可能无法加载

using namespace std;

int ac = -1; //AuthCode 调用酷Q的方法时需要用到
bool enabled = false;
string masterQQ="1069148429";
string lastStatus = "面试中";
/* 
* 返回应用的ApiVer、Appid，打包后将不会调用
*/
CQEVENT(const char*, AppInfo, 0)() {
	return CQAPPINFO;
}


/* 
* 接收应用AuthCode，酷Q读取应用信息后，如果接受该应用，将会调用这个函数并传递AuthCode。
* 不要在本函数处理其他任何代码，以免发生异常情况。如需执行初始化代码请在Startup事件中执行（Type=1001）。
*/
CQEVENT(int32_t, Initialize, 4)(int32_t AuthCode) {
	ac = AuthCode;
	return 0;
}


/*
* Type=1001 酷Q启动
* 无论本应用是否被启用，本函数都会在酷Q启动后执行一次，请在这里执行应用初始化代码。
* 如非必要，不建议在这里加载窗口。（可以添加菜单，让用户手动打开窗口）
*/
CQEVENT(int32_t, __eventStartup, 0)() {
	

	readConfigFile("..\\files\\master.cfg", "masterQQ", masterQQ);
	return 0;
}


/*
* Type=1002 酷Q退出
* 无论本应用是否被启用，本函数都会在酷Q退出前执行一次，请在这里执行插件关闭代码。
* 本函数调用完毕后，酷Q将很快关闭，请不要再通过线程等方式执行其他代码。
*/
CQEVENT(int32_t, __eventExit, 0)() {
	
	return 0;
}

/*
* Type=1003 应用已被启用
* 当应用被启用后，将收到此事件。
* 如果酷Q载入时应用已被启用，则在_eventStartup(Type=1001,酷Q启动)被调用后，本函数也将被调用一次。
* 如非必要，不建议在这里加载窗口。（可以添加菜单，让用户手动打开窗口）
*/
CQEVENT(int32_t, __eventEnable, 0)() {

	thread timeThread([]{
		while (true) {
			string reply = html_get_status();
			string qq = "1069148429";
			string path = "files\\lastStatus.cfg";
			readConfigFile(path.c_str(), qq, lastStatus);
			//cout << reply << endl;
			if(reply == ""){
				reply = "cookie已变更或请求服务发生异常，请及时更新";
				CQ_sendPrivateMsg(ac, 1069148429, reply.c_str());
			}
			else if (reply != lastStatus) {
				lastStatus = reply;
				reply = "您的状态已变更，请尽快查看  新状态：" + reply;
				CQ_sendPrivateMsg(ac, 1069148429, reply.c_str());
				writeConfigFile(path.c_str(), qq, lastStatus);
			}
			//else {
			//	reply = "当前状态：" + reply + " 上一个状态：" + lastStatus;
			//	CQ_sendPrivateMsg(ac, 1069148429, reply.c_str());
			//}
			Sleep(600000);
		}
	});
	timeThread.detach();
	enabled = true;
	return 0;
}


/*
* Type=1004 应用将被停用
* 当应用被停用前，将收到此事件。
* 如果酷Q载入时应用已被停用，则本函数*不会*被调用。
* 无论本应用是否被启用，酷Q关闭前本函数都*不会*被调用。
*/
CQEVENT(int32_t, __eventDisable, 0)() {
	enabled = false;
	return 0;
}


/*
* Type=21 私聊消息**************************************************************************************************************************************************************************
* subType 子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组
*/
CQEVENT(int32_t, __eventPrivateMsg, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, int32_t font) {
	string smsg(msg);
	string reply;
//基本回复...........................................................................................................................................................
	if (smsg == "菜单" || smsg == "功能查询" || smsg == "功能列表")
	{
	reply= "[CQ:emoji,id=127882]......欢迎体验功能型机器人.....[CQ:emoji,id=127882]\n";
	reply += "[CQ:emoji,id=128212]成语查询\n(格式:成语一望无际接什么|啥||以际开头的成语有什么|啥|那些)\n";
	reply += "[CQ:emoji,id=128291]计算\n(格式:计算63.87*98.26)\n";
	reply += "[CQ:emoji,id=9800]查询昵称\n[CQ:emoji,id=12953]命令(格式: 你在群\"(群号)\"里说\"(内容)\"\n要求QQ必须为主人QQ)\n[CQ:emoji,id=128203]更变主人QQ|qq(QQ号)\n游戏中所需私聊回复";
	CQ_sendPrivateMsg(ac, fromQQ, reply.c_str());
	return EVENT_BLOCK;
	}

	if (smsg == "你好" || smsg == "你好啊"|| smsg == "你好呀") {
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=128512]你好啊");
		return EVENT_BLOCK;
	}
		
	if (smsg == "我来找你玩啦") {
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=127748]祝你度过开心的一天");
		return EVENT_BLOCK;
	}
		
	if (smsg == "谢谢你" || smsg == "谢谢") {
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=128080]不客气啊");
		return EVENT_BLOCK;
	}
		


	if (smsg == "查看状态"||smsg=="状态") {
		reply = html_get_status();
		CQ_sendPrivateMsg(ac, fromQQ, reply.c_str());
		return EVENT_BLOCK;
	}
	if (smsg.substr(0,7) == "cookie "&&fromQQ== To_Int64(masterQQ)) {
		string cookie = smsg.substr(7, smsg.length());
		string qq = "1069148429";
		string path = "files\\userCookie.cfg";
		writeConfigFile(path.c_str(), qq, cookie);
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=128080]cookie修改成功");
		return EVENT_BLOCK;
	}
	//抽奖..............................................................................................................................................................
	if (smsg == "抽奖") {
		reply = "抽奖每次消耗5W金币，抽奖详情请见群公告\n奖品兑换联系@推广，充值找我";
				CQ_sendPrivateMsg(ac, fromQQ, reply.c_str());
		return EVENT_BLOCK;
	}
	if (smsg == "我要抽奖") {
		int64_t fromGroup = 854084390;
		int m= readmoney(fromQQ, fromGroup);
		if (m < 50000)
        	CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=127757]金币不足，抽奖每次消耗5W金币，请得到足够金币后再来\n金币充值请找@推广，充值找我");
		else
		{
			losemoney(fromQQ, fromGroup, 50000);
			int rewardNum = realRand(500);
			if (rewardNum >= 0 && rewardNum < 9) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：贵族10（拥有返还800W金币）";
			}
			else if (rewardNum >= 10 && rewardNum <= 39) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：贵族9（拥有返还400W金币）";
			}
			else if (rewardNum >= 40 && rewardNum <= 99) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：贵族8（拥有返还200W金币）";
			}
			else if (rewardNum >= 100 && rewardNum <= 104) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：步兵附魔符文Ⅰ ";
			}
			else if (rewardNum >= 105 && rewardNum <= 109) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：骑兵附魔符文Ⅰ";
			}
			else if (rewardNum >= 110 && rewardNum <= 114) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：步兵附魔符文Ⅱ ";
			}
			else if (rewardNum >= 115 && rewardNum < 119) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：骑兵附魔符文Ⅱ ";
			}
			else if (rewardNum >= 120 && rewardNum <= 129) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：领主改名卡*200 ";
			}
			else if (rewardNum >= 130 && rewardNum <= 149) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：战争守护30天*10  ";
			}
			else if (rewardNum >= 150 && rewardNum <= 154) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：战争守护30天*100 ";
			}
			else if (rewardNum >= 154 && rewardNum <= 159) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：金甲士兵装扮30天*10 ";
			}
			else if (rewardNum >= 160 && rewardNum <= 169) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：金甲士兵装扮7天*10 ";
			}
			else if (rewardNum >= 170 && rewardNum <= 189) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：100体力*10 ";
			}
			else if (rewardNum >= 190 && rewardNum <= 209) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：100体力*50 ";
			}
			else if (rewardNum >= 210 && rewardNum <= 219) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：100体力*100 ";
			}
			else if (rewardNum >= 220 && rewardNum <= 249) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：50\%出征加成*10 ";
			}
			else if (rewardNum >= 250 && rewardNum <= 259) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：50\%出征加成*100  ";
			}
			else if (rewardNum >= 260 && rewardNum <= 279) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：100巨龙经验1*100 ";
			}
			else if (rewardNum >= 280 && rewardNum <= 299) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：500巨龙经验1*50 ";
			}
			else if (rewardNum >= 300 && rewardNum <= 319) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：2000巨龙经验*50 ";
			}
			else if (rewardNum >= 320 && rewardNum <= 339) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：10000巨龙经验*10 ";
			}
			else if (rewardNum >= 340 && rewardNum <= 349) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：10000巨龙经验*50 ";
			}
			else if (rewardNum >= 350 && rewardNum <= 354) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：10000巨龙经验*100  ";
			}
			else if (rewardNum >= 355 && rewardNum <= 364) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：100巨龙能量*30  ";
			}
			else if (rewardNum >= 365 && rewardNum <= 369) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：5000巨龙生命*30     ";
			}
			else if (rewardNum >= 370 && rewardNum <= 370) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：1亿金币    ";
			}
			else if (rewardNum >= 371 && rewardNum <= 372) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：5000W金币 ";
			}
			else if (rewardNum >= 373 && rewardNum <= 379) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：1000W金币";
			}
			else if (rewardNum >= 380 && rewardNum <= 389) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：800W金币 ";
			}
			else if (rewardNum >= 390 && rewardNum <= 409) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：500W金币 ";
			}
			else if (rewardNum >= 410 && rewardNum <= 459) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：200W金币 ";
			}
			else if (rewardNum >= 460 && rewardNum <= 469) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：100W金币 ";
			}
			else if (rewardNum >= 470 && rewardNum <= 479) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：100000领主经验*10 ";
			}
			else if (rewardNum >= 480 && rewardNum <= 485) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：100000领主经验*50";
			}
			else if (rewardNum >= 486 && rewardNum <= 489) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：100000领主经验*100";
			}
			else if (rewardNum >= 490 && rewardNum <= 499) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n恭喜获得：20000领主经验*10";
			}
			reply += "本次获奖编号为：" + To_Str(rewardNum) + "\n[CQ:emoji,id=128176]请找@推广，充值找我领取奖励";
		    CQ_sendPrivateMsg(ac, fromQQ, reply.c_str());
			CQ_sendPrivateMsg(ac, 1665313816, reply.c_str());
		}
		return EVENT_BLOCK;
	}

//成语查询...........................................................................................................................................................
	idioms my;
	if (my.judge_sentence(smsg) != "n")
	{
		string ch = my.judge_sentence(smsg);
		string idioms_out = my.idioms_Find(ch);
		if (idioms_out == "n")
		{

			CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=128534]没有找到你需要的成语呀");
			return EVENT_BLOCK;
		}
		else
		{
			idioms_out = "[CQ:emoji,id=128515]你需要的成语如下：\n" + idioms_out;
			CQ_sendPrivateMsg(ac, fromQQ, idioms_out.c_str());
			return EVENT_BLOCK;
		}
	}

//命令..................................................................................................................................................................
	if ((judgecomand2qun(smsg) != "n") && (fromQQ == To_Int64(masterQQ)))
	{
		string re =judgecomand2qun(smsg);
		string ff = re.substr(0, re.find("/"));
		string ss = re.substr(re.find("/") + 1, re.length());
		CQ_sendGroupMsg(ac, _atoi64(ff.c_str()), ss.c_str());
		return EVENT_BLOCK;
	}

//计算功能..............................................................................................................................................................
if (smsg.substr(0, 4) == "计算")
{
	int choice = getOperator(smsg);
	if (choice!=0)
	{
		wstring text = stows(smsg);
		std::wstring regString(_T("计算(\\d+\\.?\\d*).(\\d*\\.?\\d*)"));

		// 表达式选项 - 忽略大小写  
		std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

		// 编译一个正则表达式语句  
		std::wregex regExpress(regString, fl);

		// 保存查找的结果  
		std::wsmatch ms;
		// 查找  
		if (std::regex_search(text, ms, regExpress))
		{
			string result;
			result = calculateFunction(choice, ms);
			CQ_sendPrivateMsg(ac, fromQQ, result.c_str());
		}
	}
	return EVENT_BLOCK;
}

//昵称查询功能...........................................................................................................................................................
if (smsg == "查询昵称")
{
	string nickname;
	nickname = getNickname(setqq_str(fromQQ));
	CQ_sendPrivateMsg(ac, fromQQ, nickname.c_str());
	return EVENT_BLOCK;
}

//变更主人QQ...........................................................................................................................................................
if (smsg.substr(0, 10) == "更变主人QQ" || smsg.substr(0, 10) == "更变主人qq" || smsg.substr(0, 10) == "更改主人QQ" || smsg.substr(0, 10) == "更改主人qq"&&fromQQ==To_Int64(masterQQ))
{
	size_t pos = smsg.find("人");
	string QQ = smsg.substr(pos + 3);
	if (judge_Digit(QQ))
	{
		writeConfigFile("..\\files\\master.cfg", "masterQQ", QQ);
		readConfigFile("..\\files\\master.cfg", "masterQQ", masterQQ);
	}
}

//狼人杀............................................................................................................................................................


//狼人回合..........................................................................................................................................................

if (smsg.substr(0,2)=="杀"&&judge_Digit(smsg.substr(2)))
{
	int64_t fromGroup = get_playergroup(fromQQ);
	int killnumber =To_Int64(smsg.substr(2));
	string result="";
	result=judge_Wusebuff(fromQQ, fromGroup, killnumber);
	CQ_sendPrivateMsg(ac, fromQQ,result.c_str());

	if (getvotes_total(fromGroup) == getwerewolves_numbers(fromGroup)&&Game_start(fromGroup))
	{
		int num = getplayer_numbers(fromGroup);
		string players[18];
		string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
		getkey(path.c_str(), players, num);
		int max = 0;
		int temp = 0;
		int result = 0;
		for (int i = 0; i < num; i++)
		{
			result = getvotes(To_Int64(players[i]), fromGroup);
			if (result > max)
			{
				max = result;
				temp = i;
			}
		}
		set_killed(fromGroup, players[temp]);
		
		reply = "[CQ:emoji,id=128124] 预言家请睁眼\n预言家请查人\n  预言家: 发送 查+编号(查1)\n[CQ:emoji,id=128341]请在本消息后50s内私聊回复\n[CQ:emoji,id=128290]";
		num = getplayer_numbers(fromGroup);
		getkey(path.c_str(), players, num);
		reply += "\n[CQ:emoji,id=128113]玩家编号列表: \n";
		for (int i = 0; i < num; i++)
			reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "号\n";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		
		if (seer_live(fromGroup))
			setWhoseturn(fromGroup, "预言家回合");
		if (witch_live(fromGroup)&&judgeWitch_buff(fromGroup))
		{
			reply = "[CQ:emoji,id=128120]女巫请睁眼,女巫手里有一瓶毒药和一瓶解药\n  女巫: 请发送 是||否 来选择救人\n请发送 毒+编号 来选择毒人\n[CQ:emoji,id=128341]请在本消息后50s内私聊回复\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			int64_t QQ = To_Int64(getplayers(fromGroup, "女巫"));
			string Preply = "昨晚死去玩家为: " + get_killed(fromGroup) + "\n请在本消息后50s内回复,否则默认视为不救\n请选择是否用药(毒药||解药)\n使用毒药请发 毒+编号(例:毒1号)";
			CQ_sendPrivateMsg(ac, QQ, Preply.c_str());
		}
		resetvotes(fromGroup);
		
		Sleep(55000);

		setWhoseturn(fromGroup, "白天");

		int64_t killedQQ = To_Int64(get_killed(fromGroup));
		string killedrole = getroles(killedQQ, fromGroup);

		if (get_killed(fromGroup) == "0" && get_poisonKilled(fromGroup)=="空")
			reply = "[CQ:emoji,id=127749]天亮了\n  昨天晚上没有玩家死亡\n";
		else
		{
			reply = "";
			if(get_killed(fromGroup) != "0")
			reply = "[CQ:emoji,id=127749]天亮了\n  昨天晚上死亡玩家为: "+get_killed(fromGroup)+"\n请发表遗言: \n" ;
			if(get_poisonKilled(fromGroup) != "空" && get_poisonKilled(fromGroup) !=get_killed(fromGroup))
				reply += "昨天晚上女巫毒死的玩家为: " + get_poisonKilled(fromGroup) + "\n毒死不可发表遗言\n";

			if (killedrole == "村民")
				subvillager(fromGroup);
			else if (killedrole == "狼人")
				subwerewolves(fromGroup);
			else if (killedrole == "预言家")
				setseer_die(fromGroup, "是");

			else if (killedrole == "女巫")
				setwitch_die(fromGroup, "是");
			path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			delcontent(path.c_str(), get_killed(fromGroup));delcontent("..\\files\\Player_Group.cfg", get_killed(fromGroup));
			subplayer(fromGroup);
		}
		if (!judge_haveSheriff(fromGroup))
			reply += "[CQ:emoji,id=128110]请按编号依次发言后投票选出警长\n";
		else
			reply += "[CQ:emoji,id=128215]请按编号依次发言后投票\n";
		reply += "[CQ:emoji,id=128215]玩家编号列表: \n";
		num = getplayer_numbers(fromGroup);
		path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
		getkey(path.c_str(), players, num);
		for (int i = 0; i < num; i++)
			reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "号\n";
		if (judgeSheriff(killedQQ, fromGroup)|| judgeSheriff(To_Int64(get_poisonKilled(fromGroup)), fromGroup))
		{
			reply += "[CQ:emoji,id=128110]警长已被杀死,请尽快选择玩家传承---\n请在40s内完成,否则将没有警长\n请在群里发送 传给+编号(例:传给1) 来传承\n";
			Sleep(45000);
			if (judgeSheriff(killedQQ, fromGroup))
				setSheriff(fromGroup, "0000");
		}
		if (killedrole == "猎人")
		{
			reply += "[CQ:emoji,id=128299]猎人: 死亡后可发送 带走 带走一名玩家(带走1)\n猎人请在40s内选择带走玩家,超时将失去技能";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			Sleep(45000);
			sethunter_die(fromGroup, "是");
		}
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		if(get_poisonKilled(fromGroup) != "空")
			set_poisonKilled(fromGroup, "空");
	}
	

	int num = getplayer_numbers(fromGroup);
	if (getwerewolves_numbers(fromGroup) == 0 || getwerewolves_numbers(fromGroup) > num - getwerewolves_numbers(fromGroup))
	{
		string reply = over(fromGroup);
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}
}

//预言家回合...........................................................................................................................................................
if (smsg.substr(0, 2) == "查"&&judge_Digit(smsg.substr(2)))
{
	int64_t fromGroup = get_playergroup(fromQQ);
	int checknumber = To_Int64(smsg.substr(2));
		int num = getplayer_numbers(fromGroup);
		string players[18];
		string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
		getkey(path.c_str(), players, num);
		if (checknumber <= num&&judge_Whoseturn(fromGroup, "预言家回合") && judge_roles(fromQQ, fromGroup, "预言家")&&seer_live(fromGroup) && Game_start(fromGroup))
		{
			string playerrole = getroles(To_Int64(players[checknumber - 1]), fromGroup);
			string preply = "[CQ:emoji,id=128100]所查玩家身份: " + playerrole;
			CQ_sendPrivateMsg(ac, fromQQ,preply.c_str());
			setWhoseturn(fromGroup, "空");
		}
}

//女巫...........................................................................................................................................................

if (smsg.substr(0, 2) == "毒"&&judge_Digit(smsg.substr(2)))
{
	int64_t fromGroup = get_playergroup(fromQQ);
	int checknumber = To_Int64(smsg.substr(2));
	int num = getplayer_numbers(fromGroup);
	if (checknumber <= num &&(judge_Whoseturn(fromGroup, "预言家回合") || judge_Whoseturn(fromGroup, "空")) && judge_roles(fromQQ, fromGroup, "女巫") && witch_live(fromGroup) && Game_start(fromGroup) && judege_poison(fromGroup))
	{
	string players[18];
	string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	getkey(path.c_str(), players, num);
	
		string killedrole = getroles(To_Int64(players[checknumber - 1]), fromGroup);
		if (killedrole == "村民")
			subvillager(fromGroup);
		else if (killedrole == "狼人")
			subwerewolves(fromGroup);
		else if (killedrole == "预言家")
			setseer_die(fromGroup, "是");

		else if (killedrole == "女巫")
			setwitch_die(fromGroup, "是");
		if (killedrole == "猎人")
			sethunter_die(fromGroup,"是");

		path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
		delcontent(path.c_str(), players[checknumber - 1]);
		delcontent("..\\files\\Player_Group.cfg", players[checknumber - 1]);
		subplayer(fromGroup);
		set_poison(fromGroup);
		set_poisonKilled(fromGroup, players[checknumber - 1]);
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=9989]毒杀成功");
	}
}

if (smsg.substr(0, 2) == "是")
{
	int64_t fromGroup = get_playergroup(fromQQ);
	if ((judge_Whoseturn(fromGroup, "预言家回合")||judge_Whoseturn(fromGroup,"空")) && judge_roles(fromQQ, fromGroup, "女巫") && witch_live(fromGroup) && judgeWitch_buff(fromGroup) && Game_start(fromGroup)	)
	{
		setWitch_buff(fromGroup);
		set_killed(fromGroup, "无");
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=9989]救人成功");
	}
}

return EVENT_IGNORE;
}

/*
* Type=2 群消息**************************************************************************************************************************************************************************************
*
*
* Type=2 群消息**************************************************************************************************************************************************************************************
*/
CQEVENT(int32_t, __eventGroupMsg, 36)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *fromAnonymous, const char *msg, int32_t font)
{
	srand((unsigned)time(NULL));
	int m= readmoney(fromQQ, fromGroup);
	int e = readexp(fromQQ, fromGroup);
	string atone = "[CQ:at,qq=" + to_string(fromQQ) + "]\n";
	string reply;
	string smsg(msg);
	int money = 0;
	int exp = 0;
	//总菜单
	if ((smsg == "菜单" || smsg == "功能查询" || smsg == "功能列表") && !Game_start(fromGroup))
	{
		reply = "[CQ:emoji,id=127882]......欢迎体验功能型机器人.....[CQ:emoji,id=127882]\n 控制Andriod讲话(格式: 你说(内容) \n 发送QQ必须为主人QQ)\n";
		reply += "[CQ:emoji,id=128212]成语查询\n(格式:成语一望无际接什么|啥||以际开头的成语有什么|啥|那些)\n";
		reply += "充值\n推广（推广语）\n抽奖\n";
		reply += "[CQ:emoji,id=128198]签到\n(重复签到每次扣除100金币)\n[CQ:emoji,id=128291]计算\n(格式:计算63.87*98.26)\n[CQ:emoji,id=128185]金币排行榜\n[CQ:emoji,id=128201]经验排行榜\n";
		reply += "[CQ:emoji,id=127922]猜数\n(详见 猜数介绍)\n[CQ:emoji,id=128101]谁是卧底\n(详见 谁是卧底介绍)\n[CQ:emoji,id=128127]狼人杀\n(详见狼人杀介绍)";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;

	}

	//推广
	if ((smsg == "推广" || smsg == "推广语")&& fromGroup == 854084390)
	{
		reply = "一代人的激情-列王的纷争\n中国制造，最高仿列王的纷争，最近官服的列王的纷争\nWar of Kings 等待你的加入\n是不是cok的界面已经让你产生了疲劳，来吧，全新的界面让你焕然一新\n";
		reply += "一般私服都只是列王的老版本，玩家间打来打去，疲劳无意义\nCOK高清重置版等待你的加入！！！\n这里有 巨龙，有海怪，有世界BOSS，甚至有指挥官，有俘虏，有悬赏任务，士兵附魔。。。\n";
		reply += "完美还原了cok的一切，并极力贴近官服，给你们想要的cok\n";
		reply += "随着任务有大量的金币奖励，资源采集量和速度都是原来的100倍\n不充值也可以享受游戏的乐趣，专业开发会带来更丰厚的奖励\n联盟挑战花样多多，不只有一般私服的黑骑士，还有更多联盟探险\n";
		reply += "活动全开，等待你的加入\n详情进群看相册，文件：854084390\n快快加入，早来早成大佬，满100人开2区\n";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
	}

   //充值
	if (smsg == "充值"&& fromGroup == 854084390) {
		reply = "充值详情请看群公告！！\n充值，抽奖联系@推广，充值找我";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}

	//抽奖
	if (smsg == "抽奖"&& fromGroup == 854084390) {
		reply = "抽奖每次消耗5W金币，抽奖详情请见群公告\n请发送 我要抽奖 开始抽奖吧\n奖品兑换联系@推广，充值找我";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}
	if (smsg == "我要抽奖"&& fromGroup == 854084390) {
	
	if (m < 50000)
		CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=127757]金币不足，抽奖每次消耗5W金币，请得到足够金币后再来\n金币充值请找@推广，充值找我");
	else
	{
		losemoney(fromQQ, fromGroup, 50000);
		int rewardNum = realRand(500);
		if (rewardNum>=0&&rewardNum<9) {
			reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：贵族10（拥有返还800W金币）";
		}
		else if (rewardNum >= 10 && rewardNum <= 39) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：贵族9（拥有返还400W金币）";
		}
		else if (rewardNum >= 40 && rewardNum <= 99) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：贵族8（拥有返还200W金币）";
		}
		else if (rewardNum >= 100 && rewardNum <= 104) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：步兵附魔符文Ⅰ ";
		}
		else if (rewardNum >= 105 && rewardNum <=109) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：骑兵附魔符文Ⅰ";
		}
		else if (rewardNum >= 110 && rewardNum <= 114) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：步兵附魔符文Ⅱ ";
		}
		else if (rewardNum >= 115 && rewardNum < 119) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：骑兵附魔符文Ⅱ ";
		}
		else if (rewardNum >= 120 && rewardNum <= 129) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：领主改名卡*200 ";
		}
		else if (rewardNum >= 130 && rewardNum <= 149) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：战争守护30天*10  ";
		}
		else if (rewardNum >= 150 && rewardNum <= 154) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：战争守护30天*100 ";
		}
		else if (rewardNum >= 154 && rewardNum <= 159) {
			           reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：金甲士兵装扮30天*10 ";
		}
		else if (rewardNum >= 160 && rewardNum <= 169) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：金甲士兵装扮7天*10 ";
		}
		else if (rewardNum >= 170 && rewardNum <= 189) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：100体力*10 ";
		}
		else if (rewardNum >= 190 && rewardNum <= 209) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：100体力*50 ";
		}
		else if (rewardNum >= 210 && rewardNum <= 219) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：100体力*100 ";
		}
		else if (rewardNum >= 220 && rewardNum <= 249) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：50\%出征加成*10 ";
		}
		else if (rewardNum >= 250 && rewardNum <= 259) {
								reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：50\%出征加成*100  ";
		}
		else if (rewardNum >= 260 && rewardNum <= 279) {
				reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：100巨龙经验1*100 ";
		}
		else if (rewardNum >= 280 && rewardNum <= 299) {
							reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：500巨龙经验1*50 ";
		}
		else if (rewardNum >= 300 && rewardNum <= 319) {
					reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：2000巨龙经验*50 ";
		}
		else if (rewardNum >= 320 && rewardNum <= 339) {
							reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：10000巨龙经验*10 ";
		}
		else if (rewardNum >= 340 && rewardNum <= 349) {
					reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：10000巨龙经验*50 ";
		}
		else if (rewardNum >= 350 && rewardNum <= 354) {
							reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：10000巨龙经验*100  ";
		}
		else if (rewardNum >= 355 && rewardNum <= 364) {
					reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：100巨龙能量*30  ";
		}
		else if (rewardNum >= 365 && rewardNum <= 369) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：5000巨龙生命*30     ";
		}
		else if (rewardNum >= 370 && rewardNum <= 370) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：1亿金币    ";			
		}
		else if (rewardNum >= 371 && rewardNum <= 372) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：5000W金币 ";
		}
		else if (rewardNum >= 373 && rewardNum <= 379) {
					reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：1000W金币";
		}
		else if (rewardNum >= 380 && rewardNum <= 389) {
							reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：800W金币 ";
		}
		else if (rewardNum >= 390 && rewardNum <= 409) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：500W金币 ";
		}
		else if (rewardNum >= 410 && rewardNum <= 459) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：200W金币 ";
		}
		else if (rewardNum >= 460 && rewardNum <= 469) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：100W金币 ";
		}
		else if (rewardNum >= 470 && rewardNum <= 479) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：100000领主经验*10 ";
		}
		else if (rewardNum >= 480 && rewardNum <= 485) {
							reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：100000领主经验*50";
		}
		else if (rewardNum >= 486 && rewardNum <= 489) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：100000领主经验*100";
		}
		else if (rewardNum >= 490 && rewardNum <= 499) {
						reply = "[CQ:emoji,id=127882]......抽奖结果.....[CQ:emoji,id=127882]\n" + atone + "\n恭喜获得：20000领主经验*10";
		}
		reply += "本次获奖编号为："+To_Str(rewardNum)+"\n[CQ:emoji,id=128176]请找@推广，充值找我领取奖励";
					CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
					CQ_sendPrivateMsg(ac, 1665313816, reply.c_str());
		}
		return EVENT_BLOCK;
	}

	//签到
	if (smsg == "签到" && !Game_start(fromGroup))
	{
		int moneyRondom;
		int expRondom;
		const time_t t = time(NULL);


		struct tm* current_time = localtime(&t);
		int day = current_time->tm_mday; //获得签到日期 
		int times = 0;
		if (Judge_SignIn(fromQQ,fromGroup, day, times))
		{
			moneyRondom = 1000 + rand() % 800;
			expRondom = 20 + rand() % 30;
			getmoney(fromQQ, fromGroup, moneyRondom);
			getexp(fromQQ, fromGroup, expRondom);

			reply = "[CQ:emoji,id=127882]......欢迎体验功能型机器人.....[CQ:emoji,id=127882]\n" + atone + "[CQ:emoji,id=128276]签到成功\n[CQ:emoji,id=128176]本次签到共获得金币: "
				+ To_Str(moneyRondom) + "\n[CQ:emoji,id=127757]共获得经验：" + To_Str(expRondom)
				+ "\n[CQ:emoji,id=128077]这是你第" + To_Str(times) + "次签到";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		else
		{
			losemoney(fromQQ, fromGroup, 100);
			reply = "[CQ:emoji,id=127882]......欢迎体验功能型机器人.....[CQ:emoji,id=127882]\n" + atone + "\n[CQ:emoji,id=128276]你今天已经签过到了，扣除100金币，请明天再来\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		return EVENT_BLOCK;
	}

//成语查询.............................................................................................................................................................
	idioms my;
	if (my.judge_sentence(smsg) != "n" &&!Game_start(fromGroup))
	{
		string ch = my.judge_sentence(smsg);
		string idioms_out = my.idioms_Find(ch);
		if (idioms_out == "n" || idioms_out == "")
		{
			reply = atone +"[CQ:emoji,id=128534]没有找到你需要的成语呀";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else
		{
			reply = atone +"[CQ:emoji,id=128516]你需要的成语如下：\n" + idioms_out;
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;

		}
	}

//命令.................................................................................................................................................................
	if ((judgecomand(smsg) != "n") && (fromQQ == To_Int64(masterQQ)))
	{
		CQ_sendGroupMsg(ac, fromGroup, judgecomand(smsg).c_str());
		return EVENT_BLOCK;
	}

//查询.................................................................................................................................................................
	if (smsg == "查看金币"||smsg=="查询金币"||smsg=="金币查询"||smsg=="我的金币" && !Game_start(fromGroup))
	{
		
		string M = To_Str(m);
		reply = "[CQ:emoji,id=128176]......欢迎体验功能型机器人.....[CQ:emoji,id=128176]\n" + atone + "[CQ:emoji,id=128180]您的金币余额为：" + M;
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}
	if (smsg == "查看经验"||smsg=="查询经验"||smsg=="经验查询"||smsg=="我的经验" && !Game_start(fromGroup))
	{
		
		string E = To_Str(e);
		reply = "[CQ:emoji,id=127757]......欢迎体验功能型机器人.....[CQ:emoji,id=127757]\n" + atone + "[CQ:emoji,id=127759]您的经验为为：" + E;
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}

//猜数.................................................................................................................................................................
	if (smsg == "猜数介绍" && !Game_start(fromGroup))
	{
		reply = "[CQ:emoji,id=127922]......欢迎体验功能型机器人.....[CQ:emoji,id=127922]\n请发送猜数来进行游戏，每次猜数将消耗您1200金币，失败扣除金币，成功获得相应金币奖励\n游戏中，请选择猜大猜小，系统将给出两个数进行比较\n祝你好运";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
	}

	
	if (smsg == "猜数" && !Game_start(fromGroup)&& !getNumberGuessing_status(fromQQ,fromGroup))
	{
		if(m<1200)
			CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=127757]金币不足，请得到足够金币后再来");
		else
		{
			losemoney(fromQQ, fromGroup, 1200);
			setNumberGuessing_status(fromQQ, fromGroup, "是");
			CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=127922]请选择猜大猜小");
			return EVENT_BLOCK;
		}
	}
	
		if ((smsg == "猜大" || smsg == "猜小"||smsg=="大"||smsg=="小") && getNumberGuessing_status(fromQQ, fromGroup))
	{
			int randomNum1 = 30 + realRand(33);
			int randomNum2 = 10 + realRand(80);
			if ((smsg == "猜大"||smsg=="大")&&randomNum1 >= randomNum2)
			{
				reply = atone + "[CQ:emoji,id=127922]玩家点数: " + To_Str(randomNum1) + "\n[CQ:emoji,id=127922]系统点数: " + To_Str(randomNum2) + "\n[CQ:emoji,id=128176]恭喜获胜，获得2000金币";
				getmoney(fromQQ, fromGroup,2000);
			}
			else if ((smsg == "猜大" || smsg == "大") &&randomNum1 < randomNum2)
			{
				reply = atone + "[CQ:emoji,id=127922]玩家点数: " + To_Str(randomNum1) + "\n[CQ:emoji,id=127922]系统点数: " + To_Str(randomNum2) + "\n[CQ:emoji,id=128555]很不幸，猜数失败，欢迎下次再来";
			}
			else if ((smsg == "猜小" || smsg == "小") &&randomNum1 < randomNum2)
			{
				reply = atone + "[CQ:emoji,id=127922]玩家点数: " + To_Str(randomNum1) + "\n[CQ:emoji,id=127922]系统点数: " + To_Str(randomNum2) + "\n[CQ:emoji,id=128176]恭喜获胜，获得2000金币";
				getmoney(fromQQ, fromGroup, 2000);
			}
			else if ((smsg == "猜小" || smsg == "小") &&randomNum1 >= randomNum2)
			{
				reply = atone + "[CQ:emoji,id=127922]玩家点数: " + To_Str(randomNum1) + "\n[CQ:emoji,id=127922]系统点数: " + To_Str(randomNum2) + "\n[CQ:emoji,id=128555]很不幸，猜数失败，欢迎下次再来";
			}
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			setNumberGuessing_status(fromQQ, fromGroup, "否");
			return EVENT_BLOCK;
	}
//魔法数游戏....................................................................................................................................................................
		if (smsg == "魔法数介绍" && !Game_start(fromGroup))
		{
			reply = "发送 魔法数 开始游戏\n每句游戏花费800金币\n游戏时长限制为3分钟\n胜利可获得 3000*剩余猜测次数*0.7的奖励(最高可获得10500金币)\n初始次数为 5 次\n每一次猜测可得到偏大或偏小的提示\n祝您好运";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		if (smsg == "魔法数" && !Game_start(fromGroup)&&!getmagicNumber_status(fromQQ,fromGroup))
		{
			string reply;
			if (m >= 800)
			{
				reply = "[CQ:emoji,id=127881]欢迎加入魔法数游戏[CQ:emoji,id=127881]\n[CQ:emoji,id=127757]游戏开启消耗金币800\n[CQ:emoji,id=128341]游戏时长限制为3分钟\n";
				setmagicNumber_status(fromQQ, fromGroup, "是");
				setmagicNumber_time(fromQQ, fromGroup, sendTime);
				setmagicNumber_times(fromQQ, fromGroup, 5);
				int random_num1 = rand() % 30 + 1;
				int random_num2 = rand() % 40 + 90;
				reply += "[CQ:emoji,id=127922]您的随机数范围为: " + To_Str(random_num1) + "--" + To_Str(random_num2) + "\n[CQ:emoji,id=128221]您共有五次猜数机会,请开始你的表演\n";
				int ur_random_num = random_num1 + rand() % (random_num2 - random_num1);
				setmagicNumber_num(fromQQ, fromGroup, ur_random_num);
				losemoney(fromQQ, fromGroup, 800);
			}
			else
				reply = "[CQ:emoji,id=127757]金币不足,无法开启魔法数游戏.........\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		else if (smsg == "魔法数" && !Game_start(fromGroup) && !getmagicNumber_status(fromQQ, fromGroup))
		{
			reply = "[CQ:emoji,id=10060]您已开启魔法数游戏,请尽快结束当前游戏.........\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		 
		if (getmagicNumber_status(fromQQ, fromGroup) && getmagicNumber_time(fromQQ, fromGroup) - sendTime <= 180 &&judge_Digit(smsg)&& getmagicNumber_times(fromQQ, fromGroup)>0&&getmagicNumber_num(fromQQ, fromGroup)!=0)
		{
			wstring wstr1(_T(""));
			string str1;
			wstring text = stows(smsg);

			std::wstring regString(_T("^(\\d+)$"));

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
				submagicNumber_times(fromQQ, fromGroup);
				int remain_times = getmagicNumber_times(fromQQ, fromGroup);
				if (num1 < getmagicNumber_num(fromQQ, fromGroup))
					reply = "[CQ:emoji,id=11014]您猜的数偏小\n[CQ:emoji,id=128221]您的剩余次数为: " + To_Str(remain_times);
				else if (num1 > getmagicNumber_num(fromQQ, fromGroup))
				{
					reply = "[CQ:emoji,id=11015]您猜的数偏大\n[CQ:emoji,id=128221]您的剩余次数为: " + To_Str(remain_times);
				}
				else
				{
					reply = "[CQ:emoji,id=128124]恭喜您猜对了相应的数字\n[CQ:emoji,id=128221]您的剩余机会为: " + To_Str(remain_times)+"\n您将获得 3000*"+To_Strd(double(remain_times+1)*0.7)+"金币奖励";
					setmagicNumber_times(fromQQ, fromGroup, 0);
					setmagicNumber_status(fromQQ, fromGroup, "否");
					setmagicNumber_time(fromQQ, fromGroup, 0);
					setmagicNumber_num(fromQQ, fromGroup, 0);
					getmoney(fromQQ, fromGroup, 3000*(remain_times+1)*0.7);
				}

				if (getmagicNumber_status(fromQQ, fromGroup) && getmagicNumber_times(fromQQ, fromGroup) <= 0)
				{
					reply += "[CQ:emoji,id=128221]您的次数耗尽,游戏结束,游戏失败\n[CQ:emoji,id=127922]您的天命数为: " + To_Str(getmagicNumber_num(fromQQ, fromGroup)) + "\n[CQ:emoji,id=127937]欢迎下次体验....... ";
					setmagicNumber_times(fromQQ, fromGroup, 0);
					setmagicNumber_status(fromQQ, fromGroup, "否");
					setmagicNumber_time(fromQQ, fromGroup, 0);
					setmagicNumber_num(fromQQ, fromGroup, 0);
				}
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			}
		}
		else if (getmagicNumber_status(fromQQ, fromGroup) && getmagicNumber_time(fromQQ, fromGroup) - sendTime > 180)
		{
			reply = "[CQ:emoji,id=128341]您的时间耗尽,游戏结束,游戏失败\n[CQ:emoji,id=127937]欢迎下次体验....... " ;
			setmagicNumber_times(fromQQ, fromGroup, 0);
			setmagicNumber_status(fromQQ, fromGroup, "否");
			setmagicNumber_time(fromQQ, fromGroup, 0);
			setmagicNumber_num(fromQQ, fromGroup, 0);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		
//魔法数对战.....................................................................
	/*	if (smsg == "魔法数对战" && !Game_start(fromGroup)&&getChallenger(fromGroup)=="0000")
		{
			reply += "欢迎加入魔法数对战\n你已成为今天的擂主\n本次上擂花费金币1000\n请等待应战者进行挑战";
			setChallenger(fromGroup, setqq_str(fromQQ));
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		if (smsg == "应战" && !Game_start(fromGroup) && getChallenger(fromGroup) != "0000")
		{
			setBattle(fromGroup, setqq_str(fromQQ));
			setChallenger_time(fromGroup, sendTime);
			string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
			writeConfigFile(path.c_str(), "游戏开始", "是");
			reply = getNickname(setqq_str(fromQQ)) + "  以应战,挑战开始\n挑战限时4分钟";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}

		if(judge_Digit(smsg)&&Game_start(fromGroup)&& getChallenger(fromGroup) != "0000"&&getBattle(fromGroup)!="0000")*/
//计算.................................................................................................................................................................
		if (smsg.substr(0, 4) == "计算" && !Game_start(fromGroup))
		{
			int choice;
			choice = getOperator(smsg);
			if (choice!=0)
			{
				wstring text = stows(smsg);

				std::wstring regString(_T("计算(\\d+\\.?\\d*).(\\d*\\.?\\d*)"));

				// 表达式选项 - 忽略大小写  
				std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

				// 编译一个正则表达式语句  
				std::wregex regExpress(regString, fl);

				// 保存查找的结果  
				std::wsmatch ms;
				// 查找  
				if (std::regex_search(text, ms, regExpress))
				{
					string result;
					result = calculateFunction(choice, ms);
					CQ_sendGroupMsg(ac, fromGroup, result.c_str());
				}
			}
			return EVENT_BLOCK;
		}

//谁是卧底游戏..........................................................................................................................................................
		if (smsg == "谁是卧底介绍" && !Game_start(fromGroup))
		{
			reply = "=====欢迎体验功能型机器人=====\n该游戏适合人数为5--12人\n游戏限制时长为15分钟(包含创建房间后的等待时间)\n房主发送 创建谁是卧底 创建房间(需金币600)\n玩家发送 加入/参加/参与谁是卧底 加入房间(需金币400)\n";
			reply += "房主有权踢出任一玩家(金币返还380) 直接@即可\n房间人数达5人及以上是房主可发送 开始谁是卧底 开始游戏\n游戏开始后Android将随机分派词组(450)\n玩家拿到词组后请按顺序发言";
			reply += "随后按照发言内容针对编号进行投票 (例: 1/1号)\n不同人数房间将有不同数量的卧底,平民,和空白\n直至某两方为0或一方为0其他两方为1时游戏结束\n获胜单方将获得2000金币奖励\n";
			reply += "获胜双方将每方获得800金币奖励\n祝你玩的愉快!!!";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}

		int num = getplayer_numbers(fromGroup);
			if (smsg == "创建谁是卧底" && !Game_creat(fromGroup) && m >= 600)
			{
				string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
				writeConfigFile(path.c_str(), "游戏创建", "是");
				setroles(fromQQ, fromGroup, "空");
				set_game1(fromGroup);
				addplayer(fromGroup);
				setcreattime_1(fromGroup, sendTime);
				getWordGroup(fromGroup);
				reply = "[CQ:emoji,id=128227]......欢迎体验功能型机器人.....\n" + atone + "[CQ:emoji,id=127759]您已成功创建房间，消耗金币600,请等待其他玩家加入\n[CQ:emoji,id=128353]当前玩家数量：1\n(玩家人数达到5后可发送 开始谁是卧底 进行游戏";
				losemoney(fromQQ, fromGroup, 600);

				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if (smsg == "创建谁是卧底" && Game_creat(fromGroup) )
			{
				reply = atone + "[CQ:emoji,id=128336]当前有尚未结束的游戏，请稍后再来";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if (smsg == "创建谁是卧底" && m < 600 )
			{
				reply = atone + "[CQ:emoji,id=128336]金币不足,请赚钱后再来....";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			if ((smsg == "参加谁是卧底" || smsg == "参与谁是卧底" || smsg == "加入谁是卧底") && Game_creat(fromGroup) && num<12 && !Game_start(fromGroup) && !judgeplayers(fromQQ, fromGroup) && m >= 400)
			{
				setroles(fromQQ, fromGroup, "空");
				addplayer(fromGroup);
				num = getplayer_numbers(fromGroup);
				string Num = To_Str(num);
				reply = "[CQ:emoji,id=128227]......欢迎体验功能型机器人.....\n" + atone + "[CQ:emoji,id=127759]您已成功加入房间，消耗金币400,请等待其他玩家加入\n[CQ:emoji,id=128353]当前玩家数量：" + Num;
				losemoney(fromQQ, fromGroup, 400);
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if ((smsg == "参加谁是卧底" || smsg == "参与谁是卧底" || smsg == "加入谁是卧底") && !Game_creat(fromGroup) )
			{
				reply = atone + "[CQ:emoji,id=128340]当前还没有房间，请等待或自己主持";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if ((smsg == "参加谁是卧底" || smsg == "参与谁是卧底" || smsg == "加入谁是卧底")  && num >= 12 )
			{
				reply = atone + "[CQ:emoji,id=128340]当前房间人数已满，请等待下一局";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;

			}
			else if ((smsg == "参加谁是卧底" || smsg == "参与谁是卧底" || smsg == "加入谁是卧底") && judgeplayers(fromQQ, fromGroup))
			{
				reply = atone + "[CQ:emoji,id=128336]你已在房间中，请等待....";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if ((smsg == "参加谁是卧底" || smsg == "参与谁是卧底" || smsg == "加入谁是卧底") && m < 400)
			{
				reply = atone + "[CQ:emoji,id=128336]金币不足,请赚钱后再来....";		
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if ((smsg == "参加谁是卧底" || smsg == "参与谁是卧底" || smsg == "加入谁是卧底") && Game_start(fromGroup))
			{
				reply = atone + "[CQ:emoji,id=128336]当前游戏已开始,请等下轮.....";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}

			if (smsg.substr(0, 4) == "踢出"&&Game_creat(fromGroup) && !Game_start(fromGroup))
			{
				string players[12];
				string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
				getkey(path.c_str(), players, num);
				if (fromQQ == To_Int64(players[0]))
				{
					wstring wstr1(_T(""));
					string str1;
					wstring text = stows(smsg);


					std::wstring regString(_T("CQ:at,qq=(\\d+)"));

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
						if (judgeplayers(To_Int64(str1), fromGroup) && To_Int64(str1) != fromQQ)
						{
							subplayer(fromGroup);
							num = getplayer_numbers(fromGroup);
							string Num = To_Str(num);
							getmoney(To_Int64(str1), fromGroup, 380);
							reply = "[CQ:emoji,id=128123]成功踢出玩家(" + str1 + ")\n[CQ:emoji,id=127975]相应金币已返还(380)......\n[CQ:emoji,id=128353]当前玩家数量：" + Num;
							CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
							delcontent("..\\files\\Player_Group.cfg", str1);
							return EVENT_BLOCK;
						}
						else if (!judgeplayers(To_Int64(str1), fromGroup))
						{
							reply = "玩家不存在,踢出失败......";
							CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
							return EVENT_BLOCK;
						}
						else
						{
							reply = "房主不可被踢出.....";
							CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
							return EVENT_BLOCK;
						}
					}
				}
			}

			if (smsg.substr(0, 8) == "结束游戏" && (Game_creat(fromGroup) || Game_start(fromGroup)) && judgeplayers(fromQQ, fromGroup)&&!Vote_to_end(fromGroup))
			{
				setVote_to_end(fromGroup);
				setvotes(1, fromGroup);
				setvotes_total(fromGroup);
				setJudge_vote(fromQQ, fromGroup, "是");
				reply = "[CQ:emoji,id=127937]玩家已发起结束投票,同意请扣1,反对请扣0\n[CQ:emoji,id=128125]投票结束游戏只有一次机会,请把握\n[CQ:emoji,id=128340]请开始投票\n";
				if (num == 1)
				{
					reply += "结束游戏成功\n";
					delcontent("..\\files\\Player_Group.cfg", setqq_str(fromQQ));
					reset(fromGroup);
					resetvotes(fromGroup);
				}
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;

			}
			if ((Game_creat(fromGroup) || Game_start(fromGroup)) && judgeplayers(fromQQ, fromGroup) && Vote_to_end(fromGroup))
			{
				int num = getplayer_numbers(fromGroup);
				wstring wstr1(_T(""));
				string str1;
				wstring text = stows(smsg);

				std::wstring regString(_T("(\\d+)(?:号|)$"));

				// 表达式选项 - 忽略大小写  
				std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

				// 编译一个正则表达式语句  
				std::wregex regExpress(regString, fl);

				// 保存查找的结果  
				std::wsmatch ms;
				// 查找  

				if (std::regex_search(text, ms, regExpress) && !Judge_votes(fromQQ, fromGroup))
				{
					wstr1 = ms.str(1);
					str1 = wstos(wstr1);
					int num1;
					num1 = stoi(str1);
					if (num1 == 1)
					{
						setvotes(1, fromGroup);
						setvotes_total(fromGroup);
						CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=9989]同意,投票成功");
						setJudge_vote(fromQQ, fromGroup, "是");
					}
					if (num1 == 0)
					{
						setvotes(0, fromGroup);
						setvotes_total(fromGroup);
						CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=10060]反对,投票成功");
						setJudge_vote(fromQQ, fromGroup, "是");
					}
				}
				int votes_total = getvotes_total(fromGroup);
				if (getvotes(1, fromGroup) > double(num / 2))
				{
					reply += "[CQ:emoji,id=127937]已有超过半数玩家同意结束此局游戏\n[CQ:emoji,id=127937]游戏异常结束,所有玩家没有奖励\n========欢迎继续体验=========\n";
					string players[18];
					string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
					getkey(path.c_str(), players, num);
					for (int i = 0; i < num; i++)
					{
						delcontent("..\\files\\Player_Group.cfg", players[i]);
					}

					reset(fromGroup);
					resetvotes(fromGroup);
				}
				if (votes_total == num && getvotes(1, fromGroup) <= double(num / 2))
					reply += "[CQ:emoji,id=127937]至少半数玩家不同意结束此轮游戏,游戏继续进行\n";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;

			}

		int creattime_1 = getcreattime_1(fromGroup,sendTime);

		if (sendTime - creattime_1 > 600 && Game_creat(fromGroup)&& sendTime - creattime_1 < 610)
		{
			string reply = "[CQ:emoji,id=128336]\n游戏时间已达到十分钟，剩余时间五分,请掌握好游戏速度\n超过规定时间所有人将失去游戏奖励,游戏将自动结束";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		if (sendTime - creattime_1 > 900 && Game_creat(fromGroup))
		{
			string reply = "[CQ:emoji,id=128337]\n游戏时间已达到十五分钟，本局自动结束，所有人没有奖励\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			reset(fromGroup);
			resetvotes(fromGroup);
		}
		
		if (smsg == "开始谁是卧底"&&num >= 5 && Game_creat(fromGroup)&&!Game_start(fromGroup) )
		{
			string players[12];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);
			if (fromQQ == To_Int64(players[0]))
			{
				reply = "[CQ:emoji,id=9989]谁是卧底游戏开始\n[CQ:emoji,id=128212]正在分配角色，请注意查看私聊消息......";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				string value;
				string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
				readConfigFile(path.c_str(), "游戏词组", value);
				
				size_t pos = value.find('&');
				if (pos == string::npos)
				{
					CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=10060]系统匹配出错!!error!");
					reset(fromGroup);
					return EVENT_BLOCK;
				}
				writeConfigFile(path.c_str(), "游戏开始", "是");

				string roles[3];
				roles[0] = value.substr(0, pos);
				roles[1] = value.substr(pos + 1);
				roles[2] = "空白";
				int count1 = 0;
				int count2 = 0;
				int count3 = 0;
				int i = 0;
				srand(time(NULL));
				if (5 <= num && num <= 7)
				{
					//一个卧底，一个空白，其他平民
					setciviliav(fromGroup, num - 2);
					setspy(fromGroup, 1);
					setblank(fromGroup, 1);
				
					while (i < num)
					{
						int x = 1+rand() % 10;
						if (x <= 6 && count1 < num - 2)
						{
							count1++;
							setroles(To_Int64(players[i]), fromGroup, roles[0]);
							setCommonRoles(To_Int64(players[i]), fromGroup, "平民");
							i++;
						}
						if (x > 6 && x <= 8 && count2 < 1)
						{
							count2++;
							setroles(To_Int64(players[i]), fromGroup, roles[1]);
							setCommonRoles(To_Int64(players[i]), fromGroup, "卧底");
							i++;
						}
						if (x > 8 && count3 < 1)
						{
							count3++;
							setroles(To_Int64(players[i]), fromGroup, roles[2]);
							setCommonRoles(To_Int64(players[i]), fromGroup, "空白");
							i++;
						}
					}
				}
				else if (num >= 8 && num <= 10)
				{
					//2个卧底，一个空白，其他平民
					setciviliav(fromGroup, num - 3);
					setspy(fromGroup, 2);
					setblank(fromGroup, 1);
					while (i < num)
					{
						int x =1+ rand() % 10;
						if (x <= 6 && count1 < num - 3)
						{
							count1++;
							setroles(To_Int64(players[i]), fromGroup, roles[0]);
							i++;
						}
						if (x > 6 && x <= 8 && count2 < 2)
						{
							count2++;
							setroles(To_Int64(players[i]), fromGroup, roles[1]);
							i++;
						}
						if (x > 8 && count3 < 1)
						{
							count3++;
							setroles(To_Int64(players[i]), fromGroup, roles[2]);
							i++;
						}
					}
				}
				else
				{
					//2个卧底，3个空白，其他平民
					setciviliav(fromGroup, num - 5);
					setspy(fromGroup, 2);
					setblank(fromGroup, 3);
					while (i < num)
					{
						int x = 1+rand() % 10;
						if (x <= 6 && count1 < num - 5)
						{
							count1++;
							setroles(To_Int64(players[i]), fromGroup, roles[0]);
							i++;
						}
						if (x > 6 && x <= 8 && count2 < 2)
						{
							count2++;
							setroles(To_Int64(players[i]), fromGroup, roles[1]);
							i++;
						}
						if (x > 8 && count3 < 3)
						{
							count3++;
							setroles(To_Int64(players[i]), fromGroup, roles[2]);
							i++;
						}
					}
				}
				string results;
				num = getplayer_numbers(fromGroup);
				for (int i = 0; i < num; i++)
				{
					results=getroles(To_Int64(players[i]), fromGroup);
					string Preply = "[CQ:emoji,id=128100]您的身份：" + results;
					CQ_sendPrivateMsg(ac, To_Int64(players[i]), Preply.c_str());
				}
				
				reply = "请依次发言并选择投出玩家编号\n玩家编号列表: \n";
				for (int i = 0; i < num; i++)
					reply += getNickname(players[i])+"("+players[i] +")"+ "  " + To_Str(i + 1) + "号\n";
				reply += "本剧配置: \n[CQ:emoji,id=128694]平民: " + To_Str(count1) + "人\n[CQ:emoji,id=128101]卧底: " + To_Str(count2) + "人\n[CQ:emoji,id=128172]空白: " + To_Str(count3) + "人\n";

				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				
			}
		}

		if (Game_start(fromGroup) && judgeplayers(fromQQ, fromGroup) && game1(fromGroup))
		{
			num = getplayer_numbers(fromGroup);
			string players[12];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);

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

			if (std::regex_search(text, ms, regExpress) && !Judge_votes(fromQQ, fromGroup))
			{
				wstr1 = ms.str(1);
				str1 = wstos(wstr1);
				int num1;
				num1 = stoi(str1);
				if (num1 <= num)
				{
					setvotes(To_Int64(players[num1 - 1]), fromGroup);
					setvotes_total(fromGroup);
					CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=9989]投票成功");
					setJudge_vote(fromQQ, fromGroup, "是");
				}
			}
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
					CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
					resetvotes(fromGroup);
				}
				else
				{
					reply += players[temp] + "[CQ:emoji,id=128202]因获得最高票数被投出\n";
					string playerroles = getCommonRoles(To_Int64(players[temp]), fromGroup);

						if (playerroles == "平民")
						{
							reply += "[CQ:emoji,id=128694]！！！平民被冤死！！！[CQ:emoji,id=128128]\n";
							subciviliavg(fromGroup);
						}
						else if (playerroles == "卧底")
						{
							reply += "[CQ:emoji,id=128101]成功解决一名卧底[CQ:emoji,id=128128]\n";
							subspy(fromGroup);
						}
						else
						{
						reply += "[CQ:emoji,id=128172]....其为空白....[CQ:emoji,id=128128]\n";
						subblank(fromGroup);
						}
						path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
						delcontent(path.c_str(), players[temp]);
						subplayer(fromGroup);
						resetvotes(fromGroup);
						num = getplayer_numbers(fromGroup);
						getkey(path.c_str(), players, num);
						path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
						reply += "[CQ:emoji,id=128113]请依次发言并选择投出玩家编号\n玩家编号列表: \n";
						for (int i = 0; i < num; i++)
							reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "号\n";
						CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
					

					if ((getspy_numbers(fromGroup) == 0 && getciviliav_numbers(fromGroup) == 0) || 
						(getspy_numbers(fromGroup) == 0 && getblank_numbers(fromGroup) == 0) ||
						(getciviliav_numbers(fromGroup) == 0 && getblank_numbers(fromGroup) == 0)||
						(getspy_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 1 && getciviliav_numbers(fromGroup) == 0) ||
						(getspy_numbers(fromGroup) == 1 && getciviliav_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 0) ||
						(getciviliav_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 1 && getspy_numbers(fromGroup) == 0))
					{
						string reply = "[CQ:emoji,id=10062]本轮游戏结束\n";
						string civiliav[7];
						string spy[2];
						string blank[3];
						int i = 0, j = 0, k = 0;
						fstream cfgFile;
						path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
						cfgFile.open(path.c_str());//打开文件      

						char tmp[1000];
						while (!cfgFile.eof())//循环读取每一行  
						{
							cfgFile.getline(tmp, 1000);//每行读取前1000个字符，1000个应该足够了  
							string line(tmp);
							size_t pos = line.find('=');
							if (pos == string::npos) continue;
							string tempvalue = line.substr(pos + 1);//取等号之后

							if (tempvalue == "平民")
							{
								civiliav[i] = line.substr(0, pos);
								i++;
							}
							else 	if (tempvalue == "卧底")
							{
								spy[j] = line.substr(0, pos);
								j++;
							}
							else 	if (tempvalue == "空白")
							{
								blank[k] = line.substr(0, pos);
								k++;
							}
						}

						string value;
						string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
						readConfigFile(path.c_str(), "游戏词组", value);
						size_t pos = value.find('&');
						string roles[2];
						roles[0] = value.substr(0, pos);
						roles[1] = value.substr(pos + 1);

						reply += "本轮的平民词汇为: " + roles[0] + "\n本轮的卧底词汇为: " + roles[1];
						reply += "\n[CQ:emoji,id=128694]本轮的平民为: \n";
					
						for (int m = 0; m < i; m++)
						{
							reply += civiliav[m] + "\n";
						}
						reply += "[CQ:emoji,id=128101]本轮的卧底为: \n";
						for (int m = 0; m < j; m++)
						{
							reply += spy[m] + "\n";
						}
						reply += "[CQ:emoji,id=128172]本轮的空白为: \n";
						for (int m = 0; m < k; m++)
						{
							reply += blank[m] + "\n";
						}

						if (getspy_numbers(fromGroup) == 0 && getciviliav_numbers(fromGroup) == 0)
						{
							//空白赢
							reply += "[CQ:emoji,id=128172]最终结果: 空白胜,胜利方将获得2000金币奖励[CQ:emoji,id=127881]";
							for (int m = 0; m < k; m++)
								getmoney(To_Int64(blank[m]), fromGroup, 2000);
						}
						else if (getspy_numbers(fromGroup) == 0 && getblank_numbers(fromGroup) == 0)
						{
							//平民赢
							reply += "[CQ:emoji,id=128694]最终结果: 平民胜,胜利方将获得2000金币奖励[CQ:emoji,id=127881]";
							for (int m = 0; m < i; m++)
								getmoney(To_Int64(civiliav[m]), fromGroup, 2000);
						}
						else if((getciviliav_numbers(fromGroup) == 0 && getblank_numbers(fromGroup) == 0))
						{
							//卧底赢
							reply += "[CQ:emoji,id=128101]最终结果: 卧底胜,胜利方将获得2000金币奖励[CQ:emoji,id=127881]";
							for (int m = 0; m < j; m++)					
								getmoney(To_Int64(spy[m]), fromGroup, 2000);
							
						}

						else if ((getspy_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 1 && getciviliav_numbers(fromGroup) == 0))
						{
							//卧底和空白平,平民输
							reply += "[CQ:emoji,id=128101]最终结果: 卧底方和空白方持平,每方将获得800金币奖励[CQ:emoji,id=128172]";
							for (int m = 0; m < j; m++)
								getmoney(To_Int64(spy[m]), fromGroup, 800);
							for (int m = 0; m < k; m++)
								getmoney(To_Int64(blank[m]), fromGroup, 800);

						}
						else if ((getspy_numbers(fromGroup) == 1 && getciviliav_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 0))
						{
							//卧底赢
							reply += "[CQ:emoji,id=128101]最终结果: 卧底胜,胜利方将获得2000金币奖励[CQ:emoji,id=127881]";
							for (int m = 0; m < j; m++)
								getmoney(To_Int64(spy[m]), fromGroup, 2000);
						}
						else
						{
							reply += "[CQ:emoji,id=128172]最终结果: 空白胜,胜利方将获得2000金币奖励[CQ:emoji,id=127881]";
							for (int m = 0; m < k; m++)
								getmoney(To_Int64(blank[m]), fromGroup, 2000);
						}
                          CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
                          reset(fromGroup);
					}
				}
			}

		}


//经验和金币排行榜查看..................................................................................................................................................

		if (smsg == "金币排行" || smsg == "金币排行榜"&&!Game_start(fromGroup))
		{
			reply = moneyRank(fromQQ, fromGroup);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		if (smsg == "经验排行" || smsg == "经验排行榜" && !Game_start(fromGroup))
		{
			reply = expRank(fromQQ, fromGroup);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}

//狼人杀游戏.............................................................................................................................................................
		if (smsg == "狼人杀介绍" && !Game_start(fromGroup))
		{
			reply = "=====欢迎体验功能型机器人=====\n该游戏适合人数为6--18人\n游戏限制时长为40分钟(包含创建房间后的等待时间)\n房主发送 创建狼人杀 创建房间(需金币600)\n玩家发送 加入/参加/参与狼人杀 加入房间(需金币400)\n";
			reply += "房主有权踢出任一玩家(金币返还380) 直接@即可\n房间人数达5人及以上是房主可发送 开始狼人杀 开始游戏\n游戏开始后Android将随机分派身份(狼人,村民,预言家,女巫,猎人)\n";
			reply += "玩家拿到身份后请按照Android要求进行操作\n随后按照发言内容针对编号进行投票 (例: 1/1号)\n不同人数房间将有不同数量的狼人和村民,由于人数原因可能会减少女巫和猎人角色\n";
			reply += "直至狼人阵营全部阵亡或狼人阵营人数超过好人阵营,游戏结束\n\n";
			reply += "浅谈狼人杀规则: \n村民: 好人阵营,最普通的投票者\n狼人: 每晚行动,选择杀害一个玩家(自行私聊统一,否则取最高票数)\n";
			reply += "预言家: 好人阵营,每晚查看一名角色身份(私聊Android)\n女巫: 好人阵营,当玩家被杀害后,可以选择救与不救,技能只可使用一次,按Android要求操作\n";
			reply += "猎人: 好人阵营,死亡时可带走一名玩家,按Android要求操作\n警长: 由第一个白天选出,其具有一票等两票的特权,死亡后可传承\n";
			reply += "好人阵营胜利每人将获得80exp奖励\n狼人阵营胜利将获得100exp奖励\n祝您游戏愉快!!!";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}

		num = getplayer_numbers(fromGroup);
		if (smsg == "创建狼人杀" && !Game_creat(fromGroup) && m >= 600 && !in_Group(fromQQ))
		{
			string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
			writeConfigFile(path.c_str(), "游戏创建", "是");
			setroles(fromQQ, fromGroup, "空");
			set_game2(fromGroup);
			addplayer(fromGroup);
			setcreattime_2(fromGroup, sendTime);
			getWordGroup(fromGroup);
			reply = "[CQ:emoji,id=128227]......欢迎体验功能型机器人.....\n" + atone + "[CQ:emoji,id=127759]您已成功创建房间，消耗金币600,请等待其他玩家加入\n[CQ:emoji,id=128353]当前玩家数量：1\n(玩家人数达到6后可发送 开始狼人杀 进行游戏";
			losemoney(fromQQ, fromGroup, 600);
			set_playergroup(fromQQ, fromGroup);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if (smsg == "创建狼人杀" && Game_creat(fromGroup))
		{
			reply = atone + "[CQ:emoji,id=128336]当前有尚未结束的游戏，请稍后再来";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if (smsg == "创建狼人杀" && m < 600)
		{
			reply = atone + "[CQ:emoji,id=128336]金币不足,请赚钱后再来....";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if (smsg == "创建狼人杀" &&in_Group(fromQQ))
		{
			reply = atone + "[CQ:emoji,id=128336]您已在其他群中参加了狼人杀游戏,请结束游戏后再来";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}

		if ((smsg == "参加狼人杀" || smsg == "参与狼人杀" || smsg == "加入狼人杀") && Game_creat(fromGroup) && num < 18 && !Game_start(fromGroup) && !judgeplayers(fromQQ, fromGroup) && m >= 400&&!in_Group(fromQQ))
		{
			setroles(fromQQ, fromGroup, "空");
			addplayer(fromGroup);
			num = getplayer_numbers(fromGroup);
			string Num = To_Str(num);
			reply = "[CQ:emoji,id=128227]......欢迎体验功能型机器人.....\n" + atone + "[CQ:emoji,id=127759]您已成功加入房间，消耗金币400,请等待其他玩家加入\n[CQ:emoji,id=128353]当前玩家数量：" + Num;
			losemoney(fromQQ, fromGroup, 400);
			set_playergroup(fromQQ, fromGroup);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;

		}
		else if ((smsg == "参加狼人杀" || smsg == "参与狼人杀" || smsg == "加入狼人杀") && !Game_creat(fromGroup) && !in_Group(fromQQ))
		{
			reply = atone + "当前还没有房间，请等待或自己主持";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "参加狼人杀" || smsg == "参与狼人杀" || smsg == "加入狼人杀") && num >= 18)
		{
			reply = atone + "当前房间人数已满，请等待下一局";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "参加狼人杀" || smsg == "参与狼人杀" || smsg == "加入狼人杀") && judgeplayers(fromQQ, fromGroup))
		{
			reply = atone + "[CQ:emoji,id=128336]你已在房间中，请等待....";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "参加狼人杀" || smsg == "参与狼人杀" || smsg == "加入狼人杀") && m < 400)
		{
			reply = atone + "[CQ:emoji,id=128336]金币不足,请赚钱后再来....";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "参加狼人杀" || smsg == "参与狼人杀" || smsg == "加入狼人杀") && m >= 400 && Game_start(fromGroup))
		{
			reply = atone + "[CQ:emoji,id=128336]当前游戏已开始,请等下轮.....";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "参加狼人杀" || smsg == "参与狼人杀" || smsg == "加入狼人杀") && in_Group(fromQQ))
		{
		reply = atone + "[CQ:emoji,id=128336]您已在其他群中参加了狼人杀游戏,请结束游戏后再来";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
         }

		int creattime_2 = getcreattime_2(fromGroup,sendTime);
		if (sendTime - creattime_2 > 1800 && Game_creat(fromGroup) && sendTime - creattime_2 < 1820 && game2(fromGroup))
		{
			string reply = "[CQ:emoji,id=128336]\n游戏时间已达到30分钟，剩余时间10分,请掌握好游戏速度\n超过规定时间所有人将失去游戏奖励,游戏将自动结束";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		if (sendTime - creattime_2 > 2400 && Game_creat(fromGroup) && game2(fromGroup))
		{
			string reply = "[CQ:emoji,id=128337]\n游戏时间已达到40分钟，本局自动结束，所有人没有奖励\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			reset(fromGroup);
			resetvotes(fromGroup);
		}

		if (smsg == "开始狼人杀"&&num >= 6 && Game_creat(fromGroup) && !Game_start(fromGroup) && game2(fromGroup))
		{
			string players[18];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);
			if (fromQQ == To_Int64(players[0]))
			{
				reply = "[CQ:emoji,id=9989]狼人杀游戏开始\n[CQ:emoji,id=128212]正在分配角色，请注意查看私聊消息......";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
				writeConfigFile(path.c_str(), "游戏开始", "是");
				string gameroles[5];
				gameroles[0] = "狼人";
				gameroles[1] = "村民";
				gameroles[2] = "女巫";
				gameroles[3] = "猎人";
				gameroles[4] = "预言家";
				int count0 = 0;
				int count1 = 0;
				int count2 = 0;
				int count3 = 0;
				int count4 = 0;
				srand(time(NULL));
				int i = 0;
				setseer_die(fromGroup, "否");
				
				if ( 6<= num && num <=9)
				{
					//2狼 1预言家 1女巫 (num-4)民
					setwitch_die(fromGroup, "否");
					setwerewolves(fromGroup, 2);
					setvillager(fromGroup, num-4);
					while (i < num)
					{
						int x = 1 + rand() % 14;
						int c = 5;
						c = choose_set_role2(x, count0, count1, count2, count3, count4, num,4,2);
						if (c == 5)
							continue;
						else
						{
							setroles(To_Int64(players[i]), fromGroup, gameroles[c]);
							setCommonRoles(To_Int64(players[i]), fromGroup, gameroles[c]);
							i++;
						}
					}
				}
				else if (num >=10 && num <= 12)
				{
					//2狼 1预言家 1女巫 1猎人 (num-5)民
					setwitch_die(fromGroup, "否");
					sethunter_die(fromGroup, "否");
					setwerewolves(fromGroup, 2);
					setvillager(fromGroup, num-5);
					while (i < num)
					{
						int x = 1 + rand() % 15;
						int c = 5;
						c = choose_set_role2(x, count0, count1, count2, count3, count4, num,5,2);
						if (c == 5)
							continue;
						else
						{
							setroles(To_Int64(players[i]), fromGroup, gameroles[c]);
							setCommonRoles(To_Int64(players[i]), fromGroup, gameroles[c]);
							i++;
						}
					}
				}
				else if(num>12&&num<=15)
				{
					//3狼 1预言家 1女巫 1猎人 (num-6)民
					setwitch_die(fromGroup, "否");
					sethunter_die(fromGroup, "否");
					setwerewolves(fromGroup, 3);
					setvillager(fromGroup, num-6);
				
					while (i < num)
					{
						int x = 1 + rand() % 15;
						int c = 5;
						c = choose_set_role2(x, count0, count1, count2, count3, count4, num,6,3);
						if (c == 5)
							continue;
						else
						{
							setroles(To_Int64(players[i]), fromGroup, gameroles[c]);
							setCommonRoles(To_Int64(players[i]), fromGroup, gameroles[c]);
							i++;
						}
					}
				}
				else if (num > 15 && num <= 18)
				{
					//4狼 1预言家 1女巫 1猎人 (num-7)民
					setwitch_die(fromGroup, "否");
					sethunter_die(fromGroup, "否");
					setwerewolves(fromGroup, 4);
					setvillager(fromGroup, num - 7);
					while (i < num)
					{
						int x = 1 + rand() % 15;
						int c = 5;
						c = choose_set_role2(x, count0, count1, count2, count3, count4, num,7,4);
						if (c == 5)
							continue;
						else
						{
							setroles(To_Int64(players[i]), fromGroup, gameroles[c]);
							setCommonRoles(To_Int64(players[i]), fromGroup, gameroles[c]);
							i++;
						}
					}
				}
				string results;
				num = getplayer_numbers(fromGroup);
				for (int i = 0; i < num; i++)
				{
					results = getroles(To_Int64(players[i]), fromGroup);
					string Preply = "[CQ:emoji,id=128100]您的身份：" + results;
					CQ_sendPrivateMsg(ac, To_Int64(players[i]), Preply.c_str());
				}
				reply = "[CQ:emoji,id=128213]玩家编号列表: \n";
				for (int i = 0; i < num; i++)
					reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "号\n";
			
				reply += "[CQ:emoji,id=128127]狼人 :发送 杀+编号(例:杀(1)号)\n狼人请自行商量,统一投票,否则取最高票数\n[CQ:emoji,id=128124]预言家: 发送 查+编号(例:查1(号))\n[CQ:emoji,id=128299]猎人: 死亡后可发送 带走 带走一名玩家(例:带走1)\n[CQ:emoji,id=128120]女巫: 发送 是||否(例:是)\n[CQ:emoji,id=128290]";
				reply += "本局配置: \n[CQ:emoji,id=128127]狼人: " + To_Str(count0) + "\n[CQ:emoji,id=128104]村民: " + To_Str(count1) + "\n[CQ:emoji,id=128124]预言家: 1\n[CQ:emoji,id=128120]女巫: 1\n";
				if (num >= 10)
					reply += "[CQ:emoji,id=128299]猎人: 1\n";

				
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				setWhoseturn(fromGroup, "狼人回合");
			}
		}
		int num_2 = getwerewolves_numbers(fromGroup);
		int mun_3 = getvillager_numbers(fromGroup);
		num = getplayer_numbers(fromGroup);

		if (Game_start(fromGroup) && judge_Whoseturn(fromGroup, "白天") && game2(fromGroup) && judgeplayers(fromQQ, fromGroup))
		{
			
			string reply;
			int hunterdie = 0;
			reply = votes(fromQQ, fromGroup, smsg,hunterdie);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			if (hunterdie==1)
			{
				Sleep(55000);
				sethunter_die(fromGroup, "是");
			}

			if (getwerewolves_numbers(fromGroup) == 0 || getwerewolves_numbers(fromGroup) > num - getwerewolves_numbers(fromGroup))
			{
				string reply = over(fromGroup);
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
		}

		num = getplayer_numbers(fromGroup);
		if (Game_start(fromGroup) && num!= 0 &&(smsg=="查看玩家列表"||smsg=="查看编号" ||smsg=="编号列表"||smsg=="玩家编号"||smsg=="玩家列表") && judgeplayers(fromQQ, fromGroup))
		{
			string players[18];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);
			reply = "[CQ:emoji,id=128213]玩家编号列表: \n";
			for (int i = 0; i < num; i++)
				reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "号\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}

		if (judge_Whoseturn(fromGroup, "狼人回合") && Game_start(fromGroup)&&num_2!=0 && game2(fromGroup))
		{
			string wolves[4];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey_withStr(path.c_str(), wolves, num_2,"狼人");
			int num_2 = getwerewolves_numbers(fromGroup);

			reply="[CQ:emoji,id=127762]天黑请闭眼\n狼人请睁眼\n狼人请杀人\n[CQ:emoji,id=128127]狼人 :发送 杀+编号(例:杀1)\n狼人请自行商量,统一投票,否则取最高票数\n";
			num = getplayer_numbers(fromGroup);
			string players[18];
			getkey(path.c_str(), players, num);
			reply += "\n[CQ:emoji,id=128113]玩家编号列表: \n";
			for (int i = 0; i < num; i++)
				reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "号\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			
			
			string preply = "\n[CQ:emoji,id=128127]本局您的狼人伙伴为: \n";
			for (int i = 0; i < num_2; i++)
				preply += getNickname(wolves[i]) + "(" + wolves[i] + ")\n";
			for (int i = 0; i < num_2; i++)
				CQ_sendPrivateMsg(ac, To_Int64(wolves[i]), preply.c_str());
			setWhoseturn(fromGroup, "狼人杀人");
		}

		if (!judgeplayers(fromQQ, fromGroup) && hunter_live(fromGroup) && judge_roles(fromQQ, fromGroup, "猎人") && game2(fromGroup))
		{

			int num = getplayer_numbers(fromGroup);
			string players[12];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);

			wstring wstr1(_T(""));
			string str1;
			wstring text = stows(smsg);
			string reply = "";

			std::wstring regString(_T("带走(\\d+)(?:号|)"));

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
				int temp;
				temp = stoi(str1);
				if (temp <= num)
				{
					int64_t killedQQ = To_Int64(players[temp]);
					string killedrole = getroles(killedQQ, fromGroup);
					reply = "[CQ:emoji,id=128299]猎人选择带走" + getNickname(players[temp]) + "(" + players[temp] + ")\n";
					if (killedrole == "村民")
					{
					subvillager(fromGroup);
					reply += "带走玩家身份为 村民\n";
				}
					else if (killedrole == "狼人")
					{
						subwerewolves(fromGroup);
						reply += "带走玩家身份为 狼人\n";
					}
					else if (killedrole == "预言家")
					{
						setseer_die(fromGroup, "是");
						reply += "带走玩家身份为 预言家\n";
					}

					else if (killedrole == "女巫")
					{
						setwitch_die(fromGroup, "是");
						reply += "带走玩家身份为 女巫\n";
					}
					if (judgeSheriff(killedQQ, fromGroup))
						reply += "[CQ:emoji,id=128110]警长已被杀死,请尽快选择玩家传承---\n";
					path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
					delcontent(path.c_str(), players[temp]);
					delcontent("..\\files\\Player_Group.cfg", players[temp]);
					subplayer(fromGroup);
					resetvotes(fromGroup);
					num = getplayer_numbers(fromGroup);
					getkey(path.c_str(), players, num);
					reply += "[CQ:emoji,id=128113]玩家编号列表: \n";
					for (int i = 0; i < num; i++)
						reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "号\n";
				}
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				sethunter_die(fromGroup,"是");
			}
		}
				
		if (!judgeplayers(fromQQ, fromGroup) && judgeSheriff(fromQQ, fromGroup) && game2(fromGroup))
		{
			int num = getplayer_numbers(fromGroup);
			string players[12];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);

			wstring wstr1(_T(""));
			string str1;
			wstring text = stows(smsg);
			string reply = "";

			std::wstring regString(_T("传给(\\d+)(?:号|)"));

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
				int temp;
				temp = stoi(str1);
				if (temp <= num)
					setSheriff(fromGroup, players[temp - 1]);
				reply += "警长已成功传承,请新任警长发言: \n";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			}
		}
	
		
		if (smsg == "更新日志"||smsg=="更新说明"||smsg=="更新介绍")
		{
			string ureply = "[CQ:emoji,id=9989]版本号: 1.20\n本次更新内容如下: \n1.增加谁是卧底最终显示双方词汇功能\n2.增加金币不足提示\n";
				ureply+="3.猜数花费金额提高到1200\n4.修复猜数BUG\n5.增加魔法数游戏,欢迎体验(详情见 魔法数介绍)\n6.即将推出魔法数多人对战版\n更多功能,敬请期待..... ";
			CQ_sendGroupMsg(ac, fromGroup, ureply.c_str());
			return EVENT_BLOCK;
		}




return EVENT_IGNORE;

}

/*
* Type=4 讨论组消息
*/
CQEVENT(int32_t, __eventDiscussMsg, 32)(int32_t subType, int32_t sendTime, int64_t fromDiscuss, int64_t fromQQ, const char *msg, int32_t font) {

	return EVENT_IGNORE; 
}


/*
* Type=101 群事件-管理员变动
* subType 子类型，1/被取消管理员 2/被设置管理员
*/
CQEVENT(int32_t, __eventSystem_GroupAdmin, 24)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t beingOperateQQ) {

	return EVENT_IGNORE; 
}


/*
* Type=102 群事件-群成员减少
* subType 子类型，1/群员离开 2/群员被踢 3/自己(即登录号)被踢
* fromQQ 操作者QQ(仅subType为2、3时存在)
* beingOperateQQ 被操作QQ
*/
CQEVENT(int32_t, __eventSystem_GroupMemberDecrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {

	return EVENT_IGNORE; 
}


/*
* Type=103 群事件-群成员增加
* subType 子类型，1/管理员已同意 2/管理员邀请
* fromQQ 操作者QQ(即管理员QQ)
* beingOperateQQ 被操作QQ(即加群的QQ)
*/
CQEVENT(int32_t, __eventSystem_GroupMemberIncrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {

	return EVENT_IGNORE; 
}


/*
* Type=201 好友事件-好友已添加
*/
CQEVENT(int32_t, __eventFriend_Add, 16)(int32_t subType, int32_t sendTime, int64_t fromQQ) {

	return EVENT_IGNORE;
}


/*
* Type=301 请求-好友添加
* msg 附言
* responseFlag 反馈标识(处理请求用)
*/
CQEVENT(int32_t, __eventRequest_AddFriend, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, const char *responseFlag) {

	//CQ_setFriendAddRequest(ac, responseFlag, REQUEST_ALLOW, "");

	return EVENT_IGNORE; 
}


/*
* Type=302 请求-群添加
* subType 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
* msg 附言
* responseFlag 反馈标识(处理请求用)
*/
CQEVENT(int32_t, __eventRequest_AddGroup, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *msg, const char *responseFlag) {

	//if (subType == 1) {
	//	CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPADD, REQUEST_ALLOW, "");
	//} else if (subType == 2) {
	//	CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPINVITE, REQUEST_ALLOW, "");
	//}

	return EVENT_IGNORE; //关于返回值说明, 见“_eventPrivateMsg”函数
}

/*
* 菜单，可在 .json 文件中设置菜单数目、函数名
* 如果不使用菜单，请在 .json 及此处删除无用菜单
*/
CQEVENT(int32_t, __menuA, 0)() {
	MessageBoxA(NULL, "私聊功能: (详细内容发送 菜单 查询)\n 主人QQ控制Android在群里讲话\n 主人QQ有权变更主人QQ \n 成语查询 \n 计算功能 \n 昵称查询功能 \n 游戏中对话功能 \n\n\n 作者QQ：1069148429", "" ,0);
	return 0;
}

CQEVENT(int32_t, __menuB, 0)() {
	MessageBoxA(NULL, "群聊功能: (详细内容发送 菜单 查询)\n 签到功能 \n 成语查询功能 \n 计算功能 \n 主人QQ控制Android在群里讲话 \n 猜数功能 \n 排行榜查询功能 \n 个人信息查询功能 \n 谁是卧底游戏 \n 狼人杀游戏 \n\n\n 作者QQ：1069148429", "" ,0);
	return 0;
}
