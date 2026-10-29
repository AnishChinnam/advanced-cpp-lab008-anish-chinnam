#include "project/binary_search_tree.h"
#include <iostream>

int main() {
    BinarySearchTree tree;
    for (int value : {10, 5, 15, 3, 7, 12, 18}) tree.insert(value);
    tree.remove(10);
    std::cout << "BST inorder:";
    for (int value : tree.inorderTraversal()) std::cout << ' ' << value;
    std::cout << "\nSize: " << tree.size() << ", height: " << tree.height() << '\n';
}
