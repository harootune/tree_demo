#include "Node.h"

class Tree 
{
    public:
        Node *search(int val);
        void insert(Node *x);
        bool remove(int val);
        bool rotate(bool left);
        
        static Node *inorderSuccessor(Node *root);
        static bool rotate(Node *root, bool left);

        Tree();

    protected:
        Node *_root;
        bool removeRecur(Node *root, int val);
        
        static Node *insertRecur(Node *root, Node *x);
};

class RedBlackTree: public Tree
{
    public:
        RedBlackTree();

    protected:
        static void restore(Node *x);
};