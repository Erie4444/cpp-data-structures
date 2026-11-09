#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include "Media.h"

class VideoGames : public Media {
 private:
  char* publisher;
  float rating;
 public:
  VideoGames(char* title, int year, char* publisher, float rating);
  VideoGames& operator=(const VideoGames& source);
  VideoGames(const VideoGames& source);
  ~VideoGames();
  void print();
};

#endif
