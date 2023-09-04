//? Leetcode 740
//? Delete and earn

#include<bits/stdc++.h>
using namespace std;

/*
   Here what we have to do is perform the below following operation any no of times:
   
    We can delete any nums[i] and earn nums[i] point but the nums[i] will only
    be added to the points if we are able to delete all nums[i]-1 and nums[i]+1

    !!! Here if we are deleting nums[i] then we also have to delete it's duplicate
       ! part and points will be equal to nums[i] * count of that element 

    the above is only applicable only when there are duplicate element because if there
    are no duplicate element then the count of that element will be 1


    And by doing the above we will have to generate the maximum point.


    This problem is similar to house robber problem because here what we are doing is that ultimately we are collecting
    maximum point.

    ! So if we are deleting nums[i] then it will contribute to the points and nums[i]+1 and nums[i]-1 will not be
    ! contributing to the point. So this is similar to the house robber problem i.e

          ? nums[i]+1   nums[i]    nums[i]-1
            ignore     delete       ignore

      So by above analogy we can solve the problem 

      So what we will do is we will create an array of size max(arr)+1 and fill with the points for element from 0 to n-1
      if they are deleted

      Ex:   arr =  2 2 3 3 3 4

        points =   0 0 4 9 4
          indx     0 1 2 3 4

    And the moment the point array is created then we will the same concept of house robber and we will get our ans
*/                        

  int getAnsRecursion(int indx , vector<int>&nums){
       
      if(indx==0) return nums[indx];

         if(indx<0) return 0;

         int pick = nums[indx]+getAnsRecursion(indx-2,nums);

         int notPick = getAnsRecursion(indx-1,nums);

         return  max(pick,notPick);
  }

    int getAnsSpaceOptimisation(int n ,vector<int>&nums){

         int prev = nums[0];
         int prev2 = 0;

         for (int i = 1; i < n; i++)
         {

             int pick = nums[i];

             if (i > 1)
                 pick += prev2;

             int notPick = prev;

             int curr = max(pick, notPick);

             prev2 = prev;
             prev = curr;
         }

         return prev;
}

int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

      // return getAnsRecursion(n,nums); 

      return getAnsSpaceOptimisation(n,nums);
}

int main(){

    vector<int>nums = {2,2,3,3,3,4};
     
      int n = *max_element(nums.begin(),nums.end());

      vector<int>points(n+1);
       
       for(int num :nums) points[num] += num;

     cout<<"The maximum point we can get is "<<deleteAndEarn(points);

}
