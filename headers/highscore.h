#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <vector>

#include "libsqlite.h"

class Highscore
{
public:
  Highscore();
  Highscore(std::string name, int score);

  void addToHighscoreList();

  std::vector<Highscore> getHighscores();

  std::string getName();
  int getScore();

private:
  std::string _name;
  int _score;

};

#endif
