#include "tree/BinaryTree.hpp"

using namespace tree;

int main()
{
    char str[] = {'A', 'B', 'C', 'D', 'E', 'e'};
    auto tree = BinaryTree<char>(str, '#');
    //tree.preorder_traverse(tree.root());
    //tree.inorder_traverse(tree.root());
    tree.postorder_traverse(tree.root());
    return 0;
}
