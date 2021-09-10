#include "Solution_xnhhkv.h"
#include <cassert>

void Solution_xnhhkv::rotate_one_layer(vector<vector<int>>& matrix, int layer_number)
{
	int size = matrix.size();
	assert(layer_number < size / 2);
	if (size % 2 == 0) {
		rotate_one_layer_even(matrix, layer_number);
	}
	else {
		rotate_one_layer_odd(matrix, layer_number);
	}
}

void Solution_xnhhkv::rotate(vector<vector<int>>& matrix) {
	int size = matrix.size();
	for (int layer_number = 0; layer_number < size / 2; layer_number++) {
		rotate_one_layer(matrix, layer_number);
	}
}

pair<int, int> Solution_xnhhkv::rotate_90_clockwise(pair<int, int> position)
{
	pair<int, int> result;
	// pre multiply by [[0,-1],[1,0]]
	result.first = position.second;
	result.second = -position.first;

	return result;
}

pair<int, int> Solution_xnhhkv::rotate_90_anticlockwise(pair<int, int> position)
{
	pair<int, int> result;
	// pre multiply by [[0,1],[-1,0]]
	result.first = -position.second;
	result.second = position.first;

	return result;
}

pair<int, int> Solution_xnhhkv::translate(pair<int, int> position, pair<int, int> offset)
{
	pair<int, int> result;
	result.first = position.first + offset.first;
	result.second = position.second + offset.second;
	return result;
}

void Solution_xnhhkv::rotate_one_layer_odd(vector<vector<int>>& matrix, int layer_number)
{
	int side_length = matrix.size() - 2 * layer_number - 1;
	if (side_length == 1) { return; }
	pair<int, int> starting_point = pair<int, int>(layer_number, layer_number);

	for (int y_offset = 0; y_offset < side_length; y_offset++) {
		pair<int, int> current_position = translate(starting_point, pair<int, int>(0, y_offset));
	    int temp = matrix[current_position.first][current_position.second];
		for (int j = 0; j < 3; j++) {
			pair<int, int> next_position = translate(rotate_90_anticlockwise(current_position), pair<int, int>(side_length, 0));
			matrix[current_position.first][current_position.second] = matrix[next_position.first][next_position.second];
			current_position = next_position;
		}
		matrix[current_position.first][current_position.second] = temp;
	}
}

void Solution_xnhhkv::rotate_one_layer_even(vector<vector<int>>& matrix, int layer_number)
{
	int side_length = matrix.size() - 2 * layer_number - 1;
	pair<int, int> starting_point = pair<int, int>(layer_number, layer_number);

	for (int y_offset = 0; y_offset < side_length; y_offset++) {
		pair<int, int> current_position = translate(starting_point, pair<int, int>(0, y_offset));
		int temp = matrix[current_position.first][current_position.second];
		for (int j = 0; j < 3; j++) {
			pair<int, int> next_position = translate(rotate_90_anticlockwise(current_position), pair<int, int>(side_length, 0));
			matrix[current_position.first][current_position.second] = matrix[next_position.first][next_position.second];
			current_position = next_position;
		}
		matrix[current_position.first][current_position.second] = temp;
	}
}

