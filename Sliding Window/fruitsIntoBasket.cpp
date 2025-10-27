// 904. Fruit Into Baskets

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// int maxFruits(vector<int> fruits){
//     int n=fruits.size();
//     unordered_map<int, int> basket;

//     int left=0, right=0, ans=0;

//     while(right<n){
//         basket[fruits[right]]++;

//         while(basket.size()>2){
//             basket[fruits[left]]--;
//             if(basket[fruits[left]]==0){
//                 basket.erase(fruits[left]);
//             }
//             left++;
//         }
//         ans=max(ans,right-left+1);
//         right++;
//     }
//     return ans;
// }

// optimal approach
int maxFruits(vector<int> fruits){
    int n=fruits.size();
    unordered_map<int, int> basket;

    int left=0, right=0, ans=0;

    while(right<n){
        basket[fruits[right]]++;
        if(basket.size()>2){
            basket[fruits[left]]--;
            if(basket[fruits[left]]==0){
                basket.erase(fruits[left]);
            }
            left++;
        }
        if(basket.size()<=2){
            ans=max(ans,right-left+1);
        }
        right++;
    }
    return ans;
}

int main(){
    vector<int> fruits={3,3,3,1,2,4,2,3,3,4};

    int ans=maxFruits(fruits);
    cout<<ans<<endl;

    return 0;
}

