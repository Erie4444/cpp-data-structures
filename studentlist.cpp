#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include "utils.h"
using namespace std;

struct Student{
  char firstNameMsg[13] = "First Name: ";
  char lastNameMsg[12] = "Last Name: ";
  char IDMsg[5] = "ID: ";
  char GPAMsg[6] = "GPA: ";
  char separator[3] = ", ";
  char firstName[81];
  char lastName[81];
  int ID;
  float GPA;

  void printInfo(){
    cout << firstNameMsg << firstName << endl;
    cout << lastNameMsg << lastName << endl;
    cout << IDMsg << ID << endl;
    cout << GPAMsg << fixed << setprecision(2) << GPA << endl;
  }

  void printInfoOneLine(){
    cout << firstName << separator << lastName << separator << ID << separator << GPA << endl;
  }
};

void print(vector<Student*> list){
  char separator[3] = ", ";
  for (vector<Student*>::iterator it = list.begin(); it != list.end(); ++it){
    (*it) -> printInfoOneLine();
  }
}

Student* findStudent(int ID, vector<Student*> list){
  for (vector<Student*>::iterator it = list.begin(); it != list.end(); ++it){
    if ((*it) -> ID == ID){
      return *it;
    }
  }
  return nullptr;
}

void add(vector<Student*>* list){
  char firstNamePrompt[42] = "Please enter the student's first name >> ";
  char lastNamePrompt[41] = "Please enter the student's last name >> ";
  char IDPrompt[34] = "Please enter the student's ID >> ";
  char GPAPrompt[35] = "Please enter the student's GPA >> ";
  char confirmation[15] = "student added!";
  char duplicate[26] = "student ID already exists";
  char firstName[81] = "";
  char lastName[81] = "";
  int ID = 0;
  float GPA = 0;
  prompt(firstNamePrompt,firstName);
  prompt(lastNamePrompt,lastName);
  prompt(IDPrompt,ID);
  prompt(GPAPrompt,GPA);
  Student* student = new Student;
  strcpy(student -> firstName, firstName);
  strcpy(student -> lastName, lastName);
  student -> ID = ID;
  student -> GPA = GPA;
  if (!findStudent(ID,*list)){
    list->push_back(student);
    cout << confirmation << endl;
  } else{
    cout << duplicate << endl;
  }
}

void del(vector<Student*>* list){
  char IDPrompt[58] = "Please enter the ID of the student you want to delete >> ";
  char confirmation[17] = "Deleted Student!";
  char invalidID[21] = "Student ID not found";
  int ID = 0;  
  prompt(IDPrompt, ID);
  if (findStudent(ID, *list)){
    list -> erase(remove_if(list -> begin(),list -> end(), [ID](Student* student){return student -> ID == ID;}));
    cout << confirmation << endl;
  } else{
    cout << invalidID << endl;
  }
}

void quit(vector<Student*>* list){
  list.clear();
}
int main(){
  vector<Student*> list;
  bool running = true;
  
  return 0;
}
