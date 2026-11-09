#include "VideoGames.h"
#include <cstring>
#include <iostream>

using namespace std;

VideoGames::VideoGames(char* title, int year, char* publisher, float rating) : Media(title, year){
  this -> publisher = new char[strlen(publisher)+1];
  strcpy(this -> publisher, publisher);
  this -> rating = rating;
}

VideoGames::VideoGames(const VideoGames& source) : Media(source){
  this -> publisher = new char[strlen(source.publisher)+1];
  strcpy(this -> publisher, source.publisher);
  this -> rating = source.rating;
}

VideoGames& VideoGames::operator=(const VideoGames& source){
  if (this == &source){
    return (*this);
  }
  Media::operator=(source);
  this -> publisher = new char[strlen(source.publisher)+1];
  strcpy(this -> publisher, source.publisher);
  this -> rating = source.rating;
  return (*this);
}

VideoGames::~VideoGames(){
  delete[] this->publisher;
  this->publisher = nullptr;
}

void print(){
  char publisherMsg[12] = "Publisher: ";
  char ratingMsg[9] = "Rating: ";
  Media::print();
  cout << publisherMsg << this -> publisher << endl;
  cout << ratingMsg << this -> rating << endl;
}
