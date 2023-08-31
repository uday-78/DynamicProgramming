#include<bits/stdc++.h>
using namespace std;

bool getAnsRecursion(int indx, int n, int sumPart1, vector<int>& arr) {
    if (indx == n) {
        int diff = abs(sumPart1 - (accumulate(arr.begin(), arr.end(), 0) - sumPart1));
        return diff == 0;
    }


    bool includeInPart1 = getAnsRecursion(indx + 1, n, sumPart1 + arr[indx], arr);
    bool includeInPart2 = getAnsRecursion(indx + 1, n, sumPart1, arr);

    return includeInPart1 || includeInPart2;
}

 bool getAnsMemoization(int indx, int n, int sumPart1, vector<int>& arr, vector<vector<int>>& dp) {
    if (indx == n) {
        int diff = abs(sumPart1 - (accumulate(arr.begin(), arr.end(), 0) - sumPart1));
        return diff == 0;
    }

    if (dp[indx][sumPart1] != -1) return dp[indx][sumPart1];

    bool includeInPart1 = getAnsMemoization(indx + 1, n, sumPart1 + arr[indx], arr, dp);
    bool includeInPart2 = getAnsMemoization(indx + 1, n, sumPart1, arr, dp);

    return dp[indx][sumPart1] = includeInPart1 || includeInPart2;
}

  bool getAnsTabulation(int n ,int k ,vector<int>&arr ,vector<vector<int>>&dp){
         
         for(int i=0; i<n; i++) dp[i][0] = true;

         if(arr[0]<=k) dp[0][arr[0]] = true;

         for(int indx=1; indx<n; indx++){
            for(int target = 1; target<=k; target++){

                  bool noTake = dp[indx-1][target];

                   bool take = false;

              if(arr[indx]<=target)
              take = dp[indx-1][target-arr[indx]];

              dp[indx][target] =  noTake || take;
            }
         }

         return dp[n-1][k];
    }


bool canPartition(vector<int>& arr, int n) {

    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if (totalSum % 2 != 0) return false;

    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

    int sumPart1 = 0;

   //return getAnsRecursion(0, n, sumPart1, arr);

   //return getAnsMemoization(0,n,sumPart1,arr,dp);

   return getAnsTabulation(n,totalSum/2 ,arr,dp);
}

int main(){

    vector<int>arr = {2,3,3,3,4,5};
    int n = arr.size();

    (canPartition(arr,n)==true ? cout<<"We can partition in two subset with equal sum" : cout<<"We can't make partiton with equal sum");

}