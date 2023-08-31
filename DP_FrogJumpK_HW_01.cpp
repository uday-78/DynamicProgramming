#include<iostream>
#include<bits/stdc++.h>

using namespace std;

  int getAns(int indx , int k , vector<int>&height){

     if(indx==0) return 0;

    int minSteps = INT_MAX;

    for(int jump=1; jump<=k; jump++){
         
        if(indx-jump >= 0 ){

             
    //? Here in this line what we are doing is that by standing at indx we are trying to make
   //? all the k jumps and trying to find the minimum among that and storing it in the ans
     int jumps = getAns(indx-jump ,k , height) + abs(height[indx]-height[indx-jump]);

             minSteps = min(minSteps , jumps);
        } 
    }

    return minSteps;
  }

  int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      int jump = solveUtil(ind-j, height, dp, k)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
    
}

int frogHeightK(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n-1, height, dp, k);
}

int main(){

    int n , k;

   cout<<"Enter the value of k ";
    cin>>k;

   vector<int> height = {30,10,60 , 10 , 60 , 50};

     n = height.size();

  cout<<"The ans is "<<frogHeightK(n,height,k);

}