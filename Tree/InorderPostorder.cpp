//  106. Construct Binary Tree from Inorder and Postorder Traversal

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(NULL), right(NULL){}
};

int find(vector<int>& inorder, int Istart, int Iend, int target){
    for(int i=Istart; i<=Iend; i++){
        if(inorder[i]==target){
            return i;
        }
    }
    return -1;
}

Node* builTree(vector<int>& postorder, vector<int>& inorder, int& idx, int Istart, int Iend){
    if(Istart>Iend) return NULL;

    Node* root=new Node(postorder[idx]);

    int pos=find(inorder,Istart,Iend,postorder[idx]);

    idx--;

    root->right=builTree(postorder,inorder,idx,pos+1,Iend);

    root->left=builTree(postorder,inorder,idx,Istart,pos-1);

    return root;
}

vector<int> traverse(Node* root) {
    if (!root) return {};

    vector<int> ans;
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
            ans.push_back(-1);
        }
    }

    // Remove trailing -1
    while (!ans.empty() && ans.back() == -1) {
        ans.pop_back();
    }

    return ans;
}


int main(){
    cout<<"No of nodes: ";
    int n;
    cin>>n;
    vector<int> postorder(n);
    vector<int> inorder(n);
    cout<<"Enter postorder nodes:"<<endl;
    for(int i=0;i<n;i++){
        cin>>postorder[i];
    }
    cout<<"Enter inorder nodes: "<<endl;
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }

    Node* root=NULL;

    int idx=postorder.size()-1;
    int Istart=0;
    int Iend=inorder.size()-1;

    root=builTree(postorder,inorder,idx,Istart,Iend);

    vector<int> ans=traverse(root);

    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}