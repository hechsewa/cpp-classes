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

int ToInt(const std::string &num) {
    std::stringstream stream(num);
    int n;
    stream >> n;
    return n;
}

std::unique_ptr<SmartTree> datastructures::ReadData(const std::string& tree, int * i) {
    std::string tmpvalue = "";
    std::unique_ptr<SmartTree> root = std::make_unique<SmartTree>();
    if (tree[*i] == '-') {
        tmpvalue = "-";
        ++(*i);
    }
    while (tree[(*i)] >= '0' && tree[(*i)] <= '9' && (*i) < tree.length()) {
        tmpvalue += tree[(*i)];
        ++(*i);
    }
    if (tmpvalue != "") {
        root = CreateLeaf(ToInt(tmpvalue));
        (*i) += 2; //skip space and opening character
        root->left = ReadData(tree, i);
        root->right = ReadData(tree, i);
    }
    else {
        root = nullptr;
        while ((*i) < tree.length() && tree[(*i)] != '[') ++(*i);
        ++(*i);
    }
    return root;
}

std::unique_ptr <SmartTree> datastructures::RestoreTree(const std::string &tree) {
    std::unique_ptr<SmartTree> root = std::make_unique<SmartTree>();
    int i = 1;
    root = ReadData(tree, &i);
    return root;
}


