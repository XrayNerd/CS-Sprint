/*  SearchCell
*   Search Cell finds the shortest path between two nodes.
*/

#include <math.h>

#define WORLD_SIZE

struct SearchCell;
{
public:
    int n_xcoord, n_ycoord;
    int n_id;
    SearchCell *parent;
    float G; //Movement cost from the start point to current square
    float H; //Estimated movement cost from current square to the destination point

    SearchCell() : parent(0) {}
    SearchCell(int x ,int y, SearchCell *_parent=0) : n_xcoord, n_ycoord, parent(_parent),
     n_id(y * WORLD_SIZE + x), G(0), H(0) {};

     float GetF() {return G+H;}
     float ManHattanDistance(SearchCell *nodeEnd)
     {
       float x = (float)(fabs(this->n_xcoord - nodeEnd -> n_xcoord));
       float y = (float)(fabs(this->n_ycoord - nodeEnd -> n_ycoord));
       return x+y;

     }

}
