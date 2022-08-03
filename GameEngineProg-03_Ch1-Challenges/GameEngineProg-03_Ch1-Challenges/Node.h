#pragma once

#include <map>
#include <iostream>

#include "Edge.h"

class Edge;

struct Vec3
{
	int X_ = 0;
	int Y_ = 0;
	int Z_ = 0;

	float DistanceTo(Vec3* other)
	{
		return sqrt(pow((other->X_ - X_), 2) + pow((other->Y_ - Y_), 2) + pow((other->Z_ - Z_), 2));
	}
};

class Node
{
private:
	std::string NodeLabel_ = "ERROR";

	Vec3 Position_;

	bool bVisited_ = false;

	float distance = 0.0f;

	std::map<std::string, Edge> AdjacencyList_;

	Node* PreviousNode_ = nullptr;

public:
	explicit Node(std::string label);

	~Node();

	std::string GetLabel() const { return NodeLabel_; }

	void Visit() { bVisited_ = true; }

	void Unvisit() { bVisited_ = false; }

	bool IsVisited() { return bVisited_; }

	bool Connect(Node *endNode, const int edgeWeight = 0);

	bool Disconnect(const Node *endNode);

	int GetEdgeWeightTo(const Node *endNode);

	int GetNumberOfNeighbors() const;

	void PrintAdjacencyList() const;

	bool operator==(const Node& rightHandItem) const;

	bool operator<(const Node& rightHandItem) const;

	friend std::ostream& operator<<(std::ostream& os, const Node& node);
};
