//
// Created by hushmans on 20.03.17.
//
#include <ostream>
#include <string>
#include <memory>
#include "SmartTree.h"

using namespace datastructures;

std::unique_ptr <SmartTree> datastructures::CreateLeaf(int value){
    std::unique_ptr <SmartTree> new_leaf = std::make_unique<SmartTree>();
    new_leaf->value = value;
    return new_leaf;
}

std::unique_ptr <SmartTree> datastructures::InsertLeftChild(std::unique_ptr <SmartTree> tree, std::unique_ptr <SmartTree> left_subtree){
    tree->left = move(left_subtree);
    return tree;
}

std::unique_ptr <SmartTree> datastructures::InsertRightChild(std::unique_ptr <SmartTree> tree, std::unique_ptr <SmartTree> right_subtree){
    tree->right = move(right_subtree);
    return tree;
}

void datastructures::PrintTreeInOrder(const std::unique_ptr <SmartTree> &unique_ptr, std::ostream *out) {
    if (unique_ptr != nullptr) {
        if (unique_ptr->left != nullptr) PrintTreeInOrder(unique_ptr->left, out);
        *out << (unique_ptr->value) << ", ";
        if(unique_ptr->right != nullptr)
    }
}

std::string datastrucutes::DumpTree(const std::unique_ptr <SmartTree> &tree) {
    std::string dump;
    if (tree != nullptr) {
        dump.append("[");
        dump.append( std::to_string(tree->value));
        dump.append(" ");
        if (tree->left != nullptr){
            result.append(DumpTree(tree->left));
        }
        else {
            dump.append("[none]");
        }
    }
    dump.append("]");
    return dump;
}

std::unique_ptr <SmartTree> datastructures::RestoreTree(const std::string &tree){
    
}