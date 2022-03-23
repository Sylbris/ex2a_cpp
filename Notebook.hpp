#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;

const uint MAX_ROW_LENGTH = 100;

struct page {
    map<uint, map<uint, char>> _page;
    //Each page holds the lowest index, where it was written.
    uint _MIN_ROW, _MIN_COL; 
    uint _MAX_ROW, _MAX_COL;
};

namespace ariel
{
    class Notebook {
        uint _row, _col, _pageNum;
        map<uint, map<uint, map<uint, char>>> _notebook;
        map<uint, page> _notebook2;

        public:
            Notebook() {}
            ~Notebook() {}
            void write(uint page, uint row, uint col, Direction direction, string const &word);
            std::string read(uint page, uint row, uint col, Direction direction, uint word_length);
            void erase(uint page, uint row, uint col, Direction direction, uint word_length);
            void show(uint page);

    };

    std::string generateWord(uint len);
};