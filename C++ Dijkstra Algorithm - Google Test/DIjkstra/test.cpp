#include "pch.h"

TEST(TestDijkstra, TestNumberOne) 
{
	GraphBuild graph1(6);
	graph1.addConnection(1, 2, 7);
	graph1.addConnection(1, 3, 9);
	graph1.addConnection(1, 6, 14);
	graph1.addConnection(2, 3, 10);
	graph1.addConnection(2, 4, 15);
	graph1.addConnection(3, 6, 2);
	graph1.addConnection(3, 4, 11);
	graph1.addConnection(4, 5, 6);
	graph1.addConnection(5, 6, 9);
	AlgorithmDijkstri algo1(graph1, 1);
	ASSERT_EQ("0, 7, 9, 20, 20, 11, ", algo1.toString());
}
TEST(TestDijkstra, TestNumberTwo)
{
	GraphBuild graph2(8);
	graph2.addConnection(1, 2, 23);
	graph2.addConnection(1, 3, 12);
	graph2.addConnection(2, 3, 25);
	graph2.addConnection(2, 5, 22);
	graph2.addConnection(2, 8, 35);
	graph2.addConnection(3, 4, 18);
	graph2.addConnection(4, 6, 20);
	graph2.addConnection(5, 6, 23);
	graph2.addConnection(5, 7, 14);
	graph2.addConnection(6, 7, 24);
	graph2.addConnection(7, 8, 16);
	AlgorithmDijkstri algo1(graph2, 1);
	ASSERT_EQ("0, 23, 12, 30, 45, 50, 59, 58, ", algo1.toString());
}
TEST(TestDijkstra1, TestNumberOne1)
{
	GraphBuild graph1(6);
	graph1.addConnection(1, 2, 7);
	graph1.addConnection(1, 3, 9);
	graph1.addConnection(1, 6, 14);
	graph1.addConnection(2, 3, 10);
	graph1.addConnection(2, 4, 15);
	graph1.addConnection(3, 6, 2);
	graph1.addConnection(3, 4, 11);
	graph1.addConnection(4, 5, 6);
	graph1.addConnection(5, 6, 9);
	AlgorithmDijkstri algo1(graph1, 3);
	ASSERT_EQ("0, 7, 9, 20, 20, 11, ", algo1.toString());
}