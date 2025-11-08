// search Node

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};

int search(Node* head, int val){
    Node* temp=head;
    int idx=0;
    while(temp!=nullptr){
        idx++;
        if(temp->data==val) return idx;
        temp=temp->next;
    }
    return -1;
}

int main(){

    Node* head=new Node(5);
    head->next=new Node(12);
    head->next->next=new Node(10);
    head->next->next->next=new Node(7);
    head->next->next->next->next=new Node(15);

    cout<<search(head,20);

    return 0;

}