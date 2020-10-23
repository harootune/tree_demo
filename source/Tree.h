#include "Node.h"

class Tree 
{
    public:
        virtual Node *search(int val);
        virtual bool insert(Node *x);
        virtual Node *remove(int val);
        virtual bool rotate(bool left);
        
        static Node *inorderSuccessor(Node *root);
        static bool rotate(Node *root, bool left);

        Tree();

    protected:
        Node *_root;
        virtual Node *removeRecur(Node *root, int val);
        
        static Node *insertRecur(Node *root, Node *x, bool &success);
};