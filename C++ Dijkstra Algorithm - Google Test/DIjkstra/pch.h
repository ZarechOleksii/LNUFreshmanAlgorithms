//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
using namespace std;
class GraphBuild
{
private:
	int** graph;
	int pointAmount;
public:
	GraphBuild(int pointNum)
	{
		pointAmount = pointNum;
		graph = new int*[pointAmount];
		for (int i = 0; i < pointAmount; i++)
		{
			graph[i] = new int[pointAmount];
		}
		for (int i = 0; i < pointAmount; i++)
		{
			for (int j = 0; j < pointAmount; j++)
			{
				graph[i][j] = 0;
			}
		}
	}
	void addConnection(int from, int to, int weight)
	{
		graph[from - 1][to - 1] = weight;
		graph[to - 1][from - 1] = weight;
	}
	void removeConnection(int from, int to)
	{
		graph[from - 1][to - 1] = 0;
		graph[to - 1][from - 1] = 0;
	}
	bool isConnected(int from, int to)
	{
		if (graph[from][to] > 0)
			return true;
		return false;
	}
	int getWeight(int from, int to)
	{
		return graph[from][to];
	}
	int getPointAmount()
	{
		return pointAmount;
	}
};
class AlgorithmDijkstri
{
private:
	bool* visited;
	int* minimalPath;
	int pointNumber;
public:
	AlgorithmDijkstri(GraphBuild graph, int start)
	{
		int index;
		int newFrom;
		pointNumber = graph.getPointAmount();
		visited = new bool[pointNumber];
		minimalPath = new int[pointNumber];
		for (int i = 0; i < pointNumber; i++)
		{
			minimalPath[i] = INT_MAX;
			visited[i] = false;
		}
		minimalPath[start - 1] = 0;
		for (int i = 0; i < pointNumber; i++)
		{
			int min = INT_MAX;
			for (int j = 0; j < pointNumber; j++)
			{
				if (!visited[j] && minimalPath[j] <= min)
				{
					min = minimalPath[j];
					index = j;
				}
			}
			newFrom = index;
			visited[index] = true;
			for (int j = 0; j < pointNumber; j++)
			{
				if (!visited[j] && graph.isConnected(newFrom, j) && minimalPath[newFrom] + graph.getWeight(newFrom, j) < minimalPath[j])
				{
					minimalPath[j] = minimalPath[newFrom] + graph.getWeight(newFrom, j);
				}
			}
		}
	}
	string toString()
	{
		string toReturn = "";
		for (int i = 0; i < pointNumber; i++)
		{
			toReturn = toReturn + to_string(minimalPath[i]) + ", ";
		}
		return toReturn;
	}
	~AlgorithmDijkstri()
	{
		delete[] visited;
		delete[] minimalPath;
	}
};
