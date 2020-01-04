/* PROBLEM:
 * Design an algorithm to figure out if someone has won a game of tic-tac-toe.
 *
 * SOLUTION:
 * 1. An algorithm to check if a TTT board is a winning board. Check all rows, all cols, and both diagonals for equality.
 * 2. An algorithm to store the wiining-ness of all possible TTT boards in a hash map. Generate every possible TTT board
 * using a recursion tree that assigns one of three possible cell states (blank, X, or O) to one of 9 cells at each level
 * of the recursion.
 * 3. A class that populates the hash map in (2) upon construction and only queries the hash map when
 * asked to determine if a TTT board is a winning board.
 *
 * SPACE / TIME:
 * If we assume that there will be N calls to determine if a TTT board is a winning board, each call will require O(1)
 * time and O(1) space will be required to store the hash table.
 *
 */

#pragma once
#include <unordered_map>

namespace chapter_16 {
    class TTTDatabase {
    private:
        /*
         * A TTT board has 9 positions with 3 possible values at each position:
         * blank, X, or O. Thus, all possible TTT boards can be represented by
         * 3^9 = 19683 hash values. Thus we only need to store true or false
         * for 19683 different numbers which fits in a uint16_t whose max value is
         * 2^16 - 1 = 65536 - 1 = 65535. The range of the key integers is 0 - 19682.
         */
        std::unordered_map<uint16_t, bool> database;
        const uint16_t boardLength = 9;
        uint16_t board2Hash(const char* board) const;
        bool winsLookup(const char* board) const;
        uint8_t linearIndex(uint8_t R, uint8_t C) const;
        bool wins(const char* board) const;
        void updateDB(const char* board);
        void permuteAndCheckBoard(char* board, uint8_t index);
        void buildDB();
    public:
        TTTDatabase();
        bool ticTacWin(const char* board);
    };
}  // namespace chapter_16
