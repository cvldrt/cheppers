#include "include/pieces.hpp"
#include "bitboard.h"

int main()
{

    print_bitboard(pawn_moves[white][b1]);
    print_bitboard(pawn_moves[white][a7]);
    print_bitboard(pawn_moves[white][h5]);
    print_bitboard(pawn_moves[white][h8]);

    print_bitboard(queen_moves[e4]);
    print_bitboard(queen_moves[b6]);
    print_bitboard(queen_moves[a3]);

    return 0;
}
