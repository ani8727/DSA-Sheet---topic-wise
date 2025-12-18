// 23. Merge k Sorted Lists

#include<iostream>
#include<vector>
#include<algorithm>
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

Node* makeList(vector<int>nums){
    Node* head=new Node(nums[0]);
    Node* temp=head;
    for(int i=1;i<nums.size();i++){
        Node* newNode=new Node(nums[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}

void traverse(vector<Node*> list){
    for(Node* head: list){
        while(head){
            cout<<head->data<<" ";
            head=head->next;
        }cout<<endl;
    }
}

Node* MergeSort(vector<Node*> list){
    
    vector<int> nums;
    for(Node* head: list){
        while(head){
            nums.push_back(head->data);
            head=head->next;
        }
    }
    sort(nums.begin(),nums.end());

    Node* head=new Node(nums[0]);
    Node* temp=head;
    for(int i=1;i<nums.size();i++){
        Node* newNode=new Node(nums[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    return head; 
}

int main(){
    vector<Node*> list;
    vector<vector<int>> nums={{1,4,5},{1,3,4},{2,6}};

    for(vector<int> num: nums){
        Node* head=makeList(num);
        list.push_back(head);
    }
    traverse(list);

    Node* head=MergeSort(list);

    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;                                                                                         

    return 0;
}