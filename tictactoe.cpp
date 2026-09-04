#include <iostream>

using namespace std;

void nextPlayer(char &player){
  if (player == 'X'){
    player = 'O';
  } else {
    player = 'X';
  }
}

int main(){
  char board[3][3]={
    {' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '}
  };
  char currentPlayer = 'X';
  cout << currentPlayer << endl;
  nextPlayer(currentPlayer);
  cout << currentPlayer << endl;
}
