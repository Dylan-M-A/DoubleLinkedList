#include "pch.h"
#include "CppUnitTest.h"
#include "ObjectPool.h"

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
			Assert::AreEqual(list.last(), 50);
			Assert::AreEqual(list.popFront(), 10);

			Assert::AreEqual(list.first(), 20);
			Assert::AreEqual(list.last(), 50);
			Assert::AreEqual(list.popFront(), 20);

			Assert::AreEqual(list.first(), 30);
			Assert::AreEqual(list.last(), 50);
			Assert::AreEqual(list.popFront(), 30);

			Assert::AreEqual(list.first(), 40);
			Assert::AreEqual(list.last(), 50);
			Assert::AreEqual(list.popFront(), 40);

			Assert::AreEqual(list.first(), 50);
			Assert::AreEqual(list.last(), 50);
			Assert::AreEqual(list.popFront(), 50);

		}

		TEST_METHOD(popBack)
		{
			List<int> list = { 10,20,30,40,50 };
			Assert::AreEqual(list.first(), 10);
			Assert::AreEqual(list.last(), 50);
			Assert::AreEqual(list.popBack(), 50);

			Assert::AreEqual(list.first(), 10);
			Assert::AreEqual(list.last(), 40);
			Assert::AreEqual(list.popBack(), 40);

			Assert::AreEqual(list.first(), 10);
			Assert::AreEqual(list.last(), 30);
			Assert::AreEqual(list.popBack(), 30);

			Assert::AreEqual(list.first(), 10);
			Assert::AreEqual(list.last(), 20);
			Assert::AreEqual(list.popBack(), 20);

			Assert::AreEqual(list.first(), 10);
			Assert::AreEqual(list.last(), 10);
			Assert::AreEqual(list.popBack(), 10);
		}

		TEST_METHOD(insert)
		{
			List<int> list = { 2,4,6,8,10 };
			list.insert(1, 0);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 10);
			Assert::AreEqual(list.getLength(), 6);

			list.insert(3, 2);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 10);
			Assert::AreEqual(list.getLength(), 7);

			list.insert(5, 4);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 10);
			Assert::AreEqual(list.getLength(), 8);

			list.insert(7, 6);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 10);
			Assert::AreEqual(list.getLength(), 9);

			list.insert(9, 7);
			Assert::AreEqual(list.first(), 1);
			Assert::AreEqual(list.last(), 10);
			Assert::AreEqual(list.getLength(), 10);
		}

		TEST_METHOD(remove)
		{
			List<int> list;
			int count;
			Assert::IsNotNull(&list);
			list.pushBack(1);
			list.pushBack(0);
			list.pushBack(1);
			list.pushBack(2);
			list.pushBack(1);
			list.pushBack(3);
			list.pushBack(1);
			Assert::AreEqual(7, list.getLength());
			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(1, *iter);

			count = list.remove(1);
			Assert::AreEqual(4, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(*iter, list.first());
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::IsTrue(iter == nullptr);

			count = list.remove(5);
			Assert::AreEqual(0, count);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(0, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);

			list = List<int>();
			Assert::IsNotNull(&list);
			list.pushBack(3);
			list.pushBack(3);
			list.pushBack(3);
			Assert::AreEqual(3, list.getLength());
			iter = list.begin();
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			count = list.remove(3);
			Assert::AreEqual(0, list.getLength());
			Assert::AreEqual(0, list.first());
			Assert::AreEqual(0, list.last());
		}
		TEST_METHOD(Find)
		{
			List<int> list;
			Assert::IsNotNull(&list);

			list.pushBack(1);
			list.pushBack(2);
			list.pushBack(3);
			list.pushBack(4);

			Iterator<int> iter = list.begin();
			Assert::AreEqual(1, *iter);
			iter++;
			Assert::AreEqual(2, *iter);
			iter++;
			Assert::AreEqual(3, *iter);
			iter++;
			Assert::AreEqual(4, *iter);

			Iterator<int> findTestIter = list.find(1);
			iter = list.begin();
			Assert::AreEqual(*iter, *findTestIter);
			findTestIter = list.find(2);
			iter++;
			Assert::AreEqual(*iter, *findTestIter);
			findTestIter = list.find(3);
			iter++;
			Assert::AreEqual(*iter, *findTestIter);
			findTestIter = list.find(4);
			iter++;
			Assert::AreEqual(*iter, *findTestIter);
		}

		TEST_METHOD(first)
		{
			List<int> list = { 10,20,30,40,50 };
			Assert::AreEqual(10, list.first());
			Assert::AreEqual(50, list.last());
			Assert::AreEqual(5, list.getLength());

			Assert::AreEqual(10, list.first());

			list.popFront();
			Assert::AreEqual(20, list.first());

			list.popFront();
			Assert::AreEqual(30, list.first());

			list.popFront();
			Assert::AreEqual(40, list.first());

			list.popFront();
			Assert::AreEqual(50, list.first());
		}

		TEST_METHOD(last)
		{
			List<int> list = { 10,20,30,40,50 };
			Assert::AreEqual(10, list.first());
			Assert::AreEqual(50, list.last());
			Assert::AreEqual(5, list.getLength());

			Assert::AreEqual(50, list.last());

			list.popBack();
			Assert::AreEqual(40, list.last());

			list.popBack();
			Assert::AreEqual(30, list.last());

			list.popBack();
			Assert::AreEqual(20, list.last());

			list.popBack();
			Assert::AreEqual(10, list.last());
		}

		TEST_METHOD(begin)
		{
			List<int> list = { 10,20,40,60,80 };
			Assert::AreEqual(10, list.first());
			Assert::AreEqual(80, list.last());
			Assert::AreEqual(5, list.getLength());

			Iterator<int> nullIter;

			Assert::IsTrue(nullIter == list.begin());

			list.popBack();
			Assert::IsTrue(nullIter == list.begin());

			list.popBack();
			Assert::IsTrue(nullIter == list.begin());

			list.popBack();
			Assert::IsTrue(nullIter == list.begin());

			list.popBack();
			Assert::IsTrue(nullIter == list.begin());
		}

		TEST_METHOD(end)
		{
			List<int> list = { 10,20,40,60,80 };
			Assert::AreEqual(10, list.first());
			Assert::AreEqual(80, list.last());
			Assert::AreEqual(5, list.getLength());

			Iterator<int> nullIter;

			Assert::IsTrue(nullIter == list.end());

			list.popBack();
			Assert::IsTrue(nullIter == list.end());

			list.popBack();
			Assert::IsTrue(nullIter == list.end());

			list.popBack();
			Assert::IsTrue(nullIter == list.end());

			list.popBack();
			Assert::IsTrue(nullIter == list.end());
		}

		TEST_METHOD(destory)
		{

		}

		TEST_METHOD(getLength)
		{
			List<int> list = { 10,20,30,40,50 };
			Assert::AreEqual(list.getLength(), 5);

			List<int> list1 = { 1,2,3,4,5,6,7 };
			Assert::AreEqual(list1.getLength(), 7);

			List<int> list2 = { 7,23,95,16,84,36 };
			Assert::AreEqual(list2.getLength(), 6);
		}

		TEST_METHOD(Get)
		{
			
		}

		TEST_METHOD(Release)
		{

		}

		TEST_METHOD(Clear)
		{

		}

		TEST_METHOD(GetInactiveCount)
		{
			
		}

		TEST_METHOD(GetActiveCount)
		{

		}

		TEST_METHOD(GetTotalCount)
		{

		}
	};
}