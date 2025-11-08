// Singly List
#include<iostream>
#include<vector>
using namespace std;

// create a single list
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};

class Solution{
    public:
    // array to list
    Node*  arrayToList(vector<int> nums){
        Node* head=new Node(nums[0]);
        Node* mover=head;
        for(int i=1;i<nums.size();i++){
            Node* temp=new Node(nums[i]);
            mover->next=temp;
            mover=temp;
        }
        return head;
    }

    // tarverse to count length and print
    int traverse(Node* head){
        Node* temp=head;
        int count=0;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            count++;
            temp=temp->next;
        }
        cout<<endl;
        return count;
    }
};

int main(){
    vector<int> nums={4,6,3,1,5,0};

    Solution obj;
    
    Node* head=obj.arrayToList(nums);

    cout<<head->data<<endl;

    int length=obj.traverse(head);
    cout<<length<<endl;

    return 0;

}