#include <chrono>
#include <stdlib.h>
#include <iostream>

#include "Utils.h"
#include "Graph.h"
#include "CheatDijkstra.h"

void BubbleSortTest();

int main()
{
	//Node* nodeA = new Node("A");
	//Node* nodeB = new Node("B");
	//Node* nodeC = new Node("C");
	//Node* nodeD = new Node("D");
	//Node* nodeE = new Node("E");
	//Node* nodeF = new Node("F");
	//Node* nodeG = new Node("G");
	//Node* nodeH = new Node("H");
	//Node* nodeI = new Node("I");
	//Node* nodeJ = new Node("J");
	//Node* nodeK = new Node("K");

	//Graph* graphTest = new Graph();
	//graphTest->AddNode(*nodeA);
	//graphTest->AddNode(*nodeB);
	//graphTest->AddNode(*nodeC);
	//graphTest->AddNode(*nodeD);
	//graphTest->AddNode(*nodeE);
	//graphTest->AddNode(*nodeF);
	//graphTest->AddNode(*nodeG);
	//graphTest->AddNode(*nodeH);
	//graphTest->AddNode(*nodeI);
	//graphTest->AddNode(*nodeJ);
	//graphTest->AddNode(*nodeK);

	//graphTest->PrintNodesInGraph();

	//graphTest->InsertEdge("A", "B", 5);
	//graphTest->InsertEdge("B", "C", 1);
	//graphTest->InsertEdge("A", "D", 7);
	//graphTest->InsertEdge("C", "D", 1);
	//graphTest->InsertEdge("A", "K", 2);
	//graphTest->InsertEdge("B", "G", 3);
	//graphTest->InsertEdge("A", "I", 10);
	//graphTest->InsertEdge("C", "H", 2);

	//std::cout << std::endl;
	//nodeA->PrintAdjacencyList();

	//std::cout << std::endl;
	//std::cout << "A -> I: " << graphTest->GetEdgeWeightBetween("A", "I") << std::endl;

	//std::cout << std::endl;

	//graphTest->DepthFirstSearch("A", "G");
	////graphTest->BreadthFirstSearch("A", "G");

	//delete graphTest;

	const int GRAPH_SIZE = 4;
	int graph[GRAPH_SIZE][GRAPH_SIZE] = { {0,5,0,7},
											{5,0,1,0},
											{0,1,0,1},
											{7,0,1,0} };
	CheatDijkstra::Dijkstra(graph, GRAPH_SIZE, 3);
}

void BubbleSortTest()
{
	const int ARRAY_SIZE = 10;
	uint32_t start = 0, end = 0;

	int arr[ARRAY_SIZE] = { 0 };
	Utils::FillArray(arr, ARRAY_SIZE);

	printf("Unsorted Array: ");
	Utils::PrintArray(arr, ARRAY_SIZE);
	start = Utils::GetNanos();
	Utils::BubbleSort(arr, ARRAY_SIZE);
	end = Utils::GetNanos();

	printf("\n\nSorted Array:   ");
	Utils::PrintArray(arr, ARRAY_SIZE);
	printf("\nBubbleSort took: %i nanoseconds\n", (end - start));
}
