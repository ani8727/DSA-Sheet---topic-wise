#include <iostream>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

ListNode* insertTail(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        return newNode;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

int main() {
    ListNode* head = nullptr;
    head = insertTail(head, 1);
    head = insertTail(head, 3);
    head = insertTail(head, 4);
    head = insertTail(head, 7);
    head = insertTail(head, 1);
    head = insertTail(head, 2);
    head = insertTail(head, 6);

    printList(head);

    head = deleteMiddle(head);
    printList(head);

    return 0;
}
