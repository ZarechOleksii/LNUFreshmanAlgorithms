#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

TEST(PushPopTest, InAndOut) {
	PriorityQueueClass PriorityQueueTest1;
	PriorityQueueTest1.enqueue(5, 4);
	ASSERT_EQ("5", PriorityQueueTest1.toString());
	PriorityQueueTest1.dequeue();
	ASSERT_EQ("", PriorityQueueTest1.toString());
	PriorityQueueTest1.enqueue(1, 3);
	ASSERT_EQ("1", PriorityQueueTest1.toString());
	PriorityQueueTest1.enqueue(2, 5);
	ASSERT_EQ("21", PriorityQueueTest1.toString());
	PriorityQueueTest1.dequeue();
	ASSERT_EQ("1", PriorityQueueTest1.toString());
}
TEST(PushTest, FiveInThreeOut)
{
	PriorityQueueClass PriorityQueueTest2;
	PriorityQueueTest2.enqueue(5, 3);
	ASSERT_EQ("5", PriorityQueueTest2.toString());
	PriorityQueueTest2.enqueue(3, 4);
	ASSERT_EQ("35", PriorityQueueTest2.toString());
	PriorityQueueTest2.enqueue(4, 5);
	ASSERT_EQ("435", PriorityQueueTest2.toString());
	PriorityQueueTest2.enqueue(5, 4);
	ASSERT_EQ("4355", PriorityQueueTest2.toString());
	PriorityQueueTest2.enqueue(6, 5);
	ASSERT_EQ("46355", PriorityQueueTest2.toString());
	PriorityQueueTest2.dequeue();
	ASSERT_EQ("6355", PriorityQueueTest2.toString());
	PriorityQueueTest2.dequeue();
	ASSERT_EQ("355", PriorityQueueTest2.toString());
	PriorityQueueTest2.dequeue();
	ASSERT_EQ("55", PriorityQueueTest2.toString());

}
TEST(EmptyPopTest, EmptyPop)
{
	PriorityQueueClass PriorityQueueTest3;
	PriorityQueueTest3.dequeue();
	ASSERT_EQ("", PriorityQueueTest3.toString());
	PriorityQueueTest3.dequeue();
	ASSERT_EQ("", PriorityQueueTest3.toString());
	PriorityQueueTest3.enqueue(4, 2);
	ASSERT_EQ("4", PriorityQueueTest3.toString());
	PriorityQueueTest3.dequeue();
	ASSERT_EQ("", PriorityQueueTest3.toString());
}
TEST(SamePriority, NewQueue)
{
	PriorityQueueClass PriorityQueueTest4;
	PriorityQueueTest4.enqueue(1, 5);
	PriorityQueueTest4.enqueue(2, 5);
	PriorityQueueTest4.enqueue(4, 5);
	PriorityQueueTest4.enqueue(3, 5);
	ASSERT_EQ("1243", PriorityQueueTest4.toString());
}
TEST(SizeChange, IncreasAndDecrease)
{
	PriorityQueueClass PriorityQueueTest4;
	PriorityQueueTest4.enqueue(0, 0);
	PriorityQueueTest4.enqueue(1, 1);
	PriorityQueueTest4.enqueue(2, 2);
	PriorityQueueTest4.enqueue(3, 3);
	PriorityQueueTest4.enqueue(4, 4);
	PriorityQueueTest4.enqueue(5, 5);
	PriorityQueueTest4.enqueue(6, 6);
	PriorityQueueTest4.enqueue(7, 7);
	PriorityQueueTest4.enqueue(8, 8);
	PriorityQueueTest4.enqueue(9, 9);
	ASSERT_EQ("9876543210", PriorityQueueTest4.toString());
	PriorityQueueTest4.dequeue();
	PriorityQueueTest4.dequeue();
	PriorityQueueTest4.dequeue();
	PriorityQueueTest4.dequeue();
	PriorityQueueTest4.dequeue();
	PriorityQueueTest4.dequeue();
	PriorityQueueTest4.dequeue();
	PriorityQueueTest4.dequeue();
	PriorityQueueTest4.dequeue();
	PriorityQueueTest4.dequeue();
	ASSERT_EQ("", PriorityQueueTest4.toString());
}