//
// pch.h
// Header for standard system include files.
//
#pragma once
#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;
class PriorityQueueClass
{
private:
	int numberAmount;
	int* numbers;
	int* priorities;
	string result;
	int currentIntegerIndex;
	int sizeArr;
public:
	PriorityQueueClass()
	{
		numberAmount = 0;
		sizeArr = 4;
		result = "";
		currentIntegerIndex = 0;
		numbers = new int[sizeArr];
		priorities = new int[sizeArr];
	}
public:
	void enqueue(int plusInteger, int integerPriority)
	{
		if (isFull())
		{
			addSpace();
		}
		currentIntegerIndex = 0;
		numberAmount++;
		for (int i = numberAmount - 1; i > 0; i--)
		{
			if (priorities[i - 1] < integerPriority)
			{
				priorities[i] = priorities[i - 1];
				numbers[i] = numbers[i - 1];
			}
			else
			{
				currentIntegerIndex = i;
				break;
			}
		}
		numbers[currentIntegerIndex] = plusInteger;
		priorities[currentIntegerIndex] = integerPriority;
	}
public:
	void dequeue()
	{
		if (numberAmount != 0)
		{
			for (int i = 0; i < numberAmount - 1; i++)
			{
				numbers[i] = numbers[i + 1];
				priorities[i] = priorities[i + 1];
			}
			numbers[numberAmount] = NULL;
			priorities[numberAmount] = NULL;
			numberAmount--;
			if (sizeArr > 4 && numberAmount <= (sizeArr / 4))
			{
				reduceSpace();
			}
		}
	}
	string toString()
	{
		result = "";
		for (int i = 0; i < numberAmount; i++)
		{
			result = result + to_string(numbers[i]);
		}
		return result;
	}
	void addSpace()
	{
		sizeArr = sizeArr * 2;
		int* increasedNumbersArr = new int[sizeArr];
		int* increasedPrioritiesArr = new int[sizeArr];
		for (int i = 0; i < sizeArr; i++)
		{
			increasedNumbersArr[i] = numbers[i];
			increasedPrioritiesArr[i] = priorities[i];
		}
		delete[]numbers;
		delete[]priorities;
		numbers = increasedNumbersArr;
		priorities = increasedPrioritiesArr;
	}
	void reduceSpace()
	{
		sizeArr = sizeArr / 2;
		int* reducedNumbersArr = new int[sizeArr];
		int* reducedPrioritiesArr = new int[sizeArr];
		for (int i = 0; i < sizeArr; i++)
		{
			reducedNumbersArr[i] = numbers[i];
			reducedPrioritiesArr[i] = priorities[i];
		}
		delete[]numbers;
		delete[]priorities;
		numbers = reducedNumbersArr;
		priorities = reducedPrioritiesArr;
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
};