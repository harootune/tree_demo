#include <iostream>
#include "Tree.h"


Node *Tree::search(Node *root, int val)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        if (val == curr->val)
        {
            break;
        }
        else if (val > curr->val)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }
    return curr;
}

Node *Tree::insert(Node *root, Node *x)
{
    if (root == nullptr)
    {
        return x;
    }
    else
    {
        if (x->val > root->val)
        {
            root->right = Tree::insert(root->right, x);
            root->right->parent = root;
        }
        else if (x->val < root->val)
        {
            root->left = Tree::insert(root->left, x);
            root->left->parent = root;
        }
    }
    return root;
}

bool Tree::remove(Node *root, int val)
{   
    if (root != nullptr)
    {
        if (val == root->val)
        {
            if (root->left != nullptr && root->right != nullptr)
            {
                Node *successor = Tree::inorderSuccessor(root->right);
                Tree::remove(successor, successor->val);
                successor->left = root->left;
                successor->right = root->right;
                Tree::swapChildren(root, successor); // might cause a whole-ass memory leak
            }
            else if (root->left != nullptr)
            {
                Tree::swapChildren(root, root->left);
            }
            else if (root->right != nullptr)
            {
                Tree::swapChildren(root, root->right);
            }
            else
            {
                Tree::swapChildren(root, nullptr);
            }
            return true;
        }
        else if (val < root->val)
        {
            return Tree::remove(root->left, val);
        }
        else
        {
            return Tree::remove(root->right, val);
        }      
    }
    return false;
}

Node *Tree::inorderSuccessor(Node *root)
{
    Node *curr = root;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}

void Tree::swapChildren(Node *root, Node *x)
{
    if (x != nullptr)
    {
        x->parent = root->parent;
    }

    if (root->parent != nullptr)
    {
        if (root->parent->left == root)
        {
            root->parent->left = x;
        }
        else
        {
            root->parent->right = x;
        }
    }
}
