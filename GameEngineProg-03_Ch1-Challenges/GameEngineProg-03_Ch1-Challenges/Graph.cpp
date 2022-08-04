#include <vector>
#include <queue>
#include <set>
#include <stack>

#include "Graph.h"

static void PrintVector(std::vector<Node*> nodeVec)
{
	int counter = 0, vecSize = nodeVec.size();
	for (Node* node : nodeVec)
	{
		std::cout << *node;
		counter++;
		if (counter < vecSize)
		{
			std::cout << " --> ";
		}
	}
	std::cout << std::endl;
}

Graph::Graph()
	: NodeCount_(0)
	, EdgeCount_(0)
{
	Nodes_.clear();
}

Graph::~Graph()
{
	for (std::pair<std::string, Node*> node : Nodes_)
	{
		delete node.second;
	}

	Nodes_.clear();
}

Node* Graph::FindNode(const std::string& nodeLabel) const
{
	if (Nodes_.count(nodeLabel) > 0)
	{
		return Nodes_.at(nodeLabel);
	}

	return nullptr;
}

void Graph::AddNode(Node& node)
{
	if (FindNode(node.GetLabel()) == nullptr)
	{
		Nodes_[node.GetLabel()] = &node;
		NodeCount_++;
	}
}

void Graph::AddNode(const std::string& nodeLabel)
{
	if (FindNode(nodeLabel) == nullptr)
	{
		Nodes_[nodeLabel] = new Node(nodeLabel);
		NodeCount_++;
	}
}

bool Graph::InsertEdge(Node& start, Node& end, const int edgeWeight, bool twoWay)
{
	return InsertEdge(start.GetLabel(), end.GetLabel(), edgeWeight, twoWay);
}

bool Graph::InsertEdge(const std::string& startLabel, const std::string& endLabel, const int edgeWeight, bool twoWay)
{
	Node* startNodePtr = FindNode(startLabel);
	Node* endNodePtr = FindNode(endLabel);
	if ((startNodePtr != nullptr) && (endNodePtr != nullptr))
	{
		startNodePtr->Connect(endNodePtr, edgeWeight);

		if (twoWay)
		{
			endNodePtr->Connect(startNodePtr, edgeWeight);
			EdgeCount_++;
		}

		EdgeCount_++;
		return true;
	}
	return false;
}

int Graph::GetEdgeWeightBetween(const std::string& startLabel, const std::string& endLabel) const
{
	Node* startNodePtr = FindNode(startLabel);
	Node* endNodePtr = FindNode(endLabel);
	if ((startNodePtr == nullptr) || (endNodePtr == nullptr) || !startNodePtr->IsConnectedTo(endNodePtr))
	{
		return INT_MAX;
	}

	int i = (startNodePtr->GetEdgeWeightTo(endNodePtr));

	return i;
}

bool Graph::SetEdgeWeightBetween(const std::string& startLabel, const std::string& endLabel, int edgeWeight)
{
	Node* startNodePtr = FindNode(startLabel);
	Node* endNodePtr = FindNode(endLabel);

	return ((startNodePtr != nullptr) && (endNodePtr != nullptr) && (startNodePtr->SetEdgeWeightTo(endNodePtr, edgeWeight)));
}

void Graph::UnvisitNodes()
{
	for (std::pair<std::string, Node*> node : Nodes_)
	{
		node.second->Unvisit();
	}
}

bool Graph::DepthFirstSearch(const std::string& startLabel, const std::string& endLabel)
{
	UnvisitNodes();

	bool bFound = false;

	Node* startNodePtr = FindNode(startLabel);
	Node* endNodePtr = FindNode(endLabel);

	if ((startNodePtr == nullptr) || (endNodePtr == nullptr) || (startNodePtr->IsThisNode(endNodePtr)))
	{
		return bFound;
	}

	std::stack<Node*> nodeStack;
	std::vector<Node*> visitedNodes;

	nodeStack.push(startNodePtr);
	
	while (!nodeStack.empty() && !bFound)
	{
		Node* currentNodePtr = nodeStack.top();
		nodeStack.pop();

		if (currentNodePtr->IsVisited())
		{
			continue;
		}

		currentNodePtr->Visit();
		visitedNodes.push_back(currentNodePtr);

		if (currentNodePtr == endNodePtr)
		{
			bFound = true;
			break;
		}

		std::map<int, std::vector<Edge*>> adjMap = currentNodePtr->GetAdjacencyList();
		std::map<int, std::vector<Edge*>>::reverse_iterator rIter;
		for (rIter = adjMap.rbegin(); rIter != adjMap.rend(); rIter++)
		{
			if (bFound)
			{
				break;
			}

			for (Edge* edge : (*rIter).second)
			{
				Node* adjNodePtr = edge->GetEndNode();
				if ((adjNodePtr != nullptr) && (!adjNodePtr->IsVisited()))
				{
					nodeStack.push(adjNodePtr);
				}
			}
		}
	}

	std::cout << "Depth First Search from " << startLabel << " to " << endLabel << "\nNodes visited ";
	PrintVector(visitedNodes);
	return bFound;
}

bool Graph::BreadthFirstSearch(const std::string& startLabel, const std::string& endLabel)
{
	UnvisitNodes();

	bool bFound = false;

	Node* startNodePtr = FindNode(startLabel);
	Node* endNodePtr = FindNode(endLabel);

	if ((startNodePtr == nullptr) || (endNodePtr == nullptr))
	{
		return bFound;
	}

	std::queue<Node*> nodeQueue;
	std::vector<Node*> visitedNodes;

	nodeQueue.push(startNodePtr);

	while (!nodeQueue.empty() && !bFound)
	{
		Node* currentNodePtr = nodeQueue.front();
		nodeQueue.pop();

		if (currentNodePtr->IsVisited())
		{
			continue;
		}

		currentNodePtr->Visit();
		visitedNodes.push_back(currentNodePtr);

		if (currentNodePtr == endNodePtr)
		{
			bFound = true;
			break;
		}

		std::map<int, std::vector<Edge*>> adjMap = currentNodePtr->GetAdjacencyList();
		std::map<int, std::vector<Edge*>>::iterator iter;
		for (iter = adjMap.begin(); iter != adjMap.end(); iter++)
		{
			if (bFound)
			{
				break;
			}

			for (Edge* edge : (*iter).second)
			{
				Node* adjNodePtr = edge->GetEndNode();
				if ((adjNodePtr != nullptr) && (!adjNodePtr->IsVisited()))
				{
					
					nodeQueue.push(adjNodePtr);
				}
			}
		}
	}

	std::cout << "Breadth First Search from " << startLabel << " to " << endLabel << "\nNodes visited ";
	PrintVector(visitedNodes);
	return bFound;
}

bool Graph::DijkstraSearch(const std::string& startLabel, const std::string& endLabel)
{
	UnvisitNodes();

	bool bFound = false;

	Node* startNodePtr = FindNode(startLabel);
	Node* endNodePtr = FindNode(endLabel);

	if ((startNodePtr == nullptr) || (endNodePtr == nullptr))
	{
		return bFound;
	}

	std::queue<Node*> nodeQueue;

	nodeQueue.push(startNodePtr);
	startNodePtr->SetDistanceFromStart(0);

	while (!nodeQueue.empty())
	{
		Node* currentNode = nullptr;


	}

	return bFound;
}

void Graph::PrintNodesInGraph() const
{
	for (std::pair<std::string, Node*> node : Nodes_)
	{
		std::cout << *node.second << std::endl;
	}
}

void Graph::PrintAdjacencyLists() const
{
	for (std::pair<std::string, Node*> node : Nodes_)
	{
		node.second->PrintAdjacencyList();
		std::cout << std::endl;
	}
}
