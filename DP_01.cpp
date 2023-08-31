#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int nthFibbonacciMemoiz(int n ,int dp[]){

   //! In memoization we save the value of our sub problem and check if the sub problem
   //! is already solved or not if yes then we will directly return the solution 

    if(n<=1) return n;

    if(dp[n] != -1) return dp[n];


    return dp[n] =  nthFibbonacciMemoiz(n-1,dp) + nthFibbonacciMemoiz(n-2,dp);
}

int nthFibbonacciTabulation(int n ,int dp[]){

   //* In Tabulation we first analyse the base case that which value is it returning
   //* and then starting from that value we will fill our dp array
   //? Then we will gradually go towards the solution for the given problem 
   
   dp[0] = 0;
   dp[1] = 1;

   for(int i=2; i<=n; i++){
     dp[i] = dp[i-1]+dp[i-2];
   }

   return dp[n];
}


int main(){
  
  int n;
  cout<<"Enter the value of n ";
  cin>>n;

  int dp[n+1];
   memset(dp,-1,sizeof(dp));

   cout<<"The "<<n<<"th "<<"fibbonacci is " ;
    cout<<nthFibbonacciTabulation(n,dp);
}