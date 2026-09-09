#include <iostream>
#include <limits>
#include "utils.h"

using namespace std;

void nextPlayer(char &player){
  if (player == 'X'){
    player = 'O';
  } else {
    player = 'X';
  }
}

bool validMove(char board[][3], int row, int col){
  if (board[row][col] == '-'){
    return true;
  }
  return false;
}

void printBoard(char board[][3]){
  for (int row = 0; row < 3; row++){
    for (int col = 0; col < 3; col++){
      cout << board[row][col] << ' ';
    }
    cout << endl;
  }
}

char checkWin(char board[][3]){
  for (int i = 0; i < 3; i++){
    //checking rows
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-'){
      return board[i][0];
    }

    //checking cols
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-'){
      return board[0][i];
    }
  }

  //checking diags
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-'){
    return board[0][0];
  }

  if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != '-'){
    return board[2][0];
  }
  
  //default return
  return ' ';
}

void playTurn(char (*board)[3], char player){
  int row;
  int col;
  do {
    
    do {
      cout << "row >> ";
      cin >> row;
    } while(!verifyCIN());

    do {
      cout << "col >> ";
      cin >> col;
    } while(!verifyCIN());

  }while(!validMove(board,row,col));

  board[row][col] = player;
  printBoard(board);
  
}

int main(){
  char board[3][3]={
    {'-','-','-'},
    {'-','-','-'},
    {'-','-','-'}
  };
  char currentPlayer = 'X';
  playTurn(board, currentPlayer);
}
