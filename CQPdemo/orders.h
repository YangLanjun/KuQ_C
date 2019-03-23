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


	std::wstring regString(_T("����Ⱥ(?:\"|��)(\\d+?)(?:\"|��)��˵(?:\"|��)(.+?)(?:\"|��)"));

	// ���ʽѡ�� - ���Դ�Сд  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

	// ����һ��������ʽ���  
	std::wregex regExpress(regString, fl);

	// ������ҵĽ��  
	std::wsmatch ms;
	// ����  
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

	//ͬ��ʹ��������ʽ���μ��ϱ����Ƶĺ���

	std::wstring regString(_T("��˵(?:\"|��)(.*?)(?:\"|��)"));

	// ���ʽѡ�� - ���Դ�Сд  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

	// ����һ��������ʽ���  
	std::wregex regExpress(regString, fl);

	// ������ҵĽ��  
	std::wsmatch ms;
	// ����  
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


	std::wstring regString(_T("����QQ(?:\\:|��)(?:\"|��)(\\d+?)(?:\"|��).*?"));

	// ���ʽѡ�� - ���Դ�Сд  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

	// ����һ��������ʽ���  
	std::wregex regExpress(regString, fl);

	// ������ҵĽ��  
	std::wsmatch ms;
	// ����  
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

