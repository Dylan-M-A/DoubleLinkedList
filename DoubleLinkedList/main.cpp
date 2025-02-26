#include <iostream>
#include "ObjectPool.h"

class Test {};

int main()
{
	ObjectPool<Test*> testPool = ObjectPool<Test*>(100, []() { return new Test(); });
}