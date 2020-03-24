#include <iostream>
#include <array>
#include <vector>
#include <stdlib.h>
using namespace std;
char board[3][3];
void computerMove(int &,int &);
void playerMove(int &,int &);
void showBoard(int row,int col){
    for(row=0;row<3;row++){
      for(col=0;col<3;col++){
          board[row][col]=' ';
          cout<<"["<<board[row][col]<<"]"<<" ";
      }
      cout<<endl;
    }
}
bool diagonal(int row,int col, char check){
    bool status=false;
    if((row==0 && col==0)||(row==0 && col==2)||(row==2&&col==0)||(row==2&&col==2)||(row==1&&col==1)){
        int count=0;
        if(row==0){
            for(int r=0;r<3;r++){
                if(col==0){
                    if(board[r][r]==check){
                        count++;
                    }
                }
                else if(col==2){
                    if(board[r][2-r]==check){
                        count++;
                    }
                }
            }
            if(count==3){
                status=true;
            }
        }
        else if(row==2){
            for(int r=2;r<=0;r--){
                if(col==0){
                    if(board[r][2-r]==check){
                        count++;
                    }
                }
                else if(col==2){
                    if(board[r][r]==check){
                        count++;
                    }
                }
            }
        }
        if(count==3){
            status=true;
        }
    }
    return status;
}
bool horizontal(int row,int col,int check){
    bool status=false;
    int count=0;
    if(col==0){
        for(int i=0;i<3;i++){
            if(board[row][i]==check){
                count++;
            }
        }
    }
    else if(col==1){
        if((board[row][col]==board[row][col-1])&&(board[row][col]==board[row][col+1])){
              count=3;
    }
    }
    else if(col==2){
        for(int i=2;i<=0;i--){
            if(board[row][i]==check){
                count++;
            }
        }
    }
    if(count==3){
        status=true;
    }
    return status;
}
bool vertical(int row,int col,char check){
    bool status=false;
    int count=0;
    if(row==0){
        for(int i=0;i<3;i++){
            if(board[i][col]==check){
                count++;
            }
        }
    }
    else if(row==1){
        if((board[row][col]==board[row-1][col])&&(board[row][col]==board[row+1][col])){
              count=3;
    }
    }
    else if(row==2){
        for(int i=2;i<=0;i--){
            if(board[i][col]==check){
                count++;
            }
        }
    }
    if(count==3){
        status=true;
    }
    return status;
}

bool checkWin(){
    bool win=false;
    //char checkChar;
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            if(board[r][c]!=' '){
                if(diagonal(r,c,board[r][c])){
                    win=true;
                }
                else if(horizontal(r,c,board[r][c])){
                    win=true;
                }
                else if(vertical(r,c,board[r][c])){
                    win=true;
                }
            }
        }
    }
    return win;
}
void printBoard(int row,int col,char marker){
    board[row][col]=marker;
    for(int r=0;r<3;r++){
      for(int c=0;c<3;c++){
          cout<<"["<<board[r][c]<<"]"<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
}
void playerMove(int &row,int &col){
    vector<int> rowSpace;
    vector<int> colSpace;
    for(int r=0;r<3;r++){
      for(int c=0;c<3;c++){
          char check=board[r][c];
          if(check==' '){
              rowSpace.push_back(r);
              colSpace.push_back(c);
          }
      }
    }
    int rSize=rowSpace.size();
    if(rSize==0){
        cout<<"It's a tie!"<<endl;
        cout<<"The game is over!"<<endl;
    }
    else{
        cout<<"Your move!"<<endl;
        do{
            cout<<"Input your row (0,1,2): ";
            cin>>row;
            cout<<"Input your column (0,1,2): ";
            cin>>col;
        }
        while(board[row][col]=='X'||board[row][col]=='O');
        printBoard(row,col,'O');
        if(checkWin()){
            cout<<"The player wins!"<<endl;
            cout<<"The game is over!"<<endl;
        }
        else{
            computerMove(row,col);
        }
    }
}
void computerMove(int &row,int &col){
    vector<int> rowSpace;
    vector<int> colSpace;
    for(int r=0;r<3;r++){
      for(int c=0;c<3;c++){
          char check=board[r][c];
          if((check!='O'||check!='X')&&(check==' ')){
              rowSpace.push_back(r);
              colSpace.push_back(c);
          }
      }
    }
    int rSize=rowSpace.size();
    //int cSize=colSpace.size();
    if(rSize==0){
        cout<<"It's a tie!"<<endl;
        cout<<"The game is over!"<<endl;
    }
    else{
        cout<<"Computer's move!"<<endl;

        rSize=rand()%rSize;
        //cSize=rand()%cSize+1;
        row=rowSpace[rSize];
        col=colSpace[rSize];
        printBoard(row,col,'X');
        if(checkWin()){
            cout<<"The computer wins!"<<endl;
            cout<<"The game is over!"<<endl;
        }
        else{
            playerMove(row,col);
        }
    }
}

int main()
{
    int row=0;
    int col=0;
    showBoard(row,col);
    playerMove(row,col);
    return 0;
}
