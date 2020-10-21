#include "Node.h"


Node::Node()
{
    _parent = _left = _right = nullptr;
    val = 0;
};

Node::Node(int x)
{
    _parent = _left = _right = nullptr;
    val = x;
};

Node *Node::getLeft()
{
    return _left;
};

void Node::setLeft(Node *x, bool reciprocal)
{
    _left = x;

    if (reciprocal && x != nullptr)
    {
        x->setParent(this);
    }
};

Node *Node::getRight()
{
    return _right;
};

void Node::setRight(Node *x, bool reciprocal)
{
    _right = x;

    if (reciprocal && x != nullptr)
    {
        x->setParent(this);
    }   
};

Node *Node::getParent()
{
    return _parent;
};

void Node::setParent(Node *x, Node *former)
{
    _parent = x;

    if (former != nullptr && x != nullptr)
    {
        if (x->getLeft() == former)
        {
            x->setLeft(x);
        }
        else if (x->getRight() == former)
        {
            x->setRight(x);
        }
        else
        {
            // raise some error
            return;
        }
    }
};

void Node::removeChild(Node *x)
{
    if (getLeft() == x)
    {
        setLeft(nullptr);
    }
    else if (getRight() == x)
    {
        setRight(nullptr);
    }
    else
    {
        //raise some error
        return;
    }
};

