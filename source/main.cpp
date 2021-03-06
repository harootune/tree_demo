#include <vector>
#include <iostream>
#include "RedBlack.h"

int main()
{
    std::vector<RedBlackNode> nodes;
    int values[7] = {3, 7, 1, 2, 0, 6, 9};
    RedBlackTree rbt;

    for (int value: values)
    {
        nodes.push_back(RedBlackNode(value));
    }
    for (int i = 0; i < nodes.size(); i++)
    {
        rbt.insert(&nodes[i]);
    }

    std::cout << "Searching for 2" << std::endl;
    std::cout << "Found: " << rbt.search(2)->val << std::endl;
    
    // std::cout << "Deleting 2" << std::endl;
    // bst.remove(2);
    // if (bst.search(2) != nullptr)
    // {
    //     std::cout << "2 still in tree, uh oh!" << std::endl;
    // }
    // else
    // {
    //     std::cout << "It worked! " << std::endl;
    // }
    
    // bst.rotate(true);
    // bst.rotate(false);
    // std::cout << "All done!" << std::endl;

    // RedBlackNode rb = RedBlackNode(5, true);
    // RedBlackNode *left = rb.getRBLeft();
}