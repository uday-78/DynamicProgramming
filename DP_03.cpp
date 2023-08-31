#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*

      Since Tabulation process is bottom up approach and the real menaning of the bottom up approach is
      to build the solution from scratch just like how we build our house that firstly we build the base 
      upon which our house will stand then upon that base we start building our house.
            In the similar way in tabulation we firstly use the base case to form the base of our
            answer then take the help of loop to build the answer.


        And to write the for loop in tabulation what we can do is after forming the base look at the 
        paramters of the memoiz code and check which of them are changing and try to know how their value
        will change in the opposite manner i.e means if recursion is going from 0 to n-1 then try to know
        the behaviour of the changing parameter values from n-2 to 0 because at n-1 it is the base case 


        And also no of loops in the tabulation will be equal to the no of changin parameters in the memoiz
        code


        And always remember the way of writing the recurence relation taught by striver bhaiya that
         1) Always try to represent the problem in terms of index(And in this we also write the base case for recursion 
         and it can be of two type : 
         
         (1a) Destination base case where we write what will happen when we reach our ans and also keep in mind try to 
             think about the various possibilites of writing the base case

         (1b) Out of bound here suppose if we are solving the question using some particular DS then in this condition
            we would write that possibilites when by doing any operation or by parameters which are used in the 
            recursion call can lead to the unwanted behaviour in that DS.

            Just like in array index get out of bound or in stack if it becomes empty or anything

         2) Explore all the possible states / paths (Generally in this step what we tend to do is
          perform the necessary action which has been ask by question)

         3) return what the question has asked to us    

*/


//! Important note about this problem

 //* Here in this problem since we are asked to find the min energy from going from 1 to N so in
 //* this case what we can do is we can use greedy approach

 //? that we can jump to the min diff energy step but there is problem in this
 //? that since here we have been asked to find the min energy among all possible ways 
 //? so it is might possible that we might miss some case that can give wrong answer

 //! That greedy doesn't count for all possible ways 

  int getAns(int n , vector<int>&height){

    //? Here we have return zero because this function asks us to return the min energy 
   //?  going from 0 to n so going from 0 to 0 requires energy 0
    if(n==0) return 0;

     int left = getAns(n-1,height)+ abs(height[n]-height[n-1]);
    
    int right = INT_MAX;

     if(n>1)
     right = getAns(n-2 ,height)+abs(height[n]-height[n-2]);

     return min(left,right);
  }

  

  int getAnsMemoiz(int n ,vector<int>&height , vector<int>&dp){

    if(n==0) return 0;

     if(dp[n] != -1) return dp[n];

     int left = getAnsMemoiz(n-1,height,dp)+ abs(height[n]-height[n-1]);
    
    int right = INT_MAX;

     if(n>1)
     right = getAnsMemoiz(n-2 ,height,dp)+abs(height[n]-height[n-2]);

     return dp[n] =  min(left,right);
  }

    int getAnsTabulation(int n , vector<int>&dp , vector<int>&height){
       
        dp[0] = 0;
        
        for(int i=1; i<n; i++){
           
           int oneStep = dp[i-1] + abs(height[i]-height[i-1]);

           int twoStep = INT_MAX;

           if(i>1)
            twoStep = dp[i-2] + abs(height[i]-height[i-2]);

            dp[i] = min(oneStep,twoStep);
        }

        return dp[n-1];
    }

    
    int getAnsSpaceOptimise(int n , vector<int>&height){
       
        //! If we have index-1 or index-2 there will always be space optimisation

        int prev1 = 0 , prev2 = 0;

        for(int i=1; i<n; i++){
           
           int oneStep = prev1 +  abs(height[i]-height[i-1]);

           int secondStep = INT_MAX;

           if(i>1)
           secondStep = prev2 + abs(height[i]-height[i-2]);

           int curr = min(oneStep ,secondStep);

           prev2 = prev1;
           prev1 = curr;
        }

        return prev1;
    }


 int frogHeight(int n , vector<int>&height,vector<int>&dp){

    // return getAns(n , height);
    // return getAnsMemoiz(n,height,dp);
    // return getAnsTabulation(n,dp,height); 
    return getAnsSpaceOptimise(n,height);
 }


int main(){

  int n;
  cout<<"Enter the value of n ";
  cin>>n;

   vector<int>heights = {10,20,30,40};

  vector<int>dp(n+1 , -1);

  cout<<"The min energy to go from 1 to " <<n<<" is " <<frogHeight(n,heights,dp);

}