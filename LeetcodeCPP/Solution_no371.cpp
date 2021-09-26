#include "Solution_no371.h"

using namespace std;

#include <list>
#include <iostream>

int Solution_no371::getSum(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;

    list<unsigned int> sum_bits;

    unsigned ua = a;
    unsigned ub = b;

    unsigned int carry = 0;
    for (int i = 0; i < 32; i++) {
        int last_bit_of_a = ua % 2;
        int last_bit_of_b = ub % 2;
        int sum_of_them = last_bit_of_a ^ last_bit_of_b ^ carry;
        carry = ((last_bit_of_a ^ last_bit_of_b) & carry) | (last_bit_of_a & last_bit_of_b);
        ua >>= 1;
        ub >>= 1;
        sum_bits.push_front(sum_of_them);
    }

    int result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= sum_bits.front();
        sum_bits.pop_front();
    }

    return result;
}
