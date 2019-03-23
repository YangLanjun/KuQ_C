#pragma once
#ifndef ORDERS_H
#define ORDERS_H
#include"cfg_file.h"
#include "FunctionConvert.h"
using namespace std;

string judgecomand2qun(string s)
{
	wstring result(_T(""));
	wstring text = stows(s);


	std::wstring regString(_T("你在群(?:\"|“)(\\d+?)(?:\"|”)里说(?:\"|“)(.+?)(?:\"|”)"));

	// 表达式选项 - 忽略大小写  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

	// 编译一个正则表达式语句  
	std::wregex regExpress(regString, fl);

	// 保存查找的结果  
	std::wsmatch ms;
	// 查找  
	if (std::regex_search(text, ms, regExpress)) {

		result = ms.str(1) + _T("/") + ms.str(2);

	}
	else
	{
		result = _T("n");
	}

	return wstos(result);
}

string judgecomand(string s)
{
	wstring result(_T(""));
	wstring text = stows(s);

	//同样使用正则表达式，参见上边类似的函数

	std::wstring regString(_T("你说(?:\"|“)(.*?)(?:\"|”)"));

	// 表达式选项 - 忽略大小写  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

	// 编译一个正则表达式语句  
	std::wregex regExpress(regString, fl);

	// 保存查找的结果  
	std::wsmatch ms;
	// 查找  
	if (std::regex_search(text, ms, regExpress)) {

		result = ms.str(1);

	}
	else
	{
		result = _T("n");
	}
	return wstos(result);
}
string judgeset(string s)
{
	wstring result(_T(""));
	wstring text = stows(s);


	std::wstring regString(_T("主人QQ(?:\\:|：)(?:\"|“)(\\d+?)(?:\"|”).*?"));

	// 表达式选项 - 忽略大小写  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

	// 编译一个正则表达式语句  
	std::wregex regExpress(regString, fl);

	// 保存查找的结果  
	std::wsmatch ms;
	// 查找  
	if (std::regex_search(text, ms, regExpress)) {

		result = ms.str(1) + _T("/") + ms.str(2);

	}
	else
	{
		result = _T("n");
	}


	return wstos(result);
}



#endif // !MINGLING_H

