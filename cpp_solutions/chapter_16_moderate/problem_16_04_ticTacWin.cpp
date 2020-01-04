#include "problem_16_04_ticTacWin.h"
#include <cmath>

namespace chapter_16 {
    TTTDatabase::TTTDatabase() {
        // build database
        buildDB();
    }

    bool TTTDatabase::ticTacWin(const char *board) {
        // check board correctness by looking up in DB
        return winsLookup(board);
    }

    uint16_t TTTDatabase::board2Hash(const char* board) const {
        // hashing function:
        // V0 * 3^0 + V1* 3^1 + V2 * 3^2 ... + V8 * 3^8
        uint16_t hash = 0;
        for (int i = 0; i < boardLength; i++) {
            uint16_t V = 0; // board[i] = '_' or something else
            if (board[i] == 'X') {
                V = 2;
            }
            else if (board[i] == 'O') {
                V = 1;
            }
            hash += V * std::pow(3, i);
        }
        return hash;
    }

    bool TTTDatabase::winsLookup(const char* board) const {
        // determine if this board is a winning board
        uint16_t hash = board2Hash(board);
        return database.count(hash) ? database.at(hash) : false;
    }

    uint8_t TTTDatabase::linearIndex(uint8_t R, uint8_t C) const {
        return R*3 + C;
    }

    bool TTTDatabase::wins(const char* board) const {
        // check rows
        for (int r = 0; r < 3; r++) {
            uint8_t index = linearIndex(r, 0);
            char first = board[index];
            char second = board[index + 1];
            char third = board[index + 2];
            if ((first == 'X' || first == 'O') && first == second && second == third) return true;
        }
        // check cols
        for (int c = 0; c < 3; c++) {
            uint8_t index = linearIndex(0, c);
            char first = board[index];
            char second = board[index + 3];
            char third = board[index + 6];
            if ((first == 'X' || first == 'O') && first == second && second == third) return true;
        }
        // check diags
        // LR downward diag
        char first = board[0];
        char second = board[4];
        char third = board[8];
        if ((first == 'X' || first == 'O') && first == second && second == third) return true;
        // LR upward diag
        first = board[6];
        second = board[4];
        third = board[2];
        return (first == 'X' || first == 'O') && first == second && second == third;
    }

    void TTTDatabase::updateDB(const char* board) {
        bool win = wins(&board[0]);
        uint16_t hash = board2Hash(&board[0]);
        database[hash] = win;
    }

    void TTTDatabase::permuteAndCheckBoard(char* board, uint8_t index) {
        if (index >= boardLength) return;
        char states[3] = {'_', 'O', 'X'};
        for (auto state : states) {
            board[index] = state;
            updateDB(&board[0]);
            permuteAndCheckBoard(board, index+1);
        }
    }

    void TTTDatabase::buildDB(){
        char board[9] = {0};
        permuteAndCheckBoard(&board[0], 0);
    }
}
