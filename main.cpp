#include <iostream>
#include <regex>
#include <string>

#include "board.hpp"
#include "pieces.hpp"

SQUARE parse_sqr(const std::string& input)
{
    int col = input[0] - 97;
    int row = input[1] - 48;

    SQUARE sqr = (SQUARE) ((8 - row) * 8 + col);

    std::cout << sqr << std::endl;

    return sqr;

}

int main()
{
    Board b;

    std::string input;

    while (true) {
        std::getline(std::cin, input);

        if (std::regex_match(input, std::regex("[a-h][1-8] [a-h][1-8]"))) {
            parse_sqr(input.substr(0, 2));
            parse_sqr(input.substr(3, 2));

            b.print();
        } else {
            std::cout << "Invalid move\n";
        }
    }

    return 0;
}
