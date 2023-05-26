#pragma once
#include "int4.h"
#include "GlobalVar.h"
class ConsoleScreen : public int4
{
public:
    ConsoleScreen()
    {

    }

    void Init(char _BaseCh);

    void SetPixel(const int4& _Pos, char _Ch);

    void Clear();

    bool IsScreenOut(const int4& _Pos) const;

    void Print() const;

    bool IsWall(const int4& _Pos) const;

protected:


private:
    char BaseCh = ' ';
    char ArrScreen[GlobalVar::YLine][GlobalVar::XLine + 1] = {};
};