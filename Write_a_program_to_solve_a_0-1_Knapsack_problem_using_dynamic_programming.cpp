#include <iostream>
#include <vector>
using namespace std;

int solveKnapsack(vector<int>& val, vector<int>& wt, int W) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> val = {50, 100, 150, 200};
    vector<int> wt = {8, 16, 32, 40};
    int W = 64;

    int maxVal = solveKnapsack(val, wt, W);
    cout << maxVal << endl;

    return 0;
}


// Time Complexity : O(NxW)
// Space Complexity : O(NxW)



// Second Approach :
   int f(int currW , int wt[] , int val[] , int n , vector<vector<int>>&dp){
        if(n==0){
            return wt[0] <= currW ? val[0] : 0;
        }
        if(currW < 0)return 0;
        
        if(dp[n][currW]!=-1)return dp[n][currW];
        int take = 0;
        int not_take = f(currW , wt , val ,n-1  ,dp);
        if(currW >= wt[n]){
            take = val[n] + f(currW-wt[n] , wt , val, n-1 ,dp);
        }
        return dp[n][currW] =  max(take , not_take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(1001 , vector<int>(1001, -1));
       return f(W , wt , val  , n-1  , dp);
    }