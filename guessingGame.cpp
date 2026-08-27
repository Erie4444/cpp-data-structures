#include <iostream>

using namespace std;

int main(){
  int targetNum = 0;
  int guesses = 0;
  int currentGuess = 0;
  srand(time(NULL));
  do {
    //cout << "Before Random: " << targetNum << endl;
    targetNum = rand()%101; //set number to a number between 0 & 100
    //cout << "After Random: " << targetNum;

    do{
      cout << "Guess: "
      cin >> currentGuess;
      guesses++;
    }while(currentGuess != targetNum);

    cout << "Guesses: " << guesses << endl;
    
    
  }while();
  return 0;
}
