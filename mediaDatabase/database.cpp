#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"
#include "Media.h"
#include "../utils/utils.h"

using namespace std;

void add(vector<Media*>* database){
  char videoGame[11] = "game";
  char movie[6] = "movie";
  char music[6] = "music";
  char typePrompt[42] = "Media type (Game, Movie, Music) >> ";
  char titlePrompt[10] = "Title >> ";
  char artistPrompt[11] = "Artist >> ";
  char publisherPrompt[14] = "Publisher >> ";
  char type[81] = "";
  char title[81] = "";
  char artist[81] = "";
  char publisher[81] = "";
  char director = [81] = "";
  int year = 0;
  float rating = 0.0;
  int duration = 0;
  
  prompt(typePrompt,type);

  if (!strcmp(lower(type),videoGame)){
    cout << "Game";
  }
  if (!strcmp(lower(type),movie)){
    cout << "Movie";
  }
  if (!strcmp(lower(type),music)){
    cout << "Music";
  }
}

int main(){
  vector<Media*> database;
  add(&database);
  return 0;
}
