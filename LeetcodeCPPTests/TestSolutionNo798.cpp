#include "pch.h"
#include "CppUnitTest.h"
#include "../LeetcodeCPP/Solution_no798.h"

#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework; 

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<>
			static std::wstring ToString<pair<int, int>>(const pair<int, int>& position) {
				wstring result = L"pair:(";
				result += to_wstring(position.first);
				result += L", ";
				result += to_wstring(position.second);
				result += L")";
				return result;
			}

			template<>
			static std::wstring ToString<vector<vector<int>>>(const vector<vector<int>>& matrix) {
				wstring result = L"matrix: [";
				for (vector<int> row : matrix) {
					result += L"[";
					for (int n : row) {
						result += to_wstring(n) + L", ";
					}
					result += L"],\n";
				}
				result += L"]";
				return result;
			}

			template<>
			static std::wstring ToString<vector<char>>(const vector<char>& ls) {
				wstring result = L"[";
				for (char c : ls) {
					result += to_wstring(c) + L", ";
				}
				return result;
			}
			template<>
			static std::wstring ToString<Solution_no798>(const class Solution_no798& t) {
				return L"Solution_no798";
			}
		}
	}
}

namespace LeetcodeCPPTests
{
	TEST_CLASS(TestSolution_no371)
	{
	public:
		Solution_no798 sol;

		static std::string matrixToString(const vector<vector<int>>& matrix) {
			string result = "matrix: [";
			for (vector<int> row : matrix) {
				result += "[";
				for (int n : row) {
					result += to_string(n) + ", ";
				}
				result += "],\n";
			}
			result += "]";
			return result;
		}

		void assertMatrixEqual(vector<vector<int>>& m1, vector<vector<int>>& m2) {
			int n1 = m1.size();
			int n2 = m2.size();
			Assert::AreEqual(n1, n2);

			for (int i = 0; i < n1; i++) {
				vector<int>& r1 = m1[i];
				vector<int>& r2 = m2[i];
				int nr1 = r1.size();
				int nr2 = r2.size();
				Assert::AreEqual(nr1, nr2);

				for (int j = 0; j < nr1; j++) {
					Assert::AreEqual(r1[j], r2[j]);
				}
			}
		}
		TEST_METHOD(TestGenerateMatrix)
		{
			vector<int> nums{ 2,3,1,4,0 };
			auto matrix = sol.generateScoreMatrix(nums);
			string mat = matrixToString(matrix);
			vector<vector<int>> answer{
				{0,0,1,0,1},
				{1,0,1,0,1},
				{1,1,0,0,1},
				{1,1,1,0,1},
				{0,0,1,1,1}
			};
			assertMatrixEqual(answer, matrix);
		}

		TEST_METHOD(TestUseMatrixToComputeCaseOne) {
			vector<int> nums{ 2,3,1,4,0 };
			int result = sol.bestRotationMatrix(nums);
			int answer = 3;
			Assert::AreEqual(answer, result);
		}

		TEST_METHOD(TestLargeData) {
			vector<int> nums;

		}
	};
}