#include "highscore.h"
#include <iostream>


Highscore::Highscore() {}

Highscore::Highscore(std::string name, int score)
{
  this->_name = name;
  this->_score = score;
}

// Chris & Alex
// Takes the class variables
// And adds them to the database
void Highscore::addToHighscoreList()
{
  sqlite::sqlite _db("highquestions.db");
  auto cur = _db.get_statement();
  cur->set_sql("INSERT INTO user_table (Name, Score) values(?, ?)");
  cur->prepare();
  cur->bind(1, this->_name);
  cur->bind(2, this->_score);
  cur->step();
}


// Chris & Alex
// Returns a vector of
// all Highscores in the
// Database
std::vector<Highscore> Highscore::getHighscores()
{
  std::string name;
  int score;
  std::vector<Highscore> highscoreList;

  // Open database
  sqlite::sqlite _db("highquestions.db");

  // Setup cursor
  auto cur = _db.get_statement();
  cur->set_sql("SELECT Name, Score FROM user_table");
  cur->prepare();

  // While there are more rows continue
  while( cur->step() ) {
    name = cur->get_text(0);
    score = cur->get_int(1);
    Highscore highscore(name, score);
    highscoreList.push_back(highscore);
  }
  return highscoreList;
}

std::string Highscore::getName()
{
  return this->_name;
}

int Highscore::getScore()
{
  return this->_score;
}
