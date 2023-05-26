#pragma once
#include "Pos.h"

class Bullet : public Pos
{
public:
	Bullet();

	void Fire();

	bool bFire = false;
private:

};