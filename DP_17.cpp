#include<bits/stdc++.h>
using namespace std;


 int MOD = 1e9+7;

 int getAnsTabulation(int n ,int k
 ,vector<int>&arr,vector<vector<int>>&dp){

    for (int i = n-1; i >=0 ; i--) {
        dp[n-1][i] = 1;
    }

	 for(int indx=n-2; indx>=0; indx--){
		 for(int target=1; target<=k; target++){

			 int includeIndx = 0;

         if(arr[indx]<=target) 
	     includeIndx = dp[indx+1][target-arr[indx]];


	  int notIncludeIndx = dp[indx+1][target];

	  dp[indx][target] =  (includeIndx+notIncludeIndx)%MOD;
		 }
	 }

	 return dp[0][k]%MOD;
 }

 int getAnsRecursion(int indx ,int n ,int target
  ,vector<int>&arr,vector<vector<int>>&dp){
	  
	  if(indx==n){

		  if(target==0) return 1;

		  return 0;
	  }

	  if(dp[indx][target] != -1) return dp[indx][target];

	  int includeIndx = 0;

     if(arr[indx]<=target) 
	 includeIndx = getAnsRecursion(indx+1,n,target-arr[indx],arr,dp);


	  int notIncludeIndx = getAnsRecursion(indx+1,n,target,arr,dp);

	  return dp[indx][target] =  (includeIndx+notIncludeIndx)%MOD;
 }


int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	int sum = 0;
    

     vector<vector<int>>dp(n ,vector<int>(k+1,0));

	return getAnsTabulation(n,k,arr,dp)%MOD;
}


int main(){

    vector<int>arr = {1,1,1};

    int k = 3;

    cout<<"Total no of subset with sum "<<k << " is "<<findWays(arr,k);

}