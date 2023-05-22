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

    int Count1 = 0;
    int Count2 = 0;
    char ch[256] = {};

    while (_string[Count1])
    {
        if (_string[Count1] != ' ')
        {
            ch[Count2] = _string[Count1];
            ++Count2;
        }
        ++Count1;
    }
    Count1 = 0;
    while (ch[Count1])
    {
        _string[Count1] = ch[Count1];
        ++Count1;
    }
    _string[Count1] = 0;
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
    int Count = 0;
    int n = _Number;
    int m = 1;
    while (n = n / 10)
    {
        ++Count;
        m *= 10;
    }

    for (int i = 0; i <= Count; ++i)
    {
        int Quotient = n / m;
        _Right[i] = (char)(Quotient + 48);

        n = n - Quotient * m;
        m = m / 10;
    }

    return 0;
}

int main()
{
    {
        int Result = ChCount("ab aaa ccc ddd eee", 'a');
        std::cout << Result << std::endl;
    }
    {
        char Arr[256] = "aa  b  c dd ee";
        TrimDelete(Arr);

        //Arr "aabcddee";
        std::cout << Arr << std::endl;
    }
    {
        int Result = DigitsCount(123456789);
        std::cout << Result << std::endl;
    }
    {
        char ArrCopyText[256] = {};
        StrCopy("1 124 124s", ArrCopyText);
        std::cout << ArrCopyText << std::endl;
    }
    {
        char Result[256] = {};

        NumberToString(123512, Result);
        std::cout << Result << std::endl;
    }
}

