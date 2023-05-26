#include "Player.h"
#include <conio.h>
#include "ConsoleScreen.h"


void Player::Input(ConsoleScreen* _Sreen)
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        MovePos = GlobalVar::Left;
        break;
    case 'd':
        MovePos = GlobalVar::Right;
        break;
    case 'w':
        MovePos = GlobalVar::Up;
        break;
    case 's':
        MovePos = GlobalVar::Down;
        break;
    case ' ':
        Fire();
        break;
    default:
        break;
    }

    if (false == _Sreen->IsScreenOut(GetPos() + MovePos) &&
        false == _Sreen->IsWall(GetPos() + MovePos))
    {
        AddPos(MovePos);
        SetDir(MovePos);
    }
}

bool Player::BulletCheck(ConsoleScreen* _Sreen)
{
    int4 Pos1 = GetBulletPos();

    if (true == _Sreen->IsScreenOut(GetBulletPos()) ||
        true == _Sreen->IsWall(GetBulletPos()))
    {
        return true;
    }
    return false;
}


void Player::Fire()
{
    SetBulletDir(GetDir());
    SetBulletPos(GetPos());
    Bullet = true;
}

bool Player::GetBullet() const
{
    return Bullet;
}

void Player::SetBullet(bool _Bullet)
{
    Bullet = _Bullet;
}

int4 Player::GetBulletPos() const
{
    return BulletPos;
}

void Player::SetBulletPos(const int4& _Pos)
{
    BulletPos = _Pos;
}

void Player::SetBulletDir(const int4& _Dir)
{
    BulletDir = _Dir;
}
int4 Player::GetBulletDir() const
{
    return BulletDir;
}