#include "pch.h"
#include "CppUnitTest.h"
#include "../LeetcodeCPP/Solution_no371.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetcodeCPPTests
{
	TEST_CLASS(TestSolution_no371)
	{
	public:
		Solution_no371 sol;

		void test_add_two_numbers(int a, int b) {
			int result = sol.getSum(a, b);
			int answer = a + b;
			Assert::AreEqual(answer, result);
		}

		TEST_METHOD(TestAddTwoPositive)
		{
			int a = 1;
			int b = 3;
			test_add_two_numbers(a, b);
		}

		TEST_METHOD(TestAddTwoZero)
		{
			int a = 0;
			int b = 0;
			test_add_two_numbers(a, b);
		}

		TEST_METHOD(TestAddTwoNegative)
		{
			int a = -100;
			int b = -20;
			test_add_two_numbers(a, b);
		}

		TEST_METHOD(TestAddTwoDiffernetSign)
		{
			int a = -100;
			int b = 100;
			test_add_two_numbers(a, b);
		}

		TEST_METHOD(TestAddZeroPositive)
		{
			int a = 0;
			int b = 3;
			test_add_two_numbers(a, b);
		}
	};
}