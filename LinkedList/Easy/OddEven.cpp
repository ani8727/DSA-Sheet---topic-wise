// 328. Odd Even Linked List
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val): data(val),next(NULL){}
};

Node* oddEven(Node* head){
    if(!head){
        cout<<"Empty List"<<endl;
        return head;
    }else if(!head->next || !head->next->next){
        return head;
    }else {
        Node* odd=head;
        Node* even = head->next;
         Node* evenStart=even;

        while(even && even->next){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }

        odd->next=evenStart;
        return head;
    }
}
Node* insert(Node* head, int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        return head;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

void printList(Node* head){
    if(!head){
        cout<<"Empty List"<<endl;
    }else{
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }
}
int main(){
    Node* head =NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    
    printList(head);

    head = oddEven(head);

    printList(head);

    return 0;
}