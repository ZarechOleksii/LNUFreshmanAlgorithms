#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

TEST(EnqueueDequeueTest, InAndOut) {
	QueueClass QueueTest1;
	QueueTest1.enqueue(5);
	ASSERT_EQ("5", QueueTest1.toString());
	QueueTest1.dequeue();
	ASSERT_EQ("", QueueTest1.toString());
	QueueTest1.enqueue(1);
	ASSERT_EQ("1", QueueTest1.toString());
	QueueTest1.enqueue(2);
	ASSERT_EQ("12", QueueTest1.toString());
	QueueTest1.dequeue();
	ASSERT_EQ("2", QueueTest1.toString());
}
TEST(EnqueueTest, FiveInFourOut)
{
	QueueClass QueueTest2;
	QueueTest2.enqueue(5);
	ASSERT_EQ("5", QueueTest2.toString());
	QueueTest2.enqueue(3);
	ASSERT_EQ("53", QueueTest2.toString());
	QueueTest2.enqueue(4);
	ASSERT_EQ("534", QueueTest2.toString());
	QueueTest2.enqueue(5);
	ASSERT_EQ("5345", QueueTest2.toString());
	QueueTest2.enqueue(6);
	ASSERT_EQ("53456", QueueTest2.toString());
	QueueTest2.dequeue();
	ASSERT_EQ("3456", QueueTest2.toString());
	QueueTest2.dequeue();
	ASSERT_EQ("456", QueueTest2.toString());
	QueueTest2.dequeue();
	ASSERT_EQ("56", QueueTest2.toString());
	QueueTest2.dequeue();
	ASSERT_EQ("6", QueueTest2.toString());

}
TEST(EmptyDequeueTest, EmptyDequeue)
{
	QueueClass QueueTest3;
	ASSERT_TRUE(QueueTest3.isEmpty());
	QueueTest3.dequeue();
	ASSERT_EQ("", QueueTest3.toString());
	QueueTest3.dequeue();
	ASSERT_EQ("", QueueTest3.toString());
	QueueTest3.enqueue(4);
	ASSERT_EQ("4", QueueTest3.toString());
	ASSERT_FALSE(QueueTest3.isEmpty());
	QueueTest3.dequeue();
	ASSERT_EQ("", QueueTest3.toString());
}
TEST(SizeChange, Increase)
{
	QueueClass QueueTest4;
	QueueTest4.enqueue(0);
	QueueTest4.enqueue(1);
	QueueTest4.enqueue(2);
	QueueTest4.enqueue(3);
	QueueTest4.enqueue(4);
	QueueTest4.enqueue(5);
	QueueTest4.enqueue(6);
	QueueTest4.enqueue(7);
	QueueTest4.enqueue(8);
	QueueTest4.enqueue(9);
	ASSERT_EQ("0123456789", QueueTest4.toString());
	QueueTest4.dequeue();
	QueueTest4.dequeue();
	QueueTest4.dequeue();
	QueueTest4.dequeue();
	QueueTest4.dequeue();
	QueueTest4.dequeue();
	QueueTest4.dequeue();
	QueueTest4.dequeue();
	QueueTest4.dequeue();
	QueueTest4.dequeue();
	ASSERT_EQ("", QueueTest4.toString());
}