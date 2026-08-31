#include <iostream>

using namespace std;

int main(){
  int targetNum = 0;
  int guesses = 0;
  int currentGuess = 0;
  char prompt[20] = "Guess: ";
  char winMessage[40] = "You guessed it! Guesses: ";
  char playAgainPrompt[20] = "Play again? (y/n)";
  char userInput = 'y';
  srand(time(NULL));
  do {
    //cout << "Before Random: " << targetNum << endl;
    targetNum = rand()%101; //set number to a number between 0 & 100
    //cout << "After Random: " << targetNum;

    do{
      cout << prompt;
      cin >> currentGuess;
      guesses++;
    }while(currentGuess != targetNum);

    cout << winMessage  << guesses << endl;
    cout << playAgainPrompt << endl;
    cin >> userInput;
    
  }while(userInput == 'y');
  return 0;
}
