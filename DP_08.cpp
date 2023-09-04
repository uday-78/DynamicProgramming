//! This problem is same as the Unique paths on grid but the only difference is that here
//! we will also have obstacle

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MOD = (int)(1e9+7);

bool isSafe(int nextRow , int nextCol ,vector< vector< int> > &mat
 ,int totalRow , int totalCol){
      
      if((nextRow>=0 and nextRow<totalRow) and (nextCol>=0 and nextCol<totalCol) 
      and mat[nextRow][nextCol]==0)return true;

      return false;
 }


int getAnsRecursion(int row , int col  ,int totalRow , int totalCol ,vector<vector<int>>&mat){

     if(row==0 and col==0) return 1;

     if(row<0 or col<0) return 0;


    int goUp = 0 , goRight = 0;

     if(isSafe(row-1,col,mat,totalRow,totalCol)){

          goUp = getAnsRecursion(row-1,col,totalRow,totalCol,mat);
     }

     if(isSafe(row,col-1,mat,totalRow,totalCol)){

          goRight = getAnsRecursion(row,col-1,totalRow,totalCol,mat);
     }

     return  (goRight+goUp);
 }


  int getAnsMemoization(int row , int col ,vector< vector< int> > &mat ,int totalRow 
 , int totalCol,vector<vector<int>>&dp){

     if(row==0 and col==0) return 1;

     if(row<0 or col<0) return 0;

     if(dp[row][col] != -1) return dp[row][col];


    int goUp = 0 , goRight = 0;

     if(isSafe(row-1,col,mat,totalRow,totalCol)){

          goUp = getAnsMemoization(row-1,col,mat,totalRow,totalCol,dp);
     }

     if(isSafe(row,col-1,mat,totalRow,totalCol)){

          goRight = getAnsMemoization(row,col-1,mat,totalRow,totalCol,dp);
     }

     return dp[row][col] =  (goRight+goUp)%MOD;
 }


   int getAnsTabulation(int TotalRow ,int TotalCol ,vector<vector<int>>&dp ,vector<vector<int>>&mat){
       

        for(int row=0; row<TotalRow; row++){
            for(int col=0; col<TotalRow; col++){

                if(row==0 and col==0) dp[row][col]=1;

                 else if(mat[row][col] == -1) dp[row][col] = 0;

                else{
                  int goUp = 0 , goRight = 0;

                  if(row>0) goUp = dp[row-1][col];

                  if(col>0) goRight = dp[row][col-1];

                  dp[row][col] = (goUp+goRight)%MOD;

                }
            }
        }

        return dp[TotalRow-1][TotalCol-1];

   }

   int getAnsSpaceOptimisation(int TotalRow , int TotalCol ,vector<vector<int>>&mat){

       vector<int> prev(TotalCol,0);

       for(int row=0; row<TotalRow; row++){
         vector<int>curr(TotalRow,0);

         for(int col=0; col<TotalCol; col++){
             
             if(row==0 and col==0) curr[col] = 1;

             else if(mat[row][col] == -1) curr[col] = 0;


             else{
                 
                 int goUp = 0 , goRight = 0;

                 if(row>0) goUp = prev[col];

                 if(col>0) goRight = curr[col-1];

                curr[col] = (goUp+goRight)%MOD;
             }
         }

           prev = curr;
       }

       return prev[TotalCol-1]%MOD;
   }

  
  int uniquePathsII(int m , int n ,vector<vector<int>>&mat){



     return getAnsRecursion(m-1,n-1,m,n,mat);

    //vector<vector<int>>dp(m,vector<int>(n,-1));

    //  return getAnsMemoization(m-1,n-1,mat,m,n,dp);

   // return getAnsTabulation(m,n,dp,mat);

    //return getAnsSpaceOptimisation(m,n,mat)%MOD;
   
  }

int main(){

    vector<vector<int>>mat = {{0,0},{0,1}};
   
    int m = mat.size();
    int n = mat[0].size();

    cout<<"Total no of unique path to reach from (0,0) " << "to "<< "("<<m-1<<","<<n-1<<") "<<"avoiding obstacle" <<" is "<<uniquePathsII(m,n,mat);
}