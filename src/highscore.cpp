#include "highscore.h"


sqlite::sqlite _db("highquestions.db");

Highscore::Highscore() {}

Highscore::Highscore(std::string name, float score)
{
  this->_name = name;
  this->_score = score;
}

Highscore::addToHighscoreList()
{
  auto cur = _db.get_statement();
  cur->set_sql("INSERT INTO \"highscore\" values(?, \"?\")");
  cur->prepare();
  cur->bind(1, this->_score);
  cur->bind(2, this->_name);
  cur->step();
}

vector<Highscore> Highscore::getHighscores()
{
  auto cur = _db.get_statement();

}

std::string getName()
{
  return this->_name;
}

float getScore()
{
  return this->_score;
}
