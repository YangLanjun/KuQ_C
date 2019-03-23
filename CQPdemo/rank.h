#pragma once
#ifndef RANK_H
#define RANK_H
#include"QQfunctions.h"
#include"cfg_file.h"
#include<valarray>			
#include<vector>

string moneyRank(int64_t fromQQ, int64_t fromGroup)
{
	vector<string>users;
	vector<int>money;
	string cfgfilepath= "files\\usersmoney" + setqq_str(fromGroup) + ".cfg";
	string result;
	fstream cfgFile;
	cfgFile.open(cfgfilepath.c_str());//打开文件      
	int totalnum = 0;
	if (!cfgFile)
	{

		return"error!";
	}
	else
	{
		if (!cfgFile.is_open())
		{

			return "error";
		}
		char tmp[1000];
		
		while (!cfgFile.eof())//循环读取每一行  
		{
			cfgFile.getline(tmp, 1000);//每行读取前1000个字符，1000个应该足够了  
			string line(tmp);
			size_t pos = line.find('=');
			if (pos == string::npos) continue;
			users.push_back( line.substr(0, pos));//取=号之前  
			money.push_back ( stoi(line.substr(pos + 1)));
			totalnum++;//取=号之后  
		}
	}
	if (totalnum == 0)
		return "error!";
	result = "[CQ:emoji,id=127882]======金币排行榜如下======[CQ:emoji,id=127882]\n";
	int temp;
	string tempstr;
	int urs = 0;
	for (int i = 0; i < totalnum; i++)
	{
		for (int j = i+1; j < totalnum; j++)
		{
			if (money[i] < money[j])
			{
				temp = money[i];
				money[i] = money[j];
				money[j] = temp;
				tempstr = users[i];
				users[i] = users[j];
				users[j] = tempstr;
			}
		
		}
		if (users[i] == setqq_str(fromQQ))
			urs = i;
		
		if (i<10)
		result += "第" + To_Str(i + 1) + "名: " + getNickname(users[i]) + "  [CQ:emoji,id=128180]" + To_Str(money[i]) + "\n";
		
	}
	result += "[CQ:emoji,id=128200]你的排名: " + To_Str(urs + 1);
	return result;
}
string expRank(int64_t fromQQ, int64_t fromGroup)
{
	vector<string>users;
	vector<int>exp;
	string cfgfilepath = "files\\usersexp" + setqq_str(fromGroup) + ".cfg";
	string result;
	fstream cfgFile;
	cfgFile.open(cfgfilepath.c_str());//打开文件      
	int totalnum = 0;
	if (!cfgFile)
	{

		return"error!";
	}
	else
	{
		if (!cfgFile.is_open())
		{

			return "error";
		}
		char tmp[1000];

		while (!cfgFile.eof())//循环读取每一行  
		{
			cfgFile.getline(tmp, 1000);//每行读取前1000个字符，1000个应该足够了  
			string line(tmp);
			size_t pos = line.find('=');
			if (pos == string::npos) continue;
			users.push_back(line.substr(0, pos));//取=号之前  
			exp.push_back(stoi(line.substr(pos + 1)));
			totalnum++;//取=号之后  
		}
	}
	if (totalnum == 0)
		return "error!";
	result = "[CQ:emoji,id=127882]======经验排行榜如下======[CQ:emoji,id=127882]\n";
	int temp;
	string tempstr;
	int urs = 0;
	for (int i = 0; i < totalnum ; i++)
	{
		for (int j = i + 1; j < totalnum; j++)
		{
			if (exp[i] < exp[j])
			{
				temp = exp[i];
				exp[i] = exp[j];
				exp[j] = temp;
				tempstr = users[i];
				users[i] = users[j];
				users[j] = tempstr;
			}

		}
		if (users[i] == setqq_str(fromQQ))
			urs = i;
		if(i<10)
		result += "第" + To_Str(i + 1) + "名: " + getNickname(users[i]) + "  [CQ:emoji,id=127758]" + To_Str(exp[i]) + "\n";
	}
	result += "[CQ:emoji,id=128201]你的排名: " + To_Str(urs + 1);
	return result;
}
#endif // !RANK_H

