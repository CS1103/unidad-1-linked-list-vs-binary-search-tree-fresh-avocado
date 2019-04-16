//
// Created by ruben on 4/5/19.
//

#include <iostream>
#include <string>

#include "LinkedList.h"



using namespace std;

LinkedList::~LinkedList() {
    if (!is_empty()) {
        for (int i = 0; i < size(); i++) {
            remove_tail();
        }
    }
}

int LinkedList::size() {
    int count = 0;
    Node* actual = head;
    while(actual != nullptr) {
        count++;
        actual = actual->next;
    }
    return count;
}

bool LinkedList::is_empty() {
    return head == nullptr;
}

Node* LinkedList::get_head() {
    return head;
}

Node* LinkedList::get_tail() {
    return tail;
}

void LinkedList::add_head(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void LinkedList::add_tail(const Location& data) {
    Node* temp = new Node(data);
    if (is_empty()) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void LinkedList::print() {
    if (size() == 0) {
        cout << "Cannot print empty linked list." << endl;
    }
    Node* temp = head;
    for (int i = 0; i < size(); ++i) {
        cout << temp->data << endl;
        temp = temp->next;
    }

}

void LinkedList::insert(int pos, const Location& data) {
    if (size() == 0) {
        this->add_tail(data);
        return;
    } else if (size() == 1) {
        if (pos == 0) {
            this->add_tail(data);
            return;
        } else if (pos == 1) {
            this->add_tail(data);
            return;
        }
    } else {
        if (pos == 0) {
            Node* newItem = nullptr;
            newItem = head;
            head = head->next;
            newItem->next = head;
            newItem->data = data;
            return;
        }
    }

    Node* temp = head;
    Node* newItem = new Node(data);
    Node* aux = head;

    for (int i = 0; i < pos; i++) {
        aux = aux->next;
    }

    for (int i = 0; i < pos-1; i++) {
        temp = temp->next;
    }

    temp->next = newItem;
    newItem->next = aux;
}

Node* LinkedList::search(string position_id) {
    Node* search_node = head;

    for (int i = 0; i < size(); ++i) {
        if (to_string(search_node->data.get_position_id()) == position_id) {
            return search_node;
        }
        search_node = search_node->next;
    }

    return nullptr;
}

void LinkedList::remove_tail() {
    if (is_empty()) {
        cout << "Cannot remove elements of empty vector." << endl;
    } else {
        delete tail; // deletes content of tail, not the pointer tail
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        tail = temp;
        tail->next = nullptr;
    }
}

void load_ll_locations(LinkedList* linked_list, string filename) {
    ifstream locations;
    locations.open(filename);

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

            linked_list->add_tail(Location(position_id, state_code, county, latitude, longitude, line, construction));

        }
        locations.close();
    } else {
        cout << "Unable to open " << filename << " file." << endl;
    }
}































































