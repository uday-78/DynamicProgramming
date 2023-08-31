#include<bits/stdc++.h>
using namespace std;

/*

 Here in the tabulation code what we are doing is ultimately finding the min diff of the sum
 of two subset.

        i.e  S1-S2

   Here if we think closely then we would get know that there is no need of calculating the S2 because as we
   know the total sum we can find S2.

   So if we know all the possible values of S1 then we can easily find our min subset sum diff.

   Here to do this DP array will help us very much that dp[indx][target] tell us that if we can
   form the target by considering the subset till indx.

   So by filling the entire DP array we will then traverse in the last column of the DP array because that 
   last column will tell us that by considering the subset of entire array can we form the target.
          And the entire values of S1 will in between 0 to sum of all the array because we can form 0 by not
          considering any of the element in the subset and sum of all array by considering all the element in
          the subset.     
       
*/

 int getAnsRecursion(int indx, int n, int sumPart1, vector<int>& arr) {
    if (indx == n) {
        return abs(sumPart1 - (accumulate(arr.begin(), arr.end(), 0) - sumPart1));
    }

    // Calculate the difference by including and excluding the current element
    int includePart1 = getAnsRecursion(indx + 1, n, sumPart1 + arr[indx], arr);
    int excludePart1 = getAnsRecursion(indx + 1, n, sumPart1, arr);

    // Return the minimum of the two differences
    return min(includePart1, excludePart1);
}

 int getAnsMemoization(int indx, int n, int sumPart1, vector<int>& arr,vector<vector<int>>&dp) {
    if (indx == n) {
        return abs(sumPart1 - (accumulate(arr.begin(), arr.end(), 0) - sumPart1));
    }

     if(dp[indx][sumPart1] != -1) return dp[indx][sumPart1];

    // Calculate the difference by including and excluding the current element
    int includePart1 = getAnsMemoization(indx + 1, n, sumPart1 + arr[indx], arr,dp);
    int excludePart1 = getAnsMemoization(indx + 1, n, sumPart1, arr,dp);

    // Return the minimum of the two differences
    return dp[indx][sumPart1] =  min(includePart1, excludePart1);
}

int getAnsTabulation(int n, vector<int> &arr)
{
    int totalSum = accumulate(begin(arr), end(arr), 0);

    vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));

    int k = totalSum;

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int indx = 1; indx < n; indx++)
    {
        for (int target = 1; target <= k; target++)
        {

            bool noTake = dp[indx - 1][target];

            bool take = false;

            if (arr[indx] <= target)
                take = dp[indx - 1][target - arr[indx]];

            dp[indx][target] = noTake or take;
        }
    }

    int mini = 1e9;

    for (int s1 = 0; s1 <= totalSum / 2; s1++)
    {

        if (dp[n - 1][s1] == true)
        {

            mini = min(mini, abs(s1 - (totalSum - s1)));
        }
    }

    return mini;
}

int minSubsetSumDifference(vector<int>& arr, int n) {

    int sumPart1 = 0;

   int totalSum  = accumulate(begin(arr),end(arr),0);

    vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));

    //return getAnsRecursion(0, n, sumPart1, arr);

   // return getAnsMemoization(0,n,sumPart1,arr,dp);

   return getAnsTabulation(n,arr);
}


int main(){

    vector<int>arr = {1,2,3,4};

    int n = arr.size();

    cout<<"min SubsetSum Difference is: "<<minSubsetSumDifference(arr,n);

}