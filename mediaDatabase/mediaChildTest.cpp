#include <iostream>
#include "Media.h"
#include "VideoGames.h"

using namespace std;

int main(){
  char vgMsg[11] = "VideoGames";
  char hkTitle[14] = "Hollow Knight";
  int hkYear = 2017;
  char publisher[12] = "Team Cherry";
  float rating = 4.5;
  Media* media = new VideoGames(hkTitle,hkYear,publisher,rating);
  media -> searchByTitle(hkTitle);
  media -> searchByYear(hkYear);
  return 0;
}
