//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;

class HashTable
{
private:
	int* table;
	int key;
public:

	HashTable()
	{
		table = new int[10];
		key = 0;
		for (int i = 0; i < 10; i++)
		{
			table[i] = -1;
		}
	}

	void addElement(int newElement)
	{
		key = newElement % 10;
		for (int i = 0; i < 10; i++)
		{
			if (isEmpty(key))
			{
				table[key] = newElement;
				break;
			}
			else
			{
				key = (key + 1) % 10;
			}
		}
	}
	void deleteElement(int keyElement)
	{
		key = keyElement % 10;
		for (int i = 0; i < 10; i++)
		{
			if (!isEmpty(key))
			{
				if (table[key] == keyElement)
				{
					table[key] = -1;
					break;
				}
				else
				{
					key = (key + 1) % 10;
				}
			}
		}
	}

	int findElement(int keyElement)
	{
		key = keyElement % 10;
		for (int i = 0; i < 10; i++)
		{
			if (!isEmpty(key))
			{
				if (table[key] == keyElement)
				{
					return key;
				}
				else
				{
					key = (key + 1) % 10;
				}
			}
		}
		return -1;
	}

	bool isEmpty(int address)
	{
		if (table[address] == -1)
		{
			return true;
		}
		return false;
	}
	string toString()
	{
		string toReturn = "";
		for (int i = 0; i < 10; i++)
		{
			if (!isEmpty(i))
			{
				toReturn = toReturn + "Value in " + to_string(i) + ": " + to_string(table[i]) + "\n";
			}
		}
		return toReturn;
	}
};