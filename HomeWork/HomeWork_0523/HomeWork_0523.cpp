#include <iostream>

class Test
{
public:


    // [A][A][A][A][cc?][cc?][cc?][cc?] [B][B][B][B][B][B][B][B] [C][D][E][E][F][F][F][F]
    int A;
    __int64 B;
    char C;
    char D;
    short E; // 2바이트 정수입니다.
    int F;
};

// 1 2 4 8

class Player
{
public:
    int HP;
    int ATT;
};

//  [H][H][H][H][A][A][A][A] //  [A][A][A][A][][][][]
void TestFunction(Player _Newplayer, int _Test)
{
    int a = 10;
    // 이것도 확인해보세요.
}

int main()
{

    Player NewPlayer;
    NewPlayer.HP = 10;
    NewPlayer.ATT = 10;
    TestFunction(NewPlayer, 20);

    Test t;
    t.A = 1;
    t.B = 2;
    t.C = 'a';
    t.D = 'b';
    t.E = 3;
    t.F = 4;

    int test = 10;
}