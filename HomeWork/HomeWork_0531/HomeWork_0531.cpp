#include <iostream>
#include <vector>

// 숙제0 => HVector의 leck을 없애와라
//         대입연산자를 사용하면 터지는걸 정상으로 돌려놔라.
//         이미 보여준 코드 이미 array에서 해결은 한거에요.

// 숙제1 => 템플릿으로 바꾸세요.

//using DataType = int;
template<typename T>
class HVector
{
public:
	T& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	size_t size() const
	{
		return sizeValue;
	}

	size_t capacity()
	{
		return capacityValue;
	}

	void push_back(const T& _Data)
	{
		if (sizeValue + 1 > capacityValue)
		{
			reserve((int)((capacityValue * 1.5) + 1));
		}

		ArrPtr[sizeValue] = _Data;
		sizeValue += 1;
	}

	void reserve(int _capacity)
	{
		T* PrevPtr = ArrPtr;

		ArrPtr = new T[_capacity];

		if (nullptr != PrevPtr)
		{
			for (int i = 0; i < sizeValue; i++)
			{
				ArrPtr[i] = PrevPtr[i];
			}

			delete PrevPtr;
			PrevPtr = nullptr;
		}

		capacityValue = _capacity;
	}

	void Copy(const HVector& _Other)
	{
		size_t SmallSize = size() <= _Other.size() ? size() : _Other.size();

		for (size_t i = 0; i < SmallSize; i++)
		{
			ArrPtr[i] = _Other.GetArrPtr()[i];
		}
	}

	HVector& operator=(const HVector& _Other)
	{
		Copy(_Other);
		return *this;
	}

	T* GetArrPtr() const
	{
		return ArrPtr;
	}

	~HVector()
	{
		if (nullptr != ArrPtr)
		{
			delete ArrPtr;
			ArrPtr = nullptr;
		}
	}

private:
	int sizeValue = 0;
	int capacityValue = 0;
	T* ArrPtr = nullptr;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	{
		HVector<int> Arr;
		for (int i = 0; i < 10; i++)
		{
			Arr.push_back(i);
		}
		for (int i = 0; i < Arr.size(); i++)
		{
			std::cout << Arr[i] << std::endl;
		}


		HVector<int> Arr0;

		Arr0 = Arr;

		for (int i = 0; i < Arr0.size(); i++)
		{
			std::cout << Arr0[i] << std::endl;
		}

	}



}