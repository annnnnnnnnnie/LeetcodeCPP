#ifndef XN5Z8R_H
#define XN5Z8R_H

#include <string>

class Solution_xn5z8r
{
public:
    int firstUniqChar(std::string s) {
        if (s.length() <= 0) {
            return -1;
        }
        int table[26] = { 0 }; //0: not seen; 1: seen once; 2: seen more than once;
        for (char c : s) {
            ++table[c - 'a'];
        }

        int pos = 0;
        for (char c : s) {
            if (table[c - 'a'] == 1) {
                return pos;
            }
            ++pos;
        }
        return -1;
    }
};
#endif // !XN5Z8R_H

