#include "Node.h"

Node::Node(std::string label)
	: NodeLabel_(label)
	, bVisited_(false)
{
	AdjacencyList_.clear();
}

Node::~Node()
{
}

bool Node::Connect(Node *endNode, const int edgeWeight)
{
	if (NodeLabel_ == endNode->GetLabel())
	{
		return false;
	}

	if (AdjacencyList_.count(endNode->GetLabel()) == 0)
	{
		AdjacencyList_[endNode->GetLabel()] = Edge(endNode, edgeWeight);
		return true;
	}

	return false;
}

bool Node::Disconnect(const Node *endNode)
{
	if (NodeLabel_ == endNode->GetLabel())
	{
		return false;
	}

	if (AdjacencyList_.count(endNode->GetLabel()) > 0)
	{
		AdjacencyList_.erase(endNode->GetLabel());
		return true;
	}

	return false;
}

int Node::GetEdgeWeightTo(const Node *endNode)
{
	if (AdjacencyList_.count(endNode->GetLabel()) > 0)
	{
		return AdjacencyList_.at(endNode->GetLabel()).GetWeight();
	}

	return (-1);
}

int Node::GetNumberOfNeighbors() const
{
	return (int)AdjacencyList_.size();
}

void Node::PrintAdjacencyList() const
{
	std::cout << "Adjacency List for Node " << *this << std::endl;
	for (std::pair<std::string, Edge> adjNode : AdjacencyList_)
	{
		std::cout << "Edge to " << adjNode.first << " has weight " << adjNode.second.GetWeight() << std::endl;
	}
}

bool Node::operator==(const Node& rightHandItem) const
{
	return (NodeLabel_ == rightHandItem.GetLabel());
}

bool Node::operator<(const Node& rightHandItem) const
{
	return (NodeLabel_ < rightHandItem.GetLabel());
}

std::ostream& operator<<(std::ostream& os, const Node& node)
{
	os << node.NodeLabel_;
	return os;
}