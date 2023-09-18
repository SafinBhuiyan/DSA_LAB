#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    bool find(int value) {
        if (head == nullptr) {
            return false;
        }
        Node* current = head;
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != head);
        return false;
    }

private:
    Node* head;
};

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    CircularLinkedList circularList;

    for (int i = 0; i < n; i++) {
        circularList.insert(arr[i]);
    }

    int target = 30;

    if (circularList.find(target)) {
        cout << "Element " << target << " found in the circular linked list." << endl;
    } else {
        cout << "Element " << target << " not found in the circular linked list." << endl;
    }

    return 0;
}
