#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter left child of " <<root->data <<": ";
    root->left = buildTree(root->left);
    cout << "Enter right child of "<< data << ":";
    root->right = buildTree(root->right);

    return root;
}

void levelTraversal(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // Complete current level
            cout << endl;
            if (!q.empty()) {
                // Queue still has some child Nodes
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Level wise traversal - BFS
// right side view 
// vector<int> rightSide(Node* root){
//       vector<int> ans;
//       if(!root){
//         return {};
//       }
//       queue<Node*> q;
//       q.push(root);

//       while(!q.empty()){
//         int n=q.size();
//         Node* curr=NULL;
//         while(n--){
//             curr=q.front();
//             q.pop(); 

//             if(curr->left){
//                 q.push(curr->left);
//             }
//             if(curr->right){
//                 q.push(curr->right);
//             }  
//         }
//         ans.push_back(curr->data);
//       }
//       return ans;      
// }

void DFS(Node* root, vector<int>& ans, int level){
     if(!root) return;
     int n=ans.size();
     if(n<level){
        ans.push_back(root->data);
     }
     DFS(root->right,ans,level+1);
     DFS(root->right,ans,level+1);
}
vector<int> rightSide(Node* root){
    vector<int> ans;
    DFS(root,ans,1);

    return ans;
}

int main() {
    Node* root = NULL;

    // Creating a tree
    root = buildTree(root);
    
    levelTraversal(root);

    vector<int> ans=rightSide(root);

    for(int i: ans){
        cout<<i<<" ";
    }

    return 0;
}
