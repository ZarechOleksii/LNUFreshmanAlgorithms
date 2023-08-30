//
// pch.h
// Header for standard system include files.
//

#pragma once
#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include <cmath> 
using namespace std;

class Table
{
private:
	string tableArray[676];
public:
	Table()
	{
	}
	void place(string toPlace, string key)
	{
		tableArray[(((int)key[0] - 65) * 26) + ((int)key[1] - 65)] = toPlace;
	}
	string getStringByKey(string key)
	{
		return tableArray[((key[0] - 65) * 26) + (key[1] - 65)];
	}
	int getAddressByKey(string key)
	{
		return ((((key[0] - 65) * 26) + (key[1] - 65)));
	}
	int getAddressByContent(string content)
	{
		for (int i = 0; i < 676; i++)
		{
			if (content == tableArray[i])
				return i;
		}
		return -1;
	}
	string getKeyByContent(string content)
	{
		string toReturn = "";
		for (int i = 0; i < 676; i++)
		{
			if (content == tableArray[i])
			{
				toReturn = (char)((i / 26) + 65);
				toReturn += (char)((i % 26) + 65);
				return toReturn;
			}
		}
		return "Missing";
	}
	void clearByKey(string key)
	{
		tableArray[((key[0] - 65) * 26) + (key[1] - 65)] = "";
	}

	 double howFull()
	{
		double elementAmount = 0;
		for (int i = 0; i < 676; i++)
		{
			if (tableArray[i] != "")
				elementAmount++;
		}
		return round(((elementAmount / 676) * 10000)) / 10000;
	}
};