#include "Movies.h"
#include "Media.h"
#include <cstring>
#include <iostream>

using namespace std;

//constructor inheriting from Media
Movies::Movies(char* title, int year, char* director, int duration, float rating) : Media(title, year){
  this -> director = new char[strlen(director)+1];
  strcpy(this -> director, director);
  this -> duration = duration;
  this -> rating = rating;
}

//copy constructor inheriting from Media
Movies::Movies(const Movies& source) : Media(source){
  this -> director = new char[strlen(source.director)+1];
  strcpy(this -> director, source.director);
  this -> duration = source.duration;
  this -> rating = source.rating;
}

//overloaded assignment
Movies& Movies::operator=(const Movies& source){
  if (this == &source){
    return (*this);
  }
  //runs the parent assignment method
  Media::operator=(source);
  //adds the attributes specific to movies
  this -> director = new char[strlen(source.director)+1];
  strcpy(this -> director, source.director);
  this -> duration = source.duration;
  this -> rating = source.rating;
  return (*this);
}

//destructor
Movies::~Movies(){
  delete[] this -> director;
  this -> director = nullptr;
}

//overridden print method that adds the specific attributes to the output
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
