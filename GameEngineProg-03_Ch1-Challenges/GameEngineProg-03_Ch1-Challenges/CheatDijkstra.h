#pragma once
#include <map>

class CheatDijkstra
{
public:
	static void Dijkstra(int graph[4][4], int size, int target);
	static void PrintOut(std::map<int, int> previous, std::map<int, int> distance, int target);
};