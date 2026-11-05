#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;


int main(){
  //testing instantiating the Media class
  char hkTitle[14] = "Hollow Knight";
  char hkvTitle[24] = "Hollow Knight Voidheart";
  char ssTitle[9] = "SilkSong";
  char reassignMsg[11] = "reassigned";
  char constructorMsg[17] = "constructor test";
  char copyMsg[10] = "copy test";
  char assignmentMsg[12] = "assign test";
  char passedMsg[9] = "Passed: ";
  char searchByTitleMsg[16] = "search by title";
  char searchByYearMsg[15] = "search by year";
  int hkYear = 2017;
  int hkvYear = 2018;
  int ssYear = 2025;
  Media* hk = new Media(hkTitle,hkYear);
  cout << constructorMsg << endl;
  //hk->print();
  cout << passedMsg << (strcmp(hkTitle,hk->getTitle()) == 0 && hk->getYear() == hkYear) << endl;
  cout << endl;

  cout << copyMsg << endl;
  Media* hkv = new Media((*hk));
  //hk->print();
  //hkv->print();
  hkv->assign(hkvTitle,hkvYear);
  //cout << reassignMsg << endl;
  //hk->print();
  //hkv->print();
  cout << passedMsg << (strcmp(hkTitle, hk->getTitle()) == 0 && hk->getYear() == hkYear && strcmp(hkvTitle, hkv->getTitle()) == 0 && hkv->getYear() == hkvYear) << endl;
  cout << endl;
  
  cout << assignmentMsg << endl;
  Media* ss = new Media(hkvTitle,hkvYear);
  (*ss)=(*hk);
  //cout << reassignMsg << endl;
  //hk->print();
  //ss->print();
  ss->assign(ssTitle,ssYear);
  //cout << reassignMsg << endl;
  //hk->print();
  //ss->print();
  cout << passedMsg << (strcmp(hkTitle, hk->getTitle()) == 0 && hk->getYear() == hkYear && strcmp(ssTitle,ss->getTitle()) == 0 && ss->getYear() == ssYear) << endl;
  cout << endl;

  cout << searchByTitleMsg << endl;
  ss->searchByTitle(ssTitle);
  cout << endl;

  cout << searchByYearMsg << endl;
  ss->searchByYear(2025);
  
  delete hk;
  delete ss;
  delete hkv;
  return 0;
}
