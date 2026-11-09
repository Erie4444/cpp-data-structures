#ifndef MEDIA_H
#define MEDIA_H

class Media{
 protected:
  char* title;
  int year;
 public:
  Media(char* title, int year);
  Media& operator=(const Media& source);
  Media(const Media& source);
  virtual ~Media();
  virtual void print();
  void assign(char* title,int year);
  void searchByTitle(char* title);
  void searchByYear(int year);
  char* getTitle() const;
  int getYear() const;
};

#endif
