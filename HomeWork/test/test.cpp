#include <iostream>
#include "Test1.h"
#include "test2.h"

typedef test2 Test2;

int main()
{

	Test1 t1;
	Test2 t2;

	//       t2의 값을넣어서 적용시키고 싶다.
	t1.SetPosition(t2.b);

}

// 몬스터가