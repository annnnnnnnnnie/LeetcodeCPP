#ifndef SOL_NO798_H
#define SOL_NO798_H

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

/***
 * https://leetcode-cn.com/problems/smallest-rotation-with-highest-score/
**/
class Solution_no798
{
public:
    int bestRotation(vector<int>& nums) {
        return bestRotationMatrix(nums);
    }

    int bestRotationMatrix(vector<int>& nums) {
        int n = nums.size();
        int max_score = 0;
        int best_k = 0;

        vector<vector<int>> matrix = generateScoreMatrix(nums);

        for (int i = 0; i < n; i++) {
            int current_score = scoreArrayFromMatrix(matrix, i);
            if (current_score > max_score) {
                max_score = current_score;
                best_k = i;
            }
        }
        return best_k;
    }

    int bestRotationDirect(vector<int>& nums) {
        int n = nums.size();
        int max_score = 0;
        int best_k = 0;
        for (int i = 0; i < n; i++) {
            int current_score = scoreArrayDirectly(nums, i);
            if (current_score > max_score) {
                max_score = current_score;
                best_k = i;
            }
        }
        return best_k;
    }

    // Compute the score according to the problem description
    int scoreArrayDirectly(vector<int>& nums, int start) {
        int n = nums.size();
        int score = 0;
        for (int i = 0; i < n; i++) {
            int idx = (i + start) % n;
            if (nums[idx] <= i) {
                score++;
            }
        }
        return score;
    }

    int scoreArrayFromMatrix(vector<vector<int>>& scoreMatrix, int start) {
        vector<int>& row = scoreMatrix[start];
        int score = accumulate(row.begin(), row.end(), 0);
        return score;
    }

    // Generate a matrix that represents the score each element might get
    // matrix[i][j] means the score of nums[j] when k = i
    vector<vector<int>> generateScoreMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            fillInMatrixColumn(matrix, i, nums[i]);
        }
        return matrix;
    }

    int mod(int i, int n) {
        return ((i % n) + n) % n;
    }

    // precondition: matrix is initialized with zero. 
    // precondition: 0 <= num < k.
    void fillInMatrixColumn(vector<vector<int>>& matrix, int col_number, int num) {
        int n = matrix.size();
        int row_begin = col_number + 1;
        int cnt = n - num;
        for (int i = 0; i < cnt; i++) {
            matrix[(row_begin + i) % n][col_number] = 1;
        }
    }
};


#endif // !SOL_NO798_H
