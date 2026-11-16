#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <limits>
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
  char directorPrompt[13] = "Director >> ";
  char yearPrompt[9] = "Year >> ";
  char ratingPrompt[23]  = "Rating (out of 10) >> ";
  char durationPrompt[23] = "Duration (seconds) >> ";
  char type[81] = "";
  char title[81] = "";
  char artist[81] = "";
  char publisher[81] = "";
  char director[81] = "";
  int year = 0;
  float rating = 0.0;
  int duration = 0;
  Media* media;
  prompt(typePrompt,type);

  if (!strcmp(lower(type),videoGame)){
    prompt(titlePrompt,title,99999,false);
    prompt(yearPrompt, year);
    prompt(publisherPrompt, publisher,99999,false);
    prompt(ratingPrompt, rating);
    database->push_back(new VideoGames(title,year,publisher,rating));
  }
  if (!strcmp(lower(type),movie)){
    prompt(titlePrompt, title, 99999, false);
    prompt(yearPrompt, year);
    prompt(directorPrompt, director, 99999, false);
    prompt(durationPrompt, duration);
    prompt(ratingPrompt, rating);
    database->push_back(new Movies(title,year,director,duration,rating));
  }
  if (!strcmp(lower(type),music)){
    prompt(titlePrompt,title, 99999, false);
    prompt(yearPrompt, year);
    prompt(artistPrompt, artist, 99999, false);
    prompt(durationPrompt, duration);
    prompt(publisherPrompt, publisher, 99999, false);
    database->push_back(new Music(title,year,artist,publisher,duration));
  }
}

void search(vector<Media*> database){
  char searchTypePrompt[32] = "search type (year or title) >> ";
  char titlePrompt[10] = "title >> ";
  char yearPrompt[9] = "year >> ";
  char titleKey[6] = "title";
  char yearKey[5] = "year";
  char invalidMsg[20] = "Invalid search type";
  char searchType[81] = "";
  char title[81] = "";
  int year = 0;
  prompt(searchTypePrompt,searchType);
  if (!strcmp(searchType, titleKey)){
    prompt(titlePrompt,title,99999,false);
  } else if (!strcmp(searchType, yearKey)){
      prompt(yearPrompt, year);
    } else{
      cout << invalidMsg << endl;
      return;
    }
  for (vector<Media*>::iterator it = database.begin(); it != database.end(); ++it){
    if (!strcmp(searchType,titleKey)){
      (*it)->searchByTitle(title);
    }
    if (!strcmp(searchType,yearKey)){
      (*it)->searchByYear(year);
    }
  }
}

void del(vector<Media*>* database){
  char deleteTypePrompt[32] = "delete type (year or title) >> ";
  char titlePrompt[10] = "title >> ";
  char yearPrompt[9] = "year >> ";
  char titleKey[6] = "title";
  char yearKey[5] = "year";
  char invalidMsg[20] = "Invalid delete type";
  char confirmationPrompt[24] = "are you sure? (y/n) >> ";
  char confirmation[81] = "";
  char no[2] = "n";
  char deleteType[81] = "";
  char title[81] = "";
  char* test;
  int year = 0;
  prompt(deleteTypePrompt,deleteType);
  if(!strcmp(deleteType, titleKey)){
    prompt(titlePrompt, title, 99999, false);
  } else if (!strcmp(deleteType, yearKey)){
    prompt(yearPrompt, year);
  } else{
    cout << invalidMsg << endl;
    return;
  }
  prompt(confirmationPrompt, confirmation);
  if (!strcmp(confirmation,no)){
    return;
  }
  for (vector<Media*>::iterator it = database->begin(); it != database->end();){
    if((!strcmp(deleteType, titleKey) && !strcmp((*it)->getTitle(),title)) || (!strcmp(deleteType, yearKey) && (*it)->getYear() == year)){
      delete (*it);
      it = database->erase(it);
    } else{
      ++it;
    }
  }
}

//only used for debugging
void printDatabase(vector<Media*> database){
  char noItemsMsg[21] = "No media in database";
  for (vector<Media*>::iterator it = database.begin(); it != database.end(); ++it){
    (*it) -> print();
  }
}

int main(){
  vector<Media*> database;
  add(&database);
  printDatabase(database);
  search(database);
  del(&database);
  printDatabase(database);
  return 0;
}
