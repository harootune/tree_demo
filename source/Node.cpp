#include "Node.h"

Node::Node ()
{
    parent = left = right = nullptr;
    val = 0;
};

Node::Node (int x)
{
    parent = left = right = nullptr;
    val = x;
};

RedBlackNode::RedBlackNode ()
{
    parent = left = right = nullptr;
    val = 0;
    red = true;
}

RedBlackNode::RedBlackNode (int x, bool color)
{
    parent = left = right = nullptr;
    val = x;
    red = color;
};

