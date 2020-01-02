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
