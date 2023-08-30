//
// pch.h
// Header for standard system include files.
//
#pragma once
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;
/*
template<size_t N>

class BitSet
{
private:
	bool setBit[N];
	bool found = false;
	int counter;
	string toString;
	unsigned long long toUllong;
	unsigned long toUlong;
	int shortened;
	int remainder;
	string fromLong;
	bool start;
	int fromChar;
public: 
	BitSet()
	{
		for (int i = 0; i < N; i++)
			setBit[i] = 0;
	}

	BitSet(vector<pair<int, bool>> pairVector)
	{
		for (int i = 0; i < N; i++)
			setBit[i] = 0;
		for (int i = 0; i < pairVector.size(); i++)
			setBit[pairVector[i].first] = pairVector[i].second;
	}
	
	BitSet(string newSet)
	{
		for (int i = 0; i < N - newSet.size(); i++) 
			setBit[i] = 0;

		for (int i = N - newSet.size(); i < N; i++) 
		{
			if (newSet[i] == '0')
				setBit[i] = 0;
			if (newSet[i] == '1')
				setBit[i] = 1;
		}
	}
	
/*	BitSet(unsigned long int newSetFromLong) 
	{
		shortened = newSetFromLong;
		remainder = 0;
		fromLong = "";
		while(shortened != 0 && shortened != 1)
		{
			remainder = shortened % 2;
			if(remainder == 0)
				fromLong = "0" + fromLong;
			if (remainder == 1)
				fromLong = "1" + fromLong;
			shortened = shortened / 2;
		}
		fromLong = "1" + fromLong;
		for (int i = 0; i < N - fromLong.size(); i++)
			setBit[i] = 0;

		for (int i = N - fromLong.size(); i < N; i++)
		{
			if (fromLong[i] == '0')
				setBit[i] = 0;
			if (fromLong[i] == '1')
				setBit[i] = 1;
		}

	}
	BitSet(wchar_t givenChar)
	{
		unsigned int fromCharToDecimal = (int)givenChar;
		remainder = 0;
		string fromChar = "";
		while (fromCharToDecimal != 0 && fromCharToDecimal != 1)
		{
			remainder = fromCharToDecimal % 2;
			if (remainder == 0)
				fromChar = "0" + fromChar;
			if (remainder == 1)
				fromChar = "1" + fromChar;
			fromCharToDecimal = fromCharToDecimal / 2;
		}
		fromChar = "1" + fromChar;
		for (int i = 0; i < N - fromChar.size(); i++)
		{
			setBit[i] = 0;
		}
		for (int i = 0; i < fromChar.size(); i++)
		{
			if (fromChar[i] == '0')
				setBit[N - fromChar.size() + i] = 0;
			if (fromChar[i] == '1')
				setBit[N - fromChar.size() + i] = 1;
		}
	}

	bool all()
	{
		for (int i = 0; i < N; i++)
		{
			if (!setBit[i])
				return false;
		}
		return true;
	}

	bool any()
	{
		for (int i = 0; i < N; i++)
		{
			if (setBit[i])
				return true;
		}
		return false;
	}

	int count()
	{
		counter = 0;
		for (int i = 0; i < N; i++)
		{
			if (setBit[i])
				counter++;
		}
		return counter;
	}

	void flip()
	{
		for (int i = 0; i < N; i++)
			setBit[i] = !setBit[i];
	}
	
	void flip(int position)
	{
		setBit[position] = !setBit[position];
	}

	bool none()
	{
		for (int i = 0; i < N; i++)
		{
			if (setBit[i])
				return false;
		}
		return true;
	}
	
	void reset()
	{
		for (int i = 0; i < N; i++)
			setBit[i] = 0;
	}
	
	void reset(int position)
	{
		setBit[position] = 0;
	}

	void set()
	{
		for (int i = 0; i < N; i++)
			setBit[i] = 1;
	}

	void set(int position)
	{
		setBit[position] = 1;
	}

	int size()
	{
		return N;
	}

	bool test(int position)
	{
		return setBit[position];
	}
	
	string to_string()
	{
		toString = "";
		start = false;
		for (int i = 0; i < N; i++)
		{
			if (setBit[i])
			{
				toString = toString + "1";
				start = true;
			}
			else if (start)
				toString = toString + "0";
		}
		return toString;
	}
	unsigned long long to_ullong()
	{
		toUllong = 0;
		for (int i = 0; i < N; i++)
			toUllong = toUllong + setBit[i];
		return toUllong;
	}
	unsigned long to_ulong()
	{
		string stringToGetLong = to_string();
		toUlong = 1;
		for (int i = 1; i < stringToGetLong.size(); i++)
		{
			toUlong = toUlong * 2;
			if(stringToGetLong[i] == '1')
				toUlong = toUlong + 1;
		}
		return toUlong;
	}
	wchar_t toChar()
	{
		string StringToGetChar = to_string();
		int toIntedChar = 1;
		for (int i = 1; i < StringToGetChar.size(); i++)
		{
			toIntedChar = toIntedChar * 2;
			if (StringToGetChar[i] == '1')
				toIntedChar = toIntedChar + 1;
		}
		wchar_t toReturn = toIntedChar;
		return toReturn;
	}
	bool operator!=(const BitSet& right) const
	{
		for (int i = 0; i < N; i++)
		{
			if (setBit[i] != right.setBit[i])
			{
				return true;
			}
		}
		return false;
	}
	bool operator==(const BitSet& right) const
	{
		for (int i = 0; i < N; i++)
		{
			if (setBit[i] != right.setBit[i])
			{
				return false;
			}
		}
		return true;
	}
	BitSet& operator&=(const BitSet& right)
	{
		for (int i = 0; i < N; i++)
		{
			setBit[i] = setBit[i] & right.setBit[i];
		}
		return* this;
	}
	BitSet& operator|=(const BitSet& right)
	{
		for (int i = 0; i < N; i++)
		{
			setBit[i] = setBit[i] | right.setBit[i];
		}
		return* this;
	}
	BitSet& operator^=(const BitSet& right)
	{
		for (int i = 0; i < N; i++)
		{
			setBit[i] = setBit[i] ^ right.setBit[i];
		}
		return* this;
	}
	BitSet& operator~()
	{
		for (int i = 0; i < N; i++)
		{
			setBit[i] = !setBit[i];
		}
		return* this;
	}

	BitSet& operator >>(int shifts)
	{
		setBit[0] = 0;
		for (int j = 0; j < shifts; j++)
		{
			for (int i = N - 1; i > 1; i--)
			{
				setBit[i] = setBit[i - 1];
			}
		}
		return* this;
	}
	BitSet& operator <<(int shifts)
	{
		for (int j = 0; j < shifts; j++)
		{
			for (int i = 0; i < N - 1; i++)
			{
				setBit[i] = setBit[i + 1];
			}
			setBit[N - 1] = 0;
		}
		return*this;
	}
};*/

class BitSet
{
private:
	int set1;
	int set2;
	int set3;
	int set4;
	int set5;
	int set6;
	int set7;
	int set8;
	int position;
public:
	BitSet()
	{
		set1 = 0;
		set2 = 0;
		set3 = 0;
		set4 = 0;
		set5 = 0;
		set6 = 0;
		set7 = 0;
		set8 = 0;
		position = 0;
	}
	int add(unsigned char toAdd)
	{
		position = toAdd % 32;
		switch (toAdd / 32)
		{
		case 0: toString(set1)[position] = '1'; break;
		case 1: toString(set2)[position] = '1'; break;
		case 2: toString(set3)[position] = '1'; break;
		case 3: toString(set4)[position] = '1'; break;
		case 4: toString(set5)[position] = '1'; break;
		case 5: toString(set6)[position] = '1'; break;
		case 6: toString(set7)[position] = '1'; break;
		case 7: toString(set8)[position] = '1'; break;
		}
	}
	string toString(int setToString)
	{
		int shortened = setToString;
		int remainder = 0;
		string toReturn = "";
		while (shortened != 0 && shortened != 1)
		{
			remainder = shortened % 2;
			if (remainder == 0)
				toReturn = "0" + toReturn;
			if (remainder == 1)
				toReturn = "1" + toReturn;
			shortened = shortened / 2;
		}
		toReturn = "1" + toReturn;
		while (toReturn.size() != 8)
		{
			toReturn = "0" + toReturn;
		}
		return toReturn;
	}
};