#include <bitset>
#include <iostream>

#include "include/pieces.hpp"

int main()
{

    auto pabb = pawn_moves[white][b1];
    set_bit(&pabb, b1);
    std::bitset<64> bb(pabb);
    std::cout << bb << '\n';

    return 0;
}
