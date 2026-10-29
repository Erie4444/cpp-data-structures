#include "Media.h"
#include <cstring>
#include <iostream>

using namespace std;

//constructor
Media::Media(char* title, int year){
  this->title = new char[strlen(title)+1];
  strcpy(this->title,title);
  this->year = year;
}

//copy constructor
Media::Media(const Media& source){
  this->title = new char[strlen(source.title)+1];
  strcpy(this->title,source.title);
  this->year = source.year;
}
//assignment overload
Media& Media::operator=(const Media& source){
  if (this == &source){
    return (*this);
  }
  this->title = new char[strlen(source.title)+1];
  strcpy(this->title,source.title);
  this->year = source.year;
  return (*this);
}
//destructor
Media::~Media(){
  delete[] this->title;
}

void Media::print(){
  char titleMsg[8] = "Title: ";
  char yearMsg[7] = "Year: ";
  cout << titleMsg << this->title << endl;
  cout << yearMsg << this->year << endl;
}

void Media::assign(char* title, int year){
  strcpy(this->title,title);
  this->year = year;
}

