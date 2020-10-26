// 链表实现二叉树
// Created by Administrator on 2020/10/26.
//

#ifndef DATASTRUCT_BINARYTREE_HPP
#define DATASTRUCT_BINARYTREE_HPP

#include <iostream>
#include <memory>
using namespace std;

namespace tree
{
    /**
     * 树节点
     * @tparam T
     */
    template<typename T>
    struct TreeNode
    {
    public:
        TreeNode():
            _left(nullptr),
            _right(nullptr),
            _parent(nullptr) {}

        T _data;
        TreeNode<T>* _left;
        TreeNode<T>* _right;
        TreeNode<T>* _parent;
    };

    /**
     * 二叉树数据结构
     * @tparam T
     */
    template<typename T>
    class BinaryTree
    {
    public:
        /**
         * 构造空二叉树
         */
        BinaryTree() = default;

        /**
         * 根据数组采用前序遍历构造二叉树，#代表无子树
         */
        BinaryTree(const T data[], const T& none);

        ~BinaryTree();
//
//        void clear();
//
//        bool empty();
//
//        const int depth() const;

        const TreeNode<T>* root() const
        { return _root; }

        void preorder_traverse(const TreeNode<T>* node) const;

        void inorder_traverse(const TreeNode<T>* node) const;

        void postorder_traverse(const TreeNode<T>* node) const;

    private:
        /**
         * 创建节点
         * @param node 节点指针
         * @param data 数据
         * @param none 空标记
         */
        bool create_node(TreeNode<T>** node, const T data[], const T& none);

        TreeNode<T>* _root;
    };

    template<typename T>
    BinaryTree<T>::BinaryTree(const T* data, const T& none)
    {
        create_node(&_root, data, none);
    }

    template<typename T>
    BinaryTree<T>::~BinaryTree()
    {
        _root = nullptr;
    }

    template<typename T>
    void BinaryTree<T>::preorder_traverse(const TreeNode<T>* node) const
    {
        if(node == nullptr)
        {
            return;
        }

        cout << node->_data << endl;
        preorder_traverse(node->_left);
        preorder_traverse(node->_right);
    }

    template<typename T>
    void BinaryTree<T>::inorder_traverse(const TreeNode<T>* node) const
    {
        if(node == nullptr)
        {
            return;
        }

        inorder_traverse(node->_left);
        cout << node->_data << endl;
        inorder_traverse(node->_right);
    }

    template<typename T>
    void BinaryTree<T>::postorder_traverse(const TreeNode<T>* node) const
    {
        if(node == nullptr)
        {
            return;
        }

        postorder_traverse(node->_left);
        postorder_traverse(node->_right);
        cout << node->_data << endl;
    }

    template<typename T>
    bool BinaryTree<T>::create_node(TreeNode<T>** node, const T* data, const T& none)
    {
        if(!data || *data == 'e')
        {
            *node = nullptr;
            return false;
        }

        if(*data == none)
        {
            *node = nullptr;
        }
        else
        {
            *node = new TreeNode<T>;
            (*node)->_data = *data;

            if(++data)
            {
                if(!create_node(&((*node)->_left), data, none))
                {
                    return false;
                }
            }
            if(++data)
            {
                if(!create_node(&((*node)->_right), data, none))
                {
                    return false;
                }
            }
        }
        return true;
    }
}

#endif //DATASTRUCT_BINARYTREE_HPP
