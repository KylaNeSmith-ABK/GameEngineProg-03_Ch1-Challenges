#include "Node.h"

Node::Node(std::string label)
	: NodeLabel_(label)
	, bVisited_(false)
	, DistanceFromStart_(INT_MAX)
	, PreviouseNode_(nullptr)
{
	AdjacencyList_.clear();
}

Node::~Node()
{
	for (std::pair<int, std::vector<Edge*>> pair : AdjacencyList_)
	{
		for (Edge* edge : pair.second)
		{
			delete edge;
		}
		pair.second.clear();
	}
	AdjacencyList_.clear();
}

Edge* Node::FindAdjacentNodeEdge(const Node* adjNode)
{
	for (std::pair<int, std::vector<Edge*>> pair : AdjacencyList_)
	{
		for (Edge* edge : pair.second)
		{
			if (edge->GetEndNode() == adjNode)
			{
				return edge;
			}
		}
	}

	return nullptr;
}

bool Node::Connect(Node *endNode, const int edgeWeight)
{
	// check first if Node provided is this Node or already connected to this Node
	if (!IsThisNode(endNode) && !IsConnectedTo(endNode))
	{
		if (AdjacencyList_.count(edgeWeight) > 0)
		{
			AdjacencyList_.at(edgeWeight).push_back(new Edge(endNode, edgeWeight));
		}
		else
		{
			AdjacencyList_.insert(std::pair<int, std::vector<Edge*>>(edgeWeight, std::vector<Edge*>{new Edge(endNode, edgeWeight)}));
		}
		return true;
	}

	return false;
}

bool Node::IsConnectedTo(const Node* endNode)
{
	return (FindAdjacentNodeEdge(endNode) != nullptr);
}

bool Node::Disconnect(const Node *endNode)
{
	// check first if Node provided is NOT connected to this Node
	if (IsConnectedTo(endNode))
	{
		int edgeWeight = FindAdjacentNodeEdge(endNode)->GetWeight();
		std::vector<Edge*> edgeVec = AdjacencyList_.at(edgeWeight);
		for (auto iter = edgeVec.begin(); iter != edgeVec.end(); iter++)
		{
			if ((**iter).GetEndNode() == endNode)
			{
				edgeVec.erase(iter);
			}
		}
		return true;
	}

	return false;
}

std::vector<Edge*> Node::GetAllEdgesWithWeight(int edgeWeight)
{
	if (AdjacencyList_.count(edgeWeight) > 0)
	{
		return AdjacencyList_.at(edgeWeight);
	}

	return std::vector<Edge*>();
}

int Node::GetEdgeWeightTo(const Node *endNode)
{
	Edge* edge = FindAdjacentNodeEdge(endNode);
	return (edge != nullptr ? edge->GetWeight() : -1);
}

bool Node::SetEdgeWeightTo(Node* endNode, int edgeWeight)
{
	if (IsConnectedTo(endNode))
	{
		Disconnect(endNode);
		Connect(endNode, edgeWeight);
		return true;
	}

	return false;
}

void Node::PrintAdjacencyList() const
{
	std::cout << "Adjacency List for Node " << *this << std::endl;
	for (std::pair<int, std::vector<Edge*>> pair : AdjacencyList_)
	{
		for (Edge* edge : pair.second)
		{
			std::cout << *this << " -- " << edge->GetWeight() << " --> " << *edge->GetEndNode() << std::endl;
		}
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