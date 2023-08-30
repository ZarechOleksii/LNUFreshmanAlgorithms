//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;
class StackClass
{
private:
	int sizeArr;
	int numberAmount;
	int* numbers;
public:
	StackClass()
	{
		sizeArr = 4;
		numberAmount = 0;
		numbers = new int[sizeArr];
	}
public:
	void push(int plusInteger)
	{
		if (isFull())
		{
			addSpace();
		}
		numbers[numberAmount] = plusInteger;
		numberAmount++;
	}
public:
	void pop()
	{
		if (!isEmpty())
		{
			numberAmount--;
			if (sizeArr > 4 && numberAmount <= (sizeArr / 4))
			{
				reduceSpace();
			}
		}
	}
	~StackClass()
	{
		delete[] numbers;
	}
	string toString()
	{
		string result = "";
		for (int i = 0; i < numberAmount; i++)
		{
			result = result + to_string(numbers[i]);
		}
		return result;
	}
	bool isEmpty()
	{
		if (numberAmount == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (numberAmount == sizeArr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void addSpace()
	{
		sizeArr = sizeArr * 2;
		int* increasedNumbersArr = new int[sizeArr];
		for (int i = 0; i < numberAmount; i++)
		{
			increasedNumbersArr[i] = numbers[i];
		}
		delete[] numbers;
		numbers = increasedNumbersArr;
	}
	void reduceSpace()
	{
		sizeArr = sizeArr / 2;
		int* reducedNumbersArr = new int[sizeArr];
		for (int i = 0; i < numberAmount; i++)
		{
			reducedNumbersArr[i] = numbers[i];
		}
		delete[] numbers;
		numbers = reducedNumbersArr;
	}
};