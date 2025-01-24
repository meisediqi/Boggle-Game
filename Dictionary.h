#ifndef BOGGLE_DICTIONARY_H
#define BOGGLE_DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int NUM_CHARS = 26;

class DictionaryError{
public:
    explicit DictionaryError(string msg) {
        this->msg = msg;
    }
    string Msg(){
        return msg;  // returns king of flavor
    }
private:
    string msg;
};

class Dictionary
{

public:
    /*
    * Function:
    * Default constructor initializes root and member variables
    *
    * Precondition:
    * none
    *
    * Postcondition:
    * The root and the member variables will be initialized
    */
    Dictionary();

    /*
    * Function:
    * Deconstructor will pass root to destroy helper
    *
    * Precondition:
    * none
    *
    * Postcondition:
    * root will be passed to destroy helper
    */
    ~Dictionary();  // I will not require this

    /*
    * Function:
    * copy constructor first initializes root and member variables. Afterward, it passes otherDict to copy other
    *
    * Precondition:
    * Passes in a dictionary object
    *
    * Postcondition:
    * otherDict will be passed to copyOther and everything will be initialized
    */
    Dictionary(const Dictionary& otherDict);    // copy constructor

    /*
    * Function:
    * Constructor initializes the root and the member variables. Afterward, it opens a file and adds words to dictionary
    *
    * Precondition:
    * A file name in the form of a string should be passed in
    *
    * Postcondition:
    * If the precondition is met, root variables will be initialized. Then, words from file will be added to the dictionary
    */
    explicit Dictionary(string filename);       // The keyword explicit is used to tell the compiler
                                                // that this is not a conversion constructor.

    /*
    * Function:
    * Function will overload the = to copy the dictionaries
    *
    * Precondition:
    * A dictionary object is passed in
    *
    * Postcondition:
    * The dictionary object will be passed to the copy other function
    */
    Dictionary& operator=(const Dictionary& otherDict);

    /*
    * Function:
    * function loads all the words from a file into the dictionary
    *
    * Precondition:
    * A file name in the form of a string should be passed in
    *
    * Postcondition:
    * If the precondition is met and the file is opened successfully, then the file will be loaded into the dictionary. Otherwise, it will throw an error
    */
    void LoadDictionaryFile(string filename);

    /*
    * Function:
    * This function serves as wrapper function to saveDictionaryHelper
    *
    * Precondition:
    * A file name in the form of a string should be passed in
    *
    * Postcondition:
    * If the precondition is met and the file is opened successfully, then the file name, root and
    * string will be passed to saveDictionaryHelper. Otherwise, it will throw an error
    */
    void SaveDictionaryFile(string filename);

    /*
    * Function:
    * This Function will add words to the dictionary
    *
    * Precondition:
    * A word will be passed in as a string
    *
    * Postcondition:
    * If the precondition is met, then the word will be converted to ints and added to the dictionary. Otherwise, it will throw an error
    */
    void AddWord(string word);

    /*
    * Function:
    * This Function is wrapper for destroy helper that resets the tree
    *
    * Precondition:
    * none
    *
    * Postcondition:
    * If the precondition is met then the root will be passed to the destroyHelper. The root and numWords will both be reset.
    */
    void MakeEmpty();

    /*
    * Function:
    * This Function will check to see if a word already exists in the dictionary
    *
    * Precondition:
    * A word will be passed in as a string
    *
    * Postcondition:
    * If the precondition is met, then the function will check if the word passed in is in the dictionary. Otherwise, it will throw an error
    */
    bool IsWord(string word);

    /*
    * Function:
    * This Function will check to see if the string passed in is a valid prefix
    *
    * Precondition:
    * A word will be passed in as a string
    *
    * Postcondition:
    * If the precondition is met, then the function will check if the string is a valid prefix. Otherwise, it will throw an error
    */
    bool IsPrefix(string word);

    /*
    * Function:
    * This function returnz the word count
    *
    * Precondition:
    * none
    *
    * Postcondition:
    * returns the word count
    *
    */
    int WordCount();  // Returns total number of words in dictionary

private:

    class Node {
    public:
        // Your node structure here.
        // You can also use a struct if you like.

        // It is strongly recommended you create a constructor
        // to set default values

        /*
        * Function:
        * The node constructor sets every letter to nullptr
        *
        * Precondition:
        * letter array must be created prior to running the constructor
        *
        * Postcondition:
        * If the precondition is met, then the constructor will set every array element of letter to nullptr
        */
        Node* letter[NUM_CHARS];
        bool isWord = false;
        Node () {
            for (int i = 0; i < NUM_CHARS; i++){
                letter[i] = nullptr;
            }
        }
    };

    Node* root;
    int numWords;

    // This function is used by the
    // copy constructor and the assignment operator.

    /*
    * Function:
    * This Function will act as a wrapper function for copyHelper
    *
    * Precondition:
    * A dictionary object will be passed in.
    *
    * Postcondition:
    * If the precondition is met, then the dictionary object and the root will be passed to copyHelper
    */
    void copyOther(const Dictionary& otherDict);

    // Any private methods you need/want
    // You may change these helpers if you want, but you don't need to.

    /*
    * Function:
    * This Function will delete all the nodes in the tree
    *
    * Precondition:
    * A node will be passed in.
    *
    * Postcondition:
    * If the precondition is met, then it will delete the tree
    */
    void destroyHelper(Node* thisTree);

    /*
    * Function:
    * This Function will copy all words from otherTree to thisTree
    *
    * Precondition:
    * thisTree and otherTree will be passed in
    *
    * Postcondition:
    * If the precondition is met then otherTree will be copied to thisTree
    */
    void copyHelper(Node*& thisTree, Node* otherTree);

    /*
    * Function:
    * This Function will find every word in the tree and save it to a file.
    *
    * Precondition:
    * The current node, a string and ofstream file will be passed in.
    *
    * Postcondition:
    * If the precondition is met, then every word in the tree will be saved to a file.
    */
    void SaveDictionaryHelper(Node* curr, string currPrefix, ofstream& outFile);
};

#endif //BOGGLE_DICTIONARY_H
