#include <iostream>
#include <vector>
#include "Tree.h"

int main()
{
    Node root = Node(5);
    std::vector<Node> nodes;
    for (int i = 0; i < 10; i++)
    {
        nodes.push_back(Node(i));
    }
        for (int i = 0; i < 10; i++)
    {
        Tree::insert(&root, &nodes[i]);
    }
    std::cout << Tree::search(&root, 5)->val << std::endl;
    std::cout << "Deleting 2" << std::endl;
    Tree::remove(&root, 2);
    if (Tree::search(&root, 2) != nullptr)
    {
        std::cout << "2 found, uh oh!" << std::endl;
    }
    else
    {
        std::cout << "It worked! ";
        std::cout << "Root left: " << root.left->val << std::endl;
    }
}