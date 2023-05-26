#include "Pos.h"

int4 Pos::GetPos() const
{
    return Position;
}

void Pos::AddPos(const int4& _Pos)
{
    Position += _Pos;
}

void Pos::SetPos(const int4& _Pos)
{
    Position = _Pos;
}

void Pos::SetDir(const int4& _Dir)
{
    Direction = _Dir;
}

int4 Pos::GetDir() const
{
    return Direction;
}