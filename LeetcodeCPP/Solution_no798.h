#ifndef SOL_NO798_H
#define SOL_NO798_H

#include<vector>
#include<iostream>
using namespace std;

class Solution_no798
{
public:
    int bestRotation(vector<int>& nums) {
        return bestRotationMatrix(nums);
    }

    int bestRotationMatrix(vector<int>& nums) {
        vector<vector<int>> matrix = generateScoreMatrix(nums);
        for (auto row : matrix) {
            for (auto num : row) {
                cout << num << " ";
            }
            cout << endl;
        }
        return 0;
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

    int scoreArrayFromMatrix(vector<vector<int>>& scoreMatrix) {
        return 0;
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

    // precondition: matrix is initialized with zero. 
    // precondition: 0 <= num < k.
    void fillInMatrixColumn(vector<vector<int>>& matrix, int col_number, int num) {
        int n = matrix.size();
        int row_begin = (col_number - num - n) % n;
        int row_end = col_number;
        for (int i = row_begin; (i - 1) % n != row_end; i = (i++) % n) {
            matrix[i][col_number] = 1;
        }
    }
};


#endif // !SOL_NO798_H
