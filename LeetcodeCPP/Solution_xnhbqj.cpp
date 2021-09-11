#include "Solution_xnhbqj.h"

void Solution_xnhbqj::reverseString(std::vector<char>& s)
{
	int length = s.size();
	for (int i = 0; i < length / 2; i++)
	{
		swap(s[i], s[length - i - 1]);
	}
}

void Solution_xnhbqj::swap(char& c1, char& c2)
{
	c1 = c1 + c2;
	c2 = c1 - c2;
	c1 = c1 - c2;
}
