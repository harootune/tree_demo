#include "Tree.h"

class RedBlackNode: public Node
{
    public:
        RedBlackNode();
        RedBlackNode(int x);
        RedBlackNode(int x, bool red);

        RedBlackNode *getRBLeft();
        RedBlackNode *getRBRight();
        RedBlackNode *getRBParent();

        bool isRed();
        void setRed(bool red);

        ~RedBlackNode() {};

    protected:
        bool _red;
};

class RedBlackTree: protected Tree
{
    public:
        RedBlackTree();

        RedBlackNode *search(int val);
        void insert(RedBlackNode *x);
        bool remove(int val);

    protected:
        RedBlackNode *_root;

        void restore(RedBlackNode *x);
};