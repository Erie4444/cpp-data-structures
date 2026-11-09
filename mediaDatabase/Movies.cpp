#include "Movies.h"
#include "Media.h"
#include <cstring>
#include <iostream>

using namespace std;

Movies::Movies(char* title, int year, char* director, int duration, float rating) : Media(title, year){
  this -> director = new char[strlen(director)+1];
  strcpy(this -> director, director);
  this -> duration = duration;
  this -> rating = rating;
}

Movies::Movies(const Movies& source) : Media(source){
  this -> director = new char[strlen(source.director)+1];
  strcpy(this -> director, source.director);
  this -> duration = source.duration;
  this -> rating = source.rating;
}

Movies& Movies::operator=(const Movies& source){
  if (this == &source){
    return (*this);
  }
  Media::operator=(source);
  this -> director = new char[strlen(source.director)+1];
  strcpy(this -> director, source.director);
  this -> duration = source.duration;
  this -> rating = source.rating;
  return (*this);
}

Movies::~Movies(){
  delete[] this -> director;
  this -> director = nullptr;
}

void Movies::print(){
  char directorMsg[11] = "Director: ";
  char durationMsg[11] = "Duration: ";
  char ratingMsg[9] = "Rating: ";
  char durationUnits[9] = " seconds";
  char ratingUnits[4] = "/10";
  Media::print();
  cout << directorMsg << this -> director << endl;
  cout << durationMsg << this -> duration << durationUnits << endl;
  cout << ratingMsg << this -> rating << ratingUnits << endl;
}
