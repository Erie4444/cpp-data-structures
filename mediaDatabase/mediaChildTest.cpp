#include <iostream>
#include "Media.h"
#include "VideoGames.h"
#include "Music.h"
#include "Movies.h"

using namespace std;

int main(){
  char vgMsg[17] = "===VideoGames===";
  char searchByTitleMsg[9] = "By Title";
  char searchByYearMsg[8] = "By Year";
  char hkTitle[14] = "Hollow Knight";
  int hkYear = 2017;
  char hkPublisher[12] = "Team Cherry";
  float hkRating = 9.0;

  char musicMsg[12] = "===Music===";
  char tearsTitle[14] = "City of Tears";
  int tearsYear = 2017;
  char tearsArtist[12] = "Team Cherry";
  char tearsPublisher[12] = "Team Cherry";
  int tearsDuration = 178; //in seconds

  char movieMsg[13] = "===Movies===";
  char mcTitle[16] = "Minecraft Movie";
  int mcYear = 2025;
  char mcDirector[11] = "Jaren Hess";
  int mcDuration = 6060;
  float mcRating = 5.5;
  
  cout << vgMsg << endl;
  Media* media = new VideoGames(hkTitle,hkYear,hkPublisher,hkRating);
  cout << searchByTitleMsg << endl;
  media -> searchByTitle(hkTitle);
  cout << endl;
  cout << searchByYearMsg << endl;
  media -> searchByYear(hkYear);
  delete media;

  cout << endl;

  
  cout << musicMsg << endl;
  media = new Music(tearsTitle, tearsYear, tearsArtist, tearsPublisher, tearsDuration);
  cout << searchByTitleMsg << endl;
  media -> searchByTitle(tearsTitle);
  cout << endl;
  cout << searchByYearMsg<< endl;
  media -> searchByYear(tearsYear);
  delete media;

  cout << endl;

  cout << movieMsg << endl;
  media = new Movies(mcTitle,mcYear,mcDirector,mcDuration,mcRating);
  cout << searchByTitleMsg << endl;
  media -> searchByTitle(mcTitle);
  cout << endl;
  cout << searchByYearMsg << endl;
  media -> searchByYear(mcYear);
  delete media;
  
  return 0;
}
