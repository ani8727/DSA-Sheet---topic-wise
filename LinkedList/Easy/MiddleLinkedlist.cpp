#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val): data(val),next(NULL){}
};

Node* middleNode(Node* head){
    if(!head){
        cout<<"Empty List"<<endl;
        return head;
    }else if(!head->next){
        cout<<"only single node present : "<<head->data<<"->"<<head->next<<endl;
        return head;
    }else {
        Node* fast=head;
        Node* slow = head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
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
    head = insert(head, 6);
    head = insert(head, 7);


    printList(head);

    Node* middle=middleNode(head);

    cout<<middle->data<<endl;
    return 0;
}