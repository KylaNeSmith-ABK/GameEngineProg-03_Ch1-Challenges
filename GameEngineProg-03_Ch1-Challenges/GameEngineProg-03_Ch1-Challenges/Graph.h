#pragma once

#include "Node.h"
#include "Edge.h"

struct NodeLessThan
{
	bool operator()(const std::pair<Node*, int>& leftHandSide, const std::pair<Node*, int>& rightHandSide)
	{
		return (leftHandSide.second < rightHandSide.second);
	}
};

class Graph
{
private:
	// number of Nodes in the Graph
	int NodeCount_ = 0;

	// number of Edges in the Graph (if two Nodes are connected in both directions, each Edge is counted separately)
	int EdgeCount_ = 0;

	// map of all the Nodes in the Graph
	std::map<std::string, Node*> Nodes_;

public:
	Graph();

	~Graph();

	int GetNodeCount() const { return NodeCount_; }

	int GetEdgeCount() const { return EdgeCount_; }

	// finds and returns the Node if it is in the Graph, otherwise returns a nullptr
	Node* FindNode(const std::string& nodeLabel) const;

	void AddNode(Node& node);

	void AddNode(const std::string& nodeLabel);

	bool InsertEdge(Node& start, Node& end, const int edgeWeight = 0, bool twoWay = false);

	bool InsertEdge(const std::string& startLabel, const std::string& endLabel, const int edgeWeight = 0, bool twoWay = false);

	int GetEdgeWeightBetween(const std::string& startLabel, const std::string& endLabel) const;

	bool SetEdgeWeightBetween(const std::string& startLabel, const std::string& endLabel, int edgeWeight);

	// sets all Nodes' bVisited to false
	void UnvisitNodes();

	bool DepthFirstSearch(const std::string& startLabel, const std::string& endLabel);

	bool BreadthFirstSearch(const std::string& startLabel, const std::string& endLabel);

	bool DijkstraSearch(const std::string& startLabel, const std::string& endLabel);

	void PrintNodesInGraph() const;
};
