#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//! ************************************************************
 
 //? Important problem we must solve to get the thorough understanding
 //? of DP on grids/2D Matrix

  //* --> Count Paths
  //* --> Count Paths with obstacle
  //* --> Minimum path sum
  //* --> Maximum path sum with certain condition
  //* --> Triangle Problem
  //* --> 2 start points

//! ************************************************************

//? In this problem why we are solving using recursion because we are standing at 0,0 and we have to reach
//? at the end and in that way we have to explore all the possible unique path to reach the end.

//* Since we have to explore all the possible path so we will use recursion

//! And to write the recurence relation in case of matrix we can follow the below steps:
     //? 1) Express every thing in terms of row and col
     //? 2) Do all the stuffs
     //? 3) Then sum up all the ways


 //! If while solving any problem we require the use of the previous solution then there is 
 //! always chance of the space optimisation


  //? *********************************************************

  //* Steps to convert the memoiz code to tabulation code

  //* 1) Declare the base case on the DP array

  //* 2) Express all the states in for loop

  //* 3) Copy the recurence & write (don't think here just copy the recurence) 

  //? *********************************************************


  int getAnsRecursion(int row ,int col){

    if(row==0 and col==0) return 1;

    if(row<0 or col<0) return 0;

    int goUp = getAnsRecursion(row-1,col);

    int goRight = getAnsRecursion(row,col-1);

    return goUp + goRight;

    //? TC--> O(2^(m*n))
    //? The above TC is because for every cell in the grid we are exploring two paths so in
    //? total there are m*n cells.

    //* SC--> O(Path length)
    //* This is because in recursion call stack it will store recursion calls corresponding to the path
    //* which we have taken to reach our destination
  }

  int getAnsMemoization(int row , int col ,vector<vector<int>>&dp){

      if(row==0 and col==0) return 1;

	   if(row<0 or col <0) return 0;

	   if(dp[row][col] != -1) return dp[row][col];

	   int goUp = getAnsMemoization(row-1,col,dp);

	   int goRight = getAnsMemoization(row,col-1,dp);

	   return dp[row][col] = goUp + goRight;

       //? TC--> O(m*n)
       //? Because by the use of the DP array there will be that much recursion call which DP array could hold 
       
       //* SC--> O(path length) + O(m*n)
       //* Here we are also using a DP array 
  }

   int getAnsTabulation(int TotalRow ,int TotalCol ,vector<vector<int>>&dp){
       

        for(int row=0; row<TotalRow; row++){
            for(int col=0; col<TotalRow; col++){

                if(row==0 and col==0) dp[row][col]=1;

                else{
                  int goUp = 0 , goRight = 0;

                  if(row>0) goUp = dp[row-1][col];

                  if(col>0) goRight = dp[row][col-1];

                  dp[row][col] = goUp+goRight;

                }
            }
        }

        return dp[TotalRow-1][TotalCol-1];

        //? TC-->O(m*n)
        //? This is because we are only using couple of nested loops for calculating our ans
        //? and we are not using recursion here

        //* SC--> O(m*n)
        //* Here by using for loop we have reduced the use of recursion 

        //! The real meaning of tabulation is to build the answer from bottom that we first build the base
        //! for the house then we start constructing our house on top of that
   }

   int getAnsSpaceOptimisation(int TotalRow , int TotalCol){

       vector<int> prev(TotalCol,0);

       for(int row=0; row<TotalRow; row++){
         vector<int>curr(TotalRow,0);

         for(int col=0; col<TotalCol; col++){
             
             if(row==0 and col==0) curr[col] = 1;

             else{
                 
                 int goUp = 0 , goRight = 0;

                 if(row>0) goUp = prev[col];

                 if(col>0) goRight = curr[col-1];

                curr[col] = goUp+goRight;
             }
         }

           prev = curr;
       }

       return prev[TotalCol-1];
   }

   int mostOptimalAns(int m , int n){
     
      int N = n+m-2;

      int r = m-1;

      double ans = 1;

      for(int i=1; i<=r; i++){
         ans = ans*(N-r+i)/i;
      }

      return (int)ans;
   }

  int uniquePaths(int m , int n){



     // return getAnsRecursion(m-1,n-1);

   //  vector<vector<int>>dp(m,vector<int>(n,-1));

    //  return getAnsMemoization(m-1,n-1,dp);

    //return getAnsTabulation(m,n,dp);

   // return getAnsSpaceOptimisation(m,n);
   
   mostOptimalAns(m,n);
  }

int main(){
  
  int m,n;

  cout<<"Enter the value of m and n";
   cin>>m>>n;

   cout<<"Total no of unique path to reach from (0,0) " << "to "<< "("<<m-1<<","<<n-1<<") "<<"is "<<uniquePaths(m-1,n-1);
}