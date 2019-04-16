//
// Created by ruben on 4/5/19.
//

#include <fstream>
#include <string>

#include "BinarySearchTree.h"

using namespace std;

// Destructor

BinarySearchTree::~BinarySearchTree() {
    clear(root);
}

// Editando

void BinarySearchTree::insert(Location data) {

    BinarySearchTreeNode* new_node = new BinarySearchTreeNode(data);

    if (root == nullptr) {
        root = new_node;
    }
    else if (root != nullptr) {
        for (BinarySearchTreeNode* temp = root; temp != nullptr;) {
            if (temp->data.get_position_id() > new_node->data.get_position_id()) {
                if (temp->left == nullptr) {
                    temp->left = new_node;
                    break;
                } else {
                    temp = temp->left;
                }
            } else if (temp->data.get_position_id() < new_node->data.get_position_id()) {
                if (temp->right == nullptr) {
                    temp->right = new_node;
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
    }


}

void BinarySearchTree::clear(BinarySearchTreeNode* root) {
    if (root != nullptr) {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}

// Accediendo

BinarySearchTreeNode* BinarySearchTree::search(int position_id) {
    for (BinarySearchTreeNode* temp = root; temp != nullptr;) {
        if (temp->data.get_position_id() == position_id)
            return temp;
        else if (temp->data.get_position_id() > position_id)
            temp = temp->left;
        else if (temp->data.get_position_id() < position_id)
            temp = temp->right;
    }
}

// Empty

bool BinarySearchTree::is_empty() {
    return (root == nullptr);
}

// Print

void BinarySearchTree::print(BinarySearchTreeNode* ptr) {
    if (ptr) {
        print(ptr->left);
        cout << ptr->data << endl;
        print(ptr->right);
    }
}

// Load

void load_bst_locations(BinarySearchTree* binarySearchTree, string file_name) {
    ifstream locations;
    locations.open(file_name);

    string position_id;
    string state_code;
    string county;
    double latitude;
    double longitude;
    string line;
    string construction;

    string latit;
    string longi;

    if (locations.is_open()) {

        while (locations.good()) {

            getline(locations, position_id, ',');
            getline(locations, state_code, ',');
            getline(locations, county, ',');
            getline(locations, latit, ',');
            getline(locations, longi, ',');
            getline(locations, line, ',');
            getline(locations, construction, '\n');

            latitude = stod(latit);
            longitude = stod(longi);


            binarySearchTree->insert(Location(position_id, state_code, county, latitude, longitude, line, construction));
        }
        locations.close();
    } else {
        cout << "Unable to open " << file_name << " file." << endl;
    }
}