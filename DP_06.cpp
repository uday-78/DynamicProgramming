#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//! NOTE : In a problem where we have been asked to find the best answer from all the possible
//!         ways the greedy way of finding the ans fails.

  //? because in greedy it is possible that we might miss some cases from all the cases
  //? so we must use recursion for finding all the ways   

  //* In order to do all the stuff on the index if we require another parameter
  //* which can decide what task we can do then we could send another parameter 
  //* with the index

   //! Depending upon what stuff we are doing in order to preserve the condition
   //! we must require some more parameters 

 
 //! ******************************************************************************

   //? Whenever we are computing something and it depends on something previous
   //? then there is always a chance of space optimisation

   //* And also to write the for loop for the tabulation code follow the simple step 
   //* that in the memoiz code see the how the parameters are changing with respect
   //* to another

 //! ******************************************************************************


  int getAnsRecursion(int day ,int lastTask ,vector<vector<int>>&points){


    //! Here we have traverse in the 0th day task because upon reaching the day 0 
    //! we have options whether we can do tasks except the last task that was done

    //* So what we will do is we will traverse in the day 0 task array and search for the 
    //* maximum ignoring the lastTask

      if(day == 0){
        
        int maxi = 0;

        for(int task=0; task<3; task++){
            if(task != lastTask){
               maxi = max(maxi ,points[0][task]);
            }                                                       
        }

        return maxi;
      }

       
       int maxi = 0;

         for(int task=0; task<3; task++){
            if(task != lastTask){

                int point = points[day][task] + getAnsRecursion(day-1 ,task ,points);

                maxi = max(maxi ,point);
            }
         }

       return maxi;

  }

  int getAnsMemoization(int day ,int lastTask ,vector<vector<int>>&points ,vector<vector<int>>&dp){
        if(day == 0){
        
        int maxi = 0;

        for(int task=0; task<3; task++){
            if(task != lastTask){
               maxi = max(maxi ,points[0][task]);
            }  
        }

        return maxi;
      }

       
       if(dp[day][lastTask] != -1) return dp[day][lastTask];

       
       int maxi = 0;

         for(int task=0; task<3; task++){
            if(task != lastTask){

                int point = points[day][task] + getAnsRecursion(day-1 ,task ,points);

                maxi = max(maxi ,point);
            }
         }

       return dp[day][lastTask] =  maxi;
  }

  int getAnsTabulation(int n,vector<vector<int>>&points ,vector<vector<int>>&dp){
   
      dp[0][0] = max(points[0][1] ,points[0][2]);
      dp[0][1] = max(points[0][0] ,points[0][2]);
      dp[0][2] = max(points[0][0] ,points[0][1]);
      dp[0][3] = max({points[0][0],points[0][1],points[0][2]});


      for(int day=1; day<n; day++){

        for(int lastTask=0; lastTask<4; lastTask++){

           int maxi = 0;

         for(int task=0; task<3; task++){
            if(task != lastTask){

                int point = points[day][task] + dp[day-1][task];

                maxi = max(maxi ,point);
            }
         }

         dp[day][lastTask] = maxi;
        
        }
      }

      return dp[n-1][3];
  }

   
   int getAnsSpaceOptimisation(int n,vector<vector<int>>&points ,vector<int>&prev){
   
      prev[0] = max(points[0][1] ,points[0][2]);
      prev[1] = max(points[0][0] ,points[0][2]);
      prev[2] = max(points[0][0] ,points[0][1]);
      prev[3] = max(points[0][0], max(points[0][1],points[0][2]));


      for(int day=1; day<n; day++){

        vector<int>curr(4,0);

        for(int lastTask=0; lastTask<4; lastTask++){

          curr[lastTask] = 0;

         for(int task=0; task<3; task++){
            if(task != lastTask){

                curr[lastTask] = max(curr[lastTask] ,points[day][task] + prev[task]);
            }
         }
        }

        prev = curr;
      }

      return prev[3];
  }



   int ninjaTraining(int n , vector<vector<int>>&points){
      
     // return getAnsRecursion(n-1 , 3 , points);
     // vector<vector<int>>dp(n ,vector<int>(4,-1)); //! don't need this instead vector<int>dp(4) will solve our problem
      //return getAnsMemoization(n-1,3,points,dp);
     // return getAnsTabulation(n,points,dp);

      //! For optimising the space we only need the previous value not the whole array
      vector<int>prev(4,0);
       return getAnsSpaceOptimisation(n,points,prev);
   }


int main(){

  vector<vector<int>>points = {{1,2,5} ,{3,1,1} ,{3,3,3}};
 
   int n = points.size();
  
  cout<<"The maximum merit points are "<<ninjaTraining(n,points);
 
}