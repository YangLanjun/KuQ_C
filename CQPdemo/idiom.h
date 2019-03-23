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

	string judge_sentence(string s)//判断成语接龙功能的命令  输入命令 返回要查的成语的字符串
	{
		wstring result(_T(""));
		wstring text = stows(s);
		//同样使用正则表达式，参见上面的函数
		std::wstring regString(_T("(?:(.+?)开头的成语有(?:什么|啥|哪些).*|成语(.+?)接(?:什么|啥).*)"));

		// 表达式选项 - 忽略大小写  
		std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

		// 编译一个正则表达式语句  
		std::wregex regExpress(regString, fl);

		// 保存查找的结果  
		std::wsmatch ms;
		// 查找  
		if (std::regex_search(text, ms, regExpress)) {

			result = ms.str(1) + ms.str(2);

		}
		else
		{
			result = _T("n");
		}

		return wstos(result);
	}
	string takeidioms(string html) //提取需要的成语  输入网页源码 返回一个包括所需成语的字符串 
	{
		std::locale loc("");
		std::wcout.imbue(loc);
		wstring result(_T(""));

		wstring text(html.begin(), html.end());
		std::wstring newIP(_T("127.0.0.1"));
		std::wstring regString(_T("<a href=\"//chengyu.51240.com/.+?__chengyuchaxun/\" target=\"_blank\">(.*?)</a>"));

		// 表达式选项 - 忽略大小写  
		std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

		// 编译一个正则表达式语句  
		std::wregex regExpress(regString, fl);

		// 保存查找的结果  
		std::wsmatch ms;
		// 查找  
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
