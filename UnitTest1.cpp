#include "pch.h"
#include "CppUnitTest.h"
#include "../RJGCSY2test1/Class.h"
#include "../RJGCSY2test1/Class.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)//�û���ż�㣬��¥��ż��
		{
			Class cs;
			int r = cs.fun(1, 4, 1, 8);
			Assert::IsTrue(r == 1);
		}
		TEST_METHOD(TestMethod2)//�û�����㣬��¥�����
		{
			Class cs;
			int r = cs.fun(1, 5, 1, 11);
			Assert::IsTrue(r == 1);
		}
		TEST_METHOD(TestMethod3)//�û���ż�㣬��¥�����
		{
			Class cs;
			int r = cs.fun(1, 6, 1, 13);
			Assert::IsTrue(r == 1);
		}
		TEST_METHOD(TestMethod4)//�û�����㣬��¥��ż��
		{
			Class cs;
			int r = cs.fun(1, 7, 1, 18);
			Assert::IsTrue(r == 1);
		}
		TEST_METHOD(TestMethod5)//�û���ż�㣬��¥��ż��
		{
			Class cs;
			int r = cs.fun(1, 4, 0, 8);
			Assert::IsTrue(r == 1);
		}
		TEST_METHOD(TestMethod6)//�û�����㣬��¥�����
		{
			Class cs;
			int r = cs.fun(1, 15, 0, 9);
			Assert::IsTrue(r == 1);
		}
		TEST_METHOD(TestMethod7)//�û���ż�㣬��¥�����
		{
			Class cs;
			int r = cs.fun(1, 14, 0, 3);
			Assert::IsTrue(r == 1);
		}
		TEST_METHOD(TestMethod8)//�û�����㣬��¥��ż��
		{
			Class cs;
			int r = cs.fun(1, 15, 0, 6);
			Assert::IsTrue(r == 1);
		}
	};
}
