// HomeWork_0519.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int ChCount(const char* const _string, char Ch)
{
    if (nullptr == _string)
    {
        return 0;
    }

    int Count = 0;
    int Result = 0;
    while (_string[Count])
    {
        if (_string[Count] == Ch)
        {
            ++Result;
        }
        ++Count;
    }
    return Result;
}

void TrimDelete(char* _string)
{
    if (nullptr == _string)
    {
        return;
    }

    int Count = 0;
    char* ch = {};
    while (_string[Count])
    {
        if (_string[Count] != ' ')
        {
            ch[Count] = _string[Count];
        }
        ++Count;
    }

    return;
}

int DigitsCount(int _Number)
{
    int Count = 0;
    while (_Number)
    {
        _Number = _Number / 10;
        ++Count;
    }
    return Count;
}

void StrCopy(const char* const _Left, char* _Right)
{
    if (nullptr == _Left)
    {
        return;
    }

    int Count = 0;
    while (_Left[Count])
    {
        _Right[Count] = _Left[Count];
        ++Count;
    }
}

int NumberToString(int _Number, char* _Right)
{
    //48
    
    _Right[0] = _Number + 48;
    return 0;
}

int main()
{
    {
        //int Result = ChCount("ab aaa ccc ddd eee", 0);
        //std::cout << Result;
    }
    {
        //char Arr[256] = "aa  b  c dd ee";
        //TrimDelete(Arr);

        ////Arr "aabcddee";
        //std::cout << Arr;
    }
    {
        //int Result = DigitsCount(123456789);
        //std::cout << Result;
    }
    {
        //char ArrCopyText[256] = {};
        //StrCopy("aaaa bbb ccc", ArrCopyText);
        //std::cout << ArrCopyText;
    }
    {
        char Result[256] = {};

        //NumberToString(1231313, Result);
        NumberToString(255, Result);
        std::cout << Result;
        /*char Ch = '0';
        int Value = 7;
        char ChConvert = Value + 48;*/
    }
}

