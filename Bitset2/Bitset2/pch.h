//
// pch.h
// Header for standard system include files.
//

#pragma once
#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

class BitSet
{
private:
	unsigned int* setAll;
	unsigned int position;
	unsigned int index;
public:
	BitSet()
	{
		setAll = new unsigned int[8];
		for (int i = 0; i < 8; i++)
		{ 
			setAll[i] = 0;
		}
		position = 0;
		index = 0;
	}
	
	void operator+=(unsigned char toAdd)
	{
		index = toAdd / 32;
		position = toAdd % 32;
		setAll[index] = setAll[index] | 1 << position;
	}

	void operator-=(unsigned char toAdd)
	{
		index = toAdd / 32;
		position = toAdd % 32;
		setAll[index] = setAll[index] & ~(1 << position);
	}

	bool present(unsigned char toAdd)
	{
		index = toAdd / 32;
		position = toAdd % 32;
		return (setAll[index] & (1 << position));
	}

	void add(int numberInArr, int positions)
	{
		setAll[numberInArr] = setAll[numberInArr] | 1 << positions;
	}

	BitSet operator&=(BitSet& right)
	{
		BitSet toReturn;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 32; j++)
			{
				if ((setAll[i] & (1 << j)) && (right.setAll[i] & (1 << j)))
				{
					toReturn.add(i, j);
				}
			}
		}
		return toReturn;
	}

	BitSet operator|=(BitSet& right)
	{
		BitSet toReturn;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 32; j++)
			{
				if ((setAll[i] & (1 << j)) || (right.setAll[i] & (1 << j)))
				{
					toReturn.add(i, j);
				}
			}
		}
		return toReturn;
	}

	BitSet operator-=(BitSet& right)
	{
		BitSet toReturn;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 32; j++)
			{
				if ((setAll[i] & (1 << j)) && !(right.setAll[i] & (1 << j)))
					toReturn.add(i, j);
			}
		}
		return toReturn;
	}
	
	bool operator==(BitSet& right) 
	{
		for (int i = 0; i < 8; i++)
		{
			if (setAll[i] != right.setAll[i])
				return false;
		}
		return true;
	}

	string toString()
	{
		string toReturn = "";
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 32; j++)
			{
				if (setAll[i] & (1 << j))
				{
					toReturn = toReturn + char((i * 32) + j) + ", ";
				}
			}
		}
		return toReturn;
	}

	BitSet findInWhichSet(BitSet objects[], int size, unsigned char toFind)
	{
		bool found = false;
		BitSet toReturn;
		BitSet errorReturn;
		for (int i = 0; i < size; i++)
		{
			if (objects[i].present(toFind) && found)
			{
				return errorReturn;
			}
			if (objects[i].present(toFind))
			{
				toReturn = objects[i];
				found = true;
			}
		}
		return toReturn;
	}
};
