#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <vector>
#include "global.h"

class PathFinding
{
public:
  PathFinding(void);
  ~PathFinding(void);

  void FindPath(Vector2 currentPos, Vector2 targetPos);
  Vector2 NextPathPos();

  void ClearOpenList()
  {m_openList.clear();}

  void ClearVisitedList()
  {n_visitedList.clear() ;}

  void ClearPathToObj()
  {m_pathToObj.clear();}

  bool m_initializedStartObj ;
  bool m_foundObj ;

private:

  void SetStartAndObj (SearchCell start, SearchCell obj);
  void PathOpened (int x , int z, float newCost, SearchCell *parent );
  SearchCell *GetNextCell();
  void ContinuePath();

  SearchCell *m_startCell;
  SearchCell *m_goalCell;
  std::vector<SearchCell*> m_openList;
  std::vector<SearchCell*> m_visitedList;
  std::vector<Vector2*>m_pathToObj;
};

#endif
