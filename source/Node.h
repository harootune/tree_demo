class Node
{
    public:
        int val;
        Node *parent, *left, *right;

        Node ();
        Node (int x);
};

class RedBlackNode: public Node
{
    public:
        bool red;

        RedBlackNode ();
        RedBlackNode (int x, bool color);
};