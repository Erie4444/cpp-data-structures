#include <iostream>
#include <limits>

using namespace std;

/*
  1) No global variables
  2) Never use strings
  3) Include <iostring> not stdio

  other rules:
   - try not to use the mouse
   - try not to use breaks and continues
 */

bool validateCIN(){
  //checks if cin failed, and if so, flushes the cin buffer
  if (cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return false;
  } else{
    //checks if there are still any garbage characters left in cin buffer
    if (cin.peek() != EOF && cin.peek() != '\n'){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return true;
  }
}

void cleanup(){
  //just flushes cin and cout buffers
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  cout << flush;
}

int main(){
  int targetNum = 0;
  int guesses = 0;
  int currentGuess = 0;
  //cstrings for messages
  char prompt[20] = "Guess (0-100): ";
  char winMessage[40] = "You guessed it! Guesses: ";
  char playAgainPrompt[20] = "Play again? (y/n)";
  char errorMsg[40] = "Please enter a valid guess (0-100)";
  char lowMsg[40] = "Too low!";
  char highMsg[40] = "Too high!";
  char userInput = 'y';
  srand(time(NULL)); //setting the rand seed
  //main game loop
  do {
    targetNum = rand()%101; //set number to a number between 0 & 100
    //loop to continuously ask the user for an input if they are wrong
    do{
      
      cout << prompt;
      cin >> currentGuess;

      //cin validation
      if (!validateCIN()){
	//outputs error message if cin failed
	cout << errorMsg << endl;
      } else{
	guesses++;
	//outputting corresponding message if guess is too high or too low
	if (currentGuess < targetNum){
	  cout << lowMsg << endl;
	} else if (currentGuess > targetNum){
	  cout << highMsg << endl;
	}
      }
      
    }while(currentGuess != targetNum);
    //User guessed the right number
    cout << winMessage << guesses << endl;
    cout << playAgainPrompt << endl;
    cin >> userInput;
    validateCIN();
    
  }while(userInput == 'y');
  cleanup(); //flushes cin and cout buffers (i think terminating the file also flushes them too)
  return 0;
}
