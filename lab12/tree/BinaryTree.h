//
// Created by Student on 25/05/17.
//

#ifndef JIMP_EXERCISES_BINARYTREE_H
#define JIMP_EXERCISES_BINARYTREE_H

#include <cstddef>
#include <initializer_list>
#include <algorithm>
#include <memory>
#include <iostream>

using namespace std;

namespace BST {

    template<class T>
    class Node{
    public:
        Node(T data);

        std::unique_ptr<Node<T>> left_;
        std::unique_ptr<Node<T>> right_;

        T value_;
    };

    template<class T>
    Node<T>::Node(T data){
        left_=nullptr;
        right_=nullptr;
        value_=data;
    }

    template<class T>
    class Tree{
    public:
        Tree();
        Tree(T data);

        Node<T> * Root();
        void Insert(T data);
        std::size_t Size() const;
        std::size_t Depth() const;


        void Print(std::unique_ptr<Node<T>> &root) const;
        auto Value();
        bool Find(const T &search, const std::unique_ptr<Node<T>> &root);
        T Remove(const T &search);


    private:
        std::size_t DepthFirstSearch(const std::unique_ptr<Node<T>> &root) const;
        std::unique_ptr<Node<T>> head_;
        std::size_t size_;

    };

/*********************/

    template<class T>
    Node<T> * Tree<T>::Root(){
        return head_.get();
    }

    template<class T>
    Tree<T>::Tree(){
        size_=0;
        head_=nullptr;
    }

}

#endif //JIMP_EXERCISES_BINARYTREE_H
