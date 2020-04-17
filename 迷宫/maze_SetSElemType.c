#include "maze.h"

void SetSElemType (SElemType_Sq *e, int ord, PosType seat, int di)
{
	(*e).ord = ord;
	(*e).seat = seat;
	(*e).di = di;
}
