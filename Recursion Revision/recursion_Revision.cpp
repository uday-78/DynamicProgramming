#include<iostream>
#include<bits/stdc++.h>
using namespace std;


   int n ;
   vector<vector<string>>ans;

   bool isPalindrome(string s , int left , int right){
       while(left<right){
           if(s[left]!=s[right])
           return false;

           left++;
           right--;
       }

       return true;
   }

   void Get_All_Partition(string& s , int indx , vector<string>curr){

       if(indx==n){
           ans.push_back(curr);
           return;
       }

       for(int i=indx; i<n; i++){
           if(isPalindrome(s,indx,i)){
               curr.push_back(s.substr(indx,i-indx+1));
               Get_All_Partition(s,i+1,curr);
               curr.pop_back();
           }
       }
   }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string>curr;

         Get_All_Partition(s,0,curr);

         return ans;
    }

int main(){

    string s = "aaaab";

    vector<vector<string>>ans = partition(s);

    std::cout<<"All palindromic substring are ";


    std::cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << "{";
        vector<string> temp = ans[i];
        for (int j = 0; j < temp.size(); j++) {
            std::cout << ans[i][j];
            if (j != ans[i].size() - 1) {
                std::cout << ",";
            }
        }
       
         if(i!=temp.size()-1){
            std::cout<<"},";
         } else{
            std::cout<<"}";
         }
       
        
    }
    std::cout << "]";

}