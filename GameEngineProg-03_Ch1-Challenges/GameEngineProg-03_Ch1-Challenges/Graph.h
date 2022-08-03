#pragma once

#include "Node.h"
#include "Edge.h"

//struct NodeLessThan
//{
//	bool operator()(const std::pair<Node*, int>& leftHandSide, const std::pair<Node*, int>& rightHandSide)
//	{
//		return (leftHandSide < rightHandSide);
//	}
//};

class Graph
{
private:
	int NumberOfNodes_ = 0;

	int NumberOfEdges_ = 0;

	std::map<std::string, Node*> Nodes_;

	void UnvisitNodes();

	Node* FindNode(const std::string& nodeLabel) const;

public:
	Graph();

	~Graph();

	int GetNumNodes() const { return NumberOfNodes_; }

	int GetNumEdges() const { return NumberOfEdges_; }

	void InsertNode(Node& node);

	void InsertNode(const std::string& nodeLabel);

	bool InsertEdge(Node& start, Node& end, const int edgeWeight = 0, bool twoWay = false);

	bool InsertEdge(const std::string& startLabel, const std::string& endLabel, const int edgeWeight = 0, bool twoWay = false);

	int GetEdgeWeight(std::string& startLabel, std::string& endLabel) const;

	void PrintNodesInGraph() const;
};
