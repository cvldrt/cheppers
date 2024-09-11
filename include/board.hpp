#ifndef BOARD_H
#define BOARD_H

#include "bitboard.h"
#include "enums.hpp"

class Board {
   private:
    bool whites_move = true;

    bitboard white_pawns = 0b0101010110101010;
    bitboard black_pawns = white_pawns << 48;

    bitboard white_queens = 0;
    bitboard black_queens = 0;

   public:
    Board();

    int eval();
    bool move(SQUARE from, SQUARE to);
    void print();
};

#endif
