
  //! This problem is slightly different from the previous problem that
  //! here the starting point and ending point is also variable

  #include<bits/stdc++.h>
  using namespace std;

  
    int getAnsRecursion(int row , int col ,vector<vector<int>>&matrix ,int n ,vector<vector<int>>&dp){

         if(col<0 or col>=matrix[0].size()) return -1e9;
         
         if(row==0) return matrix[row][col];

         if(dp[row][col] != -1) return dp[row][col];

         int goDownCost = matrix[row][col] + getAnsRecursion(row-1,col,matrix,n,dp);

         int goLeftDiaognalCost = matrix[row][col] + getAnsRecursion(row-1,col-1,matrix,n,dp);

         int goRightDiagonalCost = matrix[row][col] + getAnsRecursion(row-1,col+1,matrix,n,dp);


         return dp[row][col] =  max({goDownCost,goLeftDiaognalCost,goRightDiagonalCost});

    }

 int getAnsMemoization(int row , int col ,vector<vector<int>>&matrix ,int n ,vector<vector<int>>&dp){

         if(col<0 or col>=matrix[0].size()) return -1e9;
         
         if(row==0) return matrix[row][col];

         if(dp[row][col] != -1) return dp[row][col];

         int goDownCost = matrix[row][col] + getAnsMemoization(row-1,col,matrix,n,dp);

         int goLeftDiaognalCost = matrix[row][col] + getAnsMemoization(row-1,col-1,matrix,n,dp);

         int goRightDiagonalCost = matrix[row][col] + getAnsMemoization(row-1,col+1,matrix,n,dp);


         return dp[row][col] =  max({goDownCost,goLeftDiaognalCost,goRightDiagonalCost});

    }


    int getAnsTabulation(vector<vector<int>>&matrix ,vector<vector<int>>&dp ,int n ,int m){
         
         for(int i=0; i<m; i++) dp[0][i] = matrix[0][i];

         for(int row=1; row<n; row++){
            for(int col=0; col<m; col++){

              int goLeftDiagonalCost=-1e9 , goRightDiagonalCost=-1e9;

                int goDownCost = matrix[row][col] + dp[row-1][col];

                 if(col-1>=0) goLeftDiagonalCost = matrix[row][col] + dp[row-1][col-1];

               if(col+1<m)  goRightDiagonalCost = matrix[row][col] + dp[row-1][col+1];

               dp[row][col] =  max({goDownCost,goLeftDiagonalCost,goRightDiagonalCost});
            }
         }

        

        int ans = -1e9;

        for(int j=0; j<m; j++){
            ans = max(ans ,dp[n-1][j]);
        }

        return ans;
    }

    int getAnsSpaceOptimisation(vector<vector<int>>matrix,int m,int n){

        vector<int>prev(m,0),curr(m,0);

        for(int i=0; i<m; i++) prev[i] = matrix[0][i];

         for(int row=1; row<n; row++){
            for(int col=0; col<m; col++){

              int goLeftDiagonalCost=-1e9 , goRightDiagonalCost=-1e9;

                int goDownCost = matrix[row][col] + prev[col];

                 if(col-1>=0) goLeftDiagonalCost = matrix[row][col] + prev[col-1];

               if(col+1<m)  goRightDiagonalCost = matrix[row][col] + prev[col+1];

               curr[col] =  max({goDownCost,goLeftDiagonalCost,goRightDiagonalCost});
            }

            prev = curr;
         }

        

        int ans = -1e9;

        for(int j=0; j<m; j++){
            ans = max(ans ,prev[j]);
        }

        return ans;
    }

 
  int getMaxPathSum(vector<vector<int>> &matrix){
        
        // int ans = -1e9 , N=matrix.size() , M=matrix[0].size();

        //  vector<vector<int>>dp(N,vector<int>(M,-1));

        // for(int start=0; start<M; start++){

        //     ans = max(ans ,getAnsMemoization(N-1,start,matrix,N,dp));
        // }
        
        // return ans;

        // vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));

        // return getAnsTabulation(matrix,dp,matrix.size(),matrix[0].size());

        return getAnsSpaceOptimisation(matrix,matrix[0].size(),matrix.size());

  }


  int main(){

    vector<vector<int>>matrix = {{10,2,3},{3,7,2},{8,1,5}};

    cout<<"The maximum path sum is "<<getMaxPathSum(matrix);

  }