#ifndef BOGGLE_BOGGLE_H
#define BOGGLE_BOGGLE_H

#include <string>
#include "Dictionary.h"

using namespace std;

const int BOARD_SIZE = 4;

class BoardNotInitialized {};

class Boggle {
public:

    /*
    * Function:
    * Default constructor loads 'dictionary.txt.' and initializes member variables
    *
    * Precondition:
    * LoadDictionaryFile from the dictionary.cpp must be working properly
    *
    * Postcondition:
    * Dictionary will be loaded and member variables will be initialized
    */
    Boggle();  // load "dictionary.txt" into dict

    /*
    * Function:
    * Default constructor loads dictionary a file and initializes member variables
    *
    * Precondition:
    * A string that is a file name should be passed in, LoadDictionaryFile must be working
    *
    * Postcondition:
    * If the precondition is met, then the file will be opened and variables will be initialized
    */
    explicit Boggle(string filename);  // load filename into dict

    /*
    * Function:
    * Function that creates the board
    *
    * Precondition:
    * takes the board array as a parameter
    *
    * Postcondition:
    * The board will be created and a space allocated for the size
    */
    void SetBoard(string board[BOARD_SIZE][BOARD_SIZE]);

    /*
    * Function:
    * A wrap around for SolveBoardHelper that looks for words on the board
    *
    * Precondition:
    * SolveBoardHelper and printBoard must be coded for this function to work properly. printBoard and a ostream& output will be passed into the function
    *
    * Postcondition:
    * The function will show which words were found on the board
    */
    void SolveBoard(bool printBoard, ostream& output);

    /*
    * Function:
    * Saves the words found on the board to a given file
    *
    * Precondition:
    * SaveDictionaryFile from the dictionary.cpp must be working properly and the filename will be passed into thew function
    *
    * Postcondition:
    * The words found on the board will be saved to the file
    */
    void SaveSolve(string filename);   // Saves all the words from the last solve.

    /*
    * Function:
    * Gets the dictionary
    *
    * Precondition:
    * none
    *
    * Postcondition:
    * Returns dict
    */
    Dictionary GetDictionary();

    /*
    * Function:
    * Keeps track of the words found
    *
    * Precondition:
    * none
    *
    * Postcondition:
    * Returns the wordsFound dictionary
    */
    Dictionary WordsFound();

private:
    Dictionary dict;
    Dictionary wordsFound;
    string board[BOARD_SIZE][BOARD_SIZE];
    int visited[BOARD_SIZE][BOARD_SIZE];

    /*
    * Function:
    * Prints the board that shows the path of the word
    *
    * Precondition:
    * SolveBoardHelper should be ready to run and ostream& output will be passed into the function
    *
    * Postcondition:
    * Uses quotes to mark which letters have been visited
    */
    void PrintBoard(ostream& output);

    /*
    * Function:
    * Checks the surrounding positions and uses IsPrefix to find which combinations of letters are words
    *
    * Precondition:
    * IsPrefix, IsWord, AddWord, and PrintBoard must be working properly. Three integer values that keep track of row, column and a counter will be passed in, as well as the printBoard, and an ostream &output
    *
    * Postcondition:
    * Finds a word or returns if unable to
    */
    void SolveBoardHelper(int row, int column, bool printBoard, ostream &output, string word, int vCounter);
};

#endif //BOGGLE_BOGGLE_H
