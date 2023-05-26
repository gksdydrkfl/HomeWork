#pragma once
#include "Pos.h"

class Wall : public Pos
{
public:
	bool GetWall() const;
	void SetWall(bool _Destroy);
	void SetIndex(int _Index);
	int GetIndex() const;
private:
	int Index;
	bool Destroy = true;
};