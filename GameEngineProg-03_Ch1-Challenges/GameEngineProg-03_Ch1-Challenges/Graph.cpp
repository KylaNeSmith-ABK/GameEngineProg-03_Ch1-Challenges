#include "Graph.h"

void Graph::UnvisitNodes()
{
	for (std::pair<std::string, Node*> node : Nodes_)
	{
		node.second->Unvisit();
	}

}

Node* Graph::FindNode(const std::string& nodeLabel) const
{
	if (Nodes_.count(nodeLabel) > 0)
	{
		return Nodes_.at(nodeLabel);
	}

	return nullptr;
}

Graph::Graph()
	: NumberOfNodes_(0)
	, NumberOfEdges_(0)
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

void Graph::InsertNode(Node& node)
{
	if (FindNode(node.GetLabel()) == nullptr)
	{
		Nodes_[node.GetLabel()] = &node;
	}
}

void Graph::InsertNode(const std::string& nodeLabel)
{
	if (FindNode(nodeLabel) == nullptr)
	{
		Nodes_[nodeLabel] = new Node(nodeLabel);
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
		return startNodePtr->Connect(endNodePtr, edgeWeight);

		if (twoWay)
		{
			endNodePtr->Connect(startNodePtr, edgeWeight);
		}

		return true;
	}
	return false;
}

int Graph::GetEdgeWeight(std::string& startLabel, std::string& endLabel) const
{
	Node* startNodePtr = FindNode(startLabel);
	Node* endNodePtr = FindNode(endLabel);
	if ((startNodePtr == nullptr) || (endNodePtr == nullptr) || (startNodePtr->GetEdgeWeightTo(endNodePtr) < 0))
	{
		return INT_MAX;
	}

	return (startNodePtr->GetEdgeWeightTo(endNodePtr));
}

void Graph::PrintNodesInGraph() const
{
	for (std::pair<std::string, Node*> node : Nodes_)
	{
		std::cout << *node.second << std::endl;
	}
}
