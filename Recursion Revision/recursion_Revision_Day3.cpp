#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 void Merge(vector<int>&arr ,int low ,int mid , int high){
     
     vector<int>temp;

     int left = low;
     int right = mid+1;

     while(left<=mid and right<=high){
        if(arr[left] <= arr[right]){
          temp.push_back(arr[left]);
          left++;
        } else{
             temp.push_back(arr[right]);
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



 }

void MergeSort(vector<int>&arr ,int low , int high){

    if(low>=high) return;

    int mid = low + (high-low)/2;

    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}

  int getPivot(vector<int>&arr,int low , int high){
      
      int pivot = arr[low];

      int left = low , right = high;

      while(left < right){

        while(arr[left] <= pivot and left<=high-1) left++;
        while(arr[right] > pivot and right>=low+1) right--;

         if(left<right) swap(arr[left],arr[right]);
      } 

      swap(arr[low],arr[right]);

      return right;
  }

  void RecursiveQuickSort(vector<int>&arr, int low , int high){
        
        if(low<high){
            int PivotIndex = getPivot(arr,low,high);
            RecursiveQuickSort(arr,low,PivotIndex-1);
            RecursiveQuickSort(arr,PivotIndex+1,high);
        }
  }

 vector<int> QuickSort(vector<int>&arr){
    
    RecursiveQuickSort(arr,0,arr.size()-1);

    return arr;
 }
 


void getAllCombination(vector<int>&arr,int target , int indx , vector<int>&temp){
      
      if(indx >= arr.size()){
         
          if(target == 0){
            for(auto it : temp) cout<<it<<" ";
            cout<<endl;
          }

          return;
      }

      if(target > 0){
        temp.push_back(arr[indx]);
        getAllCombination(arr,target-arr[indx],indx,temp);
        temp.pop_back();
      }
      
      getAllCombination(arr,target,indx+1,temp);

}


 vector<vector<int>> printAllCombinationSum(vector<int>&arr , int target){
     
     vector<int>temp;

     vector<vector<int>>ans;

    getAllCombination(arr,target,0,temp);

     return ans;
 }

int main(){
    // vector<int>arr = {1,5,3,6,0,7,2,8,10,4,9};

    // cout<<"The Sorted array is ";
    // //MergeSort(arr,0,arr.size()-1);
    // QuickSort(arr);

    // for(int i=0; i<arr.size(); i++){
    //     cout<<arr[i]<<" ";
    // }

    // vector<int> arr = {2,3,5};
    // int target = 8;

    // vector<vector<int>> ans = printAllCombinationSum(arr,target);

    // int totalRow = ans.size();
    // int totalCol = ans[0].size();

    // cout<<"All the combination sum is " ;
    
    //  for(int row=0; row<totalRow; row++){
    //     for(int col=0; col<totalCol; col++){
    //         cout<<ans[row][col]<<" ";
    //     }
    //     cout<<endl;
    // }

  
    // vector<char>ch;
    // int count = 102210;
   
    //  int indx = 0;
    // while(count!=0){
    //  int digit = count%10;
    //   count = count/10;
    //   ch[indx] = digit;
    //   indx++;
    // }

    // for(auto it : ch){
    //     cout<<(int)it<<" ";
    // }


   


    

}

