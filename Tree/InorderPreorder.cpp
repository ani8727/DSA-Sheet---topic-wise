// 105. Construct Binary Tree from Preorder and Inorder Traversal

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(NULL) ,right(NULL){}
};
// find root postion in inorder
int find(vector<int>& inorder, int Istart, int Iend, int target){
    for(int i=Istart; i<=Iend; i++){
        if(inorder[i]==target){
            return i;
        }
    }
    return -1;
} 
// built tree
Node* builtTree(vector<int>& preorder, vector<int>& inorder, int& idx, int Istart, int Iend){
    if(Istart>Iend) return NULL;

    Node* root=new  Node(preorder[idx]);

    int pos=find(inorder, Istart, Iend, preorder[idx]);

    idx++;

    root->left=builtTree(preorder,inorder,idx,Istart,pos-1);

    root->right=builtTree(preorder,inorder,idx,pos+1,Iend);

    return root;
}
// store tree node in vactor inform of level order

void traverse(Node* root, vector<int>& ans) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr) {
            ans.push_back(curr->data);
            q.push(curr->left); 
            q.push(curr->right);
        } else {
            if(!q.empty())
               ans.push_back(-1);
        }
    }
    while(!ans.empty() && ans.back()==-1){
        ans.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> preorder(n);
    vector<int> inorder(n);
    cout<<"Enter preorder element: "<<endl;
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    cout<<"Enter inorder element: "<<endl;
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }

    Node* root=NULL;

    int idx=0;
    int Istart=0;
    int Iend=inorder.size()-1;

    root=builtTree(preorder,inorder,idx,Istart,Iend);

   vector<int> ans;

   traverse(root,ans);

   for(int i:ans){
    cout<<i<<" ";
   }cout<<endl;
    
   return 0;

}