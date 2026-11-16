/*
  Eric Zhao
  11/16/26
  A database that keeps track of different media and their different attributes
  Has functionality to add media, search for media, and delete media
 */
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

//method run to add media to the database
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
  //getting the type of media they want
  prompt(typePrompt,type);

  //adding a videogame
  if (!strcmp(lower(type),videoGame)){
    //prompts with 99999 and false use cin.getline() instead of cin <<
    prompt(titlePrompt,title,99999,false);
    prompt(yearPrompt, year);
    prompt(publisherPrompt, publisher,99999,false);
    prompt(ratingPrompt, rating);
    database->push_back(new VideoGames(title,year,publisher,rating));
  }

  //adding a movie
  if (!strcmp(lower(type),movie)){
    prompt(titlePrompt, title, 99999, false);
    prompt(yearPrompt, year);
    prompt(directorPrompt, director, 99999, false);
    prompt(durationPrompt, duration);
    prompt(ratingPrompt, rating);
    database->push_back(new Movies(title,year,director,duration,rating));
  }

  //adding music
  if (!strcmp(lower(type),music)){
    prompt(titlePrompt,title, 99999, false);
    prompt(yearPrompt, year);
    prompt(artistPrompt, artist, 99999, false);
    prompt(durationPrompt, duration);
    prompt(publisherPrompt, publisher, 99999, false);
    database->push_back(new Music(title,year,artist,publisher,duration));
  }
}

//method to search for media
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
  //gets the attribute they want to search with
  prompt(searchTypePrompt,searchType);
  //running the corresponding prompt based on the search type
  if (!strcmp(searchType, titleKey)){
    prompt(titlePrompt,title,99999,false);
  } else if (!strcmp(searchType, yearKey)){
      prompt(yearPrompt, year);
  } else{ //gives invalid if the type doesn't match any of the keys
      cout << invalidMsg << endl;
      return;
    }

  //iterating through the database vector and running the corresponding search method
  //the media class's search method automatically outputs the media information
  for (vector<Media*>::iterator it = database.begin(); it != database.end(); ++it){
    if (!strcmp(searchType,titleKey)){
      (*it)->searchByTitle(title);
    }
    if (!strcmp(searchType,yearKey)){
      (*it)->searchByYear(year);
    }
  }
}

//method run when deleting media
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
  //getting how the user wants to delete
  prompt(deleteTypePrompt,deleteType);
  //running the corresponding prompt based on their delete type (similar to searching)
  if(!strcmp(deleteType, titleKey)){
    prompt(titlePrompt, title, 99999, false);
  } else if (!strcmp(deleteType, yearKey)){
    prompt(yearPrompt, year);
  } else{ //give invalid if the type doesn't match
    cout << invalidMsg << endl;
    return;
  }
  //runs a confirmation prompt
  prompt(confirmationPrompt, confirmation);
  if (!strcmp(lower(confirmation),no)){
    return;
  }
  //iterates through the vector and deletes the media if the attribute matches (no built-in method in the media class)
  for (vector<Media*>::iterator it = database->begin(); it != database->end();){
    if((!strcmp(deleteType, titleKey) && !strcmp((*it)->getTitle(),title)) || (!strcmp(deleteType, yearKey) && (*it)->getYear() == year)){
      delete (*it);
      it = database->erase(it);
    } else{//only iterate if you didn't delete anything because when you delete an object, the rest of the contents get moved
      ++it;
    }
  }
}


//only used for debugging
//just prints out the whole database
void printDatabase(vector<Media*> database){
  char noItemsMsg[21] = "No media in database";
  for (vector<Media*>::iterator it = database.begin(); it != database.end(); ++it){
    (*it) -> print();
  }
}

int main(){
  char commandPrompt[48] = "Enter a command (ADD, SEARCH, DELETE, QUIT) >> ";
  char invalidMsg[16] = "Invalid command";
  char addKey[4] = "add";
  char searchKey[7] = "search";
  char deleteKey[7] = "delete";
  char quitKey[5] = "quit";
  char command[81] = "";
  bool running = true;
  vector<Media*> database;
  //runs until running is false which means user called quit
  while(running){
    //getting the prompt from the user
    prompt(commandPrompt, command);
    //running the corresponding method
    if (!strcmp(lower(command),addKey)){
      add(&database);
    }
    else if(!strcmp(lower(command),searchKey)){
      search(database);
    }
    else if(!strcmp(lower(command),deleteKey)){
      del(&database);
    }
    else if(!strcmp(lower(command),quitKey)){
      running = false;
    }
    else { //prints invalid command when no commands match
      cout << invalidMsg << endl;
    }
  }
  return 0;
}
