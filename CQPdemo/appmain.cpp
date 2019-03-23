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
#include "appmain.h" //Ӧ��AppID����Ϣ������ȷ��д�������Q�����޷�����

using namespace std;

int ac = -1; //AuthCode ���ÿ�Q�ķ���ʱ��Ҫ�õ�
bool enabled = false;
string masterQQ="1069148429";
string lastStatus = "������";
/* 
* ����Ӧ�õ�ApiVer��Appid������󽫲������
*/
CQEVENT(const char*, AppInfo, 0)() {
	return CQAPPINFO;
}


/* 
* ����Ӧ��AuthCode����Q��ȡӦ����Ϣ��������ܸ�Ӧ�ã���������������������AuthCode��
* ��Ҫ�ڱ��������������κδ��룬���ⷢ���쳣���������ִ�г�ʼ����������Startup�¼���ִ�У�Type=1001����
*/
CQEVENT(int32_t, Initialize, 4)(int32_t AuthCode) {
	ac = AuthCode;
	return 0;
}


/*
* Type=1001 ��Q����
* ���۱�Ӧ���Ƿ����ã������������ڿ�Q������ִ��һ�Σ���������ִ��Ӧ�ó�ʼ�����롣
* ��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�
*/
CQEVENT(int32_t, __eventStartup, 0)() {
	

	readConfigFile("..\\files\\master.cfg", "masterQQ", masterQQ);
	return 0;
}


/*
* Type=1002 ��Q�˳�
* ���۱�Ӧ���Ƿ����ã������������ڿ�Q�˳�ǰִ��һ�Σ���������ִ�в���رմ��롣
* ������������Ϻ󣬿�Q���ܿ�رգ��벻Ҫ��ͨ���̵߳ȷ�ʽִ���������롣
*/
CQEVENT(int32_t, __eventExit, 0)() {
	
	return 0;
}

/*
* Type=1003 Ӧ���ѱ�����
* ��Ӧ�ñ����ú󣬽��յ����¼���
* �����Q����ʱӦ���ѱ����ã�����_eventStartup(Type=1001,��Q����)�����ú󣬱�����Ҳ��������һ�Ρ�
* ��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�
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
				reply = "cookie�ѱ��������������쳣���뼰ʱ����";
				CQ_sendPrivateMsg(ac, 1069148429, reply.c_str());
			}
			else if (reply != lastStatus) {
				lastStatus = reply;
				reply = "����״̬�ѱ�����뾡��鿴  ��״̬��" + reply;
				CQ_sendPrivateMsg(ac, 1069148429, reply.c_str());
				writeConfigFile(path.c_str(), qq, lastStatus);
			}
			//else {
			//	reply = "��ǰ״̬��" + reply + " ��һ��״̬��" + lastStatus;
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
* Type=1004 Ӧ�ý���ͣ��
* ��Ӧ�ñ�ͣ��ǰ�����յ����¼���
* �����Q����ʱӦ���ѱ�ͣ�ã��򱾺���*����*�����á�
* ���۱�Ӧ���Ƿ����ã���Q�ر�ǰ��������*����*�����á�
*/
CQEVENT(int32_t, __eventDisable, 0)() {
	enabled = false;
	return 0;
}


/*
* Type=21 ˽����Ϣ**************************************************************************************************************************************************************************
* subType �����ͣ�11/���Ժ��� 1/��������״̬ 2/����Ⱥ 3/����������
*/
CQEVENT(int32_t, __eventPrivateMsg, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, int32_t font) {
	string smsg(msg);
	string reply;
//�����ظ�...........................................................................................................................................................
	if (smsg == "�˵�" || smsg == "���ܲ�ѯ" || smsg == "�����б�")
	{
	reply= "[CQ:emoji,id=127882]......��ӭ���鹦���ͻ�����.....[CQ:emoji,id=127882]\n";
	reply += "[CQ:emoji,id=128212]�����ѯ\n(��ʽ:����һ���޼ʽ�ʲô|ɶ||�Լʿ�ͷ�ĳ�����ʲô|ɶ|��Щ)\n";
	reply += "[CQ:emoji,id=128291]����\n(��ʽ:����63.87*98.26)\n";
	reply += "[CQ:emoji,id=9800]��ѯ�ǳ�\n[CQ:emoji,id=12953]����(��ʽ: ����Ⱥ\"(Ⱥ��)\"��˵\"(����)\"\nҪ��QQ����Ϊ����QQ)\n[CQ:emoji,id=128203]��������QQ|qq(QQ��)\n��Ϸ������˽�Ļظ�";
	CQ_sendPrivateMsg(ac, fromQQ, reply.c_str());
	return EVENT_BLOCK;
	}

	if (smsg == "���" || smsg == "��ð�"|| smsg == "���ѽ") {
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=128512]��ð�");
		return EVENT_BLOCK;
	}
		
	if (smsg == "������������") {
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=127748]ף��ȹ����ĵ�һ��");
		return EVENT_BLOCK;
	}
		
	if (smsg == "лл��" || smsg == "лл") {
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=128080]��������");
		return EVENT_BLOCK;
	}
		


	if (smsg == "�鿴״̬"||smsg=="״̬") {
		reply = html_get_status();
		CQ_sendPrivateMsg(ac, fromQQ, reply.c_str());
		return EVENT_BLOCK;
	}
	if (smsg.substr(0,7) == "cookie "&&fromQQ== To_Int64(masterQQ)) {
		string cookie = smsg.substr(7, smsg.length());
		string qq = "1069148429";
		string path = "files\\userCookie.cfg";
		writeConfigFile(path.c_str(), qq, cookie);
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=128080]cookie�޸ĳɹ�");
		return EVENT_BLOCK;
	}
	//�齱..............................................................................................................................................................
	if (smsg == "�齱") {
		reply = "�齱ÿ������5W��ң��齱�������Ⱥ����\n��Ʒ�һ���ϵ@�ƹ㣬��ֵ����";
				CQ_sendPrivateMsg(ac, fromQQ, reply.c_str());
		return EVENT_BLOCK;
	}
	if (smsg == "��Ҫ�齱") {
		int64_t fromGroup = 854084390;
		int m= readmoney(fromQQ, fromGroup);
		if (m < 50000)
        	CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=127757]��Ҳ��㣬�齱ÿ������5W��ң���õ��㹻��Һ�����\n��ҳ�ֵ����@�ƹ㣬��ֵ����");
		else
		{
			losemoney(fromQQ, fromGroup, 50000);
			int rewardNum = realRand(500);
			if (rewardNum >= 0 && rewardNum < 9) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�����10��ӵ�з���800W��ң�";
			}
			else if (rewardNum >= 10 && rewardNum <= 39) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�����9��ӵ�з���400W��ң�";
			}
			else if (rewardNum >= 40 && rewardNum <= 99) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�����8��ӵ�з���200W��ң�";
			}
			else if (rewardNum >= 100 && rewardNum <= 104) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�������ħ���Ģ� ";
			}
			else if (rewardNum >= 105 && rewardNum <= 109) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã������ħ���Ģ�";
			}
			else if (rewardNum >= 110 && rewardNum <= 114) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�������ħ���Ģ� ";
			}
			else if (rewardNum >= 115 && rewardNum < 119) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã������ħ���Ģ� ";
			}
			else if (rewardNum >= 120 && rewardNum <= 129) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�����������*200 ";
			}
			else if (rewardNum >= 130 && rewardNum <= 149) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�ս���ػ�30��*10  ";
			}
			else if (rewardNum >= 150 && rewardNum <= 154) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�ս���ػ�30��*100 ";
			}
			else if (rewardNum >= 154 && rewardNum <= 159) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã����ʿ��װ��30��*10 ";
			}
			else if (rewardNum >= 160 && rewardNum <= 169) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã����ʿ��װ��7��*10 ";
			}
			else if (rewardNum >= 170 && rewardNum <= 189) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�100����*10 ";
			}
			else if (rewardNum >= 190 && rewardNum <= 209) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�100����*50 ";
			}
			else if (rewardNum >= 210 && rewardNum <= 219) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�100����*100 ";
			}
			else if (rewardNum >= 220 && rewardNum <= 249) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�50\%�����ӳ�*10 ";
			}
			else if (rewardNum >= 250 && rewardNum <= 259) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�50\%�����ӳ�*100  ";
			}
			else if (rewardNum >= 260 && rewardNum <= 279) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�100��������1*100 ";
			}
			else if (rewardNum >= 280 && rewardNum <= 299) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�500��������1*50 ";
			}
			else if (rewardNum >= 300 && rewardNum <= 319) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�2000��������*50 ";
			}
			else if (rewardNum >= 320 && rewardNum <= 339) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�10000��������*10 ";
			}
			else if (rewardNum >= 340 && rewardNum <= 349) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�10000��������*50 ";
			}
			else if (rewardNum >= 350 && rewardNum <= 354) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�10000��������*100  ";
			}
			else if (rewardNum >= 355 && rewardNum <= 364) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�100��������*30  ";
			}
			else if (rewardNum >= 365 && rewardNum <= 369) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�5000��������*30     ";
			}
			else if (rewardNum >= 370 && rewardNum <= 370) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�1�ڽ��    ";
			}
			else if (rewardNum >= 371 && rewardNum <= 372) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�5000W��� ";
			}
			else if (rewardNum >= 373 && rewardNum <= 379) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�1000W���";
			}
			else if (rewardNum >= 380 && rewardNum <= 389) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�800W��� ";
			}
			else if (rewardNum >= 390 && rewardNum <= 409) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�500W��� ";
			}
			else if (rewardNum >= 410 && rewardNum <= 459) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�200W��� ";
			}
			else if (rewardNum >= 460 && rewardNum <= 469) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�100W��� ";
			}
			else if (rewardNum >= 470 && rewardNum <= 479) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�100000��������*10 ";
			}
			else if (rewardNum >= 480 && rewardNum <= 485) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�100000��������*50";
			}
			else if (rewardNum >= 486 && rewardNum <= 489) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�100000��������*100";
			}
			else if (rewardNum >= 490 && rewardNum <= 499) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n��ϲ��ã�20000��������*10";
			}
			reply += "���λ񽱱��Ϊ��" + To_Str(rewardNum) + "\n[CQ:emoji,id=128176]����@�ƹ㣬��ֵ������ȡ����";
		    CQ_sendPrivateMsg(ac, fromQQ, reply.c_str());
			CQ_sendPrivateMsg(ac, 1665313816, reply.c_str());
		}
		return EVENT_BLOCK;
	}

//�����ѯ...........................................................................................................................................................
	idioms my;
	if (my.judge_sentence(smsg) != "n")
	{
		string ch = my.judge_sentence(smsg);
		string idioms_out = my.idioms_Find(ch);
		if (idioms_out == "n")
		{

			CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=128534]û���ҵ�����Ҫ�ĳ���ѽ");
			return EVENT_BLOCK;
		}
		else
		{
			idioms_out = "[CQ:emoji,id=128515]����Ҫ�ĳ������£�\n" + idioms_out;
			CQ_sendPrivateMsg(ac, fromQQ, idioms_out.c_str());
			return EVENT_BLOCK;
		}
	}

//����..................................................................................................................................................................
	if ((judgecomand2qun(smsg) != "n") && (fromQQ == To_Int64(masterQQ)))
	{
		string re =judgecomand2qun(smsg);
		string ff = re.substr(0, re.find("/"));
		string ss = re.substr(re.find("/") + 1, re.length());
		CQ_sendGroupMsg(ac, _atoi64(ff.c_str()), ss.c_str());
		return EVENT_BLOCK;
	}

//���㹦��..............................................................................................................................................................
if (smsg.substr(0, 4) == "����")
{
	int choice = getOperator(smsg);
	if (choice!=0)
	{
		wstring text = stows(smsg);
		std::wstring regString(_T("����(\\d+\\.?\\d*).(\\d*\\.?\\d*)"));

		// ���ʽѡ�� - ���Դ�Сд  
		std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

		// ����һ��������ʽ���  
		std::wregex regExpress(regString, fl);

		// ������ҵĽ��  
		std::wsmatch ms;
		// ����  
		if (std::regex_search(text, ms, regExpress))
		{
			string result;
			result = calculateFunction(choice, ms);
			CQ_sendPrivateMsg(ac, fromQQ, result.c_str());
		}
	}
	return EVENT_BLOCK;
}

//�ǳƲ�ѯ����...........................................................................................................................................................
if (smsg == "��ѯ�ǳ�")
{
	string nickname;
	nickname = getNickname(setqq_str(fromQQ));
	CQ_sendPrivateMsg(ac, fromQQ, nickname.c_str());
	return EVENT_BLOCK;
}

//�������QQ...........................................................................................................................................................
if (smsg.substr(0, 10) == "��������QQ" || smsg.substr(0, 10) == "��������qq" || smsg.substr(0, 10) == "��������QQ" || smsg.substr(0, 10) == "��������qq"&&fromQQ==To_Int64(masterQQ))
{
	size_t pos = smsg.find("��");
	string QQ = smsg.substr(pos + 3);
	if (judge_Digit(QQ))
	{
		writeConfigFile("..\\files\\master.cfg", "masterQQ", QQ);
		readConfigFile("..\\files\\master.cfg", "masterQQ", masterQQ);
	}
}

//����ɱ............................................................................................................................................................


//���˻غ�..........................................................................................................................................................

if (smsg.substr(0,2)=="ɱ"&&judge_Digit(smsg.substr(2)))
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
		
		reply = "[CQ:emoji,id=128124] Ԥ�Լ�������\nԤ�Լ������\n  Ԥ�Լ�: ���� ��+���(��1)\n[CQ:emoji,id=128341]���ڱ���Ϣ��50s��˽�Ļظ�\n[CQ:emoji,id=128290]";
		num = getplayer_numbers(fromGroup);
		getkey(path.c_str(), players, num);
		reply += "\n[CQ:emoji,id=128113]��ұ���б�: \n";
		for (int i = 0; i < num; i++)
			reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "��\n";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		
		if (seer_live(fromGroup))
			setWhoseturn(fromGroup, "Ԥ�Լһغ�");
		if (witch_live(fromGroup)&&judgeWitch_buff(fromGroup))
		{
			reply = "[CQ:emoji,id=128120]Ů��������,Ů��������һƿ��ҩ��һƿ��ҩ\n  Ů��: �뷢�� ��||�� ��ѡ�����\n�뷢�� ��+��� ��ѡ����\n[CQ:emoji,id=128341]���ڱ���Ϣ��50s��˽�Ļظ�\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			int64_t QQ = To_Int64(getplayers(fromGroup, "Ů��"));
			string Preply = "������ȥ���Ϊ: " + get_killed(fromGroup) + "\n���ڱ���Ϣ��50s�ڻظ�,����Ĭ����Ϊ����\n��ѡ���Ƿ���ҩ(��ҩ||��ҩ)\nʹ�ö�ҩ�뷢 ��+���(��:��1��)";
			CQ_sendPrivateMsg(ac, QQ, Preply.c_str());
		}
		resetvotes(fromGroup);
		
		Sleep(55000);

		setWhoseturn(fromGroup, "����");

		int64_t killedQQ = To_Int64(get_killed(fromGroup));
		string killedrole = getroles(killedQQ, fromGroup);

		if (get_killed(fromGroup) == "0" && get_poisonKilled(fromGroup)=="��")
			reply = "[CQ:emoji,id=127749]������\n  ��������û���������\n";
		else
		{
			reply = "";
			if(get_killed(fromGroup) != "0")
			reply = "[CQ:emoji,id=127749]������\n  ���������������Ϊ: "+get_killed(fromGroup)+"\n�뷢������: \n" ;
			if(get_poisonKilled(fromGroup) != "��" && get_poisonKilled(fromGroup) !=get_killed(fromGroup))
				reply += "��������Ů�׶��������Ϊ: " + get_poisonKilled(fromGroup) + "\n�������ɷ�������\n";

			if (killedrole == "����")
				subvillager(fromGroup);
			else if (killedrole == "����")
				subwerewolves(fromGroup);
			else if (killedrole == "Ԥ�Լ�")
				setseer_die(fromGroup, "��");

			else if (killedrole == "Ů��")
				setwitch_die(fromGroup, "��");
			path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			delcontent(path.c_str(), get_killed(fromGroup));delcontent("..\\files\\Player_Group.cfg", get_killed(fromGroup));
			subplayer(fromGroup);
		}
		if (!judge_haveSheriff(fromGroup))
			reply += "[CQ:emoji,id=128110]�밴������η��Ժ�ͶƱѡ������\n";
		else
			reply += "[CQ:emoji,id=128215]�밴������η��Ժ�ͶƱ\n";
		reply += "[CQ:emoji,id=128215]��ұ���б�: \n";
		num = getplayer_numbers(fromGroup);
		path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
		getkey(path.c_str(), players, num);
		for (int i = 0; i < num; i++)
			reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "��\n";
		if (judgeSheriff(killedQQ, fromGroup)|| judgeSheriff(To_Int64(get_poisonKilled(fromGroup)), fromGroup))
		{
			reply += "[CQ:emoji,id=128110]�����ѱ�ɱ��,�뾡��ѡ����Ҵ���---\n����40s�����,����û�о���\n����Ⱥ�﷢�� ����+���(��:����1) ������\n";
			Sleep(45000);
			if (judgeSheriff(killedQQ, fromGroup))
				setSheriff(fromGroup, "0000");
		}
		if (killedrole == "����")
		{
			reply += "[CQ:emoji,id=128299]����: ������ɷ��� ���� ����һ�����(����1)\n��������40s��ѡ��������,��ʱ��ʧȥ����";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			Sleep(45000);
			sethunter_die(fromGroup, "��");
		}
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		if(get_poisonKilled(fromGroup) != "��")
			set_poisonKilled(fromGroup, "��");
	}
	

	int num = getplayer_numbers(fromGroup);
	if (getwerewolves_numbers(fromGroup) == 0 || getwerewolves_numbers(fromGroup) > num - getwerewolves_numbers(fromGroup))
	{
		string reply = over(fromGroup);
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}
}

//Ԥ�Լһغ�...........................................................................................................................................................
if (smsg.substr(0, 2) == "��"&&judge_Digit(smsg.substr(2)))
{
	int64_t fromGroup = get_playergroup(fromQQ);
	int checknumber = To_Int64(smsg.substr(2));
		int num = getplayer_numbers(fromGroup);
		string players[18];
		string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
		getkey(path.c_str(), players, num);
		if (checknumber <= num&&judge_Whoseturn(fromGroup, "Ԥ�Լһغ�") && judge_roles(fromQQ, fromGroup, "Ԥ�Լ�")&&seer_live(fromGroup) && Game_start(fromGroup))
		{
			string playerrole = getroles(To_Int64(players[checknumber - 1]), fromGroup);
			string preply = "[CQ:emoji,id=128100]����������: " + playerrole;
			CQ_sendPrivateMsg(ac, fromQQ,preply.c_str());
			setWhoseturn(fromGroup, "��");
		}
}

//Ů��...........................................................................................................................................................

if (smsg.substr(0, 2) == "��"&&judge_Digit(smsg.substr(2)))
{
	int64_t fromGroup = get_playergroup(fromQQ);
	int checknumber = To_Int64(smsg.substr(2));
	int num = getplayer_numbers(fromGroup);
	if (checknumber <= num &&(judge_Whoseturn(fromGroup, "Ԥ�Լһغ�") || judge_Whoseturn(fromGroup, "��")) && judge_roles(fromQQ, fromGroup, "Ů��") && witch_live(fromGroup) && Game_start(fromGroup) && judege_poison(fromGroup))
	{
	string players[18];
	string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
	getkey(path.c_str(), players, num);
	
		string killedrole = getroles(To_Int64(players[checknumber - 1]), fromGroup);
		if (killedrole == "����")
			subvillager(fromGroup);
		else if (killedrole == "����")
			subwerewolves(fromGroup);
		else if (killedrole == "Ԥ�Լ�")
			setseer_die(fromGroup, "��");

		else if (killedrole == "Ů��")
			setwitch_die(fromGroup, "��");
		if (killedrole == "����")
			sethunter_die(fromGroup,"��");

		path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
		delcontent(path.c_str(), players[checknumber - 1]);
		delcontent("..\\files\\Player_Group.cfg", players[checknumber - 1]);
		subplayer(fromGroup);
		set_poison(fromGroup);
		set_poisonKilled(fromGroup, players[checknumber - 1]);
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=9989]��ɱ�ɹ�");
	}
}

if (smsg.substr(0, 2) == "��")
{
	int64_t fromGroup = get_playergroup(fromQQ);
	if ((judge_Whoseturn(fromGroup, "Ԥ�Լһغ�")||judge_Whoseturn(fromGroup,"��")) && judge_roles(fromQQ, fromGroup, "Ů��") && witch_live(fromGroup) && judgeWitch_buff(fromGroup) && Game_start(fromGroup)	)
	{
		setWitch_buff(fromGroup);
		set_killed(fromGroup, "��");
		CQ_sendPrivateMsg(ac, fromQQ, "[CQ:emoji,id=9989]���˳ɹ�");
	}
}

return EVENT_IGNORE;
}

/*
* Type=2 Ⱥ��Ϣ**************************************************************************************************************************************************************************************
*
*
* Type=2 Ⱥ��Ϣ**************************************************************************************************************************************************************************************
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
	//�ܲ˵�
	if ((smsg == "�˵�" || smsg == "���ܲ�ѯ" || smsg == "�����б�") && !Game_start(fromGroup))
	{
		reply = "[CQ:emoji,id=127882]......��ӭ���鹦���ͻ�����.....[CQ:emoji,id=127882]\n ����Andriod����(��ʽ: ��˵(����) \n ����QQ����Ϊ����QQ)\n";
		reply += "[CQ:emoji,id=128212]�����ѯ\n(��ʽ:����һ���޼ʽ�ʲô|ɶ||�Լʿ�ͷ�ĳ�����ʲô|ɶ|��Щ)\n";
		reply += "��ֵ\n�ƹ㣨�ƹ��\n�齱\n";
		reply += "[CQ:emoji,id=128198]ǩ��\n(�ظ�ǩ��ÿ�ο۳�100���)\n[CQ:emoji,id=128291]����\n(��ʽ:����63.87*98.26)\n[CQ:emoji,id=128185]������а�\n[CQ:emoji,id=128201]�������а�\n";
		reply += "[CQ:emoji,id=127922]����\n(��� ��������)\n[CQ:emoji,id=128101]˭���Ե�\n(��� ˭���Ե׽���)\n[CQ:emoji,id=128127]����ɱ\n(�������ɱ����)";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;

	}

	//�ƹ�
	if ((smsg == "�ƹ�" || smsg == "�ƹ���")&& fromGroup == 854084390)
	{
		reply = "һ���˵ļ���-�����ķ���\n�й����죬��߷������ķ���������ٷ��������ķ���\nWar of Kings �ȴ���ļ���\n�ǲ���cok�Ľ����Ѿ����������ƣ�ͣ����ɣ�ȫ�µĽ��������Ȼһ��\n";
		reply += "һ��˽����ֻ���������ϰ汾����Ҽ������ȥ��ƣ��������\nCOK�������ð�ȴ���ļ��룡����\n������ �������к��֣�������BOSS��������ָ�ӹ٣��з�²������������ʿ����ħ������\n";
		reply += "������ԭ��cok��һ�У������������ٷ�����������Ҫ��cok\n";
		reply += "���������д����Ľ�ҽ�������Դ�ɼ������ٶȶ���ԭ����100��\n����ֵҲ����������Ϸ����Ȥ��רҵ��������������Ľ���\n������ս������࣬��ֻ��һ��˽���ĺ���ʿ�����и�������̽��\n";
		reply += "�ȫ�����ȴ���ļ���\n�����Ⱥ����ᣬ�ļ���854084390\n�����룬������ɴ��У���100�˿�2��\n";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
	}

   //��ֵ
	if (smsg == "��ֵ"&& fromGroup == 854084390) {
		reply = "��ֵ�����뿴Ⱥ���棡��\n��ֵ���齱��ϵ@�ƹ㣬��ֵ����";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}

	//�齱
	if (smsg == "�齱"&& fromGroup == 854084390) {
		reply = "�齱ÿ������5W��ң��齱�������Ⱥ����\n�뷢�� ��Ҫ�齱 ��ʼ�齱��\n��Ʒ�һ���ϵ@�ƹ㣬��ֵ����";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}
	if (smsg == "��Ҫ�齱"&& fromGroup == 854084390) {
	
	if (m < 50000)
		CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=127757]��Ҳ��㣬�齱ÿ������5W��ң���õ��㹻��Һ�����\n��ҳ�ֵ����@�ƹ㣬��ֵ����");
	else
	{
		losemoney(fromQQ, fromGroup, 50000);
		int rewardNum = realRand(500);
		if (rewardNum>=0&&rewardNum<9) {
			reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�����10��ӵ�з���800W��ң�";
		}
		else if (rewardNum >= 10 && rewardNum <= 39) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�����9��ӵ�з���400W��ң�";
		}
		else if (rewardNum >= 40 && rewardNum <= 99) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�����8��ӵ�з���200W��ң�";
		}
		else if (rewardNum >= 100 && rewardNum <= 104) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�������ħ���Ģ� ";
		}
		else if (rewardNum >= 105 && rewardNum <=109) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã������ħ���Ģ�";
		}
		else if (rewardNum >= 110 && rewardNum <= 114) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�������ħ���Ģ� ";
		}
		else if (rewardNum >= 115 && rewardNum < 119) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã������ħ���Ģ� ";
		}
		else if (rewardNum >= 120 && rewardNum <= 129) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�����������*200 ";
		}
		else if (rewardNum >= 130 && rewardNum <= 149) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�ս���ػ�30��*10  ";
		}
		else if (rewardNum >= 150 && rewardNum <= 154) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�ս���ػ�30��*100 ";
		}
		else if (rewardNum >= 154 && rewardNum <= 159) {
			           reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã����ʿ��װ��30��*10 ";
		}
		else if (rewardNum >= 160 && rewardNum <= 169) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã����ʿ��װ��7��*10 ";
		}
		else if (rewardNum >= 170 && rewardNum <= 189) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�100����*10 ";
		}
		else if (rewardNum >= 190 && rewardNum <= 209) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�100����*50 ";
		}
		else if (rewardNum >= 210 && rewardNum <= 219) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�100����*100 ";
		}
		else if (rewardNum >= 220 && rewardNum <= 249) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�50\%�����ӳ�*10 ";
		}
		else if (rewardNum >= 250 && rewardNum <= 259) {
								reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�50\%�����ӳ�*100  ";
		}
		else if (rewardNum >= 260 && rewardNum <= 279) {
				reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�100��������1*100 ";
		}
		else if (rewardNum >= 280 && rewardNum <= 299) {
							reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�500��������1*50 ";
		}
		else if (rewardNum >= 300 && rewardNum <= 319) {
					reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�2000��������*50 ";
		}
		else if (rewardNum >= 320 && rewardNum <= 339) {
							reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�10000��������*10 ";
		}
		else if (rewardNum >= 340 && rewardNum <= 349) {
					reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�10000��������*50 ";
		}
		else if (rewardNum >= 350 && rewardNum <= 354) {
							reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�10000��������*100  ";
		}
		else if (rewardNum >= 355 && rewardNum <= 364) {
					reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�100��������*30  ";
		}
		else if (rewardNum >= 365 && rewardNum <= 369) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�5000��������*30     ";
		}
		else if (rewardNum >= 370 && rewardNum <= 370) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�1�ڽ��    ";			
		}
		else if (rewardNum >= 371 && rewardNum <= 372) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�5000W��� ";
		}
		else if (rewardNum >= 373 && rewardNum <= 379) {
					reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�1000W���";
		}
		else if (rewardNum >= 380 && rewardNum <= 389) {
							reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�800W��� ";
		}
		else if (rewardNum >= 390 && rewardNum <= 409) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�500W��� ";
		}
		else if (rewardNum >= 410 && rewardNum <= 459) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�200W��� ";
		}
		else if (rewardNum >= 460 && rewardNum <= 469) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�100W��� ";
		}
		else if (rewardNum >= 470 && rewardNum <= 479) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�100000��������*10 ";
		}
		else if (rewardNum >= 480 && rewardNum <= 485) {
							reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�100000��������*50";
		}
		else if (rewardNum >= 486 && rewardNum <= 489) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�100000��������*100";
		}
		else if (rewardNum >= 490 && rewardNum <= 499) {
						reply = "[CQ:emoji,id=127882]......�齱���.....[CQ:emoji,id=127882]\n" + atone + "\n��ϲ��ã�20000��������*10";
		}
		reply += "���λ񽱱��Ϊ��"+To_Str(rewardNum)+"\n[CQ:emoji,id=128176]����@�ƹ㣬��ֵ������ȡ����";
					CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
					CQ_sendPrivateMsg(ac, 1665313816, reply.c_str());
		}
		return EVENT_BLOCK;
	}

	//ǩ��
	if (smsg == "ǩ��" && !Game_start(fromGroup))
	{
		int moneyRondom;
		int expRondom;
		const time_t t = time(NULL);


		struct tm* current_time = localtime(&t);
		int day = current_time->tm_mday; //���ǩ������ 
		int times = 0;
		if (Judge_SignIn(fromQQ,fromGroup, day, times))
		{
			moneyRondom = 1000 + rand() % 800;
			expRondom = 20 + rand() % 30;
			getmoney(fromQQ, fromGroup, moneyRondom);
			getexp(fromQQ, fromGroup, expRondom);

			reply = "[CQ:emoji,id=127882]......��ӭ���鹦���ͻ�����.....[CQ:emoji,id=127882]\n" + atone + "[CQ:emoji,id=128276]ǩ���ɹ�\n[CQ:emoji,id=128176]����ǩ������ý��: "
				+ To_Str(moneyRondom) + "\n[CQ:emoji,id=127757]����þ��飺" + To_Str(expRondom)
				+ "\n[CQ:emoji,id=128077]�������" + To_Str(times) + "��ǩ��";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		else
		{
			losemoney(fromQQ, fromGroup, 100);
			reply = "[CQ:emoji,id=127882]......��ӭ���鹦���ͻ�����.....[CQ:emoji,id=127882]\n" + atone + "\n[CQ:emoji,id=128276]������Ѿ�ǩ�����ˣ��۳�100��ң�����������\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		return EVENT_BLOCK;
	}

//�����ѯ.............................................................................................................................................................
	idioms my;
	if (my.judge_sentence(smsg) != "n" &&!Game_start(fromGroup))
	{
		string ch = my.judge_sentence(smsg);
		string idioms_out = my.idioms_Find(ch);
		if (idioms_out == "n" || idioms_out == "")
		{
			reply = atone +"[CQ:emoji,id=128534]û���ҵ�����Ҫ�ĳ���ѽ";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else
		{
			reply = atone +"[CQ:emoji,id=128516]����Ҫ�ĳ������£�\n" + idioms_out;
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;

		}
	}

//����.................................................................................................................................................................
	if ((judgecomand(smsg) != "n") && (fromQQ == To_Int64(masterQQ)))
	{
		CQ_sendGroupMsg(ac, fromGroup, judgecomand(smsg).c_str());
		return EVENT_BLOCK;
	}

//��ѯ.................................................................................................................................................................
	if (smsg == "�鿴���"||smsg=="��ѯ���"||smsg=="��Ҳ�ѯ"||smsg=="�ҵĽ��" && !Game_start(fromGroup))
	{
		
		string M = To_Str(m);
		reply = "[CQ:emoji,id=128176]......��ӭ���鹦���ͻ�����.....[CQ:emoji,id=128176]\n" + atone + "[CQ:emoji,id=128180]���Ľ�����Ϊ��" + M;
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}
	if (smsg == "�鿴����"||smsg=="��ѯ����"||smsg=="�����ѯ"||smsg=="�ҵľ���" && !Game_start(fromGroup))
	{
		
		string E = To_Str(e);
		reply = "[CQ:emoji,id=127757]......��ӭ���鹦���ͻ�����.....[CQ:emoji,id=127757]\n" + atone + "[CQ:emoji,id=127759]���ľ���ΪΪ��" + E;
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
	}

//����.................................................................................................................................................................
	if (smsg == "��������" && !Game_start(fromGroup))
	{
		reply = "[CQ:emoji,id=127922]......��ӭ���鹦���ͻ�����.....[CQ:emoji,id=127922]\n�뷢�Ͳ�����������Ϸ��ÿ�β�����������1200��ң�ʧ�ܿ۳���ң��ɹ������Ӧ��ҽ���\n��Ϸ�У���ѡ��´��С��ϵͳ���������������бȽ�\nף�����";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
	}

	
	if (smsg == "����" && !Game_start(fromGroup)&& !getNumberGuessing_status(fromQQ,fromGroup))
	{
		if(m<1200)
			CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=127757]��Ҳ��㣬��õ��㹻��Һ�����");
		else
		{
			losemoney(fromQQ, fromGroup, 1200);
			setNumberGuessing_status(fromQQ, fromGroup, "��");
			CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=127922]��ѡ��´��С");
			return EVENT_BLOCK;
		}
	}
	
		if ((smsg == "�´�" || smsg == "��С"||smsg=="��"||smsg=="С") && getNumberGuessing_status(fromQQ, fromGroup))
	{
			int randomNum1 = 30 + realRand(33);
			int randomNum2 = 10 + realRand(80);
			if ((smsg == "�´�"||smsg=="��")&&randomNum1 >= randomNum2)
			{
				reply = atone + "[CQ:emoji,id=127922]��ҵ���: " + To_Str(randomNum1) + "\n[CQ:emoji,id=127922]ϵͳ����: " + To_Str(randomNum2) + "\n[CQ:emoji,id=128176]��ϲ��ʤ�����2000���";
				getmoney(fromQQ, fromGroup,2000);
			}
			else if ((smsg == "�´�" || smsg == "��") &&randomNum1 < randomNum2)
			{
				reply = atone + "[CQ:emoji,id=127922]��ҵ���: " + To_Str(randomNum1) + "\n[CQ:emoji,id=127922]ϵͳ����: " + To_Str(randomNum2) + "\n[CQ:emoji,id=128555]�ܲ��ң�����ʧ�ܣ���ӭ�´�����";
			}
			else if ((smsg == "��С" || smsg == "С") &&randomNum1 < randomNum2)
			{
				reply = atone + "[CQ:emoji,id=127922]��ҵ���: " + To_Str(randomNum1) + "\n[CQ:emoji,id=127922]ϵͳ����: " + To_Str(randomNum2) + "\n[CQ:emoji,id=128176]��ϲ��ʤ�����2000���";
				getmoney(fromQQ, fromGroup, 2000);
			}
			else if ((smsg == "��С" || smsg == "С") &&randomNum1 >= randomNum2)
			{
				reply = atone + "[CQ:emoji,id=127922]��ҵ���: " + To_Str(randomNum1) + "\n[CQ:emoji,id=127922]ϵͳ����: " + To_Str(randomNum2) + "\n[CQ:emoji,id=128555]�ܲ��ң�����ʧ�ܣ���ӭ�´�����";
			}
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			setNumberGuessing_status(fromQQ, fromGroup, "��");
			return EVENT_BLOCK;
	}
//ħ������Ϸ....................................................................................................................................................................
		if (smsg == "ħ��������" && !Game_start(fromGroup))
		{
			reply = "���� ħ���� ��ʼ��Ϸ\nÿ����Ϸ����800���\n��Ϸʱ������Ϊ3����\nʤ���ɻ�� 3000*ʣ��²����*0.7�Ľ���(��߿ɻ��10500���)\n��ʼ����Ϊ 5 ��\nÿһ�β²�ɵõ�ƫ���ƫС����ʾ\nף������";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		if (smsg == "ħ����" && !Game_start(fromGroup)&&!getmagicNumber_status(fromQQ,fromGroup))
		{
			string reply;
			if (m >= 800)
			{
				reply = "[CQ:emoji,id=127881]��ӭ����ħ������Ϸ[CQ:emoji,id=127881]\n[CQ:emoji,id=127757]��Ϸ�������Ľ��800\n[CQ:emoji,id=128341]��Ϸʱ������Ϊ3����\n";
				setmagicNumber_status(fromQQ, fromGroup, "��");
				setmagicNumber_time(fromQQ, fromGroup, sendTime);
				setmagicNumber_times(fromQQ, fromGroup, 5);
				int random_num1 = rand() % 30 + 1;
				int random_num2 = rand() % 40 + 90;
				reply += "[CQ:emoji,id=127922]�����������ΧΪ: " + To_Str(random_num1) + "--" + To_Str(random_num2) + "\n[CQ:emoji,id=128221]��������β�������,�뿪ʼ��ı���\n";
				int ur_random_num = random_num1 + rand() % (random_num2 - random_num1);
				setmagicNumber_num(fromQQ, fromGroup, ur_random_num);
				losemoney(fromQQ, fromGroup, 800);
			}
			else
				reply = "[CQ:emoji,id=127757]��Ҳ���,�޷�����ħ������Ϸ.........\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		else if (smsg == "ħ����" && !Game_start(fromGroup) && !getmagicNumber_status(fromQQ, fromGroup))
		{
			reply = "[CQ:emoji,id=10060]���ѿ���ħ������Ϸ,�뾡�������ǰ��Ϸ.........\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		 
		if (getmagicNumber_status(fromQQ, fromGroup) && getmagicNumber_time(fromQQ, fromGroup) - sendTime <= 180 &&judge_Digit(smsg)&& getmagicNumber_times(fromQQ, fromGroup)>0&&getmagicNumber_num(fromQQ, fromGroup)!=0)
		{
			wstring wstr1(_T(""));
			string str1;
			wstring text = stows(smsg);

			std::wstring regString(_T("^(\\d+)$"));

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
				submagicNumber_times(fromQQ, fromGroup);
				int remain_times = getmagicNumber_times(fromQQ, fromGroup);
				if (num1 < getmagicNumber_num(fromQQ, fromGroup))
					reply = "[CQ:emoji,id=11014]���µ���ƫС\n[CQ:emoji,id=128221]����ʣ�����Ϊ: " + To_Str(remain_times);
				else if (num1 > getmagicNumber_num(fromQQ, fromGroup))
				{
					reply = "[CQ:emoji,id=11015]���µ���ƫ��\n[CQ:emoji,id=128221]����ʣ�����Ϊ: " + To_Str(remain_times);
				}
				else
				{
					reply = "[CQ:emoji,id=128124]��ϲ���¶�����Ӧ������\n[CQ:emoji,id=128221]����ʣ�����Ϊ: " + To_Str(remain_times)+"\n������� 3000*"+To_Strd(double(remain_times+1)*0.7)+"��ҽ���";
					setmagicNumber_times(fromQQ, fromGroup, 0);
					setmagicNumber_status(fromQQ, fromGroup, "��");
					setmagicNumber_time(fromQQ, fromGroup, 0);
					setmagicNumber_num(fromQQ, fromGroup, 0);
					getmoney(fromQQ, fromGroup, 3000*(remain_times+1)*0.7);
				}

				if (getmagicNumber_status(fromQQ, fromGroup) && getmagicNumber_times(fromQQ, fromGroup) <= 0)
				{
					reply += "[CQ:emoji,id=128221]���Ĵ����ľ�,��Ϸ����,��Ϸʧ��\n[CQ:emoji,id=127922]����������Ϊ: " + To_Str(getmagicNumber_num(fromQQ, fromGroup)) + "\n[CQ:emoji,id=127937]��ӭ�´�����....... ";
					setmagicNumber_times(fromQQ, fromGroup, 0);
					setmagicNumber_status(fromQQ, fromGroup, "��");
					setmagicNumber_time(fromQQ, fromGroup, 0);
					setmagicNumber_num(fromQQ, fromGroup, 0);
				}
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			}
		}
		else if (getmagicNumber_status(fromQQ, fromGroup) && getmagicNumber_time(fromQQ, fromGroup) - sendTime > 180)
		{
			reply = "[CQ:emoji,id=128341]����ʱ��ľ�,��Ϸ����,��Ϸʧ��\n[CQ:emoji,id=127937]��ӭ�´�����....... " ;
			setmagicNumber_times(fromQQ, fromGroup, 0);
			setmagicNumber_status(fromQQ, fromGroup, "��");
			setmagicNumber_time(fromQQ, fromGroup, 0);
			setmagicNumber_num(fromQQ, fromGroup, 0);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		
//ħ������ս.....................................................................
	/*	if (smsg == "ħ������ս" && !Game_start(fromGroup)&&getChallenger(fromGroup)=="0000")
		{
			reply += "��ӭ����ħ������ս\n���ѳ�Ϊ���������\n�������޻��ѽ��1000\n��ȴ�Ӧս�߽�����ս";
			setChallenger(fromGroup, setqq_str(fromQQ));
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		if (smsg == "Ӧս" && !Game_start(fromGroup) && getChallenger(fromGroup) != "0000")
		{
			setBattle(fromGroup, setqq_str(fromQQ));
			setChallenger_time(fromGroup, sendTime);
			string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
			writeConfigFile(path.c_str(), "��Ϸ��ʼ", "��");
			reply = getNickname(setqq_str(fromQQ)) + "  ��Ӧս,��ս��ʼ\n��ս��ʱ4����";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}

		if(judge_Digit(smsg)&&Game_start(fromGroup)&& getChallenger(fromGroup) != "0000"&&getBattle(fromGroup)!="0000")*/
//����.................................................................................................................................................................
		if (smsg.substr(0, 4) == "����" && !Game_start(fromGroup))
		{
			int choice;
			choice = getOperator(smsg);
			if (choice!=0)
			{
				wstring text = stows(smsg);

				std::wstring regString(_T("����(\\d+\\.?\\d*).(\\d*\\.?\\d*)"));

				// ���ʽѡ�� - ���Դ�Сд  
				std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

				// ����һ��������ʽ���  
				std::wregex regExpress(regString, fl);

				// ������ҵĽ��  
				std::wsmatch ms;
				// ����  
				if (std::regex_search(text, ms, regExpress))
				{
					string result;
					result = calculateFunction(choice, ms);
					CQ_sendGroupMsg(ac, fromGroup, result.c_str());
				}
			}
			return EVENT_BLOCK;
		}

//˭���Ե���Ϸ..........................................................................................................................................................
		if (smsg == "˭���Ե׽���" && !Game_start(fromGroup))
		{
			reply = "=====��ӭ���鹦���ͻ�����=====\n����Ϸ�ʺ�����Ϊ5--12��\n��Ϸ����ʱ��Ϊ15����(�������������ĵȴ�ʱ��)\n�������� ����˭���Ե� ��������(����600)\n��ҷ��� ����/�μ�/����˭���Ե� ���뷿��(����400)\n";
			reply += "������Ȩ�߳���һ���(��ҷ���380) ֱ��@����\n����������5�˼������Ƿ����ɷ��� ��ʼ˭���Ե� ��ʼ��Ϸ\n��Ϸ��ʼ��Android��������ɴ���(450)\n����õ�������밴˳����";
			reply += "����շ���������Ա�Ž���ͶƱ (��: 1/1��)\n��ͬ�������佫�в�ͬ�������Ե�,ƽ��,�Ϳհ�\nֱ��ĳ����Ϊ0��һ��Ϊ0��������Ϊ1ʱ��Ϸ����\n��ʤ���������2000��ҽ���\n";
			reply += "��ʤ˫����ÿ�����800��ҽ���\nף��������!!!";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}

		int num = getplayer_numbers(fromGroup);
			if (smsg == "����˭���Ե�" && !Game_creat(fromGroup) && m >= 600)
			{
				string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
				writeConfigFile(path.c_str(), "��Ϸ����", "��");
				setroles(fromQQ, fromGroup, "��");
				set_game1(fromGroup);
				addplayer(fromGroup);
				setcreattime_1(fromGroup, sendTime);
				getWordGroup(fromGroup);
				reply = "[CQ:emoji,id=128227]......��ӭ���鹦���ͻ�����.....\n" + atone + "[CQ:emoji,id=127759]���ѳɹ��������䣬���Ľ��600,��ȴ�������Ҽ���\n[CQ:emoji,id=128353]��ǰ���������1\n(��������ﵽ5��ɷ��� ��ʼ˭���Ե� ������Ϸ";
				losemoney(fromQQ, fromGroup, 600);

				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if (smsg == "����˭���Ե�" && Game_creat(fromGroup) )
			{
				reply = atone + "[CQ:emoji,id=128336]��ǰ����δ��������Ϸ�����Ժ�����";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if (smsg == "����˭���Ե�" && m < 600 )
			{
				reply = atone + "[CQ:emoji,id=128336]��Ҳ���,��׬Ǯ������....";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			if ((smsg == "�μ�˭���Ե�" || smsg == "����˭���Ե�" || smsg == "����˭���Ե�") && Game_creat(fromGroup) && num<12 && !Game_start(fromGroup) && !judgeplayers(fromQQ, fromGroup) && m >= 400)
			{
				setroles(fromQQ, fromGroup, "��");
				addplayer(fromGroup);
				num = getplayer_numbers(fromGroup);
				string Num = To_Str(num);
				reply = "[CQ:emoji,id=128227]......��ӭ���鹦���ͻ�����.....\n" + atone + "[CQ:emoji,id=127759]���ѳɹ����뷿�䣬���Ľ��400,��ȴ�������Ҽ���\n[CQ:emoji,id=128353]��ǰ���������" + Num;
				losemoney(fromQQ, fromGroup, 400);
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if ((smsg == "�μ�˭���Ե�" || smsg == "����˭���Ե�" || smsg == "����˭���Ե�") && !Game_creat(fromGroup) )
			{
				reply = atone + "[CQ:emoji,id=128340]��ǰ��û�з��䣬��ȴ����Լ�����";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if ((smsg == "�μ�˭���Ե�" || smsg == "����˭���Ե�" || smsg == "����˭���Ե�")  && num >= 12 )
			{
				reply = atone + "[CQ:emoji,id=128340]��ǰ����������������ȴ���һ��";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;

			}
			else if ((smsg == "�μ�˭���Ե�" || smsg == "����˭���Ե�" || smsg == "����˭���Ե�") && judgeplayers(fromQQ, fromGroup))
			{
				reply = atone + "[CQ:emoji,id=128336]�����ڷ����У���ȴ�....";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if ((smsg == "�μ�˭���Ե�" || smsg == "����˭���Ե�" || smsg == "����˭���Ե�") && m < 400)
			{
				reply = atone + "[CQ:emoji,id=128336]��Ҳ���,��׬Ǯ������....";		
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
			else if ((smsg == "�μ�˭���Ե�" || smsg == "����˭���Ե�" || smsg == "����˭���Ե�") && Game_start(fromGroup))
			{
				reply = atone + "[CQ:emoji,id=128336]��ǰ��Ϸ�ѿ�ʼ,�������.....";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}

			if (smsg.substr(0, 4) == "�߳�"&&Game_creat(fromGroup) && !Game_start(fromGroup))
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
						if (judgeplayers(To_Int64(str1), fromGroup) && To_Int64(str1) != fromQQ)
						{
							subplayer(fromGroup);
							num = getplayer_numbers(fromGroup);
							string Num = To_Str(num);
							getmoney(To_Int64(str1), fromGroup, 380);
							reply = "[CQ:emoji,id=128123]�ɹ��߳����(" + str1 + ")\n[CQ:emoji,id=127975]��Ӧ����ѷ���(380)......\n[CQ:emoji,id=128353]��ǰ���������" + Num;
							CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
							delcontent("..\\files\\Player_Group.cfg", str1);
							return EVENT_BLOCK;
						}
						else if (!judgeplayers(To_Int64(str1), fromGroup))
						{
							reply = "��Ҳ�����,�߳�ʧ��......";
							CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
							return EVENT_BLOCK;
						}
						else
						{
							reply = "�������ɱ��߳�.....";
							CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
							return EVENT_BLOCK;
						}
					}
				}
			}

			if (smsg.substr(0, 8) == "������Ϸ" && (Game_creat(fromGroup) || Game_start(fromGroup)) && judgeplayers(fromQQ, fromGroup)&&!Vote_to_end(fromGroup))
			{
				setVote_to_end(fromGroup);
				setvotes(1, fromGroup);
				setvotes_total(fromGroup);
				setJudge_vote(fromQQ, fromGroup, "��");
				reply = "[CQ:emoji,id=127937]����ѷ������ͶƱ,ͬ�����1,�������0\n[CQ:emoji,id=128125]ͶƱ������Ϸֻ��һ�λ���,�����\n[CQ:emoji,id=128340]�뿪ʼͶƱ\n";
				if (num == 1)
				{
					reply += "������Ϸ�ɹ�\n";
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

				std::wstring regString(_T("(\\d+)(?:��|)$"));

				// ���ʽѡ�� - ���Դ�Сд  
				std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

				// ����һ��������ʽ���  
				std::wregex regExpress(regString, fl);

				// ������ҵĽ��  
				std::wsmatch ms;
				// ����  

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
						CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=9989]ͬ��,ͶƱ�ɹ�");
						setJudge_vote(fromQQ, fromGroup, "��");
					}
					if (num1 == 0)
					{
						setvotes(0, fromGroup);
						setvotes_total(fromGroup);
						CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=10060]����,ͶƱ�ɹ�");
						setJudge_vote(fromQQ, fromGroup, "��");
					}
				}
				int votes_total = getvotes_total(fromGroup);
				if (getvotes(1, fromGroup) > double(num / 2))
				{
					reply += "[CQ:emoji,id=127937]���г����������ͬ������˾���Ϸ\n[CQ:emoji,id=127937]��Ϸ�쳣����,�������û�н���\n========��ӭ��������=========\n";
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
					reply += "[CQ:emoji,id=127937]���ٰ�����Ҳ�ͬ�����������Ϸ,��Ϸ��������\n";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;

			}

		int creattime_1 = getcreattime_1(fromGroup,sendTime);

		if (sendTime - creattime_1 > 600 && Game_creat(fromGroup)&& sendTime - creattime_1 < 610)
		{
			string reply = "[CQ:emoji,id=128336]\n��Ϸʱ���Ѵﵽʮ���ӣ�ʣ��ʱ�����,�����պ���Ϸ�ٶ�\n�����涨ʱ�������˽�ʧȥ��Ϸ����,��Ϸ���Զ�����";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		if (sendTime - creattime_1 > 900 && Game_creat(fromGroup))
		{
			string reply = "[CQ:emoji,id=128337]\n��Ϸʱ���Ѵﵽʮ����ӣ������Զ�������������û�н���\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			reset(fromGroup);
			resetvotes(fromGroup);
		}
		
		if (smsg == "��ʼ˭���Ե�"&&num >= 5 && Game_creat(fromGroup)&&!Game_start(fromGroup) )
		{
			string players[12];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);
			if (fromQQ == To_Int64(players[0]))
			{
				reply = "[CQ:emoji,id=9989]˭���Ե���Ϸ��ʼ\n[CQ:emoji,id=128212]���ڷ����ɫ����ע��鿴˽����Ϣ......";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				string value;
				string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
				readConfigFile(path.c_str(), "��Ϸ����", value);
				
				size_t pos = value.find('&');
				if (pos == string::npos)
				{
					CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=10060]ϵͳƥ�����!!error!");
					reset(fromGroup);
					return EVENT_BLOCK;
				}
				writeConfigFile(path.c_str(), "��Ϸ��ʼ", "��");

				string roles[3];
				roles[0] = value.substr(0, pos);
				roles[1] = value.substr(pos + 1);
				roles[2] = "�հ�";
				int count1 = 0;
				int count2 = 0;
				int count3 = 0;
				int i = 0;
				srand(time(NULL));
				if (5 <= num && num <= 7)
				{
					//һ���Եף�һ���հף�����ƽ��
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
							setCommonRoles(To_Int64(players[i]), fromGroup, "ƽ��");
							i++;
						}
						if (x > 6 && x <= 8 && count2 < 1)
						{
							count2++;
							setroles(To_Int64(players[i]), fromGroup, roles[1]);
							setCommonRoles(To_Int64(players[i]), fromGroup, "�Ե�");
							i++;
						}
						if (x > 8 && count3 < 1)
						{
							count3++;
							setroles(To_Int64(players[i]), fromGroup, roles[2]);
							setCommonRoles(To_Int64(players[i]), fromGroup, "�հ�");
							i++;
						}
					}
				}
				else if (num >= 8 && num <= 10)
				{
					//2���Եף�һ���հף�����ƽ��
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
					//2���Եף�3���հף�����ƽ��
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
					string Preply = "[CQ:emoji,id=128100]������ݣ�" + results;
					CQ_sendPrivateMsg(ac, To_Int64(players[i]), Preply.c_str());
				}
				
				reply = "�����η��Բ�ѡ��Ͷ����ұ��\n��ұ���б�: \n";
				for (int i = 0; i < num; i++)
					reply += getNickname(players[i])+"("+players[i] +")"+ "  " + To_Str(i + 1) + "��\n";
				reply += "��������: \n[CQ:emoji,id=128694]ƽ��: " + To_Str(count1) + "��\n[CQ:emoji,id=128101]�Ե�: " + To_Str(count2) + "��\n[CQ:emoji,id=128172]�հ�: " + To_Str(count3) + "��\n";

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

			std::wstring regString(_T("^(\\d+)(?:��|)$"));

			// ���ʽѡ�� - ���Դ�Сд  
			std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

			// ����һ��������ʽ���  
			std::wregex regExpress(regString, fl);

			// ������ҵĽ��  
			std::wsmatch ms;
			// ����  

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
					CQ_sendGroupMsg(ac, fromGroup, "[CQ:emoji,id=9989]ͶƱ�ɹ�");
					setJudge_vote(fromQQ, fromGroup, "��");
				}
			}
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
					CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
					resetvotes(fromGroup);
				}
				else
				{
					reply += players[temp] + "[CQ:emoji,id=128202]�������Ʊ����Ͷ��\n";
					string playerroles = getCommonRoles(To_Int64(players[temp]), fromGroup);

						if (playerroles == "ƽ��")
						{
							reply += "[CQ:emoji,id=128694]������ƽ��ԩ��������[CQ:emoji,id=128128]\n";
							subciviliavg(fromGroup);
						}
						else if (playerroles == "�Ե�")
						{
							reply += "[CQ:emoji,id=128101]�ɹ����һ���Ե�[CQ:emoji,id=128128]\n";
							subspy(fromGroup);
						}
						else
						{
						reply += "[CQ:emoji,id=128172]....��Ϊ�հ�....[CQ:emoji,id=128128]\n";
						subblank(fromGroup);
						}
						path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
						delcontent(path.c_str(), players[temp]);
						subplayer(fromGroup);
						resetvotes(fromGroup);
						num = getplayer_numbers(fromGroup);
						getkey(path.c_str(), players, num);
						path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
						reply += "[CQ:emoji,id=128113]�����η��Բ�ѡ��Ͷ����ұ��\n��ұ���б�: \n";
						for (int i = 0; i < num; i++)
							reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "��\n";
						CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
					

					if ((getspy_numbers(fromGroup) == 0 && getciviliav_numbers(fromGroup) == 0) || 
						(getspy_numbers(fromGroup) == 0 && getblank_numbers(fromGroup) == 0) ||
						(getciviliav_numbers(fromGroup) == 0 && getblank_numbers(fromGroup) == 0)||
						(getspy_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 1 && getciviliav_numbers(fromGroup) == 0) ||
						(getspy_numbers(fromGroup) == 1 && getciviliav_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 0) ||
						(getciviliav_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 1 && getspy_numbers(fromGroup) == 0))
					{
						string reply = "[CQ:emoji,id=10062]������Ϸ����\n";
						string civiliav[7];
						string spy[2];
						string blank[3];
						int i = 0, j = 0, k = 0;
						fstream cfgFile;
						path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
						cfgFile.open(path.c_str());//���ļ�      

						char tmp[1000];
						while (!cfgFile.eof())//ѭ����ȡÿһ��  
						{
							cfgFile.getline(tmp, 1000);//ÿ�ж�ȡǰ1000���ַ���1000��Ӧ���㹻��  
							string line(tmp);
							size_t pos = line.find('=');
							if (pos == string::npos) continue;
							string tempvalue = line.substr(pos + 1);//ȡ�Ⱥ�֮��

							if (tempvalue == "ƽ��")
							{
								civiliav[i] = line.substr(0, pos);
								i++;
							}
							else 	if (tempvalue == "�Ե�")
							{
								spy[j] = line.substr(0, pos);
								j++;
							}
							else 	if (tempvalue == "�հ�")
							{
								blank[k] = line.substr(0, pos);
								k++;
							}
						}

						string value;
						string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
						readConfigFile(path.c_str(), "��Ϸ����", value);
						size_t pos = value.find('&');
						string roles[2];
						roles[0] = value.substr(0, pos);
						roles[1] = value.substr(pos + 1);

						reply += "���ֵ�ƽ��ʻ�Ϊ: " + roles[0] + "\n���ֵ��Ե״ʻ�Ϊ: " + roles[1];
						reply += "\n[CQ:emoji,id=128694]���ֵ�ƽ��Ϊ: \n";
					
						for (int m = 0; m < i; m++)
						{
							reply += civiliav[m] + "\n";
						}
						reply += "[CQ:emoji,id=128101]���ֵ��Ե�Ϊ: \n";
						for (int m = 0; m < j; m++)
						{
							reply += spy[m] + "\n";
						}
						reply += "[CQ:emoji,id=128172]���ֵĿհ�Ϊ: \n";
						for (int m = 0; m < k; m++)
						{
							reply += blank[m] + "\n";
						}

						if (getspy_numbers(fromGroup) == 0 && getciviliav_numbers(fromGroup) == 0)
						{
							//�հ�Ӯ
							reply += "[CQ:emoji,id=128172]���ս��: �հ�ʤ,ʤ���������2000��ҽ���[CQ:emoji,id=127881]";
							for (int m = 0; m < k; m++)
								getmoney(To_Int64(blank[m]), fromGroup, 2000);
						}
						else if (getspy_numbers(fromGroup) == 0 && getblank_numbers(fromGroup) == 0)
						{
							//ƽ��Ӯ
							reply += "[CQ:emoji,id=128694]���ս��: ƽ��ʤ,ʤ���������2000��ҽ���[CQ:emoji,id=127881]";
							for (int m = 0; m < i; m++)
								getmoney(To_Int64(civiliav[m]), fromGroup, 2000);
						}
						else if((getciviliav_numbers(fromGroup) == 0 && getblank_numbers(fromGroup) == 0))
						{
							//�Ե�Ӯ
							reply += "[CQ:emoji,id=128101]���ս��: �Ե�ʤ,ʤ���������2000��ҽ���[CQ:emoji,id=127881]";
							for (int m = 0; m < j; m++)					
								getmoney(To_Int64(spy[m]), fromGroup, 2000);
							
						}

						else if ((getspy_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 1 && getciviliav_numbers(fromGroup) == 0))
						{
							//�Ե׺Ϳհ�ƽ,ƽ����
							reply += "[CQ:emoji,id=128101]���ս��: �Ե׷��Ϳհ׷���ƽ,ÿ�������800��ҽ���[CQ:emoji,id=128172]";
							for (int m = 0; m < j; m++)
								getmoney(To_Int64(spy[m]), fromGroup, 800);
							for (int m = 0; m < k; m++)
								getmoney(To_Int64(blank[m]), fromGroup, 800);

						}
						else if ((getspy_numbers(fromGroup) == 1 && getciviliav_numbers(fromGroup) == 1 && getblank_numbers(fromGroup) == 0))
						{
							//�Ե�Ӯ
							reply += "[CQ:emoji,id=128101]���ս��: �Ե�ʤ,ʤ���������2000��ҽ���[CQ:emoji,id=127881]";
							for (int m = 0; m < j; m++)
								getmoney(To_Int64(spy[m]), fromGroup, 2000);
						}
						else
						{
							reply += "[CQ:emoji,id=128172]���ս��: �հ�ʤ,ʤ���������2000��ҽ���[CQ:emoji,id=127881]";
							for (int m = 0; m < k; m++)
								getmoney(To_Int64(blank[m]), fromGroup, 2000);
						}
                          CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
                          reset(fromGroup);
					}
				}
			}

		}


//����ͽ�����а�鿴..................................................................................................................................................

		if (smsg == "�������" || smsg == "������а�"&&!Game_start(fromGroup))
		{
			reply = moneyRank(fromQQ, fromGroup);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		if (smsg == "��������" || smsg == "�������а�" && !Game_start(fromGroup))
		{
			reply = expRank(fromQQ, fromGroup);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}

//����ɱ��Ϸ.............................................................................................................................................................
		if (smsg == "����ɱ����" && !Game_start(fromGroup))
		{
			reply = "=====��ӭ���鹦���ͻ�����=====\n����Ϸ�ʺ�����Ϊ6--18��\n��Ϸ����ʱ��Ϊ40����(�������������ĵȴ�ʱ��)\n�������� ��������ɱ ��������(����600)\n��ҷ��� ����/�μ�/��������ɱ ���뷿��(����400)\n";
			reply += "������Ȩ�߳���һ���(��ҷ���380) ֱ��@����\n����������5�˼������Ƿ����ɷ��� ��ʼ����ɱ ��ʼ��Ϸ\n��Ϸ��ʼ��Android������������(����,����,Ԥ�Լ�,Ů��,����)\n";
			reply += "����õ���ݺ��밴��AndroidҪ����в���\n����շ���������Ա�Ž���ͶƱ (��: 1/1��)\n��ͬ�������佫�в�ͬ���������˺ʹ���,��������ԭ����ܻ����Ů�׺����˽�ɫ\n";
			reply += "ֱ��������Ӫȫ��������������Ӫ��������������Ӫ,��Ϸ����\n\n";
			reply += "ǳ̸����ɱ����: \n����: ������Ӫ,����ͨ��ͶƱ��\n����: ÿ���ж�,ѡ��ɱ��һ�����(����˽��ͳһ,����ȡ���Ʊ��)\n";
			reply += "Ԥ�Լ�: ������Ӫ,ÿ��鿴һ����ɫ���(˽��Android)\nŮ��: ������Ӫ,����ұ�ɱ����,����ѡ����벻��,����ֻ��ʹ��һ��,��AndroidҪ�����\n";
			reply += "����: ������Ӫ,����ʱ�ɴ���һ�����,��AndroidҪ�����\n����: �ɵ�һ������ѡ��,�����һƱ����Ʊ����Ȩ,������ɴ���\n";
			reply += "������Ӫʤ��ÿ�˽����80exp����\n������Ӫʤ�������100exp����\nף����Ϸ���!!!";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}

		num = getplayer_numbers(fromGroup);
		if (smsg == "��������ɱ" && !Game_creat(fromGroup) && m >= 600 && !in_Group(fromQQ))
		{
			string path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
			writeConfigFile(path.c_str(), "��Ϸ����", "��");
			setroles(fromQQ, fromGroup, "��");
			set_game2(fromGroup);
			addplayer(fromGroup);
			setcreattime_2(fromGroup, sendTime);
			getWordGroup(fromGroup);
			reply = "[CQ:emoji,id=128227]......��ӭ���鹦���ͻ�����.....\n" + atone + "[CQ:emoji,id=127759]���ѳɹ��������䣬���Ľ��600,��ȴ�������Ҽ���\n[CQ:emoji,id=128353]��ǰ���������1\n(��������ﵽ6��ɷ��� ��ʼ����ɱ ������Ϸ";
			losemoney(fromQQ, fromGroup, 600);
			set_playergroup(fromQQ, fromGroup);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if (smsg == "��������ɱ" && Game_creat(fromGroup))
		{
			reply = atone + "[CQ:emoji,id=128336]��ǰ����δ��������Ϸ�����Ժ�����";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if (smsg == "��������ɱ" && m < 600)
		{
			reply = atone + "[CQ:emoji,id=128336]��Ҳ���,��׬Ǯ������....";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if (smsg == "��������ɱ" &&in_Group(fromQQ))
		{
			reply = atone + "[CQ:emoji,id=128336]����������Ⱥ�вμ�������ɱ��Ϸ,�������Ϸ������";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}

		if ((smsg == "�μ�����ɱ" || smsg == "��������ɱ" || smsg == "��������ɱ") && Game_creat(fromGroup) && num < 18 && !Game_start(fromGroup) && !judgeplayers(fromQQ, fromGroup) && m >= 400&&!in_Group(fromQQ))
		{
			setroles(fromQQ, fromGroup, "��");
			addplayer(fromGroup);
			num = getplayer_numbers(fromGroup);
			string Num = To_Str(num);
			reply = "[CQ:emoji,id=128227]......��ӭ���鹦���ͻ�����.....\n" + atone + "[CQ:emoji,id=127759]���ѳɹ����뷿�䣬���Ľ��400,��ȴ�������Ҽ���\n[CQ:emoji,id=128353]��ǰ���������" + Num;
			losemoney(fromQQ, fromGroup, 400);
			set_playergroup(fromQQ, fromGroup);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;

		}
		else if ((smsg == "�μ�����ɱ" || smsg == "��������ɱ" || smsg == "��������ɱ") && !Game_creat(fromGroup) && !in_Group(fromQQ))
		{
			reply = atone + "��ǰ��û�з��䣬��ȴ����Լ�����";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "�μ�����ɱ" || smsg == "��������ɱ" || smsg == "��������ɱ") && num >= 18)
		{
			reply = atone + "��ǰ����������������ȴ���һ��";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "�μ�����ɱ" || smsg == "��������ɱ" || smsg == "��������ɱ") && judgeplayers(fromQQ, fromGroup))
		{
			reply = atone + "[CQ:emoji,id=128336]�����ڷ����У���ȴ�....";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "�μ�����ɱ" || smsg == "��������ɱ" || smsg == "��������ɱ") && m < 400)
		{
			reply = atone + "[CQ:emoji,id=128336]��Ҳ���,��׬Ǯ������....";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "�μ�����ɱ" || smsg == "��������ɱ" || smsg == "��������ɱ") && m >= 400 && Game_start(fromGroup))
		{
			reply = atone + "[CQ:emoji,id=128336]��ǰ��Ϸ�ѿ�ʼ,�������.....";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			return EVENT_BLOCK;
		}
		else if ((smsg == "�μ�����ɱ" || smsg == "��������ɱ" || smsg == "��������ɱ") && in_Group(fromQQ))
		{
		reply = atone + "[CQ:emoji,id=128336]����������Ⱥ�вμ�������ɱ��Ϸ,�������Ϸ������";
		CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		return EVENT_BLOCK;
         }

		int creattime_2 = getcreattime_2(fromGroup,sendTime);
		if (sendTime - creattime_2 > 1800 && Game_creat(fromGroup) && sendTime - creattime_2 < 1820 && game2(fromGroup))
		{
			string reply = "[CQ:emoji,id=128336]\n��Ϸʱ���Ѵﵽ30���ӣ�ʣ��ʱ��10��,�����պ���Ϸ�ٶ�\n�����涨ʱ�������˽�ʧȥ��Ϸ����,��Ϸ���Զ�����";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}
		if (sendTime - creattime_2 > 2400 && Game_creat(fromGroup) && game2(fromGroup))
		{
			string reply = "[CQ:emoji,id=128337]\n��Ϸʱ���Ѵﵽ40���ӣ������Զ�������������û�н���\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			reset(fromGroup);
			resetvotes(fromGroup);
		}

		if (smsg == "��ʼ����ɱ"&&num >= 6 && Game_creat(fromGroup) && !Game_start(fromGroup) && game2(fromGroup))
		{
			string players[18];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);
			if (fromQQ == To_Int64(players[0]))
			{
				reply = "[CQ:emoji,id=9989]����ɱ��Ϸ��ʼ\n[CQ:emoji,id=128212]���ڷ����ɫ����ע��鿴˽����Ϣ......";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				path = "..\\files\\Game_status" + setqq_str(fromGroup) + ".cfg";
				writeConfigFile(path.c_str(), "��Ϸ��ʼ", "��");
				string gameroles[5];
				gameroles[0] = "����";
				gameroles[1] = "����";
				gameroles[2] = "Ů��";
				gameroles[3] = "����";
				gameroles[4] = "Ԥ�Լ�";
				int count0 = 0;
				int count1 = 0;
				int count2 = 0;
				int count3 = 0;
				int count4 = 0;
				srand(time(NULL));
				int i = 0;
				setseer_die(fromGroup, "��");
				
				if ( 6<= num && num <=9)
				{
					//2�� 1Ԥ�Լ� 1Ů�� (num-4)��
					setwitch_die(fromGroup, "��");
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
					//2�� 1Ԥ�Լ� 1Ů�� 1���� (num-5)��
					setwitch_die(fromGroup, "��");
					sethunter_die(fromGroup, "��");
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
					//3�� 1Ԥ�Լ� 1Ů�� 1���� (num-6)��
					setwitch_die(fromGroup, "��");
					sethunter_die(fromGroup, "��");
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
					//4�� 1Ԥ�Լ� 1Ů�� 1���� (num-7)��
					setwitch_die(fromGroup, "��");
					sethunter_die(fromGroup, "��");
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
					string Preply = "[CQ:emoji,id=128100]������ݣ�" + results;
					CQ_sendPrivateMsg(ac, To_Int64(players[i]), Preply.c_str());
				}
				reply = "[CQ:emoji,id=128213]��ұ���б�: \n";
				for (int i = 0; i < num; i++)
					reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "��\n";
			
				reply += "[CQ:emoji,id=128127]���� :���� ɱ+���(��:ɱ(1)��)\n��������������,ͳһͶƱ,����ȡ���Ʊ��\n[CQ:emoji,id=128124]Ԥ�Լ�: ���� ��+���(��:��1(��))\n[CQ:emoji,id=128299]����: ������ɷ��� ���� ����һ�����(��:����1)\n[CQ:emoji,id=128120]Ů��: ���� ��||��(��:��)\n[CQ:emoji,id=128290]";
				reply += "��������: \n[CQ:emoji,id=128127]����: " + To_Str(count0) + "\n[CQ:emoji,id=128104]����: " + To_Str(count1) + "\n[CQ:emoji,id=128124]Ԥ�Լ�: 1\n[CQ:emoji,id=128120]Ů��: 1\n";
				if (num >= 10)
					reply += "[CQ:emoji,id=128299]����: 1\n";

				
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				setWhoseturn(fromGroup, "���˻غ�");
			}
		}
		int num_2 = getwerewolves_numbers(fromGroup);
		int mun_3 = getvillager_numbers(fromGroup);
		num = getplayer_numbers(fromGroup);

		if (Game_start(fromGroup) && judge_Whoseturn(fromGroup, "����") && game2(fromGroup) && judgeplayers(fromQQ, fromGroup))
		{
			
			string reply;
			int hunterdie = 0;
			reply = votes(fromQQ, fromGroup, smsg,hunterdie);
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			if (hunterdie==1)
			{
				Sleep(55000);
				sethunter_die(fromGroup, "��");
			}

			if (getwerewolves_numbers(fromGroup) == 0 || getwerewolves_numbers(fromGroup) > num - getwerewolves_numbers(fromGroup))
			{
				string reply = over(fromGroup);
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				return EVENT_BLOCK;
			}
		}

		num = getplayer_numbers(fromGroup);
		if (Game_start(fromGroup) && num!= 0 &&(smsg=="�鿴����б�"||smsg=="�鿴���" ||smsg=="����б�"||smsg=="��ұ��"||smsg=="����б�") && judgeplayers(fromQQ, fromGroup))
		{
			string players[18];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);
			reply = "[CQ:emoji,id=128213]��ұ���б�: \n";
			for (int i = 0; i < num; i++)
				reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "��\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
		}

		if (judge_Whoseturn(fromGroup, "���˻غ�") && Game_start(fromGroup)&&num_2!=0 && game2(fromGroup))
		{
			string wolves[4];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey_withStr(path.c_str(), wolves, num_2,"����");
			int num_2 = getwerewolves_numbers(fromGroup);

			reply="[CQ:emoji,id=127762]��������\n����������\n������ɱ��\n[CQ:emoji,id=128127]���� :���� ɱ+���(��:ɱ1)\n��������������,ͳһͶƱ,����ȡ���Ʊ��\n";
			num = getplayer_numbers(fromGroup);
			string players[18];
			getkey(path.c_str(), players, num);
			reply += "\n[CQ:emoji,id=128113]��ұ���б�: \n";
			for (int i = 0; i < num; i++)
				reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "��\n";
			CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			
			
			string preply = "\n[CQ:emoji,id=128127]�����������˻��Ϊ: \n";
			for (int i = 0; i < num_2; i++)
				preply += getNickname(wolves[i]) + "(" + wolves[i] + ")\n";
			for (int i = 0; i < num_2; i++)
				CQ_sendPrivateMsg(ac, To_Int64(wolves[i]), preply.c_str());
			setWhoseturn(fromGroup, "����ɱ��");
		}

		if (!judgeplayers(fromQQ, fromGroup) && hunter_live(fromGroup) && judge_roles(fromQQ, fromGroup, "����") && game2(fromGroup))
		{

			int num = getplayer_numbers(fromGroup);
			string players[12];
			string path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
			getkey(path.c_str(), players, num);

			wstring wstr1(_T(""));
			string str1;
			wstring text = stows(smsg);
			string reply = "";

			std::wstring regString(_T("����(\\d+)(?:��|)"));

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
				int temp;
				temp = stoi(str1);
				if (temp <= num)
				{
					int64_t killedQQ = To_Int64(players[temp]);
					string killedrole = getroles(killedQQ, fromGroup);
					reply = "[CQ:emoji,id=128299]����ѡ�����" + getNickname(players[temp]) + "(" + players[temp] + ")\n";
					if (killedrole == "����")
					{
					subvillager(fromGroup);
					reply += "����������Ϊ ����\n";
				}
					else if (killedrole == "����")
					{
						subwerewolves(fromGroup);
						reply += "����������Ϊ ����\n";
					}
					else if (killedrole == "Ԥ�Լ�")
					{
						setseer_die(fromGroup, "��");
						reply += "����������Ϊ Ԥ�Լ�\n";
					}

					else if (killedrole == "Ů��")
					{
						setwitch_die(fromGroup, "��");
						reply += "����������Ϊ Ů��\n";
					}
					if (judgeSheriff(killedQQ, fromGroup))
						reply += "[CQ:emoji,id=128110]�����ѱ�ɱ��,�뾡��ѡ����Ҵ���---\n";
					path = "..\\files\\Game_roles" + setqq_str(fromGroup) + ".cfg";
					delcontent(path.c_str(), players[temp]);
					delcontent("..\\files\\Player_Group.cfg", players[temp]);
					subplayer(fromGroup);
					resetvotes(fromGroup);
					num = getplayer_numbers(fromGroup);
					getkey(path.c_str(), players, num);
					reply += "[CQ:emoji,id=128113]��ұ���б�: \n";
					for (int i = 0; i < num; i++)
						reply += getNickname(players[i]) + "(" + players[i] + ")" + "  " + To_Str(i + 1) + "��\n";
				}
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
				sethunter_die(fromGroup,"��");
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

			std::wstring regString(_T("����(\\d+)(?:��|)"));

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
				int temp;
				temp = stoi(str1);
				if (temp <= num)
					setSheriff(fromGroup, players[temp - 1]);
				reply += "�����ѳɹ�����,�����ξ�������: \n";
				CQ_sendGroupMsg(ac, fromGroup, reply.c_str());
			}
		}
	
		
		if (smsg == "������־"||smsg=="����˵��"||smsg=="���½���")
		{
			string ureply = "[CQ:emoji,id=9989]�汾��: 1.20\n���θ�����������: \n1.����˭���Ե�������ʾ˫���ʻ㹦��\n2.���ӽ�Ҳ�����ʾ\n";
				ureply+="3.�������ѽ����ߵ�1200\n4.�޸�����BUG\n5.����ħ������Ϸ,��ӭ����(����� ħ��������)\n6.�����Ƴ�ħ�������˶�ս��\n���๦��,�����ڴ�..... ";
			CQ_sendGroupMsg(ac, fromGroup, ureply.c_str());
			return EVENT_BLOCK;
		}




return EVENT_IGNORE;

}

/*
* Type=4 ��������Ϣ
*/
CQEVENT(int32_t, __eventDiscussMsg, 32)(int32_t subType, int32_t sendTime, int64_t fromDiscuss, int64_t fromQQ, const char *msg, int32_t font) {

	return EVENT_IGNORE; 
}


/*
* Type=101 Ⱥ�¼�-����Ա�䶯
* subType �����ͣ�1/��ȡ������Ա 2/�����ù���Ա
*/
CQEVENT(int32_t, __eventSystem_GroupAdmin, 24)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t beingOperateQQ) {

	return EVENT_IGNORE; 
}


/*
* Type=102 Ⱥ�¼�-Ⱥ��Ա����
* subType �����ͣ�1/ȺԱ�뿪 2/ȺԱ���� 3/�Լ�(����¼��)����
* fromQQ ������QQ(��subTypeΪ2��3ʱ����)
* beingOperateQQ ������QQ
*/
CQEVENT(int32_t, __eventSystem_GroupMemberDecrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {

	return EVENT_IGNORE; 
}


/*
* Type=103 Ⱥ�¼�-Ⱥ��Ա����
* subType �����ͣ�1/����Ա��ͬ�� 2/����Ա����
* fromQQ ������QQ(������ԱQQ)
* beingOperateQQ ������QQ(����Ⱥ��QQ)
*/
CQEVENT(int32_t, __eventSystem_GroupMemberIncrease, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, int64_t beingOperateQQ) {

	return EVENT_IGNORE; 
}


/*
* Type=201 �����¼�-���������
*/
CQEVENT(int32_t, __eventFriend_Add, 16)(int32_t subType, int32_t sendTime, int64_t fromQQ) {

	return EVENT_IGNORE;
}


/*
* Type=301 ����-�������
* msg ����
* responseFlag ������ʶ(����������)
*/
CQEVENT(int32_t, __eventRequest_AddFriend, 24)(int32_t subType, int32_t sendTime, int64_t fromQQ, const char *msg, const char *responseFlag) {

	//CQ_setFriendAddRequest(ac, responseFlag, REQUEST_ALLOW, "");

	return EVENT_IGNORE; 
}


/*
* Type=302 ����-Ⱥ���
* subType �����ͣ�1/����������Ⱥ 2/�Լ�(����¼��)������Ⱥ
* msg ����
* responseFlag ������ʶ(����������)
*/
CQEVENT(int32_t, __eventRequest_AddGroup, 32)(int32_t subType, int32_t sendTime, int64_t fromGroup, int64_t fromQQ, const char *msg, const char *responseFlag) {

	//if (subType == 1) {
	//	CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPADD, REQUEST_ALLOW, "");
	//} else if (subType == 2) {
	//	CQ_setGroupAddRequestV2(ac, responseFlag, REQUEST_GROUPINVITE, REQUEST_ALLOW, "");
	//}

	return EVENT_IGNORE; //���ڷ���ֵ˵��, ����_eventPrivateMsg������
}

/*
* �˵������� .json �ļ������ò˵���Ŀ��������
* �����ʹ�ò˵������� .json ���˴�ɾ�����ò˵�
*/
CQEVENT(int32_t, __menuA, 0)() {
	MessageBoxA(NULL, "˽�Ĺ���: (��ϸ���ݷ��� �˵� ��ѯ)\n ����QQ����Android��Ⱥ�ｲ��\n ����QQ��Ȩ�������QQ \n �����ѯ \n ���㹦�� \n �ǳƲ�ѯ���� \n ��Ϸ�жԻ����� \n\n\n ����QQ��1069148429", "" ,0);
	return 0;
}

CQEVENT(int32_t, __menuB, 0)() {
	MessageBoxA(NULL, "Ⱥ�Ĺ���: (��ϸ���ݷ��� �˵� ��ѯ)\n ǩ������ \n �����ѯ���� \n ���㹦�� \n ����QQ����Android��Ⱥ�ｲ�� \n �������� \n ���а��ѯ���� \n ������Ϣ��ѯ���� \n ˭���Ե���Ϸ \n ����ɱ��Ϸ \n\n\n ����QQ��1069148429", "" ,0);
	return 0;
}
