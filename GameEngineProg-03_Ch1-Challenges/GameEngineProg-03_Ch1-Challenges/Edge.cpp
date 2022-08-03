#include "Edge.h"

Edge::Edge()
	: EndNode_(nullptr)
	, EdgeWeight_(0)
{
}

Edge::Edge(Node *endNode, const int weight)
	: EndNode_(endNode)
	, EdgeWeight_(weight)
{
}

Edge::~Edge()
{
}
