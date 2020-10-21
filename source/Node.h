class Node
{
    public:
        int val;

        Node ();
        Node (int x);

        virtual Node *getLeft();
        virtual void setLeft(Node *x, bool reciprocal = false);
        virtual Node *getRight();
        virtual void setRight(Node *x, bool reciprocal = false);
        virtual Node *getParent();
        virtual void setParent(Node *x, Node *former = nullptr);
        virtual void removeChild(Node *child);

        virtual ~Node() {};
    
    protected:
        Node *_parent, *_left, *_right;  
};