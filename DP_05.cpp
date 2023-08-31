#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 //! This problem is same as the previous lecture 4 problem
 //? lecture 4 problem = Maximum sum of non adjacent elements

 //* The only difference is that in lec4 it is stated that we can't take adjacent
 //* elements but here along with not taking adjacent elements the first and last elements
 //* neighbour of each other.

 //! That means both of them can't be the part of the answer

 //? So to solve this problem what we will do is we will use the same logic of lec 4

 //! We will calculate firstly by sending array and excluding the first element of the array
 //! and then we will calculate ans by sending the array and excluding the last element of array
 //! and finally we will take the maximum of two

 //! **************************************************************************************************

  //? Here while solving dp question in case where we use dp array we generally store ans in the last cell of the array
  //? it is because of the following reason

  //* 1)Sequential problem solving : Since DP involves the solving problem by breaking it into the smaller problem 
  //*  and solving them sequentially and we are mostly interested in the solution of the last sub problem.
  //*  So placing the ans in the last cell aligns us with sequential problem solving

  //? 2) Bottom up approach : Since in this approach we require solving the smaller sub problem first and then 
  //? gradually building the solution for the larger sub problem. In this approach the DP array is often index 
  //? in a way that correspond to the size of the subProblem Since the last cell of the DP array corresponds to 
  //? the largest subproblem (i.e., the entire problem), storing the answer there ensures that you're storing the final result.

  //* 3) Easy retrival : Placing the answer in the last cell makes it easy for the retirval of the answer of the final
  //*  subProblem after all the subProblem have been solved and this can be done without further processing

  //? 4) Clarity and Convention : Using the last cell to store the answer becomes convention over the time.
  //?  Since the last cell of the DP array corresponds to the largest subproblem (i.e., the entire problem),
  //?  storing the answer there ensures that you're storing the final result.

 //! **************************************************************************************************

 long long int getAnsSpaceOptimisation(vector<int>&nums){

    int n = nums.size();
     
     long long int prev = nums[0];
     long long int prev2 = 0;

     for(int i=1; i<n; i++){

        long long int pick = nums[i];

        if(i>1) pick += prev2;

        long long int notPick = prev;

        long long int curr = max(pick,notPick);

        prev2 = prev;
        prev = curr;
     }

      return prev;
  }

long long int houseRobber(vector<int>& House)
{

     if(House.size()==1) return House[0];
         
    vector<int> newArray1(House.begin() + 1, House.end());
    
    House.pop_back();

    return max(getAnsSpaceOptimisation(newArray1) ,getAnsSpaceOptimisation(House));
      
}

int main(){

    vector<int>house = {1,2,2,1};

    cout<<"The maximum loot collected by robber "<<houseRobber(house);

}