#ifndef MEDIA_H
#define MEDIA_H

class Media{
protected: //only accessible for children
  //generic information that every media has
  char* title;
  int year;
 public:
  //constructor
  Media(char* title, int year);
  //overloaded assignment
  Media& operator=(const Media& source);
  //copy constructor
  Media(const Media& source);
  //destructor
  //virtual because different children will need to delete more elements such as director
  virtual ~Media();
  //virtual because different children will have different attributes to print out
  virtual void print();
  //misc. methods
  void assign(char* title,int year);
  void searchByTitle(char* title);
  void searchByYear(int year);
  char* getTitle() const;
  int getYear() const;
};

#endif
