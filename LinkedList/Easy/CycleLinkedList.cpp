// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

#include<iostream> 
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value): data(value), next(NULL){}
};

Node* isCycle(Node* head){
    if(!head || !head->next) return NULL;
    Node* slow=head;
    Node* fast=head;
    bool isTrue=false;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            isTrue=true;
            break;
        }
    }
    if(!isTrue) return NULL;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}
Node* insert(Node* head, int value){
    Node* newNode=new Node(value);
    if(!head){
        return newNode;
    }else{
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newNode;
        return head;
    }
}

void display(Node* head){
    if(!head) cout<<"List Empty!"<<endl;
    else{
        Node* temp=head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;
        }cout<<"NULL"<<endl;
    }
}

 int main(){
    Node* head=NULL;
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=insert(head,5);
    head->next->next->next->next=head->next->next;

    // display(head);

    Node* loopNode = isCycle(head);

   if(loopNode){
      cout<<loopNode->data<<endl;
   }else{
    cout<<"Cycle not found"<<endl;
   }
    

    return 0;


 }