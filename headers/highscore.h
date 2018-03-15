#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <string>
#include <vector>

#include "libsqlite.h"

class Highscore
{
public:
  Highscore();
  Highscore(std::string name, float score);

  void addToHighscoreList();

  vector<Highscore> getHighscores();

  std::string getName();
  float getScore();

private:
  std::string _name;
  float _score;

};

#endif
