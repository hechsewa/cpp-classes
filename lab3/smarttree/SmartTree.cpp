//
// Created by hushmans on 20.03.17.
//
#include <ostream>
#include <string>
#include <stack>
#include <regex>
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
        if(unique_ptr->right != nullptr) PrintTreeInOrder(unique_ptr->right, out);
    }
}

std::string datastructures::DumpTree(const std::unique_ptr <SmartTree> &tree) {
    std::string dump;
    if (tree != nullptr) {
        dump.append("[");
        dump.append(std::to_string(tree->value));
        dump.append(" ");
        if (tree->left != nullptr) dump.append(DumpTree(tree->left));
        else {
            dump.append("[none]");
        }
        dump.append(" ");

        if(tree->right != nullptr) dump.append(DumpTree(tree->right));
        else {
            dump.append("[none]");
        }
        dump.append("]");
    }
    return dump;
}

std::unique_ptr <SmartTree> datastructures::RestoreTree(const std::string &tree){
    std::unique_ptr <SmartTree> ptr = std::make_unique<SmartTree>();
    int counter=0;
    std::regex pattern {R"([(d+|none)\s(.*))"};
    std::smatch matches;

    if(regex_match(tree, matches,pattern)){
        if (matches[1] == "none") ptr = nullptr;
        else {
            int first_val  = std::stoi(matches[1]);
            ptr->value = first_val;

            std::string leftChild;
            std::string rightChild;
            std::string children = matches[2].str();
            for (int i=0; i<children.length(); i++) {
                if (tree[i] ==  '[') counter++;
                if (tree[i] ==  ']') counter--;
                if (counter == 0) {
                    leftChild = children.substr(0, i);
                    rightChild = children.substr(i + 2, children.length() - 1);
                }
            }
            InsertLeftChild(move(ptr),RestoreTree(leftChild));
            InsertRightChild(move(ptr),RestoreTree(rightChild));
        }

}
    return ptr;
}



