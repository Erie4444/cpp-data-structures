#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

class VideoGames : public Media{
 private:
  char* publisher;
  int rating;
 public:
  VideoGames(char* title, int year, char* publisher, int rating) : Media(title, year);
  VideoGames& operator=(const VideoGames& source);
  VideoGames(const VideoGames& source) : Media(source);
  ~VideoGames();
  void virtual print();
}

#endif
