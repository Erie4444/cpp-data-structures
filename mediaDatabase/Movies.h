#ifndef MOVIES_H
#define MOVIES_H

#include "Media.h"

//inherits from Media
class Movies : public Media {
 private:
  //specific attributes
  char* director;
  int duration;
  float rating;
 public:
  //same 5 methods, constructors, assignment, print, and destructor
  Movies(char* title, int year, char* director, int duration, float rating);
  Movies& operator=(const Movies& source);
  Movies(const Movies& source);
  ~Movies();
  void print();
};

#endif
