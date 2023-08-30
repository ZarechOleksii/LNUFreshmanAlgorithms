#include "pch.h"
#pragma once
TEST(MarkovAlgoTest, Test1)
{
	MarkovAlgo test1;
	vector<pair<string, string>> pairVector1;
	pairVector1.push_back(make_pair("ok", "o"));
	EXPECT_EQ("o", test1.exchange("okkkkk", pairVector1));
}
TEST(MarkovAlgoTest, Test2)
{
	MarkovAlgo test2;
	vector<pair<string, string>> pairVector2;
	pairVector2.push_back(make_pair("1", "11"));
	pairVector2.push_back(make_pair("|0", "0||"));
	pairVector2.push_back(make_pair("0", ""));
	EXPECT_EQ("|||||", test2.exchange("101", pairVector2));
}
TEST(MarkovAlgoTest, Test3)
{
	MarkovAlgo test3;
	vector<pair<string, string>> pairVector3;
	pairVector3.push_back(make_pair("|b", "ba|"));
	pairVector3.push_back(make_pair("ab", "ba"));
	pairVector3.push_back(make_pair("b", ""));
	pairVector3.push_back(make_pair("*|", "b*"));
	pairVector3.push_back(make_pair("*", "c"));
	pairVector3.push_back(make_pair("|c", "c"));
	pairVector3.push_back(make_pair("ac", "c|"));
	pairVector3.push_back(make_pair("c", ""));
	EXPECT_EQ("||||||||||||", test3.exchange("||||*|||", pairVector3));
}