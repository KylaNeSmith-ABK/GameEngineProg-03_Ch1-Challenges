#pragma once

#include <map>
#include<vector>
#include <iostream>

#include "Edge.h"

class Edge;

struct Vec3
{
	int X_ = 0;
	int Y_ = 0;
	int Z_ = 0;

	double DistanceTo(Vec3* other)
	{
		return sqrt(pow((other->X_ - X_), 2) + pow((other->Y_ - Y_), 2) + pow((other->Z_ - Z_), 2));
	}
};

class Node
{
private:
	// the key used to identify this Node
	std::string NodeLabel_ = "ERROR";

	Vec3 Position_;

	// for searching, if the Node has been visited
	bool bVisited_ = false;

	// for searching, the distrance from the starting Node
	int DistanceFromStart_ = INT_MAX;

	// a map containing all the Edges that connect this Node to its adjacent Nodes
	std::map<int, std::vector<Edge*>, std::less<int>> AdjacencyList_;

	Node* PreviouseNode_ = nullptr;

public:
	explicit Node(std::string label);

	~Node();

	std::string GetLabel() const { return NodeLabel_; }

	void Visit() { bVisited_ = true; }

	void Unvisit() { bVisited_ = false; }

	bool IsVisited() { return bVisited_; }

	Node* GetPreviousNode() const { return PreviouseNode_; }

	void SetPreviousNode(Node* prevNode) { PreviouseNode_ = prevNode; }

	Edge* FindAdjacentNodeEdge(const Node* adjNode);

	// checks if passed in Node's key matches this one's
	bool IsThisNode(const Node *node) { return (NodeLabel_ == node->GetLabel()); }

	// connects this Node to a given Node and provides and Edge weight, returns false if connection failed
	bool Connect(Node *endNode, const int edgeWeight = 0);

	// checks if this Node is connected to given Node
	bool IsConnectedTo(const Node* endNode); /*{ return (AdjacencyList_.count(endNode->GetLabel()) > 0); }*/

	// disconnects this Node from a given Node, returns false if disconnection failed
	bool Disconnect(const Node *endNode);

	std::vector<Edge*> GetAllEdgesWithWeight(int edgeWeight);

	// gets the Edge weight between this Node and a provided Node
	int GetEdgeWeightTo(const Node *endNode);

	// sets the Edge weight between this Node and a provided Node, returns false if it failed
	bool SetEdgeWeightTo(Node* endNode, int edgeWeight);

	std::map<int, std::vector<Edge*>> GetAdjacencyList() { return AdjacencyList_; }

	// for searching, allows for setting how far this Node is from the starting Node
	void SetDistanceFromStart(int distance) { DistanceFromStart_ = distance; }
	
	// for searching, allows for adding to the distance from this Node to the starting Node
	void AddToDistance(int distance) { DistanceFromStart_ += distance; }

	// for searching, returns the distance from this Node to the starting Node
	int GetDistanceFromStart() const { return DistanceFromStart_; }

	void PrintAdjacencyList() const;

	bool operator==(const Node& rightHandItem) const;

	bool operator<(const Node& rightHandItem) const;

	friend std::ostream& operator<<(std::ostream& os, const Node& node);
};
