#include "pch.h"
#include "CppUnitTest.h"
#include "../LeetcodeCPP/Solution_no798.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetcodeCPPTests
{
	TEST_CLASS(TestSolution_no371)
	{
	public:
		Solution_no798 sol;

		TEST_METHOD(TestGenerateMatrix)
		{
			vector<int> nums{ 2,3,1,4,0 };
			auto matrix = sol.generateScoreMatrix(nums);

		}
	};
}