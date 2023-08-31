#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countNthStairsMemoiz(int indx ,vector<int>&dp){
      
      if(indx==0) return 1;
    if(indx==1) return 1;

    if(dp[indx] != -1) return dp[indx];

    int oneStep = countNthStairsMemoiz(indx-1,dp);
    int twoStep = countNthStairsMemoiz(indx-2,dp);

    return dp[indx] =  oneStep + twoStep;
}

int countNthStairsTabulation(int indx ,vector<int>&dp){
     
     dp[0]= 1;
     dp[1]= 1;

     for(int i=2; i<=indx; i++){
        dp[i] = dp[i-1]+dp[i-2];
     }

     return dp[indx];
}

int countNthStairsConstSpace(int indx){
    int prev1 = 1;
    int prev2 = 1;

    int curr = 0;

    for(int i=2; i<=indx; i++){
       curr = prev1+prev2;

       prev2 = prev1;
       prev1 = curr;
    }

    return curr;
}


int main(){

   int n;
   cin>>n;

   vector<int>dp(n+1,-1);

   cout<<"The total no of ways to reach "<<n<<"th stairs are "<<countNthStairsConstSpace(n)<<endl;

}