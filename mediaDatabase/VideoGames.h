#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include "Media.h"

//inherits from Media
class VideoGames : public Media {
 private:
  //specific attributes
  char* publisher;
  float rating;
 public:
  //same 5 methods
  VideoGames(char* title, int year, char* publisher, float rating);
  VideoGames& operator=(const VideoGames& source);
  VideoGames(const VideoGames& source);
  ~VideoGames();
  void print();
};

#endif
