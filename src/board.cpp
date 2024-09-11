#include "board.hpp"

#include <iostream>

Board::Board() {};

void Board::print()
{
    std::cout << "\n   ---------------------------------\n";

    for (int row = 0; row < 8; ++row) {
        std::cout << 8 - row << "  |";

        for (int col = 0; col < 8; ++col) {
            int square = row * 8 + col;
            if (get_bit(white_pawns, square)){
                std::cout << " ♟ |";
            } 

            else if (get_bit(black_pawns, square)){
                std::cout << " ♙ |";
            } 

            else if (get_bit(white_queens, square)){
                std::cout << " ♛ |";
            } 

            else if (get_bit(black_queens, square)){
                std::cout << " ♕ |";
            } 
            else {
                std::cout << "   |";
            }

        }

        std::cout << "\n   ---------------------------------\n";
    }

    std::cout << "     a   b   c   d   e   f   g   h\n\n";
}
