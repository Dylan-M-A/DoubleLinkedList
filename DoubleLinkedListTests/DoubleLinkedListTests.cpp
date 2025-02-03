#include "pch.h"
#include "CppUnitTest.h"
#include "List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoubleLinkedListTests
{
	TEST_CLASS(DoubleLinkedListTests)
	{
	public:

		TEST_METHOD(DefaultConstructor)
		{
			List<int> list;
			Assert::AreEqual(list.first(), 0);
			Assert::AreEqual(list.last(), 0);
			Assert::AreEqual(list.getLength(), 0);
		}

		TEST_METHOD(InitializerListConstructor)
		{
			List<int> list = { 9,8,7,6,5 };
			Iterator<int> iter = list.begin();
			Assert::AreEqual(*iter, 9);
			iter++;
			Assert::AreEqual(*iter, 8);
			iter++;
			Assert::AreEqual(*iter, 7);
			iter++;
			Assert::AreEqual(*iter, 6);
			iter++;
			Assert::AreEqual(*iter, 5);
			Assert::AreEqual(list.getLength(), 5);
		}

		TEST_METHOD(PushFront)
		{
			List<int> list;
			list.pushFront(1);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 1);

			list.pushFront(2);
			Assert::AreEqual(list.first(), 2);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 2);

			list.pushFront(3);
			Assert::AreEqual(list.first(), 3);
			Assert::AreEqual(*(list.begin()++), 2);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 3);
		}

		TEST_METHOD(PushBack)
		{
			List<int> list;
			list.pushBack(1);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 1);
			Assert::AreEqual(list.getLength(), 1);

			list.pushBack(2);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 2);
			Assert::AreEqual(list.getLength(), 2);

			list.pushBack(3);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(*(list.begin()++), 2);
			Assert::AreEqual(list.last(), 3);
			Assert::AreEqual(list.getLength(), 3);
		}

		TEST_METHOD(popFront)
		{
			List<int> list = { 10,20,30,40,50 };
			Assert::AreEqual(list.first(), 10);
			Assert::AreEqual(list.popFront(), 10);
		}

		TEST_METHOD(popBack)
		{
			List<int> list;
		}

		TEST_METHOD(insert)
		{
			List<int> list;
		}

		TEST_METHOD(remove)
		{
			List<int> list;
		}

		TEST_METHOD(first)
		{
			List<int> list;
		}

		TEST_METHOD(last)
		{
			List<int> list;
		}

		TEST_METHOD(begin)
		{
			List<int> list;
		}

		TEST_METHOD(end)
		{
			List<int> list;
		}

		TEST_METHOD(destory)
		{
			List<int> list;
		}

		TEST_METHOD(getLength)
		{
			List<int> list;
		}
	};
}