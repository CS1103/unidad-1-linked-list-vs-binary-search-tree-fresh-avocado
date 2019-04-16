//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_BINARYTREE_H
#define LINKEDLISTVSBINARYTREE_BINARYTREE_H

#include "Location.h"


    struct BinarySearchTreeNode {
        Location data;
        BinarySearchTreeNode* right;
        BinarySearchTreeNode* left;
        bool is_final;

        BinarySearchTreeNode(Location data): data{data}, right{nullptr}, left{nullptr} {
            is_final = right == nullptr && left == nullptr;
        }
    };


    class BinarySearchTree {
        BinarySearchTreeNode* root;
    public:
        BinarySearchTree(): root{nullptr} {}
        ~BinarySearchTree();
        void insert(Location data);
        void clear(BinarySearchTreeNode* root);
        bool is_empty();
        BinarySearchTreeNode* get_root() { return root; }
        BinarySearchTreeNode* search(int position_id);
        void print(BinarySearchTreeNode* ptr);
    };

    void load_bst_locations(BinarySearchTree* binarySearchTree, std::string file_name);


#endif //LINKEDLISTVSBINARYTREE_BINARYTREE_H
