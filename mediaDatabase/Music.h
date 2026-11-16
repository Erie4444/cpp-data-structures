#ifndef MUSIC_H
#define MUSIC_H

#include "Media.h"

//inherits from Media
class Music : public Media {
 private:
  //adds 3 more specific attributes
  char* artist;
  char* publisher;
  int duration;
 public:
  //just adds the basic 5 methods you need
  Music(char* title, int year, char* artist, char* publisher, int duration);
  Music& operator=(const Music& source);
  Music(const Music& source);
  ~Music();
  void print();
};

#endif
