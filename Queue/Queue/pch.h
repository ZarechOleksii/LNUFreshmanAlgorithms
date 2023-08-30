//
// pch.h
// Header for standard system include files.
//

#pragma once
#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;

class QueueClass
{
private:
	int sizeArr;
	int numberAmount;
	string result;
	int* numbers;
	int end;
	int begin;
public:
	QueueClass()
	{
		sizeArr = 4;
		result = "";
		numberAmount = 0;
		numbers = new int[sizeArr];
		end = 0;
		begin = 0;
	}
public:
	void enqueue(int plusInteger)
	{
		numbers[end] = plusInteger;
		end = (end + 1) % sizeArr;
		numberAmount++;
		if ((end + 1) % sizeArr == begin)
		{
			addSpace();
		}
	}
public:
	void dequeue()
	{
		if (!isEmpty())
		{
			begin = (begin + 1) % sizeArr;
			numberAmount--;
		}
	}
	~QueueClass()
	{
		delete[] numbers;
	}
	string toString()
	{
		result = "";
		for (int i = 0; i < numberAmount; i++)
		{
			result = result + to_string(numbers[begin + i]);
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
	void addSpace()
	{
		sizeArr = sizeArr * 2;
		int* increasedNumbersArr = new int[sizeArr];
		for (int i = begin; i < numberAmount; i++)
		{
			increasedNumbersArr[i] = numbers[i];
		}
		delete[]numbers;
		numbers = increasedNumbersArr;
	}
};