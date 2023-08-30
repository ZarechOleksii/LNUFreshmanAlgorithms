#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
TEST(BitSetTester, test1)
{
	BitSet<5> test1("10011");
	ASSERT_FALSE(test1.all());
	ASSERT_FALSE(test1.none());
	ASSERT_TRUE(test1.any());
	ASSERT_EQ(3, test1.count());
	ASSERT_EQ(5, test1.size());
	ASSERT_FALSE(test1.test(2));
	test1.set(2);
	ASSERT_TRUE(test1.test(2));
	test1.flip(1);
	ASSERT_TRUE(test1.all());
	test1.reset();
	ASSERT_TRUE(test1.none());
	ASSERT_EQ(0, test1.count());
	ASSERT_FALSE(test1.any());
	test1.flip();
	ASSERT_EQ("11111",test1.to_string());
	ASSERT_EQ(5, test1.to_ullong());
	ASSERT_EQ(31, test1.to_ulong());
}*/
/*
TEST(BitSetTester, test2)
{
	BitSet<16> test2(23211);
	ASSERT_FALSE(test2.all());
	ASSERT_FALSE(test2.none());
	ASSERT_TRUE(test2.any());
	ASSERT_EQ(9, test2.count());
	ASSERT_EQ(16, test2.size());
	test2.reset();
	ASSERT_TRUE(test2.none());
	ASSERT_EQ(0, test2.count());
	ASSERT_FALSE(test2.any());
	test2.flip();
	test2.reset(5);
	test2.reset(8);
	ASSERT_EQ(14, test2.to_ullong());
	ASSERT_EQ(64383, test2.to_ulong());
}

TEST(BitSetTester, test3)
{
	vector<pair<int, bool>> pairVector;
	pairVector.push_back(make_pair(2, true));
	pairVector.push_back(make_pair(5, true));
	pairVector.push_back(make_pair(6, true));
	BitSet<7> test3(pairVector);
	ASSERT_FALSE(test3.all());
	ASSERT_FALSE(test3.none());
	ASSERT_TRUE(test3.any());
	ASSERT_EQ(3, test3.count());
	ASSERT_EQ(7, test3.size());
	test3.reset();
	ASSERT_TRUE(test3.none());
	ASSERT_EQ(0, test3.count());
	ASSERT_FALSE(test3.any());
	test3.flip();
	test3.reset(5);
	test3.reset(2);
	test3.reset(3);
	ASSERT_EQ("1100101", test3.to_string());
	ASSERT_EQ(4, test3.to_ullong());
	ASSERT_EQ(101, test3.to_ulong());
}
TEST(BitSetTesterAE, test1)
{
	wchar_t newWIDE1 = L'ﮙ';
	BitSet<16> test3(newWIDE1);
	ASSERT_EQ("1111101110011001", test3.to_string());
	ASSERT_EQ(newWIDE1, test3.toChar());
	wchar_t newWIDE2 = L'ẙ';
	BitSet<16> test4(newWIDE2);
	ASSERT_EQ("1111010011001", test4.to_string());
	ASSERT_EQ(newWIDE2, test4.toChar());
	wchar_t newWIDE3 = L'Ø';
	BitSet<16> test5(newWIDE3);
	ASSERT_EQ("11011000", test5.to_string());
	ASSERT_EQ(newWIDE3, test5.toChar());
}
TEST(BitSetTesterOperator, test2)
{
	wchar_t newWIDE4 = L'Ṍ';
	BitSet<16> test4(newWIDE4);
	wchar_t newWIDE5 = L'υ';
	BitSet<16> test5(newWIDE5);

	ASSERT_FALSE(test4 == test5);
	ASSERT_TRUE(test4 != test5);

	~test4;
	ASSERT_EQ("1110000110110011", test4.to_string());

	test4&= test5;
	ASSERT_EQ("110000001", test4.to_string());

	test4^= test5;
	ASSERT_EQ("1001000100", test4.to_string());

	test4|= test5;
	ASSERT_EQ("1111000101", test4.to_string());
	
	ASSERT_TRUE(test4 == test5);
	ASSERT_FALSE(test4 != test5);
	
	test4 >> 3;
	ASSERT_EQ("1111000", test4.to_string());
	test4 >> 2;
	ASSERT_EQ("11110", test4.to_string());

	test4 << 1;
	ASSERT_EQ("111100", test4.to_string());
	test4 << 4;
	ASSERT_EQ("1111000000", test4.to_string());

	test4 >> 3;
	ASSERT_EQ("1111000", test4.to_string());

	ASSERT_EQ(L'x', test4.toChar());
	cout << (char)49;
}*/
TEST(BitSetTester, test1)
{
	BitSet testerObj1();
	unsigned char testChar1 = 'a';
	testerObj1.add(testChar1);
}