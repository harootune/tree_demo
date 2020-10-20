#include <iostream>
#include <vector>
#include "Tree.h"

int main()
{
    std::vector<Node> nodes;
    int values[7] = {3, 7, 1, 2, 0, 6, 9};
    Tree bst;

    for (int value: values)
    {
        nodes.push_back(Node(value));
    }
    for (int i = 0; i < nodes.size(); i++)
    {
        bst.insert(&nodes[i]);
    }

    std::cout << "Searching for 2" << std::endl;
    std::cout << "Found: " << bst.search(2)->val << std::endl;
    std::cout << "Deleting 2" << std::endl;
    bst.remove(2);
    if (bst.search(2) != nullptr)
    {
        std::cout << "2 still in tree, uh oh!" << std::endl;
    }
    else
    {
        std::cout << "It worked! " << std::endl;
    }
    
    bst.rotate(true);
    bst.rotate(false);
    std::cout << "All done!" << std::endl;
}