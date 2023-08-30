//
// pch.h
// Header for standard system include files.
//
#pragma once
#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;
class SortingClass
{
private:
	int* sortedArray;
	int size;
public:
	SortingClass()
	{
		size = 0;
	}
public:
	void selection(int intArray[], int arrSize)
	{
		bool done;
		int min;
		int minIndex;
		size = arrSize;
		sortedArray = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			sortedArray[i] = intArray[i];
		}
		for (int i = 0; i < arrSize; i++)
		{
			done = false;
			min = sortedArray[i];
			for (int j = i; j < arrSize; j++)
			{
				if (min > sortedArray[j])
				{
					min = sortedArray[j];
					minIndex = j;
					done = true;
				}
			}
			if (done)
				swap(sortedArray[minIndex], sortedArray[i]);
		}
	}
	void insertion(int intArray[], int arrSize)
	{
		int key;
		size = arrSize;
		sortedArray = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			sortedArray[i] = intArray[i];
		}
		for (int i = 1; i < arrSize; i++)
		{
			key = sortedArray[i];
			for (int j = i; j > 0; j--)
			{
				if (key < sortedArray[j - 1])
					swap(sortedArray[j], sortedArray[j - 1]);
			}
		}
	}
	void bubble(int intArray[], int arrSize)
	{
		bool done;
		size = arrSize;
		sortedArray = new int[arrSize];
		for (int i = 0; i < arrSize; i++)
		{
			sortedArray[i] = intArray[i];
		}
		do
		{
			done = false;
			for (int i = 0; i < arrSize - 1; i++)
			{
				if (sortedArray[i] > sortedArray[i + 1])
				{
					swap(sortedArray[i], sortedArray[i + 1]);
					done = true;
				}
			}
		}
		while (done);
	}
	string toString()
	{
		string result = "";
		for (int i = 0; i < size; i++)
		{
			result = result + to_string(sortedArray[i]);
		}
		return result;
	}
};