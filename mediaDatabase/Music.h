#ifndef MUSIC_H
#define MUSIC_H

#include "Media.h"

class Music : public Media {
 private:
  char* artist;
  char* publisher;
  int duration;
 public:
  Music(char* title, int year, char* artist, char* publisher, int duration);
  Music& operator=(const Music& source);
  Music(const Music& source);
  ~Music();
  void print();
};

#endif
