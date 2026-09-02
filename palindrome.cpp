#include <iostream>
#include <cctype>
#include <cstring>
#include <limits>

using namespace std;

int main(){
  char userInput[81] = "";
  char forward[81] = "";
  char backward[81] = "";
  char trueMsg[] = "Palindrome.";
  char falseMsg[] = "Not a palindrome.";
  bool inputFail = false;

  //cin verification
  do{
    inputFail = false;
    cin.get(userInput,81);

    if (cin.fail()){
      inputFail = true;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n')
    }
  } while(inputFail);

  //only keeping alphabetical characters into forward
  for (int i=0; i<strlen(userInput); i++){
    if (isalpha(userInput[i])){
      forward[strlen(forward)]=tolower(userInput[i]);
    }
  }

  //assigning letters backwards into backward
  for (int i=1; i<=strlen(forward); i++){
    backward[i-1]=forward[strlen(forward)-i];
  }

  //check if the strings are the same
  if(!strcmp(forward,backward)){
    cout << trueMsg << endl;
  } else{
    cout << falseMsg<< endl;
  }
  
  return 0;
}
