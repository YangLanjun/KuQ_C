#pragma once
#ifndef CFG_FILE_H
#define CFG_FILE_H

#include <iostream>  
#include <string>  
#include <fstream>  
//#include "FunctionConvert.h"

using namespace std;


string UTF8_To_String(const std::string & str) //网上找的utf-8转string的函数，因为网页获取时是utf-8编码的，直接用有乱码
{
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];
	memset(pwBuf, 0, nwLen * 2 + 2);

	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	memset(pBuf, 0, nLen + 1);

	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr = pBuf;

	delete[]pBuf;
	delete[]pwBuf;

	pBuf = NULL;
	pwBuf = NULL;

	return retStr;
}
static bool readConfigFileU_to_str(const char * cfgfilepath, const string & key, string & value)
{
	fstream cfgFile;
	cfgFile.open(cfgfilepath);//打开文件      
	if (!cfgFile)
	{
		
		return false;
	}
	else
	{
		if (!cfgFile.is_open())
		{

			return false;
		}
		char tmp[1000];
		while (!cfgFile.eof())//循环读取每一行  
		{
			cfgFile.getline(tmp, 1000);//每行读取前1000个字符，1000个应该足够了  
			string line(tmp);

			string reline = UTF8_To_String(line);
			size_t pos = reline.find('=');
			if (pos == string::npos) continue;
			string tmpKey = reline.substr(0, pos);//取=号之前  
			if (key == tmpKey)
			{
				value = reline.substr(pos + 1);//取=号之后  
				return true;
			}
		}
		return false;
	}
}

static bool readConfigFile(const char * cfgfilepath, const string & key, string & value)
{
	fstream cfgFile;
	cfgFile.open(cfgfilepath);//打开文件      
	if (!cfgFile)
	{

		return false;
	}
	else
	{
		if (!cfgFile.is_open())
		{

			return false;
		}
		char tmp[1000];
		while (!cfgFile.eof())//循环读取每一行  
		{
			cfgFile.getline(tmp, 1000);//每行读取前1000个字符，1000个应该足够了  
			string line(tmp);
			size_t pos = line.find('=');
			if (pos == string::npos) continue;
			string tmpKey = line.substr(0, pos);//取=号之前  
			if (key == tmpKey)
			{
				value = line.substr(pos + 1);//取=号之后  
				return true;
			}
		}
		return false;
	}
}

static bool readConfigFile(const char * cfgfilepath, const string & key, int & value)
{
	fstream cfgFile;
	cfgFile.open(cfgfilepath);//打开文件    
	if (!cfgFile)
	{
		return false;
	}
	else
	{
		if (!cfgFile.is_open())
		{

			return false;
		}
		char tmp[1000];
		while (!cfgFile.eof())
		{
			cfgFile.getline(tmp, 1000);
			string line(tmp);
		
			size_t pos = line.find('=');
			if (pos == string::npos) continue;
			string tmpKey = line.substr(0, pos);
			if (key == tmpKey)
			{
				value = stoi(line.substr(pos + 1));
				return true;
			}
		}
		return false;
	}
}
static bool readConfigFileKey(const char * cfgfilepath, const string & value, string & key)
{
	fstream cfgFile;
	cfgFile.open(cfgfilepath);//打开文件      
	if (!cfgFile)
	{

		return false;
	}
	else
	{
		if (!cfgFile.is_open())
		{

			return false;
		}
		char tmp[1000];
		while (!cfgFile.eof())//循环读取每一行  
		{
			cfgFile.getline(tmp, 1000);//每行读取前1000个字符，1000个应该足够了  
			string line(tmp);
			size_t pos = line.find('=');
			if (pos == string::npos) continue;
			string tempvalue = line.substr(pos + 1);
			//取=号之前  
			if (value == tempvalue)
			{
				 key = line.substr(0, pos);
				return true;
			}
		}
		return false;
	}
}


static bool findkey(const char * cfgfilepath, const string & key)
{
	fstream cfgFile;
	cfgFile.open(cfgfilepath);
	if (!cfgFile)
	{
		return false;
	}
	else
	{
		if (!cfgFile.is_open())
		{

			return false;
		}
		char tmp[1000];
		while (!cfgFile.eof())
		{
			cfgFile.getline(tmp, 1000);
			string line(tmp);
			size_t pos = line.find('=');
			if (pos == string::npos) continue;
			string tmpKey = line.substr(0, pos);
			if (key == tmpKey)
				return true;
		}
		return false;
	}

}

static void getkey(const char * cfgfilepath, string keys[],int num)
{
	fstream cfgFile;
	cfgFile.open(cfgfilepath);
	if (!cfgFile)
	{
		return ;
	}
	else
	{
		if (!cfgFile.is_open())
		{

			return ;
		}
		char tmp[1000];
		int i = 0;
		while (!cfgFile.eof())
		{
			cfgFile.getline(tmp, 1000);
			string line(tmp);
			size_t pos = line.find('=');
			if (pos == string::npos) 
				continue;
			string tmpKey = line.substr(0, pos);
			keys[i] = tmpKey;
			i++;
		}
	}
}

static void getkey_withStr(const char * cfgfilepath, string keys[], int& num,string str)
{
	fstream cfgFile;
	cfgFile.open(cfgfilepath);
	if (!cfgFile)
	{
		return;
	}
	else
	{
		if (!cfgFile.is_open())
		{

			return;
		}
		char tmp[1000];
		int i = 0;
		while (!cfgFile.eof())
		{
			cfgFile.getline(tmp, 1000);
			string line(tmp);
			size_t pos = line.find('=');
			if (pos == string::npos)
				continue;
			if (line.substr(pos + 1) == str)
			{
				string tmpKey = line.substr(0, pos);
				keys[i] = tmpKey;
				i++;
			}
		}
		num = i;
	}
}

void delcontent(const char * cfgfilepath, const string & key)
{
	fstream cfgFile(cfgfilepath);
	string line;
	fstream outfile("linshi.cfg", ios::out | ios::trunc);
	char tmp[1000];
	while (!cfgFile.eof())
	{
		cfgFile.getline(tmp, 1000);
		string line(tmp);
		size_t pos = line.find('=');
		if (pos == string::npos) continue;
		string tmpKey = line.substr(0, pos);
		if (key != tmpKey)
		{
			outfile << line << endl;
		}
	}

	outfile.close();

	cfgFile.close();

	fstream outfile1(cfgfilepath, ios::out | ios::trunc);

	fstream file1("linshi.cfg");

	while (!file1.eof())
	{
		getline(file1, line);
		outfile1 << line << endl;
	}

	outfile1.close();

	file1.close();

}

static void writeConfigFile(const char * cfgfilepath, const string & key, const string value)
{
	fstream out(cfgfilepath);
	if (!out)
	{
		ofstream outcreat(cfgfilepath);
		outcreat << key << "=" << value << endl;
		outcreat.close();
	}
	else
	{
		delcontent(cfgfilepath, key);
		out.seekp(0, ios_base::end);
		out << key << "=" << value << endl;
	}
}

#endif 

