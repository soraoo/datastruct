#include "tree/BinaryTree.hpp"

using namespace tree;

///最大公约数
int gcd(int p, int q)
{
    if(q == 0) return p;
    int r = p % q;
    return gcd(q, r);
}

int sequential_search2(int* a, int n, int key)
{
    a[0] = key;
    int i = n;
    while(a[i] != key)
    {
        i--;
    }
    return i;
}

///二分查找
int binary_search(int* a, int n, int key)
{
    int left = 1;
    int right = 1;
    while(left <= right)
    {
        int mid = 0.5 * (right - left);
        if(a[mid] < key)
        {
            left = mid + 1;
        }
        else if(a[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return 0;
}

///插值查找
int inter_search(int* a, int n, int key)
{
    int left = 1;
    int right = 1;
    while(left <= right)
    {
        int mid = left + (right - left) * (a[key] - a[left]) / (a[right] - a[left]);
        if(a[mid] < key)
        {
            left = mid + 1;
        }
        else if(a[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return 0;
}

int main()
{
    int a = 5;
    int& r = a;
    int* b = &r;
    cout << r << " " << b << endl;
//    char str[] = {'A', 'B', 'C', 'D', 'E', 'e'};
//    auto tree = BinaryTree<char>(str, '#');
//    //tree.preorder_traverse(tree.root());
//    //tree.inorder_traverse(tree.root());
//    tree.postorder_traverse(tree.root());
    return 0;
}
