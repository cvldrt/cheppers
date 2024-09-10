#include <array>

#include "bitboard.h"
#include "enums.hpp"

constexpr static std::array<std::array<bitboard, 64>, 2> pawn_moves = []() {
    std::array<std::array<bitboard, 64>, 2> result{{0}};

    for (int i = 8; i < 64; ++i) {
        result[white][i] = 0;

        if (i % 8 != 7) {
            result[white][i] |= 1ll << (63 - i + 7);
        }

        if (i % 8 != 0) {
            result[white][i] |= 1ll << (63 - i + 9);
        }
    }

    for (int i = 0; i < 56; ++i) {
        result[black][i] = 0;

        if (i % 8 != 7) {
            result[black][i] |= 1ll << (63 - i - 9);
        }

        if (i % 8 != 0) {
            result[black][i] |= 1ll << (63 - i - 7);
        }
    }

    return result;
}();

constexpr static std::array<bitboard, 64> queen_moves = []() {
    std::array<bitboard, 64> result{};

    for (int i = 8; i < 56; ++i) {
    }

    return result;
}();
