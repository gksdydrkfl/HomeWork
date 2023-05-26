#pragma once
#include "int4.h"
class Pos : public int4
{
public:
    int4 GetPos() const;

    void AddPos(const int4& _Pos);

    void SetPos(const int4& _Pos);

    void SetDir(const int4& _Dir);

    int4 GetDir() const;
private:

    int4 Position;
    int4 Direction;
};