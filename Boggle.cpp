
#include "Dictionary.h"
#include "Boggle.h"

// Your code here


// This function is done.
Dictionary Boggle::GetDictionary() {
    return dict;
}

// This function is done.
Dictionary Boggle::WordsFound() {
    return wordsFound;
}

Boggle::Boggle() {
    dict.LoadDictionaryFile("dictionary.txt");
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = "";
            visited[i][j] = 0;
        }
    }
}

Boggle::Boggle(string filename) {
    dict.LoadDictionaryFile(filename);
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            board[i][j] = "";
            visited[i][j] = 0;
        }
    }

}

void Boggle::SetBoard(string (*board)[4]) {
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++) {
            this->board[i][j] = board[i][j];
        }
    }
}

void Boggle::SolveBoard(bool printBoard, ostream &output) {
    wordsFound.MakeEmpty();
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++) {
            int instance = 1;
            string tempword;
            SolveBoardHelper(i, j, printBoard, output, tempword, instance);
        }
    }
}

void Boggle::SaveSolve(string filename) {
    wordsFound.SaveDictionaryFile(filename);
}

void Boggle::PrintBoard(ostream &output) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (visited[i][j]) {
                output << " '" << board[i][j] << "' ";
            } else {
                output << "  " << board[i][j] << "  ";
            }
        }
        output << "\t";
        for (int j = 0; j < BOARD_SIZE; j++) {
            output << "  " << visited[i][j] << "  ";
        }
        output << endl;
    }
    output << endl;
}

void Boggle::SolveBoardHelper(int row, int column, bool printBoard, ostream &output, string word, int vCounter) {
    if (row < 0 || column < 0 || row >= BOARD_SIZE || column >= BOARD_SIZE) {
        return;
    }
    if (visited[row][column] != 0) {
        return;
    }
    word += board[row][column];
    if (!dict.IsPrefix(word)) {
        return;
    }
    visited[row][column] = vCounter;
    vCounter++;
    if (dict.IsWord(word) && !wordsFound.IsWord(word)) {
        wordsFound.AddWord(word);
        if (printBoard) {
            output << "Word: " << word << endl;
            output << "Number of Words: " << wordsFound.WordCount() << endl;
            PrintBoard(output);
        } else {
            output << wordsFound.WordCount() << "\t" << word << endl;
        }
    }
    int x = row - 1;
    int y = column;
    SolveBoardHelper(x, y, printBoard, output, word, vCounter);

    x = row - 1;
    y = column + 1;
    SolveBoardHelper(x, y, printBoard, output, word, vCounter);

    x = row;
    y = column + 1;
    SolveBoardHelper(x, y, printBoard, output, word, vCounter);

    x = row + 1;
    y = column + 1;
    SolveBoardHelper(x, y, printBoard, output, word, vCounter);

    x = row + 1;
    y = column;
    SolveBoardHelper(x, y, printBoard, output, word, vCounter);

    x = row + 1;
    y = column - 1;//SouthWest
    SolveBoardHelper(x, y, printBoard, output, word, vCounter);
    x = row;
    y = column - 1;//West
    SolveBoardHelper(x, y, printBoard, output, word, vCounter);
    x = row - 1;
    y = column - 1;//NorthWest
    SolveBoardHelper(x, y, printBoard, output, word, vCounter);
    visited[row][column] = 0;
}




