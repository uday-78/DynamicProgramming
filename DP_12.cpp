#include<bits/stdc++.h>
using namespace std;

  //! There are two base case :
      //? 1) Destination Base case
      //? 2) Out of bound base case

   //! And while writing the base case write the out of bound base case first and also
   //! while writing the base case consider all the possibilites of the movement

   //* Here what i was thinking that firstly solve for alice and then for bob and then
   //* maximise the answer. But this will not work due to following:

   //? When either of them start first then while collecting chocolates it will make that cell
   //? zero so what will happen is when other person start collecting and if he visited that
   //? same cell which the other person has visited earlier and collected the chocolate there 
   //? is a problem that according to question if both of them visited the same cell then we have
   //? to consider collecting the chocolates once. So if that cell value is zero so we can't collect
   //? chocolates from there.
   //?           And to solve this we have to map the row and col value with the cell value so that we
   //?           will not loose that value so for this we have to use an extra space which can cause problem


   //! And if there is a situation where we have to write recursion go from fix starting point 
   //! to variable starting then always wrtie recursion from the fix starting point because since
   //! the starting point is fix we only have to write only one recursion.
   //?        But if we want to write the recursion call for the variable starting point then problem
   //?      is that we have to write the recursion call for each of the point in the variable ending point

















  int getAnsRecursion(int row,int r ,int c ,int colAlice ,int colBob ,vector<vector<int>>&grid){
      
      //*Here we are returning -1e8 to avoid the integer overflow
      if(colAlice<0||colAlice>= c || colBob<0 || colBob >=c) return -1e8;

      if(row==r-1){
          
          //! Both return to the same position
           if(colAlice==colBob) return grid[row][colAlice];
         
          //! Both of them return to the different position
           else return grid[row][colAlice] + grid[row][colBob];
      }
        
        int ans = -1e8;

        for(int dAlice= -1; dAlice<= +1; dAlice++){
           for(int dBob= -1; dBob<= +1; dBob++){
              
                int value = 0;

                if(colAlice==colBob) value = grid[row][colAlice];

                else value = grid[row][colAlice]+grid[row][colBob];

                value += getAnsRecursion(row+1,r,c,colAlice+dAlice,colBob+dBob,grid);

                ans = max(ans,value);
           }
        }


        return ans;

        //? TC--> O(3^n * 3^n) because at max both of them are travelling down the
        //? row and while travelling for each column cell they have three option

        //* SC--> O(N) because at max it will only store the recursion calls along
        //* the row
  }

   int getAnsMemoization(int row,int r ,int c ,int colAlice ,int colBob 
   ,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
      
        //*Here we are returning -1e8 to avoid the integer overflow
      if(colAlice<0||colAlice>= c || colBob<0 || colBob >=c) return -1e8;

      if(row==r-1){
          
          //! Both return to the same position
           if(colAlice==colBob) return grid[row][colAlice];
         
          //! Both of them return to the different position
           else return grid[row][colAlice] + grid[row][colBob];
      }

      if(dp[row][colAlice][colBob] != -1) return dp[row][colAlice][colBob];

       int ans = -1e8;

        for(int dAlice= -1; dAlice<= +1; dAlice++){
           for(int dBob= -1; dBob<= +1; dBob++){
              
                int value = 0;

                if(colAlice==colBob) value = grid[row][colAlice];

                else value = grid[row][colAlice]+grid[row][colBob];

                value += getAnsRecursion(row+1,r,c,colAlice+dAlice,colBob+dBob,grid);

                ans = max(ans,value);
           }
        }


        return dp[row][colAlice][colBob] = ans;
        
       //? TC--> O(r*c*c)*9 because TC will be the no of different states because the other
       //? will get return by the dp array and *9 is because for every state we are running
       //? loop 

       //* SC--> O(r*c*c)+O(N) this is because here we are using dp array  
   }

    int getAnsTabulation(int r ,int c ,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){

       for(int colAlice=0; colAlice<c; colAlice++){
           for(int colBob=0; colBob<c; colBob++){
              
              if(colAlice==colBob) dp[r-1][colAlice][colBob] = grid[r-1][colAlice];

              else dp[r-1][colAlice][colBob] = grid[r-1][colAlice] + grid[r-1][colBob];
           }
       }

        for(int row=r-2; row>=0; row--){
            for(int colAlice=0; colAlice<c; colAlice++){
               for(int colBob=0; colBob<c; colBob++){
                  
                  
                  
       int ans = -1e8;

        for(int dAlice= -1; dAlice<= +1; dAlice++){
           for(int dBob= -1; dBob<= +1; dBob++){
              
                int value = 0;

                if(colAlice==colBob) value = grid[row][colAlice];

                else value = grid[row][colAlice]+grid[row][colBob];
                 
                 if(colAlice+dAlice>=0 and colAlice+dAlice<c and colBob+dBob>=0 and colBob+dBob<c)
                value += dp[row+1][colAlice+dAlice][colBob+dBob];

                else value += -1e8;

                ans = max(ans,value);
           }
        }     

        dp[row][colAlice][colBob] = ans;   
               }
            }
        }


        return dp[0][0][c-1];
         
    }


  int maximumChocolates(int R ,int C ,vector<vector<int>>&grid){
      
      // return getAnsRecursion(0,R,C,0,C-1,grid);

      vector<vector<vector<int>>>dp(R,vector<vector<int>>(C,vector<int>(C,-1)));
       
      // return getAnsMemoization(0,R,C,0,C-1,grid,dp);

      return getAnsTabulation(R,C,grid,dp);
  }


  int main(){

     vector<vector<int>>grid = {{2,3,1,2},{3,4,2,2},{5,6,3,5}};

      int r = grid.size(), c = grid[0].size();

      cout<<"The maximum chocolates return by alice and bob is "<<maximumChocolates(r,c,grid);

  }
   