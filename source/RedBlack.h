#include "Tree.h"

class RedBlackNode: public Node
{
    public:
        RedBlackNode();
        RedBlackNode(int x);
        RedBlackNode(int x, int color);

        RedBlackNode *getRBLeft();
        RedBlackNode *getRBRight();
        RedBlackNode *getRBParent();

        int getColor();
        void setColor(int color);

        ~RedBlackNode() {};

        enum colors {red, black, doubleblack};

    protected:
        int _color;
};

class RedBlackTree: public Tree
{
    public:
        RedBlackTree();

        bool insert(Node* x);
        Node *remove(int val);

    protected:
        void restore(RedBlackNode *x);
};