# include "RedBlack.h"
# include <iostream>

// node

RedBlackNode::RedBlackNode()
{
    _parent = _left = _right = nullptr;
    _red = true;
    val = 0;
};

RedBlackNode::RedBlackNode(int x)
{
    _parent = _left = _right = nullptr;
    _red = true;
    val = x;
};

RedBlackNode::RedBlackNode(int x, bool red)
{
    _parent = _left = _right = nullptr;
    _red = red;
    val = x;
};

RedBlackNode* RedBlackNode::getRBLeft()
{   
    Node *res = Node::getLeft();
    try
    {
        return dynamic_cast<RedBlackNode*>(res);
    }
    catch (std::bad_cast &e)
    {
        std::cout << "Invalid node detected, check tree construction.";
        std::cerr << e.what();
    }
};

RedBlackNode* RedBlackNode::getRBRight()
{   
    Node *res = Node::getRight();
    try
    {
        return dynamic_cast<RedBlackNode*>(res);
    }
    catch (std::bad_cast &e)
    {
        std::cout << "Invalid node detected, check tree construction.";
        std::cerr << e.what();
    }
};

RedBlackNode* RedBlackNode::getRBParent()
{   
    Node *res = Node::getParent();
    try
    {
        return dynamic_cast<RedBlackNode*>(res);
    }
    catch (std::bad_cast &e)
    {
        std::cout << "Invalid node detected, check tree construction.";
        std::cerr << e.what();
    }
};


bool RedBlackNode::isRed()
{
    return _red;
};

void RedBlackNode::setRed(bool red)
{
    _red = red;
};

RedBlackTree::RedBlackTree()
{
    _root = nullptr;
};