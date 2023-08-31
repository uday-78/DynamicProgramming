#include<iostream>
#include<bits/stdc++.h>

using namespace std;


  /*  
      
  
  
  */


 int getAnsRecursion(int indx ,vector<int>&nums){
     
     //! Here we have return nums[0] because if we are reaching index 0 then it means
     //! we haven't picked index 1 then only we are able to reach index 0 so we will
     //! pick the element at the index 0
     if(indx == 0) return nums[indx];

    //? Here we have return 0 because if index reach goes to out of bound
    //? then we have nothing to pick that's why we would return 0
     if(indx < 0) return 0;

     int pick = nums[indx] + getAnsRecursion(indx-2 ,nums);

     int notPick =  getAnsRecursion(indx-1 , nums);

     return max(pick , notPick);
 }

  int getAnsMemoization(int indx ,vector<int>&nums ,vector<int>&dp){
    
     
     if(indx == 0) return nums[indx];

   
     if(indx < 0) return 0;

     if(dp[indx] != -1) return dp[indx];

     int pick = nums[indx] + getAnsRecursion(indx-2 ,nums);

     int notPick =  getAnsRecursion(indx-1 , nums);

     return dp[indx] =  max(pick , notPick);
  }

   int getAnsTabulation(int indx ,vector<int>&nums ,vector<int>&dp){
      
       dp[0] = nums[0];
        
        int neg = 0;

      for(int i=1; i<nums.size(); i++){
         
         int pick = nums[indx] ;
          
          if(i>1)
          pick += dp[i-2];

         int notPick = dp[i-1];

         dp[i] = max(pick , notPick);
      }

      return dp[nums.size()-1];
   }

  int getAnsSpaceOptimisation(int n , vector<int>&nums){
     
     int prev = nums[0];
     int prev2 = 0;

     for(int i=1; i<n; i++){

        int pick = nums[i];

        if(i>1) pick += prev2;

        int notPick = prev;

        int curr = max(pick,notPick);

        prev2 = prev;
        prev = curr;
     }

      return prev;
  }

int maximumNonAdjacentSum(int n , vector<int>&nums){
     

   return getAnsSpaceOptimisation(n,nums);
   
    //  vector<int>dp(n,-1);
   //return getAnsTabulation(n-1,nums,dp);
   // return getAnsMemoization(n-1,nums,dp);
   // return getAnsRecursion(n-1,nums);
}

int main(){

vector<int>nums {2,1,4,9};

 int n = nums.size();

 cout<<"The Maximum sum of non adjacent elements is "<<maximumNonAdjacentSum(n ,nums);

}