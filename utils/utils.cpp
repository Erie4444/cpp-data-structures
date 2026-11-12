#include "utils.h"
#include <iostream>
#include <limits>
#include <cctype>

using namespace std;

void clearCINBuffer(){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

bool verifyCIN(){
  if (cin.fail()){
    clearCINBuffer();
    return false;
    
  } else if (cin.peek() != EOF && cin.peek() != '\n'){
    clearCINBuffer();
  }
  return true;
}

bool verifyWholeCIN(){
  if (cin.fail() || (cin.peek() != EOF && cin.peek() != '\n')){
    clearCINBuffer();
    return false;
  }
  return true;
}

void prompt(char promptMsg[], char variable[], int size, bool checkWholeCIN = false){
  //do{
    cout << promptMsg;
    cout << "getline";
    cin.getline(variable, size);
    //}while ((!checkWholeCIN && !verifyCIN()) || (checkWholeCIN && !verifyWholeCIN()));
}

char* lower(char input[]){
  for (int i = 0; input[i] != '\0'; i++){
    input[i] = tolower(static_cast<unsigned char>(input[i]));
  }
  return input;
}
