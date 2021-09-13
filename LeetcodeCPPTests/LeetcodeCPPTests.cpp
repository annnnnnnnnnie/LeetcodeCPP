#include "pch.h"
#include "CppUnitTest.h"

#include "../LeetcodeCPP/Solution_xnhhkv.cpp"
#include "../LeetcodeCPP/Solution_xnhbqj.cpp"
#include "../LeetcodeCPP/Solution_xn5z8r.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<>
			static std::wstring ToString<pair<int, int>>(const pair<int, int>& position) {
				wstring result = L"pair:(";
				result += to_wstring(position.first);
				result +=  L", ";
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
		}
	}
}

namespace LeetcodeCPPTests
{
	TEST_CLASS(TestSolution_xnhhkv)
	{
	public:
		Solution_xnhhkv sol;
		vector<vector<int>> matrix_odd = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
		vector<vector<int>> matrix_even = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
		TEST_METHOD(TestTranslateToTheRight) {
			pair<int, int> before = pair<int, int>(0, 0);
			pair<int, int> offset = pair<int, int>(0, 2);
			pair<int, int> result = sol.translate(before, offset);

			pair<int, int> answer = pair<int, int>(0, 2);

			Assert::AreEqual<pair<int,int>>(answer, result);
		}

		TEST_METHOD(TestTranslateDownwards) {
			pair<int, int> before = pair<int, int>(0, 0);
			pair<int, int> offset = pair<int, int>(2, 0);
			pair<int, int> result = sol.translate(before, offset);

			pair<int, int> answer = pair<int, int>(2, 0);

			Assert::AreEqual<pair<int, int>>(answer, result);
		}

		TEST_METHOD(TestRotateOrigin) {
			pair<int, int> before = pair<int, int>(0, 0);
			pair<int, int> result = sol.rotate_90_clockwise(before);

			pair<int, int> answer = pair<int, int>(0, 0);

			Assert::AreEqual<pair<int, int>>(answer, result);
		}

		TEST_METHOD(TestRotatePoint) {
			pair<int, int> before = pair<int, int>(2, 2);
			pair<int, int> result = sol.rotate_90_clockwise(before);

			pair<int, int> answer = pair<int, int>(2, -2);

			Assert::AreEqual<pair<int, int>>(answer, result);
		}

		TEST_METHOD(TestRotateOneLayerOdd) {
			sol.rotate_one_layer(matrix_odd, 0);
			vector<vector<int>> answer = { {7,4,1},{8,5,2},{9,6,3} };

			Assert::AreEqual<vector<vector<int>>>(answer, matrix_odd);
		}

		TEST_METHOD(TestRotateOneLayerEven) {
			sol.rotate_one_layer(matrix_even, 0);
			vector<vector<int>> answer = { {13,9,5,1}, {14,6,7,2}, {15,10,11,3}, {16,12,8,4} };

			Assert::AreEqual<vector<vector<int>>>(answer, matrix_even);
		}

		TEST_METHOD(TestRotateEven) {
			sol.rotate(matrix_even);
			vector<vector<int>> answer = { {13,9,5,1}, {14,10,6,2}, {15,11,7,3}, {16,12,8,4} };

			Assert::AreEqual<vector<vector<int>>>(answer, matrix_even);
		}

		TEST_METHOD(TestRotateOdd) {
			sol.rotate(matrix_odd);
			vector<vector<int>> answer = { {7,4,1},{8,5,2},{9,6,3} };

			Assert::AreEqual<vector<vector<int>>>(answer, matrix_odd);
		}
	};

	TEST_CLASS(TestSolution_xnhbqj)
	{
	public:
		Solution_xnhbqj sol;
		TEST_METHOD(TestSwap) {
			char c1 = 'a';
			char c2 = 'b';
			sol.swap(c1, c2);
			Assert::AreEqual('b', c1);
			Assert::AreEqual('a', c2);
		}

		TEST_METHOD(TestSwapVectorElems) {
			vector<char> cs = { 'a','b','c','d' };
			sol.swap(cs[0], cs[3]);
			Assert::AreEqual('d', cs[0]);
			Assert::AreEqual('a', cs[3]);
		}

		TEST_METHOD(TestReverseShort) {
			vector<char> cs = { 'a','b','c' };
			sol.reverseString(cs);
			vector<char> answer = { 'c','b','a' };
			Assert::AreEqual<vector<char>>(answer, cs);
		}

		TEST_METHOD(TestReverseLong) {
			vector<char> cs;
			for (char c = 'a'; c < 'z'; c++) {
				cs.push_back(c);
			}

			sol.reverseString(cs);

			vector<char> answer;
			for (char c = 'z' - 1; c >= 'a'; c--) {
				answer.push_back(c);
			}

			Assert::AreEqual<vector<char>>(answer, cs);
		}
	};

	TEST_CLASS(TestSolution_xn5z8r) {
	public:
		Solution_xn5z8r sol;
		TEST_METHOD(TestSimpleString) {
			std::string s = "leetcode";
			int result = sol.firstUniqChar(s);
			int answer = 0;
			Assert::AreEqual(answer, result);
		}

		TEST_METHOD(TestSimpleStringAnswerInTheMiddle) {
			std::string s = "leetcodel";
			int result = sol.firstUniqChar(s);
			int answer = 3;
			Assert::AreEqual(answer, result);
		}

		TEST_METHOD(TestSimpleNegative) {
			std::string s = "eeee";
			int result = sol.firstUniqChar(s);
			int answer = -1;
			Assert::AreEqual(answer, result);
		}

		TEST_METHOD(TestBadInput) {
			std::string s = "";
			int result = sol.firstUniqChar(s);
			int answer = -1;
			Assert::AreEqual(answer, result);
		}
	};
}
