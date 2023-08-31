#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 void solveNQueen(int col ,int n,int& count ,vector<string>&board  ,vector<vector<string>>&ans 
       ,vector<int>&leftRow ,vector<int>&upperDiagonal,vector<int>&lowerDiagonal){

        if(col >= n){
            ans.push_back(board);
            count++;
            return;
        }


        for(int row=0; row<n; row++){
           if(leftRow[row]==0 and upperDiagonal[n-1+col-row]==0 and lowerDiagonal[row+col]==0){
              
              board[row][col] = 'Q';
              leftRow[row] = lowerDiagonal[row+col] = upperDiagonal[n-1+col-row] =1;

              solveNQueen(col+1 ,n,count ,board,ans ,leftRow ,upperDiagonal ,lowerDiagonal);

              board[row][col] = '.' ;
              
              leftRow[row] = lowerDiagonal[row+col] = upperDiagonal[n-1+col-row] =0;
           }
        }

 }

 pair<vector<vector<string>>,int> NQueens(int n){
    vector<vector<string>>ans;

    vector<string>board(n);

    string s(n,'.');

    for(int i=0; i<board.size(); i++) board[i] = s;

    int count = 0;

    
    vector<int>leftRow(n,0) , upperDiagonal(2*n-1 ,0) ,lowerDiagonal(2*n-1 ,0);

    solveNQueen(0,n,count,board,ans,leftRow,upperDiagonal,lowerDiagonal);

    return {ans,count};
}
       
       bool isSafe(int row ,int col ,char ch ,vector<vector<char>>&board){
           
           for(int i=0; i<9; i++){
               
             if(board[row][i] == ch) return false;

             if(board[i][col] == ch) return false;

             if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch) return false;

           }

           return true;

       }


 //! Here the return type of function solveSudoko is bool because it is a type of pattern which is taught by
 //! striver bhaiya where he explain that if among various possible answer if we want only one 
 //! then we have to make the return type bool
 //* And also he explains the reason for doing because the moment we find our answer and return true we are not making
 //* any further recursion call so we will only get one single answer 

 //? Here to solve this problem what we are doing is we are going on every cell and checking that can we 
 //? fill digits from 1 to 9 
 
    bool solveSudoko(vector<vector<char>>&board){
         
         for(int row=0; row<board.size(); row++){
            for(int col=0; col<board.size(); col++){
                 if(board[row][col] == '.'){
                     
                     //? If it is empty space then we will try to fill from 1 to 9

                     for(char ch='1'; ch<='9'; ch++){

                        if(isSafe(row,col,ch,board)){
                            board[row][col] = ch;

                            if(solveSudoko(board)== true) return true;

                            board[row][col] = '.';
                        }
                     }

                      return false;
                 }
            }
         }

        return true;
    }
 
  void sudokoSolver(vector<vector<char>>&board){
      
      solveSudoko(board);

  }

    bool isSafeNodeColoring(int node ,int n ,int nodeColor ,bool graph[101][101] ,vector<int>&color){

        for(int adjNode=0; adjNode<n; adjNode++){
            if(node!=adjNode and graph[node][adjNode]==1 and color[adjNode]==nodeColor) return false;
        }

        return true;
    }

    bool checkGraphColoring(int node , int n , int m ,bool graph[101][101],vector<int>&color){
    //?Here n is the total no of nodes in the graph and m is the maximum no of coloring we can use to color the graph
       
      if(node == n) return true;

        for(int nodeColor=0; nodeColor<=m; nodeColor++){
            if(isSafeNodeColoring(node,n,nodeColor,graph,color)==true){
                color[node] = nodeColor;

                if(checkGraphColoring(node+1,n,m,graph,color)==true) return true;

                color[node] = 0;
            }
        }

        return false;

    }


  bool graphColoring(int n ,int m ,bool graph[101][101]){
     //?Here n is the total no of nodes in the graph and m is the maximum no of coloring we can use to color the graph

     //* So for graph coloring what approach we are following is that we will try to color the each node of the graph with every possible color
     //* and will check if we are able to do that if yes then we will return true otherwise return false
     //! And for the above approach one of the best method is using recursion
     //? And also while coloring each node of the graph we will have to take care that the color of the node is not as all of it's
     //? adjacent node if adjacent node color is same as that of the curr node which we are coloring then we can't color that node
     //? with that color
     

     vector<int>color(n,0);
    
   
     if(checkGraphColoring(0,n,m,graph,color)==true) return true;

     return false;
  }

int main(){

    // int n;
    
    // cout<<"Enter the size of the chess board ";
    //  cin>>n;

    //  pair<vector<vector<string>>,int> temp = NQueens(n);

    //   vector<vector<string>>ans = temp.first;
    //   int count = temp.second;

    //   cout<<"And the count is "<<count<<endl;
    
    // cout<<"One Possible Solution is ";

    // cout<<"{";
    // for (const auto& vec : ans) {
    //     cout << "[";
    //     for (int i = 0; i < vec.size(); ++i) {
    //         cout << "\"" << vec[i] << "\"";
    //         if (i != vec.size() - 1) {
    //             cout << ",";
    //         }
    //     }
    //     cout<<"]";
    // }

    // cout<<"}";



    vector<vector<char>> board =  {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    sudokoSolver(board);

    cout<<"One of the possible solution is "<<endl;
       for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i != 0) {
            std::cout << "------+-------+------\n";
        }
        for (int j = 0; j < 9; ++j) {
            if (j % 3 == 0 && j != 0) {
                std::cout << "| ";
            }
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }



    //  bool graph[101][101] = {(0,1),(1,2),(2,3),(3,0),(0,2)};

    //  int n ,m;

    //  std::cout<<"Enter the value of n and m: ";
    //     std::cin>>n>>m;

    //   if(graphColoring(n,m,graph)==true){
    //    std::cout<<"The graph can be coloured with the "<<m<<" colors"<<endl;
    //   }  else{
    //     std::cout<<"The graph can't be coloured with the"<<m<<"colors"<<endl;
    //   } 


}