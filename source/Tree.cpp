#include <iostream>
#include "Tree.h"

Tree::Tree()
{
    _root = nullptr;
}

Node *Tree::search(int val)
{
    Node *curr = _root;
    while (curr != nullptr)
    {
        if (val == curr->val)
        {
            break;
        }
        else if (val > curr->val)
        {
            curr = curr->getRight();
        }
        else
        {
            curr = curr->getLeft();
        }
    }
    return curr;
}

void Tree::insert(Node *x)
{
    _root = insertRecur(_root, x);
}

Node *Tree::insertRecur(Node *root, Node *x)
{
    if (root == nullptr)
    {
        return x;
    }
    else
    {
        if (x->val > root->val)
        {
            root->setRight(insertRecur(root->getRight(), x), true);
        }
        else if (x->val < root->val)
        {
            root->setLeft(insertRecur(root->getLeft(), x), true);
        }
    }
    return root;
}

bool Tree::remove(int val)
{
    return removeRecur(_root, val);
}

bool Tree::removeRecur(Node *root, int val) // not super happy with this, but will work for now
{   
    if (root != nullptr)
    {
        if (val == root->val)
        {
            Node *replacement = nullptr;

            if (root->getLeft() != nullptr && root->getRight() != nullptr)
            {
                replacement = inorderSuccessor(root) ;
                removeRecur(replacement, replacement->val);
                replacement->setLeft(root->getLeft(), true);
                replacement->setRight(root->getRight(), true);
                replacement->setParent(root->getParent(), root);
            }
            else if (root->getLeft() != nullptr || root->getRight() != nullptr)
            {
                replacement = root->getLeft() == nullptr ? root->getLeft() : root->getRight();
                replacement->setParent(root->getParent(), root);

            }
            else
            {
                if (root->getParent() != nullptr)
                {
                    root->getParent()->removeChild(root);
                }
            }
            
            if (root == _root)
            {
                _root = replacement;
            }

            return true;
        }
        else if (val < root->val)
        {
            return removeRecur(root->getLeft(), val);
        }
        else
        {
            return removeRecur(root->getRight(), val);
        }      
    }
    return false;
}

Node *Tree::inorderSuccessor(Node *root)
{
    if (root->getRight() == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node *curr = root->getRight();
        while (curr->getLeft() != nullptr)
        {
            curr = curr->getLeft();
        }
        return curr;
    }

}

bool Tree::rotate(bool left)
{
    Node *replacement = left ? _root->getRight() : _root->getLeft();
    bool result = rotate(_root, left);
    if (result)
    {
        _root = replacement;
    }
    return result;
}

bool Tree::rotate(Node *root, bool left)
{
    Node *pivot;
    Node *orphan;

    if (left)
    {
        if (root->getRight() != nullptr)
        {
            pivot = root->getRight();
            orphan =  pivot->getLeft();
            pivot->setParent(root->getParent(), root);
            pivot->setLeft(root, true);
            root->setRight(orphan);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (root->getLeft() != nullptr)
        {
            pivot = root->getLeft();
            orphan =  pivot->getRight();
            pivot->setParent(root->getParent(), root);
            pivot->setRight(root, true);
            root->setLeft(orphan);
        }
        else
        {
            return false;
        }
    }

    return true;
}