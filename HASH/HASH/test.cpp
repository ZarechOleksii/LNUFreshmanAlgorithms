#include "pch.h"

TEST(HashTableTest, Adding)
{
	HashTable tableTest1;
	tableTest1.addElement(123);
	EXPECT_EQ("Value in 3: 123\n", tableTest1.toString());
	tableTest1.addElement(254);
	tableTest1.addElement(1379);
	tableTest1.addElement(5231);
	tableTest1.addElement(2);
	tableTest1.addElement(10);
	EXPECT_EQ("Value in 0: 10\nValue in 1: 5231\nValue in 2: 2\nValue in 3: 123\nValue in 4: 254\nValue in 9: 1379\n", tableTest1.toString());
	tableTest1.addElement(300);
	EXPECT_EQ("Value in 0: 10\nValue in 1: 5231\nValue in 2: 2\nValue in 3: 123\nValue in 4: 254\nValue in 5: 300\nValue in 9: 1379\n", tableTest1.toString());
	tableTest1.addElement(150);
	EXPECT_EQ("Value in 0: 10\nValue in 1: 5231\nValue in 2: 2\nValue in 3: 123\nValue in 4: 254\nValue in 5: 300\nValue in 6: 150\nValue in 9: 1379\n", tableTest1.toString());
}
TEST(HashTableTest, AddingAndRemoving)
{
	HashTable tableTest2;
	tableTest2.addElement(123);
	EXPECT_EQ("Value in 3: 123\n", tableTest2.toString());
	tableTest2.addElement(254);
	tableTest2.addElement(1379);
	tableTest2.addElement(5231);
	tableTest2.addElement(2);
	tableTest2.addElement(10);
	EXPECT_EQ("Value in 0: 10\nValue in 1: 5231\nValue in 2: 2\nValue in 3: 123\nValue in 4: 254\nValue in 9: 1379\n", tableTest2.toString());
	tableTest2.deleteElement(254);
	tableTest2.deleteElement(5231);
	tableTest2.deleteElement(10);
	EXPECT_EQ("Value in 2: 2\nValue in 3: 123\nValue in 9: 1379\n", tableTest2.toString());
	tableTest2.addElement(42);
	EXPECT_EQ("Value in 2: 2\nValue in 3: 123\nValue in 4: 42\nValue in 9: 1379\n", tableTest2.toString());
	tableTest2.deleteElement(42);
	tableTest2.deleteElement(123);
	tableTest2.addElement(102);
	EXPECT_EQ("Value in 2: 2\nValue in 3: 102\nValue in 9: 1379\n", tableTest2.toString());
}
TEST(HastTableTest, AddingAndSearching)
{
	HashTable tableTest3;
	tableTest3.addElement(123);
	tableTest3.addElement(257);
	tableTest3.addElement(3044);
	tableTest3.addElement(212);

	EXPECT_EQ(3, tableTest3.findElement(123));
	EXPECT_EQ(4, tableTest3.findElement(3044));

	tableTest3.addElement(4254);
	EXPECT_EQ(5, tableTest3.findElement(4254));
}