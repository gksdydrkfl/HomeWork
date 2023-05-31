// HomeWork_0526.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "ConsoleScreen.h"
#include "Player.h"
#include "int4.h"
#include "Wall.h"
#include "Bullet.h"
// 1. 파일 정리
// 2. 10개의 장애물 배치 class Wall
//    Player 
//    Wall 
//    같은 클래스를 상속받아서 만들어져야 한다.
// 
// 3. 장애물을 통과 못하게 하기.

// 4. 플레이어가 어떠한 키를 누르면 플레이어 위치에서
//    총알 1발이 발사되게 만드세요.

// 5. 그 총알 1발에 벽이 닿으면 벽이 없어지게 만드세요.

// 숙제 플레이어가 화면 바깥으로 나가지 못하게 해라.




int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    // 클래스의경우에는 
    MainPlayer.SetPos({ 10, 5 });

    int Count = 0;

    Wall Walls[10];
    Walls[0].SetPos({0, 1});
    Walls[1].SetPos({8, 6});
    Walls[2].SetPos({7, 1});
    Walls[3].SetPos({6, 3});
    Walls[4].SetPos({3, 2});
    Walls[5].SetPos({2, 7});
    Walls[6].SetPos({3, 1});
    Walls[7].SetPos({7, 8});
    Walls[8].SetPos({8, 2 });
    Walls[9].SetPos({5, 0});

    for (int i = 0; i < 10; i++)
    {
        Walls[i].SetIndex(i);
    }

    Bullet bullet;
    //Wall ArrWall[10];
    //Wall* PtrWall = ArrWall;
    while (true)
    {
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), 'a');


        for (size_t i = 0; i < 10; i++)
        {
            if (Walls[i].GetWall())
            {
                Screen.SetPixel(Walls[i].GetPos(), 'o');
            }
            
        }
        if (MainPlayer.GetBullet())
        {
            MainPlayer.SetBulletPos(MainPlayer.GetBulletPos() + MainPlayer.GetBulletDir());

            if (MainPlayer.BulletCheck(&Screen))
            {
                int4 Pos = MainPlayer.GetBulletPos();
                for (int i = 0; i < 10; ++i)
                {
                    if (Walls[i].GetPos() == Pos)
                    {
                        Walls[i].SetWall(false);
                    }
                }
                //Screen.SetPixel(MainPlayer.GetBulletPos(), '*');
                MainPlayer.SetBullet(false);
            }
            else
            {
                Screen.SetPixel(MainPlayer.GetBulletPos(), '0');
            }
        }
        Screen.Print();

        if (0 != _kbhit())
        {

            //0x0000004E812FEC40
            //0x0000004E812FEE28
            MainPlayer.Input(&Screen);

            // 1000이면 1초입니다.
        }



        // 1초 동안 정지합니다.
        Sleep(200);
    }


}