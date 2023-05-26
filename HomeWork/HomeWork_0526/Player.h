#pragma once
#include "Pos.h"
class ConsoleScreen;
//class Bullet;

class Player : public Pos
{
public:


    Player()
    {
    }

    Player(const Player&) = delete;

    void Input(ConsoleScreen* _Sreen);

//    Bullet* CreateBullet();
    void Fire();

    bool GetBullet() const;
    void SetBullet(bool _Bullet);
    int4 GetBulletPos() const;
    void SetBulletPos(const int4& _Pos);
    void SetBulletDir(const int4& _Dir);
    int4 GetBulletDir() const;

    bool BulletCheck(ConsoleScreen* _Sreen);
protected:

private:

    int4 BulletPos;
    int4 BulletDir;
    bool Bullet = false;

};