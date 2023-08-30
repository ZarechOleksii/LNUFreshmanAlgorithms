//
// pch.h
// Header for standard system include files.
//

#pragma once
#include "gtest/gtest.h"
#include <string>
#include <vector>
using namespace std;
class MarkovAlgo
{
private:
	int pairNum;
	string finalString;
	string* arrayFrom;
	string* arrayTo;
	int first;
	int search;
	int firstChange;
	string before, after;
	bool done;
	string previousString;
public:
	MarkovAlgo()
	{
		before, after = "";
		firstChange = -1;
		first = -1;
		search = -1;
		pairNum = 0;
		finalString = "";
		done = false;
		previousString = "";
	}
	string exchange(string start, vector<pair<string, string>> pairVector)
	{
		pairNum = pairVector.size();
		finalString = start;
		arrayFrom = new string[pairNum];
		arrayTo = new string[pairNum];
		for (int i = 0; i < pairNum; i++)
		{
			arrayFrom[i] = pairVector[i].first;
			arrayTo[i] = pairVector[i].second;
		}
		while (previousString != finalString)
		{
			previousString = finalString;
			for (int i = 0; i < finalString.size(); i++)
			{
				first = -1;
				search = -1;
				firstChange = -1;
				done = false;
				for (int j = 0; j < pairNum; j++)
				{
					search = finalString.find(arrayFrom[j]);
					if ((first > search && search >= 0) || (first < search && first == -1))
					{
						firstChange = j;
						first = search;
						done = true;
					}
					if (first == search && arrayFrom[j].size() > arrayFrom[firstChange].size() && search >= 0 && done)
					{
						firstChange = j;
						first = search;
					}
				}
				if (first != -1)
				{
					before = finalString.substr(0, finalString.find(arrayFrom[firstChange]));
					after = finalString.substr(finalString.find(arrayFrom[firstChange]) + arrayFrom[firstChange].size(), finalString.size() - arrayFrom[firstChange].size() - finalString.find(arrayFrom[firstChange]));
					finalString = before + arrayTo[firstChange] + after;
					break;
				}
			}
			if (start.size() * 100 < finalString.size())
			{
				return "ERROR: MEMORY LEAKING";
			}
		}
		return finalString;
	}
};