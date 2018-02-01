#include <math.h>

#define WORLD_SIZE

struct SearchTile
{
public:
    int n_xcoord, n_ycoord;
    int n_id;
    SearchCell *parent;
    float G; //Movement cost from the start point to current square
    float H; //Estimated movement cost from current square to the destination point

    SearchTile() : parent(0) {}
    SearchTile(int x ,int y, SearchTile *_parent=0) : n_xcoord, n_ycoord, parent(_parent),
     n_id(y * WORLD_SIZE + y), G(0), H(0) {};

     float GetF() {return G+H;}
     float ManHattanDistance(SearchTile *nodeEnd)
     {
       float x = (float)(fabs(this->n_xcoord - nodeEnd -> n_xcoord));
       float y = (float)(fabs(this->n_ycoord - nodeEnd -> n_ycoord));
       return x+y;

     }

}
