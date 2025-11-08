#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        this->data = val;
        this->next = NULL;
    }
};

class list {
    Node* head;

public:
    list() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node* getHead() {
        return head;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search for node pointer by value
    Node* findNode(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val)
                return temp;
            temp = temp->next;
        }
        return NULL;  // Not found
    }
};

class Solution {
public:
    // Deletes node in place except last node
    void deleteNode(Node* deleteTemp) {
        if (deleteTemp == NULL || deleteTemp->next == NULL) {
            cout << "Cannot delete last node or NULL pointer using this method." << endl;
            return;
        }
        Node* nextNode = deleteTemp->next;
        deleteTemp->data = nextNode->data;
        deleteTemp->next = nextNode->next;
        delete nextNode;
    }
};

int main() {
    list ll;

    ll.insert(8);
    ll.insert(10);
    ll.insert(12);
    ll.display();

    Solution sol;

    // Find the node pointer inside the list to delete
    Node* nodeToDelete = ll.findNode(10);
    sol.deleteNode(nodeToDelete);

    ll.display();

    return 0;
}
