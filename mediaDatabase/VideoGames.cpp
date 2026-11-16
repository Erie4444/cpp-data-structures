#include "VideoGames.h"
#include "Media.h"
#include <cstring>
#include <iostream>

using namespace std;

//constructor inheriting from Media
VideoGames::VideoGames(char* title, int year, char* publisher, float rating) : Media(title, year){
  this -> publisher = new char[strlen(publisher)+1];
  strcpy(this -> publisher, publisher);
  this -> rating = rating;
}

//copy constructor inheriting from Media
VideoGames::VideoGames(const VideoGames& source) : Media(source){
  this -> publisher = new char[strlen(source.publisher)+1];
  strcpy(this -> publisher, source.publisher);
  this -> rating = source.rating;
}

//overloaded assignment
VideoGames& VideoGames::operator=(const VideoGames& source){
  if (this == &source){
    return (*this);
  }
  //runs the parent overloaded assignment method
  Media::operator=(source);
  this -> publisher = new char[strlen(source.publisher)+1];
  strcpy(this -> publisher, source.publisher);
  this -> rating = source.rating;
  return (*this);
}

//destructor
VideoGames::~VideoGames(){
  delete[] this->publisher;
  this->publisher = nullptr;
}


//overridded print method that adds more information specific to VideoGames
void VideoGames::print(){
  char publisherMsg[12] = "Publisher: ";
  char ratingMsg[9] = "Rating: ";
  char ratingUnits[4] = "/10";
  Media::print();
  cout << publisherMsg << this -> publisher << endl;
  cout << ratingMsg << this -> rating << ratingUnits << endl;
}
