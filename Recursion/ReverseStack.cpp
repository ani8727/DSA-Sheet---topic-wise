//  reverse Stack 
#include<iostream>
#include<stack>
using namespace std;

// void insert(stack<int>& st, int top){
//     if(!st.empty()){
//         stack<int> temp;
//         while(!st.empty()){
//             temp.push(st.top());
//             st.pop();
//         }
//         st.push(top);
//         while(!temp.empty()){
//             st.push(temp.top());
//             temp.pop();
//         }
//     }else{
//         st.push(top);
//     }   
// }

void insert(stack<int>& st, int bottom){
    if(!st.empty()){
        int top=st.top();
        insert(st,bottom);
        st.push(top);
    }else{
        st.push(bottom);
    }
}

void reverse(stack<int>& st){
    if (st.empty()) return;
    int top=st.top();
    st.pop();
    reverse(st);
    insert(st,top);
}

int main(){
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    // while(!st.empty()){
    //     cout<<st.top();
    //     st.pop();
    // }cout<<endl;

    reverse(st);

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }cout<<endl;

    return 0;
}
