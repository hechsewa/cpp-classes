//
// Created by Student on 25/05/17.
//

#ifndef JIMP_EXERCISES_BINARYTREE_H
#define JIMP_EXERCISES_BINARYTREE_H

#include <cstddef>
#include <initializer_list>
#include <algorithm>
#include <iostream>

using namespace std;

namespace BST {
    template<class T>
    class Node;

    template<class T>
    class BinaryTree{
    public:
        BinaryTree();
        BinaryTree(Node<T> node);

        void Insert(T node);
        std::size_t Size() const;
        T Find(const T &data) const;
        T Remove(const T &data);

    private:
        std::unique_ptr<Node<T>> root;
        std::size_t size_;

    };

    template<class T>
    class Node{
    public:
        Node(T node);
        T data_;
        std::unique_ptr<Node<T>> left;
        std::unique_ptr<Node<T>> right;
    };

    template<class T>
    BinaryTree<T>::BinaryTree() {
        root = nullptr;
    }

}

#endif //JIMP_EXERCISES_BINARYTREE_H
