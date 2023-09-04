
//? Leetcode 1239 
//? Maximum length of a concatenated string with unique characters

#include<bits/stdc++.h>
using namespace std;

bool hasRepeatedCharacters(const string& s) {
    bool charSet[128] = {false}; // Assuming ASCII characters
    for (char c : s) {
        if (charSet[int(c)]) {
            return true;
        }
        charSet[int(c)] = true;
    }
    return false;
}   

 int getAnsRecursion(int indx,int n,string temp ,vector<string>&arr){
     
     if(indx==n) return temp.length();

     int include = 0 , exclude = 0;

     if(!hasRepeatedCharacters(arr[indx]) and !hasRepeatedCharacters(arr[indx]+temp)){
         include = getAnsRecursion(indx+1,n,temp+arr[indx],arr);
     }

     exclude = getAnsRecursion(indx+1,n,temp,arr);

     return max(include,exclude);
 }

   int getAnsMemoization(int indx ,int n ,string temp ,vector<string>&arr ,unordered_map<string,int>&mp){

        if(indx==n) return temp.length();

         int include = 0 , exclude = 0;

         if(mp.find(temp) != mp.end()) return mp[temp];

     if(!hasRepeatedCharacters(arr[indx]) and !hasRepeatedCharacters(arr[indx]+temp))
         include = getAnsRecursion(indx+1,n,temp+arr[indx],arr);

     exclude = getAnsRecursion(indx+1,n,temp,arr);

     return mp[temp] =  max(include,exclude);
   }

   int getAnsTabulation(int n ,vector<string>&arr ,map<string,int>&mp){
       
       
   }

int maxLength(vector<string>& arr) {

       int n = arr.size();
      string temp = "";
       //return getAnsRecursion(0,n,temp,arr); 

       unordered_map<string,int>mp;

       return getAnsMemoization(0,n,temp,arr,mp);
}


int main(){

    vector<string>arr = {"un","iq","ue"};

    cout<<"The maximum length is: "<<maxLength(arr);

}