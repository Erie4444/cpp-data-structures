/*
  Eric Zhao
  10/8/26
  Student List
  A program that has commands to add, remove, and print students
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <iterator>
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

  //used for debugging
  void printInfo(){
    cout << firstNameMsg << firstName << endl;
    cout << lastNameMsg << lastName << endl;
    cout << IDMsg << ID << endl;
    cout << GPAMsg << fixed << setprecision(2) << GPA << endl;
  }
  //used for the actual print method
  void printInfoOneLine(){
    cout << firstName << separator << lastName << separator << ID << separator << fixed << setprecision(2) << GPA << endl;
  }
};

//prints the contents of the vector
void print(vector<Student*> list){
  char noItemsMsg[30] = "No students currently in list";
  //loops through the vector and runs the printInfoOneLine() for each Student
  for (vector<Student*>::iterator it = list.begin(); it != list.end(); ++it){
    (*it) -> printInfoOneLine();
  }
  //outputs a message if the vector is empty
  if (list.size() == 0){
    cout << noItemsMsg << endl;
  }
  
}

//returns the pointer to a Student struct that corresponds to the ID
Student* findStudent(int ID, vector<Student*> list){
  //loops through the vector and check if the ID matches
  for (vector<Student*>::iterator it = list.begin(); it != list.end(); ++it){
    if ((*it) -> ID == ID){
      return *it;
    }
  }
  //returns nullptr if nothing matches
  return nullptr;
}

//add method to add a student to the list
//pointer so we can actually modify the list
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
  //getting the user inputs (these methods are in the utils.h file)
  prompt(firstNamePrompt,firstName);
  prompt(lastNamePrompt,lastName);
  prompt(IDPrompt,ID, true);
  prompt(GPAPrompt,GPA, true);

  //checking if the inputted id is already in the vector
  if (!findStudent(ID,*list)){

    //making a new Student instance
    Student* student = new Student;

    //assigning values
    strcpy(student -> firstName, firstName);
    strcpy(student -> lastName, lastName);
    student -> ID = ID;
    student -> GPA = GPA;

    //adding student to the vector
    list->push_back(student);
    cout << confirmation << endl;
  }else{
    cout << duplicate << endl;
  }
  

}

  


void del(vector<Student*>* list){
  char IDPrompt[58] = "Please enter the ID of the student you want to delete >> ";
  char confirmation[17] = "Deleted Student!";
  char invalidID[21] = "Student ID not found";
  int ID = 0;  

  //getting the ID of the student to remove
  prompt(IDPrompt, ID, true);
  Student* toDelete = findStudent(ID, *list); //returns a nullptr which is a falsely if nothing is found

  if (toDelete){
    //goes through the vector and erases the pointer to the corresponding student in the vector
    list -> erase(remove_if(list -> begin(),list -> end(), [ID](Student* student){return student -> ID == ID;}));
    //erases the student entirely to prevent a memory leak
    delete toDelete;
    cout << confirmation << endl;
  } else{
    cout << invalidID << endl;
  }
}

void quit(vector<Student*>* list){
  //deletes all instances in the vector
  for (Student* ptr : (*list)){
    delete ptr;
  }
  //deletes all the pointers in the vector
  list -> clear();
}

int main(){
  vector<Student*> list;
  char userPrompt[47] = "Enter a command (ADD, DELETE, PRINT, QUIT) >> ";
  char invalidInput[16] = "Invalid command";
  char addCommand[4] = "ADD";
  char deleteCommand[7] = "DELETE";
  char printCommand[6] = "PRINT";
  char quitCommand[5] = "QUIT";
  char userInput[81];
  bool running = true;
  do{
    //getting user input
    prompt(userPrompt,userInput);

    //running the corresponding method if the user input matches the command name
    if (!strcmp(userInput, addCommand)){
      add(&list);
    } else if (!strcmp(userInput,deleteCommand)){
      del(&list);
    } else if (!strcmp(userInput,printCommand)){
      print(list);
    } else if (!strcmp(userInput,quitCommand)){
      quit(&list);
      running = false;
    } else{
      cout << invalidInput << endl;
    }
  }while(running);
  
  return 0;
}
