#include<iostream>
#include<bits/stdc++.h>
using namespace std;

  void findAllCombination(int indx ,vector<int>&arr,int target ,vector<vector<int>>&ans,vector<int>&temp){
      
      if(target == 0){
        ans.push_back(temp);
        return;
      }

      //! Explanation for if(i>indx and arr[i]==arr[i-1]) continue

      //* Here by first condition we are checking that we should not select the index from which 
      //* we are starting that is indx and if we don't do this then we would have consider the same
      //* element twice

      //? Here by second condition we are checking that we should not select the duplicate number and
      //? by doing this we can avoid duplicate in our combination

      

      for(int i = indx; i < arr.size(); i++){
          if(i>indx and arr[i]==arr[i-1]) continue;

          if(arr[i] > target) break;

          temp.push_back(arr[i]);

          findAllCombination(i+1,arr,target-arr[i],ans,temp);

          temp.pop_back();
      }

  }

 vector<vector<int>> getAllCombinations(vector<int>&arr, int target){
     
     vector<vector<int>>ans;
     vector<int>temp;

    //! Here we have sorted the vector because we want our combination to be in sorted order
     sort(begin(arr),end(arr));

     findAllCombination(0,arr,target,ans,temp);

     return ans;
 }

   void getAllSubsetSum(int indx,int sum ,vector<int>&nums , vector<int>&ans){
       
       if(indx >= nums.size()){
         ans.push_back(sum);
         return;
       }

      getAllSubsetSum(indx+1,sum+nums[indx],nums,ans);

       getAllSubsetSum(indx+1,sum,nums,ans);
   }

   vector<int> findAllSubsetSum(vector<int>&nums){
      vector<int> ans;
       
       getAllSubsetSum(0,0,nums,ans);


     sort(begin(ans),end(ans));
      return ans;
   }


int main(){
    
    vector<int>nums = {1,2,3};
  //   int target = 8;

  //   vector<vector<int>>ans = getAllCombinations(nums,target);

  //   cout<<"All the unique combinations subsequence are " ;

  //  cout<<"[ ";
  //   for(int i=0; i<ans.size(); i++){
  //       cout<<"{";
  //       for(int j=0; j<ans[i].size(); j++){
  //          (j==ans[i].size()-1 ? cout<<ans[i][j]:cout<<ans[i][j]<<",");
  //       }
  //       cout<<"}";
  //   }
  //   cout<<" ]";

   
    //  vector<int> nums = {3,1,2};

     

     vector<int> ans = findAllSubsetSum(nums);

     cout<<"All the subset sum are ";

     cout<<"{";
     for(int i=0; i<ans.size(); i++){
       (i==ans.size()-1 ? cout<<ans[i] : cout<<ans[i]<<",");
     }
    cout<<"}";

    // vector<int>nums = {3,1,2}; 
    // int n = nums.size();

    // cout<<"All the subset sum are ";

    // cout<<"{";
    //  findSubsetSum(nums,n,0,0);
    //  cout<<"}";

}