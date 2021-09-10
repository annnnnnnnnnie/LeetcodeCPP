#include <vector>

using namespace std;

class Solution_xnhhkv
{
public:
    void rotate(vector<vector<int>>& matrix);

    // layer_number 0 is the outermost layer
    void rotate_one_layer(vector<vector<int>>& matrix, int layer_number);

    pair<int, int> rotate_90_clockwise(pair<int, int> position);
    pair<int, int> rotate_90_anticlockwise(pair<int, int> position);

    pair<int, int> translate(pair<int, int> position, pair<int, int> offset);

private:
    void rotate_one_layer_odd(vector<vector<int>>& matrix, int layer_number);
    void rotate_one_layer_even(vector<vector<int>>& matrix, int layer_number);
};

