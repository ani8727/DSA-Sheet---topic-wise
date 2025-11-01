// Nth Root of a Number using Binary Search

#include<iostream>
#include<cmath>
using namespace std;

// brute force appraoch - n
// int nthRoot(int n, int m){
//     for (int i = 1; i <= m; i++) {
//             long long power = pow(i, n);
//             if (power == m) return i;
//             if (power > m) break;
//         }
//         return -1;
// }

// optimal appraoch- logn
 int nthRoot(int n, int m) {
         int low = 1, high = m;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long ans = 1;

        // Compute mid^n safely (and stop early if it exceeds m)
        for (int i = 0; i < n; i++) {
            ans *= mid;
            if (ans > m) break;
        }

        if (ans == m) return mid;       // Found exact nth root
        else if (ans < m) low = mid + 1; // Move right
        else high = mid - 1;             // Move left
    }

    return -1; // No integer nth root exists
}

int main(){
    int n,m;
    cout<<"n: ";
    cin>>n;
    cout<<"m: ";
    cin>>m;

    cout<<nthRoot(n,m);
    return 0;
}
