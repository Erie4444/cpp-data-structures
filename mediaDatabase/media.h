#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

class Media{
 private:
  char title[];
  int year;
 public:
  Media(char title[], int year);
  Media(const Media& source);
  Media& operator=(const Media& source);
  ~Media();

  virtual int getYear();
  virtual char* getTitle();
}

#endif
