#include "Node.h"

namespace Tree 
{
    Node *search(Node *root, int val);
    Node *insert(Node *root, Node *x);
    bool remove(Node *root, int val);
    Node *inorderSuccessor(Node *root);
    void swapChildren(Node *root, Node *x);
};

namespace RedBlackTree  
{
    void restore(Node *x);
};