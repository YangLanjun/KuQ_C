#pragma once

#include "stdafx.h"
#include "FunctionConvert.h"
#define MAXSIZE 1024
#pragma comment(lib, "Wininet.lib") 
using namespace std;
string takeStatus(string html) //��ȡ��Ҫ�ĳ���  ������ҳԴ�� ����һ���������������ַ��� 
{
	std::locale loc("");
	std::wcout.imbue(loc);
	wstring result(_T(""));

	wstring text(html.begin(), html.end());
	std::wstring newIP(_T("127.0.0.1"));
	//std::wstring regString(_T("<a href=\"//chengyu.51240.com/.+?__chengyuchaxun/\" target=\"_blank\">(.*?)</a>"));

	std::wstring regString(_T("<td class=\"state-name\" interviewTime=\"\" writeUrl=\"\" interviewUrl=\"\" statusType=\" (.*) \""));

	// ���ʽѡ�� - ���Դ�Сд  
	std::regex_constants::syntax_option_type fl = std::regex_constants::icase;

	// ����һ��������ʽ���  
	std::wregex regExpress(regString, fl);

	// ������ҵĽ��  
	std::wsmatch ms;
	// ����  
	while (std::regex_search(text, ms, regExpress)) {
		result = result + ms.str(1);
		text = text.substr(ms.position(0) + ms.length(0), text.length());
	}
	return string(result.begin(), result.end());
}

string html_get_status()
{
	string getUrl = "http://campus.alibaba.com/myJobApply.htm";
	wstring w_url = stows(getUrl.c_str());
	wchar_t* url_o_t = new wchar_t[w_url.size() + 1];
	swprintf(url_o_t, w_url.size() + 1, L"%lS", w_url.c_str());
	string cookie = "Cookie:";
	string qq = "1069148429";
	string value = "";
	string path = "files\\userCookie.cfg";
	readConfigFile(path.c_str(), qq, value);
    cookie = cookie + value;
	wstring headStr = stows(cookie);
	string html = urlOpenWithCookies(url_o_t, headStr);
	string status = takeStatus(html);
	return status;
}



