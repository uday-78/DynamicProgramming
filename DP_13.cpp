#include<bits/stdc++.h>
using namespace std;

/* 
 To solve this problem what we will do is we will generate all the subsequences and check if sum is 
 equal to target or not

 And to generate all the subsequence we can either follow the power set approach or we can use recursion

*/

 //! Thumb rule for writing the recurrence in subsequence or subset problem with target:
//?    Express every thing in terms of target and index
//?    Explore the possibilites on that index
//*    No of states in memoization is equal to the nested loop in tabulation


 bool getAnsRecursion(int indx ,int target ,vector<int>&arr){
     
     if(target==0) return true;

     if(indx==0) return(arr[0]==target);

     bool noTake = getAnsRecursion(indx-1,target,arr);

      bool take = false;

      if(arr[indx]<=target)
       take = getAnsRecursion(indx-1,target-arr[indx],arr);

       return noTake || take;
 }

   bool getAnsMemoization(int indx ,int target ,vector<int>&arr ,vector<vector<int>>&dp){
      
       
     if(target==0) return true;

     if(indx==0) return(arr[0]==target);

     if(dp[indx][target] != -1) return dp[indx][target];

     bool noTake = getAnsMemoization(indx-1,target,arr,dp);

      bool take = false;

      if(arr[indx]<=target)
       take = getAnsMemoization(indx-1,target-arr[indx],arr,dp);

       return dp[indx][target] =  noTake || take;
   }

    bool getAnsTabulation(int n ,int k ,vector<int>&arr ,vector<vector<int>>&dp){
         
         for(int i=0; i<n; i++) dp[i][0] = true;

         if(arr[0]<=k)dp[0][arr[0]] = true;

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

bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>>dp(n,vector<int>(k+1,-1));
   
   //return getAnsRecursion(n-1,k,arr);

   //return getAnsMemoization(n-1,k,arr,dp);

   return getAnsTabulation(n,k,arr,dp);
}


int main(){

    vector<int>arr = {1,2,3,4};

    int target = 4;

    (subsetSumToK(arr.size(),target,arr)==true ? cout<<"Subset with sum target exist" : cout<<"Subset with sum target don't exist");

}



