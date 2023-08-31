#include<iostream>
#include<bits/stdc++.h>
using namespace std;

  bool checkPalindrome(string& s , int i){
     
        if(i >= s.size()/2) return true;

       if(s[i] != s[s.size()-i-1]) return false;

       return checkPalindrome(s,i+1);
  }

 void reverseArrayUsingSingle(vector<int>&nums , int indx){

    if(indx >= nums.size()/2) return;

      for(auto it : nums){
          cout<<it<<" ";
      }

     swap(nums[indx],nums[nums.size()-indx-1]);

      cout<<endl;

     reverseArrayUsingSingle(nums,indx+1);
 }

  void reverseArray(vector<int>&nums , int left , int right){
        
        if(left >= right)
        return;

        for(auto it : nums){
          cout<<it<<" ";
         }

        swap(nums[left],nums[right]);


         cout<<endl;

        reverseArray(nums,left+1,right-1);
  }


  int nthFibonacci(int n){
    
      if(n<=1) return n;

      int last = nthFibonacci(n-1);
      int secondLast = nthFibonacci(n-2);

      return last+secondLast;
  }

     void printAll_SubSeq_Sum_K(vector<int>&nums , vector<int>&ans , int i , int k){
       
       //If index reach the end we will got our subsequence so we will check whether it's sum is k or not
        if(i >= nums.size()){
             int sum = accumulate(begin(ans),end(ans),0);
             
             //If sum is equal to k then we will print it
             if(sum == k){
               for(auto it : ans) cout<<it<<" ";
               cout<<endl;
             }

             return ;
        }

        ans.push_back(nums[i]);

        printAll_SubSeq_Sum_K(nums,ans,i+1,k);

        ans.pop_back();

        printAll_SubSeq_Sum_K(nums,ans,i+1,k) ;
    }

    
    //Here if we want to print only one of the subsequence whose sum is k
    bool printSubSeq_Sum_K_OnlyOne(vector<int>&nums , vector<int>&ans , int i , int k){
       
       //If index reach the end we will got our subsequence so we will check whether it's sum is k or not
        if(i >= nums.size()){
             int sum = accumulate(begin(ans),end(ans),0);
             
             //If sum is equal to k then we will print it
             if(sum == k){
               for(auto it : ans) cout<<it<<" ";
               cout<<endl;
               return true;
             }

             return false;
        }

        ans.push_back(nums[i]);


      //The moment we get our subsequence then we will return true we don't need to make further calls
        if(printSubSeq_Sum_K_OnlyOne(nums,ans,i+1,k) == true) return true;

        ans.pop_back();


      //The moment we get our subsequence then we will return true we don't need to make further calls
        if(printSubSeq_Sum_K_OnlyOne(nums,ans,i+1,k) == true) return true;


       //If both condition didn't return true then we will return false
        return false;
    }


    int  count_SubSeq_WithSum_K(vector<int>&nums,int sum, int i , int k){

      /*Here what intution we have used is that if by any recursion call we get our ans
       we will count it in our count so we will return 1 and else 0*/

        if(i>=nums.size()){

           return (sum==k ? 1 : 0);
        }

        sum += nums[i];

        int left = count_SubSeq_WithSum_K(nums,sum,i+1,k);
         
       sum -= nums[i];

        int right = count_SubSeq_WithSum_K(nums,sum,i+1,k);

        return left+right;

    }


   void printAllSubsequence(vector<int>&nums , vector<int>&ans , int i){
      
         if(i >= nums.size()){
            
            for(auto it : ans) cout<<it<<" ";
          
            if(ans.size() == 0) cout<<"{}";
             cout<<endl;

            return;
         }
        

        //Not take the particular index into the subsequence
         printAllSubsequence(nums,ans,i+1);
       //Take the prticular index into the subsequence
         ans.push_back(nums[i]);

         printAllSubsequence(nums,ans,i+1);

  //Since we have taken the index then to try another index we have to remove that index
         ans.pop_back();
   }

int main(){

   //vector<int> nums = {1,2,3,4,5,6};

  //  int left = 0 , right = nums.size() -1 ;
   
  //  reverseArray(nums,left,right);

   //reverseArrayUsingSingle(nums,0);

  //  string s = "madam";

    
  //   (checkPalindrome(s,0)==true ? cout<<"The given string is palindrome" : cout<<"The given string is not palindrome");
    
    //  int n;
    //  cout<<"Enter the value of n ";
    //   cin>>n;
    // cout<<"The " << n <<" Fibonacci number is " <<nthFibonacci(n);

   
    vector<int>nums = {1,2,3};

     vector<int>ans;

     printAllSubsequence(nums,ans,0);

//   vector<int> nums = {1,5, 18, 6, 11, 2, 4}; 
//   vector<int>ans;
//   int K = 6;  

// // printAll_SubSeq_Sum_K(nums,ans,0,K);
//   //printSubSeq_Sum_K_OnlyOne(nums,ans,0,K);
//   cout<<"The total no of subseq are "<<count_SubSeq_WithSum_K(nums,0,0,K);
}