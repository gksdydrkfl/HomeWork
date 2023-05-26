#pragma once
#include "int4.h"

class GlobalVar : public int4
{
public:
	static const int XLine = 20;
	static const int YLine = 10;


	static const int4 Left;
	static const int4 Right;
	static const int4 Up;
	static const int4 Down;
};

