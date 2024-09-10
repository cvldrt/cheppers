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

    for (int i = 0; i < 64; ++i) {
        // used to avoid "owerflow" between ranks
        int max_left_offset  = i % 8;
        int max_right_offset = 7 - max_left_offset;

        for (int dist = 1; dist < 8; ++dist) {
            // left
            for (int direction : {-9, 7}) {
                int target_i = i + direction * dist;

                if (target_i >= 0 && target_i < 64 &&
                    dist <= max_left_offset) {
                    result[i] |= 1ll << (63 - target_i);
                }
            }

            // right
            for (int direction : {-7, 9}) {
                int target_i = i + direction * dist;

                if (target_i >= 0 && target_i < 64 &&
                    dist <= max_right_offset) {
                    result[i] |= 1ll << (63 - target_i);
                }
            }
        }
    }

    return result;
}();
