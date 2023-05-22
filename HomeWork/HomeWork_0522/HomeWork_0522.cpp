#include <iostream>
#include <conio.h> // 키를 누를때까지 기다리는 함수

// 숙제 1 -- 문자의 오른쪽끝을 맞춰오세요. 이름은 알파뱃만
// fasdhjkfasdhjfkasd--------
// Monster-------------------
// 위와같이 UI의 끝부분이 맞게 만들어라.

// 숙제 2 -- 실시간으로 만들어오세요.
// 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 만들어라.
// 화면 지우는 함수 화면에 출력하는 함수를 잘 생각해보세요.
// 그냥 무식하게 생각해라.

// 숙제 3 -- 누군가 죽었다. 누군가의 Hp가 0이 된순간 종료.


// 상태와 개념을 하나로 묶어서 내가 인간적인 생각을 문법으로 표현한다.
// 이걸 객체지향의 특성이 추상화라고 합니다.
class Player
{

};

int StrCount(const char* const _Str)
{
    int Count = 0;
    while (_Str[Count])
    {
        ++Count;
    }

    return Count;
}

void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    int Count = 0;
    Count = StrCount(_Name);

    // 40개로 맞춰오세요.

    // 줄바꿈이 안되고 있습니다.
    printf_s("%s", _Name);
    while (Count < 40)
    {
        printf_s("-");
        ++Count;
    }
    printf_s("\n");
    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);
    printf_s("----------------------------------------\n");
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

void Damage(int& _Hp, int _Att)
{
    _Hp -= _Att;
}

// 내일꼭 break continue

int main()
{
    int PlayerHp = 200;
    int PlayerAtt = 10;
    char PlayerName[40] = "fgfdgfdgdfg";

    int MonsterHp = 100;
    int MonsterAtt = 10;
    char MonsterName[40] = "Monster";

    while (true)
    {
        // 콘솔창을 모조리 지우는 함수
        system("cls");

        // 한번에 함수로 만든것이고
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);

        _getch();

        // 아무키나 입력할때까지 기다리는 함수

        system("cls");
        Damage(MonsterHp, PlayerAtt);
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(PlayerName, MonsterName, PlayerAtt);

        // MonsterHp -= PlayerAtt;
        _getch();

        system("cls");
        Damage(PlayerHp, MonsterAtt);
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(MonsterName, PlayerName, MonsterAtt);

        _getch();

        if (0 >= PlayerHp || 0 >= MonsterHp)
        {
            return -1;
        }
    }
}