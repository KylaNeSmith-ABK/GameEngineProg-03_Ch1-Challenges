#include <iostream>

#include "CheatDijkstra.h"

void CheatDijkstra::Dijkstra(int graph[4][4], int size, int target)
{
	const int INF = INT_MAX;

	std::map<int, int> Distance;
	std::map<int, int> Previous;
	std::map<int, bool> Visited;

	// initialization
	for (int i = 0; i < size; i++)
	{
		Distance[i] = INF;
		Previous[i] = -1;
		Visited[i] = false;
	}

	Distance[0] = 0;

	// find closest node
	for (int i = 0; i < size; i++)
	{
		int Closest = -1;

		for (int n = 0; n < size; n++)
		{
			if ((!Visited[n]) && ((Closest == -1) || (Distance[n] < Distance[Closest])))
			{
				Closest = n;
			}
		}

		// search for path
		for (int x = 0; x < size; x++)
		{
			if (!Visited[x])
			{
				int AltDistance = Distance[Closest] + *graph[Closest, x];
				if (AltDistance < Distance[x] && Distance[Closest] != INF)
				{
					Distance[x] = AltDistance;
					Previous[x] = Closest;
				}
			}
		}
	}

	PrintOut(Previous, Distance, target);
}

void CheatDijkstra::PrintOut(std::map<int, int> previous, std::map<int, int> distance, int target)
{
	int End = target;

	std::cout << "To get to " << target << " traversed ";

	if (previous[target] != -1)
	{
		while (End != -1)
		{
			std::cout << End << " <- ";
			End = previous[End];
		}
		std::cout << " with complete distance of " << distance[target] << std::endl;
	}
}