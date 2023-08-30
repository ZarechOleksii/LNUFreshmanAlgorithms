#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

TEST(PushPopTest, InAndOut) {
	StackClass StackTest1;
	StackTest1.push(5);
	ASSERT_EQ("5", StackTest1.toString());
	StackTest1.pop();
	ASSERT_EQ("", StackTest1.toString());
	StackTest1.push(1);
	ASSERT_EQ("1", StackTest1.toString());
	StackTest1.push(2);
	ASSERT_EQ("12", StackTest1.toString());
	StackTest1.pop();
	ASSERT_EQ("1", StackTest1.toString());
}
TEST(PushTest, FiveInFourOut)
{
	StackClass StackTest2;
	StackTest2.push(5);
	ASSERT_EQ("5", StackTest2.toString());
	StackTest2.push(3);
	ASSERT_EQ("53", StackTest2.toString());
	StackTest2.push(4);
	ASSERT_EQ("534", StackTest2.toString());
	StackTest2.push(5);
	ASSERT_EQ("5345", StackTest2.toString());
	StackTest2.push(6);
	ASSERT_EQ("53456", StackTest2.toString());
	StackTest2.pop();
	ASSERT_EQ("5345", StackTest2.toString());
	StackTest2.pop();
	ASSERT_EQ("534", StackTest2.toString());
	StackTest2.pop();
	ASSERT_EQ("53", StackTest2.toString());
	StackTest2.pop();
	ASSERT_EQ("5", StackTest2.toString());

}
TEST(EmptyPopTest, EmptyPop)
{
	StackClass StackTest3;
	ASSERT_TRUE(StackTest3.isEmpty());
	StackTest3.pop();
	ASSERT_EQ("", StackTest3.toString());
	StackTest3.pop();
	ASSERT_EQ("", StackTest3.toString());
	StackTest3.push(4);
	ASSERT_EQ("4", StackTest3.toString());
	ASSERT_FALSE(StackTest3.isEmpty());
	StackTest3.pop();
	ASSERT_EQ("", StackTest3.toString());
}
TEST(SizeChange, IncreaseAndDecrease)
{
	StackClass StackTest4;
	StackTest4.push(0);
	StackTest4.push(1);
	StackTest4.push(2);
	StackTest4.push(3);
	StackTest4.push(4);
	StackTest4.push(5);
	StackTest4.push(6);
	StackTest4.push(7);
	StackTest4.push(8);
	StackTest4.push(9);
	ASSERT_EQ("0123456789", StackTest4.toString());
	StackTest4.pop();
	StackTest4.pop();
	StackTest4.pop();
	StackTest4.pop();
	StackTest4.pop();
	StackTest4.pop();
	StackTest4.pop();
	StackTest4.pop();
	StackTest4.pop();
	StackTest4.pop();
	ASSERT_EQ("", StackTest4.toString());
}