#include<bits/stdc++.h>
using namespace std;


//* This question is different from the previous one is that here the end point is variable

//! ************************************************

//* Thumb Rule : Whatever we write for recursion will be opposite for the tabulation

//? Important Point : Whenever we are writing the tabulation code the first step we must do
//?                   is look at recurrence parameter in the recursion and try to write the 
//?                   for loop in their terms.

//*  That for a given parameter how the other parameter is changing i.e for given parameter i
//*  what are the possible values for j

//? And here we are not starting from the bottom row as we used to do in earlier problem
//? because here the end point in the bottom row is variable so earlier since our ending 
//? point is fix we were only making one recursion call.

//?    But here since there no fix ending point available we will have to make no
//?   of recursion call equal to no of ending point but that is not possible. So that's why 
//?  we are starting from top row as there is only one element and starting pt is fix so we will
//?  only have to make one recursion call

//! ************************************************

//* Tip : To understand the space optimisation better what we can do is we should
//*       do a dry run of the tabulation for loops 


  int getAnsRecursion(int row , int col ,int n ,vector<vector<int>>&triangle){
      
      if(row==n-1) return triangle[row][col];

      int goDownCost = triangle[row][col] + getAnsRecursion(row+1,col,n,triangle);

      int goDiagonalCost = triangle[row][col] + getAnsRecursion(row+1,col+1,n,triangle);

      return min(goDownCost,goDiagonalCost);

      //? TC --> O(2^(n*n)) this is because we have n rows and for every row we have 2 options for its all the 
      //?        column elements

      //* SC --> O(N) it is the recursive call space
  }

    int getAnsMemoization(int row , int col , int n ,vector<vector<int>>&triangle,vector<vector<int>>&dp){
     
	 if(row == n-1) return triangle[row][col];

	 if(dp[row][col] != -1) return dp[row][col];

	 int goDownCost = triangle[row][col] + getAnsMemoization(row+1,col,n,triangle,dp);

	 int goDiagonalCost = triangle[row][col] + getAnsMemoization(row+1,col+1,n,triangle,dp);

	 return dp[row][col] =  min(goDiagonalCost,goDownCost);

     //? TC --> O(n*n) 
     //* SC --> O(N) + O(n*n) because here we are using DP array 
   }

   int getAnsTabulation(int n ,vector<vector<int>>&triangle,vector<vector<int>>&dp){
       
       for(int col=0; col<n; col++){
          dp[n-1][col] = triangle[n-1][col];
       }


        for(int row=n-2; row>=0; row--){
            for(int col=row; col>=0; col--){
             
             int goDownCost = triangle[row][col] + dp[row+1][col];

	       int goDiagonalCost = triangle[row][col] + dp[row+1][col+1];

	        dp[row][col] =  min(goDiagonalCost,goDownCost);

            }
        }

        return dp[0][0];

        //? TC --> O(n*n) 
     //* SC -->  O(n*n) because here we are not using recursion
   }

    int getAnsSpaceOptimisation(int n ,vector<vector<int>>&triangle){

        vector<int>front(n,0),curr(n,0);

         for(int col=0; col<n; col++){
          front[col] = triangle[n-1][col];
       }

        for(int row=n-2; row>=0; row--){
            for(int col=row; col>=0; col--){
              
            int goDownCost = triangle[row][col] + front[col];
 
	          int goDiagonalCost = triangle[row][col] + front[col+1];

	         curr[col] =  min(goDiagonalCost,goDownCost);

            }

            front = curr;
        }

        return front[0];
    }
  

 int minimumPathSum(vector<vector<int>>& triangle, int n){
	
    //return getAnsRecursion(0,0,n,triangle);

   // vector<vector<int>>dp(n,vector<int>(n,-1));

   // return getAnsMemoization(0,0,n,triangle,dp);

   //return getAnsTabulation(n,triangle,dp);

   return getAnsSpaceOptimisation(n,triangle);
}

int main(){

    vector<vector<int>>triangle ={{1},{2,3},{3,6,7},{8,9,6,10}};

    int n = triangle.size();

    cout<<"The minimum path sum is "<<minimumPathSum(triangle,n);

}