#pragma once
#ifndef IDIOM_H
#define IDIOM_H


#include "stdafx.h"
#include "FunctionConvert.h"

#define MAXSIZE 1024
#pragma comment(lib, "Wininet.lib") 
using namespace std;
class idioms
{
public:
	idioms(){}
	~idioms(){}

	string judge_sentence(string s)//�жϳ���������ܵ�����  �������� ����Ҫ��ĳ�����ַ���
	{
		wstring result(_T(""));
		wstring text = stows(s);
		//ͬ��ʹ��������ʽ���μ�����ĺ���
		std::wstring regString(_T("(?:(.+?)��ͷ�ĳ�����(?:ʲô|ɶ|��Щ).*|����(.+?)��(?:ʲô|ɶ).*)"));

		// ���ʽѡ�� - ���Դ�Сд  
		std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

		// ����һ��������ʽ���  
		std::wregex regExpress(regString, fl);

		// ������ҵĽ��  
		std::wsmatch ms;
		// ����  
		if (std::regex_search(text, ms, regExpress)) {

			result = ms.str(1) + ms.str(2);

		}
		else
		{
			result = _T("n");
		}

		return wstos(result);
	}
	string takeidioms(string html) //��ȡ��Ҫ�ĳ���  ������ҳԴ�� ����һ���������������ַ��� 
	{
		std::locale loc("");
		std::wcout.imbue(loc);
		wstring result(_T(""));

		wstring text(html.begin(), html.end());
		std::wstring newIP(_T("127.0.0.1"));
		std::wstring regString(_T("<a href=\"//chengyu.51240.com/.+?__chengyuchaxun/\" target=\"_blank\">(.*?)</a>"));

		// ���ʽѡ�� - ���Դ�Сд  
		std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

		// ����һ��������ʽ���  
		std::wregex regExpress(regString, fl);

		// ������ҵĽ��  
		std::wsmatch ms;
		// ����  
		while (std::regex_search(text, ms, regExpress)) {
			result = result + ms.str(1) + _T("\n");
			text = text.substr(ms.position(0) + ms.length(0), text.length());

		}
		return string(result.begin(), result.end());
	}
	string idioms_Find(string ch) 
	{
		string idioms_o = ch;
		idioms_o = "http://chengyujielong.51240.com/" + UrlEncode(string_To_UTF8(idioms_o)) + "__chengyujielong/"; 

		wstring widioms_o = stows(idioms_o.c_str());
		wchar_t* idioms_o_t = new wchar_t[widioms_o.size() + 1]; 
		swprintf(idioms_o_t, widioms_o.size() + 1, L"%lS", widioms_o.c_str());
		string html = urlopen(idioms_o_t);

		string idioms = takeidioms(html);
		return idioms;
	}

	
};
#endif // !IDIOM_H
