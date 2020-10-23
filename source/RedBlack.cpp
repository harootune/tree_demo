# include "RedBlack.h"
# include <iostream>

// node

RedBlackNode::RedBlackNode()
{
    _parent = _left = _right = nullptr;
    _color = colors::red;
    val = 0;
};

RedBlackNode::RedBlackNode(int x)
{
    _parent = _left = _right = nullptr;
    _color = colors::red;
    val = x;
};

RedBlackNode::RedBlackNode(int x, int color)
{
    _parent = _left = _right = nullptr;
    _color = color;
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

int RedBlackNode::getColor()
{
    return _color;
};

void RedBlackNode::setColor(int color)
{
    _color = color;
};

RedBlackTree::RedBlackTree()
{
    _root = nullptr;
};

bool RedBlackTree::insert(Node *x)
{
    RedBlackNode *restorePoint;
    try
    {
        restorePoint = dynamic_cast<RedBlackNode*>(x);
    }
    catch (std::bad_cast &e)
    {
        std::cout << "Attempted insert of non-RedBlackNode into RedBlackTree";
        std::cerr << e.what();
        std::exit(1);
    };

    bool result = Tree::insert(x);
    if (result)
    {
        restore(restorePoint);
    }
    return result;
};

Node *RedBlackTree::remove(int val)
// TBD
{
    return nullptr;
}

void RedBlackTree::restore(RedBlackNode *x)
// enforces RB-Tree rules after an insert
{
    if (x == _root)
    {
        x->setColor(RedBlackNode::colors::black);
    }
    else if (x->getRBParent()->getColor() == RedBlackNode::colors::red)
    {
        RedBlackNode *uncle;
        RedBlackNode *parent = x->getRBParent();
        RedBlackNode *grandParent = parent->getRBParent();

        if (grandParent->getRBLeft() == parent)
        {
            uncle = grandParent->getRBRight();
        }
        else
        {
            uncle = grandParent->getRBLeft();
        }

        if (uncle->getColor() == RedBlackNode::colors::red)
        {
            int temp;

            uncle->setColor(RedBlackNode::colors::black);
            parent->setColor(RedBlackNode::colors::black);
            grandParent->setColor(RedBlackNode::colors::red);
            restore(grandParent);
        }
        else
        {
            int tempColor;
            bool PXLeft = parent->getRBLeft() == x;
            bool GPLeft = grandParent->getRBLeft() == parent;

            if (PXLeft != GPLeft)
            {
                rotate(parent, !PXLeft);
                parent = x;
            };
            
            tempColor = grandParent->getColor();
            grandParent->setColor(parent->getColor());
            parent->setColor(tempColor);
            rotate(grandParent, !GPLeft);
        }
    }
}

