class Node
{
    public:
        int val;

        Node ();
        Node (int x);

        Node *getLeft();
        void setLeft(Node *x, bool reciprocal = false);
        Node *getRight();
        void setRight(Node *x, bool reciprocal = false);
        Node *getParent();
        void setParent(Node *x, Node *former = nullptr);
        void removeChild(Node *child);
    
    protected:
        Node *_parent, *_left, *_right;
        

};

class RedBlackNode: public Node
{
    public:
        bool red;

        RedBlackNode ();
        RedBlackNode (int x, bool color);
};