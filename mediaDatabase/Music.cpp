#include "Music.h"
#include "Media.h"
#include <cstring>
#include <iostream>

using namespace std;

Music::Music(char* title, int year, char* artist, char* publisher, int duration) : Media(title, year){
  this -> artist = new char[strlen(artist)+1];
  strcpy(this -> artist, artist);
  this -> publisher = new char[strlen(publisher)+1];
  strcpy(this -> publisher, publisher);
  this -> duration = duration;
}

Music::Music(const Music& source) : Media(source){
  this -> artist = new char[strlen(source.artist)+1];
  strcpy(this -> artist, source.artist);
  this -> publisher = new char[strlen(source.publisher)+1];
  strcpy(this -> publisher, source.publisher);
  this -> duration  = source.duration;
}

Music& Music::operator=(const Music& source){
  if (this == &source){
    return (*this);
  }
  Media::operator=(source);
  this -> artist = new char[strlen(source.artist)+1];
  strcpy(this -> artist, source.artist);
  this -> publisher = new char[strlen(source.publisher)+1];
  strcpy(this -> publisher, source.publisher);
  this -> duration = source.duration;
  return (*this);
}

Music::~Music(){
  delete[] this -> artist;
  delete[] this -> publisher;
  this -> artist = nullptr;
  this -> publisher = nullptr;
}

void Music::print(){
  char artistMsg[9] = "Artist: ";
  char publisherMsg[12] = "Publisher: ";
  char durationMsg[11] = "Duration: ";
  char durationUnits[9] = " seconds";
  Media::print();
  cout << artistMsg << this -> artist << endl;
  cout << publisherMsg << this -> publisher << endl;
  cout << durationMsg << this -> duration << durationUnits << endl;
}
