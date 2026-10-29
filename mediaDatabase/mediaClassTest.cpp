#include <iostream>
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
  int hkYear = 2017;
  int hkvYear = 2018;
  int ssYear = 2025;
  Media* hk = new Media(hkTitle,hkYear);
  cout << constructorMsg << endl;
  hk->print();

  cout << copyMsg << endl;
  Media* hkv = new Media((*hk));
  hk->print();
  hkv->print();
  hkv->assign(hkvTitle,hkvYear);
  cout << reassignMsg << endl;
  hk->print();
  hkv->print();

  cout << assignmentMsg << endl;
  Media* ss = new Media(ssTitle,ssYear);
  ss->print();
  ss=hk;
  cout << reassignMsg << endl;
  hk->print();
  ss->print();
  ss->assign(ssTitle,ssYear);
  cout << reassignMsg << endl;
  hk->print();
  ss->print();

  delete hk;
  delete hkv;
  delete ss;
  return 0;
}
