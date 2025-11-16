// 109. Convert Sorted List to Binary Search Tree

#include<iostream>
#include<vector>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int val){
        data=val;
        next=nullptr;
    }
};

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data=val;
        left=right=nullptr;
    }
};

ListNode* makeList(vector<int>& nums){
    ListNode* head=new ListNode(nums[0]);

    ListNode* temp=head;
    for(int i=1;i<nums.size();i++){
        ListNode* newNode=new ListNode(nums[i]);
        temp->next=newNode;
        temp=temp->next;
    }
    return head;
}

void ListTraverse(ListNode* head){
    ListNode* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;

}
TreeNode* listToBst(ListNode* head){
    if(!head) return nullptr;
    if(!head->next) return new TreeNode(head->data);

    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=nullptr;

    while(fast && fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    // slow -> middle = root
    TreeNode* root = new TreeNode(slow->data);

    prev->next=nullptr;
    root->left=listToBst(head);
    root->right=listToBst(slow->next);

    return root;
}

void treeTraverse(TreeNode* root){
    if(!root) return;
    else{
        cout<<root->data<<" ";
        treeTraverse(root->left);
        treeTraverse(root->right);
    }
}

int main(){
    vector<int> nums={-10,-3,0,5,9};
    ListNode* head=makeList(nums);
    ListTraverse(head);

    // make treeNode
    TreeNode* root=nullptr;
    root=listToBst(head);
    treeTraverse(root);

    return 0;

}