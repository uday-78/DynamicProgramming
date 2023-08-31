#include<bits/stdc++.h>
using namespace std;


//! ********************************************

//* We can only apply greedy when the values have uniformity that means
//* either the values are increasing or decreasing

//! ********************************************

//? All the TC will remain same as that of previous question
    
  int getAnsRecursion(int row , int col ,vector<vector<int>>&grid){
     
     if(row==0 and col==0) return grid[row][col];

     if(row<0 or col<0) return INT_MAX;

      int goUpCost=INT_MAX,goLeftCost=INT_MAX;

      if(row>0) goUpCost = grid[row][col]+getAnsRecursion(row-1,col,grid);

      if(col>0) goLeftCost = grid[row][col] + getAnsRecursion(row,col-1,grid);

      return min(goLeftCost,goUpCost);
  }

  int getAnsMemoization(int row , int col ,vector<vector<int>>&grid ,vector<vector<int>>&dp){
     
     if(row==0 and col==0) return grid[row][col];

     if(row<0 or col<0) return INT_MAX;

     if(dp[row][col] != -1) return dp[row][col];

      int goUpCost=INT_MAX,goLeftCost=INT_MAX;

      if(row>0) goUpCost = grid[row][col]+getAnsRecursion(row-1,col,grid);

      if(col>0) goLeftCost = grid[row][col] + getAnsRecursion(row,col-1,grid);

      return dp[row][col] =  min(goLeftCost,goUpCost);
  }

   int getAnsTabulation(int totalRow , int totalCol ,vector<vector<int>>&grid ,vector<vector<int>>&dp){
       for(int row=0; row<totalRow; row++){
       for(int col=0; col<totalCol; col++){

           if(row==0 and col==0) dp[row][col] = grid[0][0];

           else{

               int goUpCost=INT_MAX,goLeftCost=INT_MAX;

             if(row>0)  goUpCost = grid[row][col] + dp[row-1][col];

              if(col>0)  goLeftCost = grid[row][col] + dp[row][col-1];

               dp[row][col] = min(goUpCost,goLeftCost);
           }
       }
   }

   return dp[totalRow-1][totalCol-1];
   }

   int getAnsSpaceOptimisation(int totalRow , int totalCol,vector<vector<int>>&grid){
       vector<int>prev(totalRow,0);

   for(int row=0; row<totalRow; row++){
       vector<int>curr(totalCol,0);
       for(int col=0; col<totalCol; col++){

           if(row==0 and col==0) curr[col] = grid[row][col];

           else{

               int goUpCost=INT_MAX,goLeftCost=INT_MAX;

             if(row>0)  goUpCost = grid[row][col] + prev[col];

              if(col>0)  goLeftCost = grid[row][col] + curr[col-1];

               curr[col] = min(goUpCost,goLeftCost);

           }
       }

       prev = curr;
   }

  return prev[totalCol-1];
   }

  int minSumPath(vector<vector<int>>&grid){
      
      int n = grid.size() , m = grid[0].size();

      vector<vector<int>>dp(n,vector<int>(m,-1));

      //return getAnsRecursion(n-1,m-1,grid);
     // return getAnsMemoization(n-1,m-1,grid,dp);
     //return getAnsTabulation(n,m,grid,dp);
     return getAnsSpaceOptimisation(n,m,grid);
  }


int main(){

    vector<vector<int> > grid{{5,9,6},{11,5,2}};

    cout<<"The minimum path sum is "<<minSumPath(grid);
    
}