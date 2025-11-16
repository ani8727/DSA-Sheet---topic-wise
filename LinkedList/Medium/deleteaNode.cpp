// 237. Delete Node in a Linked List
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

void deleteNode(Node* node){
    // Node* prev=NULL;
    // while(node!=NULL && node->next!=NULL){
    //     node->data=node->next->data;
    //     prev=node;
    //     node=node->next;
    // }
    // prev->next=NULL;
    // delete(node);
    
    node->data=node->next->data;
    node->next=node->next->next;
}
int main(){
    Node* head=NULL;
    head=new Node(5);
    head->next=new Node(7);
    head->next->next=new Node(8);
    head->next->next->next=new Node(10);

    deleteNode(head->next);

    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;

    return 0;



}