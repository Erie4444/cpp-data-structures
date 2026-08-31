#include <iostream>
#include <limits>

using namespace std;


int main(){
  int targetNum = 0;
  int guesses = 0;
  int currentGuess = 0;
  char prompt[20] = "Guess (0-100): ";
  char winMessage[40] = "You guessed it! Guesses: ";
  char playAgainPrompt[20] = "Play again? (y/n)";
  char errorMsg[40] = "Please enter a valid guess (0-100)";
  char lowMsg[40] = "Too low!";
  char highMsg[40] = "Too high!";
  char userInput = 'y';
  srand(time(NULL));
  do {
    //cout << "Before Random: " << targetNum << endl;
    targetNum = rand()%101; //set number to a number between 0 & 100
    //cout << "After Random: " << targetNum << endl;

    do{
      cout << prompt;
      cin >> currentGuess;
      //cin validation
      if (cin.fail()){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	cout << errorMsg << endl;
      } else{
	guesses++;
	if (currentGuess < targetNum){
	  cout << lowMsg << endl;
	} else if (currentGuess > targetNum){
	  cout << highMsg << endl;
	}
      }
    }while(currentGuess != targetNum);

    cout << winMessage << guesses << endl;
    cout << playAgainPrompt << endl;
    cin >> userInput;
    
  }while(userInput == 'y');
  return 0;
}
