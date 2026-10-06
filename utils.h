#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;

void flushCINBuffer();
bool verifyCIN();
void upper(char (&input)[81]);
  
template <typename T>
bool in(T array[], T value){
  for (T item : (*array)){
    if(item == value){
      return true;
    }
  }
  return false;
}
template <typename T>
void prompt(char promptMsg[], T& variable){
  do{
    cout << promptMsg;
    cin >> variable;
  }while (!verifyCIN());
}


#endif
