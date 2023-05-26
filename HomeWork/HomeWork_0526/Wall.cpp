#include"Wall.h"

bool Wall::GetWall() const
{
	return Destroy;
}

void Wall::SetWall(bool _Destroy)
{
	Destroy = _Destroy;
}

void Wall::SetIndex(int _Index)
{
	Index = _Index;
}

int Wall::GetIndex() const
{
	return Index;
}
