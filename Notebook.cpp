#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
using namespace std;

namespace ariel {

    void Notebook::write(uint page, uint row, uint col, Direction direction, string const &word){
        //Edge case
        if(col >= MAX_ROW_LENGTH){
            throw invalid_argument("Invalid column");
        }

        for(uint i=0; i < word.length(); i++){
            if(col >= MAX_ROW_LENGTH){
                throw invalid_argument("Invalid column");
            }
            if((bool)_notebook.count(page) && (bool)_notebook[page].count(row) && (bool)_notebook[page][row].count(col)){
                // throw invalid_argument("cannot write over an existing text.");
            }
            _notebook[page][row][col] = word[i];
            if(direction == Direction::Horizontal){ col++;}
            if(direction == Direction::Vertical){ row++;}
        }
    }

    std::string Notebook::read(uint page, uint row, uint col, Direction direction, uint word_length){
        //Edge case
        if(col >= MAX_ROW_LENGTH){
            throw invalid_argument("Invalid column");
        }

        string ans;
        for(int i=0; i < word_length; i++){
            if(col >= MAX_ROW_LENGTH){
                throw invalid_argument("Invalid column");
            }
            //Check if value exists.
            if((bool)_notebook.count(page) && (bool)_notebook[page].count(row) && (bool)_notebook[page][row].count(col)){
                ans += _notebook[page][row][col];
            }
            else {
                ans += "_";
            }
            if(direction == Direction::Horizontal){ col++;}
            if(direction == Direction::Vertical){ row++;}
        }
        return ans;
    }

    void Notebook::erase(uint page, uint row, uint col, Direction direction, uint word_length){
        //Edge case
        if(col >= MAX_ROW_LENGTH){
            throw invalid_argument("Invalid column");
        }

        for(uint i=0; i < word_length; i++){
            if(col >= MAX_ROW_LENGTH){
                throw invalid_argument("Invalid column");
            }
            _notebook[page][row][col] = '~';
            if(direction == Direction::Horizontal){ col++;}
            if(direction == Direction::Vertical){ row++;}
        }
    }

    void Notebook::show(uint page){
        uint min_row = _notebook2[page]._MIN_ROW;
        uint min_col = _notebook2[page]._MIN_COL;
        uint max_row = _notebook2[page]._MAX_ROW;
        uint max_col = _notebook2[page]._MAX_COL;
        
        for(uint i = min_row; i < max_row; i++){
            for(uint j = min_col; j < max_col; j++){
                cout << _notebook2[page]._page[i][j] << " ";
            }
            cout << "\n" ;
        }
    }

}