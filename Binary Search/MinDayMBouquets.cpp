// 1482. Minimum Number of Days to Make m Bouquets

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Check if we can make m bouquets on a given day
bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
    int bouquets = 0, flowers = 0;

    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= day) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
            }
        } else {
            flowers = 0; 
        }
    }
    return bouquets >= m;
}

// Brute Force – Check all days linearly
// int minDays(vector<int>& bloomDay, int m, int k) {
//     long long total = 1LL * m * k;
//     if (total > bloomDay.size()) return -1;

//     int minDay = *min_element(bloomDay.begin(), bloomDay.end());
//     int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

//     for (int day = minDay; day <= maxDay; day++) {
//         if (canMakeBouquets(bloomDay, m, k, day))
//             return day;
//     }
//     return -1;
// }

// optimal appraoch - log n
int minDays(vector<int>& bloomDay, int m, int k) {
    long long total = 1LL * m * k;
    if (total > bloomDay.size()) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canMakeBouquets(bloomDay, m, k, mid)) {
            ans = mid;
            high = mid - 1; // try smaller days
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3; // number of bouquets
    int k = 1; // flowers needed per bouquet

    cout << "Minimum days to make bouquets: " << minDays(bloomDay, m, k) << endl;
    return 0;
}
