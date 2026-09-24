#include <iostream>
#include <vector>
#include "utils.h"
using namespace std;

struct Student{
  char firstName[81];
  char lastName[81];
  int ID;
  float GPA;
};
void add(vector<Student>* list){
  char firstNamePrompt[] = "Please enter the student's first name >> ";
  char lastNamePrompt[] = "Please enter the student's last name >> ";
  char IDPrompt[] = "Please enter the student's ID >> ";
  char GPAPrompt[] = "Please enter the student's GPA >> ";
  char confirmation[] = "student added!";
  char firstName[81];
  char lastName[81];
  int ID = 0;
  int GPA = 0;

  prompt(firstNamePrompt,firstName);
  prompt(lastNamePrompt,lastName);
  prompt(IDPrompt,ID);
  prompt(GPAPrompt,GPA);
  Student* student = new Student{firstName,lastName,ID,GPA};
  list->push_back(student);
  cout << confirmation << endl;
}
  
int main(){
  vector<Student> list;
  add(&list);
  return 0;
}
