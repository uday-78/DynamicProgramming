#include<iostream>
using namespace std;

 void printFactorial(int i , int fact){
    
     if(i < 1){
       cout<<"The factorial is "<<fact;
       return;
     }

      printFactorial(i-1 , fact*i);
 }

   int printFactorialBacktrack(int i ){
        
        if(i==1) return 1;

       int result = printFactorialBacktrack(i-1);
       
       return result*i;
      
   }

void printBackTrack(int i , int n){
    
    if( i > n) return;

    printBackTrack(i+1,n);

    cout<<i<<endl;
}

 void printReverse(int n){
    
     if( n == 0) return;

     cout<<n<<endl;

     printReverse(n-1);
 }

  void printLinearly(int i , int n){
    
    if(i > n) return;

    cout<<i<<endl;

    ++i;

    printLinearly(i,n);
  }

void printName(int i , int n){
 
  if( i > n) return;

  cout<<"UDAY"<<endl;
   printName(i+1,n);
   
}

int main(){
 
 int n;

cout<<"Enter the value of n ";
 cin>>n;

 //printName(1,n);

//  printLinearly(1,n);

//printReverse(n);

//printBackTrack(1,n);

 cout<<"The factorial is "<<printFactorialBacktrack(n);


}