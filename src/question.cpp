#include "question.h"

#include <iostream>


sqlite::sqlite _db("highquestions.db");

Question::Question() {}

Question::Question(SDL_Texture* tileset, Graphics &graphics, Vector2 position, unsigned short id) : Tile (tileset, graphics, position, id)
{
}

std::vector<std::string> Question::getRandomQuestion()
{
  auto cur = _db.get_statement();
  cur->set_sql("SELECT * FROM any_questions LIMIT (ABS(RANDOM()) % (SELECT COUNT(*) FROM any_questions)),1;");
  cur->prepare();
  cur->step();
  std::vector<std::string> stringArr = {cur->get_text(1), cur->get_text(2), cur->get_text(3)};

  return stringArr;

}
