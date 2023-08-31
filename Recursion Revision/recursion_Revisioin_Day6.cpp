#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s ,int start ,int end){

    while(start <end){
        if(s[start++] != s[end--]) return false;
    }

    return true;
}

void getPartitionPalindrome(int indx,int n ,string s ,vector<vector<string>>&ans ,vector<string>&temp){
     
     if(indx == n){
        ans.push_back(temp);
        return;
     }


     for(int i=indx; i<n; i++){
        if(isPalindrome(s,indx ,i)==true){
            temp.push_back(s.substr(indx ,i-indx+1));
            getPartitionPalindrome(i+1,n,s,ans,temp);
            temp.pop_back();
        }
     }
}


vector<vector<string>> partition(string s){

    vector<vector<string>>ans;
     vector<string>temp;
 
       int n = s.length();

     getPartitionPalindrome(0,n,s,ans,temp);

    return ans;
}


     vector<int>dRow = {-1,0,0,-1};
    vector<int>dCol = {0,-1,1,0};
    
    bool isSafeToMove(int row ,int col,int n ,vector<vector<bool>>&vis,vector<vector<int>>&path){
        if((row>=0 and row<n) and (col>=0 and col<n) and vis[row][col]==false and path[row][col]==1 )
          return true;
          
          
          return false;
    }
    
    void getAllPath(int row ,int col ,int n ,vector<string>&ans ,string temp
    ,vector<vector<int>>&path,vector<vector<bool>>&vis){
        
        if(row==n-1 and col==n-1){
            ans.push_back(temp);
            return;
        }
        
        
        string DIR = "DLRU";
        
        for(int indx=0; indx<4; indx++){
            int nextRow = row + dRow[indx];
            int nextCol = col + dCol[indx];
            
            if(isSafeToMove(nextRow,nextCol,n,vis,path)==true){
                vis[row][col] = true;
                getAllPath(nextRow,nextCol,n,ans,temp+DIR[indx],path,vis);
                vis[row][col] = false;
            }
        }
         
    }
    
    vector<string> findPath(vector<vector<int>> &path, int n) {
        
         vector<string>ans;
         vector<vector<bool>>vis(n,vector<bool>(n,false));
         
         string temp = "";
         
         if(path[0][0] == 1) getAllPath(0,0,n,ans,temp,path,vis);
         
         return ans;
    }

    string KthPermutation(int n , int k){
        int fact = 1;
        vector<int>numbers;

        for(int i=1; i<n; i++){
            fact *= i;
            numbers.push_back(i);
        }

        numbers.push_back(n);

        string ans = "";

        k=k-1;

        while(true){
            ans = ans +to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);

            if(numbers.size() == 0) break;

            k=k%fact;
            fact = fact/numbers.size();
        }

        return ans;
    }

     int Merge(vector<int>&arr ,int low , int mid ,int high){
        vector<int>temp;

        int left = low , right = mid+1;

        int count = 0;

        while(left<=mid and right<=high){
           if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
           } else{
              temp.push_back(arr[right]);
              count +=(mid-left+1);
              right++;
           }
        }

        while(left<=mid){
             temp.push_back(arr[left]);
            left++;
        }

        while(right<=high){
             temp.push_back(arr[right]);
              right++;
        }


        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }

        return count;
     }

    int MergeSort(int low , int high ,vector<int>&arr ,int n){

        int count = 0;
        
        if(low>=high) return count;

        int mid = low + (high-low)/2;

       count += MergeSort(low,mid,arr,n);
       count += MergeSort(mid+1,high,arr,n);
       count += Merge(arr,low,mid,high);

       return count;
    }

  int countInversion(vector<int>&arr , int n){
     
     return MergeSort(0,n-1,arr,n);

  }


int main(){

    // string s = "aab";

    // vector<vector<string>> ans = partition(s);

    // cout<<"All the palindrome partition substring are ";

    // cout<<"[";

    // for(int i=0; i<ans.size(); i++){
    //     cout<<"{";
    //    for(int j=0; j<ans[i].size(); j++){
    //       (j==ans[i].size()-1 ? cout<<ans[i][j] : cout<<ans[i][j]<<",");
    //    }
        
    //     (i != ans.size()-1 ? cout<<"} ," : cout<<"}" );
    // }

    // cout<<"]";


    // vector<vector<int>>path = {{1, 0, 0, 0}, {1, 1, 0, 1},  {1, 1, 0, 0}, {0, 1, 1, 1}};
    //  int n = path.size();

    //  vector<string> ans = findPath(path,n);

    //  cout<<"All the Path explored by the rat is ";
    //  cout<<"{";
    //    for(int i=0; i<ans.size(); i++){
    //       (i==ans.size()-1 ? cout<<ans[i] : cout<<ans[i]<<",");
    //    }
    //  cout<<"}";

    // int n , k;
    // cout<<"Enter the value of n and k ";
    // cin>>n>>k;

    // cout<<"The " <<k<<"th permutation is "<<KthPermutation(n,k);


    vector<int>arr = {5,3,2,1,4};
    int n = arr.size();

    cout<<"The total no of count inversion in arr is ";
    cout<<countInversion(arr,n);

}