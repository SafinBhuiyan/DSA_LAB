#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool find(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList myList;
    myList.insert(10);
    myList.insert(20);
    myList.insert(30);

    myList.display();

    int target = 20;
    if (myList.find(target)) {
        cout << "Element " << target << " found in the list." << endl;
    } else {
        cout << "Element " << target << " not found in the list." << endl;
    }

    return 0;
}
