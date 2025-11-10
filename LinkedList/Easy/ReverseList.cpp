// Reverse LinkedList
#include<iostream>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int val){
        data=val;
        next=back=nullptr;
    }
};

Node* addNode(Node* head, int val){
    Node* newNode=new Node(val);
    if(head==nullptr){
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->back=temp;
    return head;
}

void traverse(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

class Solution{
    public:
    // using stack to swap data not actual revesrse link
    // Node* reverse(Node* head){
    //     if(head==nullptr || head->next==nullptr)
    //         return head;
    //     stack<int> st;

    //     Node* temp=head;

    //     while(temp!=nullptr){
    //         st.push(temp->data);
    //         temp=temp->next;
    //     }
    //     temp=head;

    //     while(temp!=nullptr){
    //         temp->data=st.top();
    //         st.pop();
    //         temp=temp->next;
    //     }
    //     return head;
    // }
    
    Node* reverse(Node* head){
        if(head==nullptr || head->next==nullptr)
            return head;
        Node* curr=head;

        while(curr!=nullptr){
            Node* prev=curr->back;  // head/curr -> uska back ko store 
            curr->back=curr->next;  // curr/head -> back(previous)=next(nextNode) ko address
            curr->next=prev;        // jo next node tha vha pe last node ka address

            if(curr->back==nullptr) head=curr;  // ye last par pahuch gya uska track rakhne ke liye head de diya || ya phit curr->back return kar sakte hai

            curr=curr->back;    // ab usko ek step aage karn hai (back=next)ka data hai to back krana hai
        }
        return head;
    }
};

int main(){

    Node* head=new Node(1);
    head=addNode(head,2);
    head=addNode(head,3);
    head=addNode(head,4);
    head=addNode(head,5);

    traverse(head);

    Solution obj;
    head=obj.reverse(head);

    traverse(head);

    return 0;

}