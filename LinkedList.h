//
// Created by ruben on 4/5/19.
//

#ifndef LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#define LINKEDLISTVSBINARYTREE_LINKEDLIST_H
#include "Location.h"

#include <fstream>
#include <string>

using namespace std;

const int LOCATION_PROPERTIES = 7;

struct Node {
    Location data;
    Node* next;

    explicit Node(const Location& data): data{data}, next{nullptr} {}
};

class LinkedList {
    Node* head;
    Node* tail;
public:
    LinkedList(): head{nullptr}, tail{nullptr} {};
    ~LinkedList();
    int size();
    bool is_empty();
    Node* get_head();
    Node* get_tail();
    void add_head(const Location& data);
    void add_tail(const Location& data);
    void remove_tail();
    void print();
    void insert(int pos, const Location& data);
    Node* search(std::string position_id);
};

void load_ll_locations(LinkedList* linked_list, string filename);


#endif //LINKEDLISTVSBINARYTREE_LINKEDLIST_H
