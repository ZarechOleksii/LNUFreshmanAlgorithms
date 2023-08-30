#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

TEST(BubbleSortTest, BubbleTest) 
{
	SortingClass BubbleSorter;
	int intArray1[] = { 5, 6, 4, 2, 3, 5, 7, 4, 3 };
	int size = (sizeof(intArray1) / sizeof(intArray1[0]));
	BubbleSorter.bubble(intArray1, size);
	ASSERT_EQ("233445567", BubbleSorter.toString());
	int intArray2[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	size = (sizeof(intArray2) / sizeof(intArray2[0]));
	BubbleSorter.bubble(intArray2, size);
	ASSERT_EQ("123456789", BubbleSorter.toString());
	int intArray3[9] = { 1, 2, 3, 6, 5, 4, 3, 2, 1 };
	size = (sizeof(intArray3) / sizeof(intArray3[0]));
	BubbleSorter.bubble(intArray3, size);
	ASSERT_EQ("112233456", BubbleSorter.toString());
}
TEST(InsertionSortTest, InsertionTest)
{
	SortingClass InsertionSorter;
	int intArray1[] = { 5, 6, 4, 2, 3, 5, 7, 4, 3};
	int size = (sizeof(intArray1) / sizeof(intArray1[0]));
	InsertionSorter.insertion(intArray1, size);
	ASSERT_EQ("233445567", InsertionSorter.toString());
	int intArray2[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	size = (sizeof(intArray2) / sizeof(intArray2[0]));
	InsertionSorter.insertion(intArray2, size);
	ASSERT_EQ("123456789", InsertionSorter.toString());
	int intArray3[9] = { 1, 2, 3, 6, 5, 4, 3, 2, 1 };
	size = (sizeof(intArray3) / sizeof(intArray3[0]));
	InsertionSorter.insertion(intArray3, size);
	ASSERT_EQ("112233456", InsertionSorter.toString());
}
TEST(SelectionSortTest, SelectionTest)
{
	SortingClass SelectionSorter;
	int intArray1[] = { 5, 6, 4, 2, 3, 5, 7, 4, 3};
	int size = (sizeof(intArray1) / sizeof(intArray1[0]));
	SelectionSorter.selection(intArray1, size);
	ASSERT_EQ("233445567", SelectionSorter.toString());
	int intArray2[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1};
	size = (sizeof(intArray2) / sizeof(intArray2[0]));
	SelectionSorter.selection(intArray2, size);
	ASSERT_EQ("123456789", SelectionSorter.toString());
	int intArray3[] = { 1, 2, 3, 6, 5, 4, 3, 2, 1};
	size = (sizeof(intArray3) / sizeof(intArray3[0]));
	SelectionSorter.selection(intArray3, size);
	ASSERT_EQ("112233456", SelectionSorter.toString());
}