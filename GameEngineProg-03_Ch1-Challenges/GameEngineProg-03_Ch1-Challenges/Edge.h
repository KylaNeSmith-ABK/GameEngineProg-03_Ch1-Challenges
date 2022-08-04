#pragma once

#include <string>

#include "Node.h"

class Node;

class Edge
{
private:
	Node* EndNode_ = nullptr;

	int EdgeWeight_ = 0;

public:
	Edge();

	Edge(Node *endNode, const int weight);

	~Edge();

	Node* GetEndNode() const { return EndNode_; }

	int GetWeight() const { return EdgeWeight_; }

	void SetWeight(int edgeWeight) { EdgeWeight_ = edgeWeight; }
};
