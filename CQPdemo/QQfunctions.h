#pragma once
#ifndef QQFUNCTIONS_H
#define QQFUNCTIONS_H
#include "FunctionConvert.h"
#include<ctime>

using namespace std;
string getNickname(string fromQQ)
{
	string path = "http://r.pengyou.com/fcg-bin/cgi_get_portrait.fcg?uins=" + fromQQ;

	wstring wpath = stows(path.c_str());
	wchar_t* path_t = new wchar_t[wpath.size() + 1];
	swprintf(path_t, wpath.size() + 1, L"%lS", wpath.c_str());
	string html = urlopenGBK(path_t);

	std::locale loc("");
	std::wcout.imbue(loc);
	wstring result(_T(""));

	wstring text(html.begin(), html.end());
	wstring newIP(_T("127.0.0.1"));
	wstring regString(_T("-1,0,0,0,\"(.+)\",0"));

	// ���ʽѡ�� - ���Դ�Сд  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;
	// ����һ��������ʽ���  
	std::wregex regExpress(regString, fl);

	// ������ҵĽ��  
	std::wsmatch ms;
	// ����  
	if (std::regex_search(text, ms, regExpress)) 
	{
		result = result + ms.str(1);
	}
	return string(result.begin(), result.end());


}



bool judge_Digit(string str)
{
	
	if (str[0] >= '0'&&str[0] <= '9')
		return true;
	else
		return false;
 }
#endif // !QQFUNCTIONS_H


