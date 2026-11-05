#include "VideoGames.h"
#include <cstring>
#include <iostream>

using namespace std;

VideoGames::VideoGames(char* title, int year, char* publisher, int rating){
  this -> publisher = new char[strlen(publisher+1)];
  strcpy(this -> publisher, publisher);
  this -> rating = rating;
}

VideoGames::VideoGames(const VideoGames& source){
}
