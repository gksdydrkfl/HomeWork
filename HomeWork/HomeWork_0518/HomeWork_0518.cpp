#include <iostream>

int StringCount(char* _Arr)
{
    if (nullptr == _Arr)
    {
        return 0;
    }

    int Count = 0;
    while (_Arr[Count])
    {
        ++Count;
    }
    return Count;
}

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
    if (nullptr == _Arr)
    {
        return;
    }

    int Count = 0;
    while (_Arr[Count])
    {
        if (_Arr[Count] == _PrevCh)
        {
            _Arr[Count] = _NextCh;
        }
        ++Count;
    }
}

int main()
{
    char Arr[100] = "312312321";

    int Count = StringCount(Arr);

    //char Arr[100] = "aaa bbb ccc";

    ChangeCh(Arr, 'c', 'd');
}