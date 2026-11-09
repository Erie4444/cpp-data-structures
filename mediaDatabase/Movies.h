#ifndef MOVIES_H
#define MOVIES_H

#include "Media.h"

class Movies : public Media {
 private:
  char* director;
  int duration;
  float rating;
 public:
  Movies(char* title, int year, char* director, int duration, float rating);
  Movies& operator=(const Movies& source);
  Movies(const Movies& source);
  ~Movies();
  void print();
};

#endif
