#include <iostream>
#include <limits>
#include "utils.h"

using namespace std;

//sets the player variable to the next player
//uses reference as we need to modify the player variable
void nextPlayer(char &player){
  if (player == 'X'){
    player = 'O';
  } else {
    player = 'X';
  }
}

//converts the row input into an index
int convertLetterToNum(char rowLetter){
  int ascii = static_cast<int>(rowLetter); //casting the char into int for its ascii value
  return ascii-97; //converts the ascii value to a row index (97 because 97 is the ascii value of a, and we want a to correspond to 0)
}

//checks if a move is valid
//we make a copy of the board as we don't need to modify it
bool validMove(char board[][3], int row, int col){
  if (board[row][col] == '-' && row < 3 && row >=0 && col < 3 && col >=0){
    return true;
  }
  return false;
}

//prints out the board
//added some extra character to make the board look good
void printBoard(char board[][3]){
  char border[] = "=========="; //borders for the top & bottom
  char topLine[] = "|  0 1 2 |"; //line for column number display
  cout << border << endl;
  cout << topLine << endl;
  
  for (int row = 0; row < 3; row++){
    char rowChar = static_cast<char> (row+97);
    cout << '|' << rowChar << ' '; //adds the pipe character before the contents of the board are printed
    for (int col = 0; col < 3; col++){
      cout << board[row][col] << ' '; //printing contents of the board
    }
    cout << '|' << endl; //adding another pipe character at the end of the line
  }
  cout << border << endl; //print one more border at the bottom
}

//checks to see who won (returns the char of who won, ' ' if no win)
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

//checks if there are any more moves left
bool movesLeft(char board[][3]){
  for (int row = 0; row < 3; row++){
    for (int col = 0; col < 3; col++){
      if(board[row][col] == '-'){
	return true;
      }
    }
  }
  return false;
}

//checks the outcome of the board
//returns true if there is an outcome (the game ended), false if not
//gets xWins, oWins, and ties by reference because it needs to modify them
bool checkOutcome(char board[][3], int &xWins, int &oWins, int &ties){
  char winMsg[] = " wins!";
  char tieMsg[] = "tie!";
  char outcome = checkWin(board);
  if (outcome != ' '){ //checking win
    if (outcome == 'X'){
      xWins++;
    } else {
      oWins++;
    }
    cout << outcome << winMsg << endl; //printing the win message
    return true;
  }

  if (!movesLeft(board)){ //checking for tie (if no one won and no more moves)
    ties++;
    cout << tieMsg << endl; //printing tie message
    return true;
  }

  return false;
}

//function to play a turn of tictactoe
void playTurn(char (*board)[3], char player){
  char rowInput = 'a';
  int row = 0;
  int col = 0;
  char turnMsg[] = " turn";
  char rowPrompt[] = "row >> ";
  char colPrompt[] = "col >> ";
  cout << player << turnMsg << endl; //printing out the turn message
  do { //loop to wait for a valid move
    
    do { //loop for verified row input
      cout << rowPrompt;
      cin >> rowInput;
    } while(!verifyCIN());
    row = convertLetterToNum(rowInput);

    do { //loop for verified col input
      cout << colPrompt;
      cin >> col;
    } while(!verifyCIN());

  }while(!validMove(board,row,col));

  board[row][col] = player; //does the move
  printBoard(board);
}

int main(){
  char continuePrompt[] = "continue playing? (y/n) >> ";
  char continuePlaying = 'y';
  char xStats[] = "X: ";
  char oStats[] = "O: ";
  char tieStats[] = "Tie(s): ";
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  do { //loop to play multiple games
    char board[3][3]={
      {'-','-','-'},
      {'-','-','-'},
      {'-','-','-'}
    };
    char currentPlayer = 'X';
    printBoard(board);
    do{ //game loop
      playTurn(board, currentPlayer);
      nextPlayer(currentPlayer);
    } while(not checkOutcome(board,xWins,oWins,ties)); //continue playing turns if no outcome yet
    //printing the stats
    cout << xStats << xWins << endl;
    cout << oStats << oWins << endl;
    cout << tieStats << ties << endl;
    cout << continuePrompt;
    cin >> continuePlaying;
    verifyCIN(); //verify cin, we don't need to re-input as it will exit for any value other than 'y'
  }while(continuePlaying == 'y');
  
}
