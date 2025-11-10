// 2. Add Two Numbers
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

Node* addTwoNum(Node* head1, Node* head2){
    Node dummy(0);
    Node* curr=&dummy;

    int carry=0;

    while(head1 || head2 || carry){  // atleast ek null na ho
        int sum=carry;  // carry ko add karo

        if(head1){ // head1 null nhi hai
            sum+=head1->data;  // data add karo
            head1=head1->next; // move kar do
        }
        if(head2){  // head2 null nhi hai
            sum+=head2->data;  // data ko add karo
            head2=head2->next;
        }
        // check karo ki double digit na ho agar hai to carry add kar lo
        carry=sum/10; // agar mila to next step ke liye store kar lo
        // add kar lo uske one digit ko dummy ke address par
        curr->next=new Node(sum%10);
        curr=curr->next;
    }
    return dummy.next;
}

int main(){
    Node* head1=new Node(2);
    head1->next=new Node(4);
    head1->next->next=new Node(5);

    Node* head2=new Node(5);
    head2->next=new Node(6);
    head2->next->next=new Node(4);

    Node* ans=addTwoNum(head1,head2);

    while(ans!=nullptr){
        cout<<ans->data<<" ";
        ans=ans->next;
    }
    return 0;
}