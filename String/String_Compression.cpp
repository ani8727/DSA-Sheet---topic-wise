#include <iostream>
#include <vector>
using namespace std;

// we can use extra space
// int compression(vector<char> &chars)
// {
//     vector<char> ans;
//     int sum = 1;
//     for (int i = 1; i < chars.size(); i++)
//     {
//         if (chars[i - 1] == chars[i])
//         {
//             sum++;
//         }
//         else
//         {
//             ans.push_back(chars[i - 1]);
//             if (sum > 1)
//             {
//                 string cnt = to_string(sum);
//                 for (char c : cnt)
//                 {
//                     ans.push_back(c);
//                 }
//             }
//             sum = 1;
//         }
//     }
//     ans.push_back(chars[chars.size() - 1]);
//     if (sum > 1)
//     {
//         string cnt = to_string(sum);
//         for (char c : cnt)
//         {
//             ans.push_back(c);
//         }
//     }
//     for (char &ch : ans)
//     {
//         cout << ch << " ";
//     }
//     cout << endl;
//     return ans.size();
// }

// without using extra space 
    int compression(vector<char>& chars) {
        int n=chars.size();
        int sum=1;
        int j=0;
        int i=0;
        while(i<n){
            char curr=chars[i];
            int count=0;

            while(i<n && curr==chars[i]){
                count++;
                i++;
            }
            chars[j++]=curr;
            if(count>1){
                string cnt = to_string(count);
                for(char ch: cnt){
                    chars[j++]=ch;
                }
            }
        }
    for (char &ch : chars)
    {
        cout << ch << " ";
    }
    cout << endl;
    return j;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int result = compression(chars);

    cout << result;

    return 0;
}