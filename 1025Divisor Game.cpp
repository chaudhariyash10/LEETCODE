#include<bits/stdc++.h>
using namespace std;

// class Solution {
    

// public:
//     bool divisorGame(int N) {
//         bool dp[N + 1];
//         dp[0] = false;
//         dp[1] = false;
//         dp[2] = true;
//         dp[3] = false;
//         dp[4] = true;

//         for (int i = 5; i <= N; i++)
//         {
//             for (int j = i - 1; j >= 1; j--)
//             {
//                 if(i % j == 0 && dp[i -j] == false)
//                 {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }

//         return dp[N];
//     }
// };


class Solution {

    unordered_map<int, char> umap;

public:
    bool divisorGame(int N) {
       if(N <= 1)
           return false;

       if(umap[N] == 'f')
           return false;
       else if(umap[N] == 't')
           return true;

       for (int i = 1; i <= N / 2; i++)
        {
            if(N % i == 0)
            {
                if(!divisorGame(N - i)){
                    umap[N - i] = 't';
                    return true;
                }
            }
        }

        umap[N] = 'f';
        return false;
    }
};