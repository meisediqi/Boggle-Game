## Boggle-Game

Project created under the guidance of Dr. Varick Erickson. Copyright (c) 2021 Varick Erickson.

# Boggle Solver

The Boggle board is a 4x4 grid onto which you shake and randomly distribute 16 
dice. These 6-sided dice have letters rather than numbers, creating a grid of 
letters from which you can form words. In the original version, the players 
start simultaneously and write down all the words they can find by tracing by a 
path through adjoining letters. Two letters adjoin if they are next to each 
other horizontally, vertically, or diagonally. There are up to eight letters 
adjoining a cube. A grid position can only be used once in the word.  When time
is called, duplicates are removed from the players' lists and the players 
receive points for their remaining words based on the word lengths. In this 
assignment, you will be creating a program that will find all the words on a 
boggle board.  Any word found in the dictionary will count as a word on the 
boggle board.

> **Boggle Game:** https://www.youtube.com/watch?v=BJAdXnGAb7k

To store the words in this project, we will be creating dictionary using 
a data structure called a prefix tree (also known as a Trie). This data 
structure allows for the  quick lookup of whether or not a word is valid. It 
will also allow you to find all words with a specific prefix. Rather than 
store each word individually, we instead store the words using a tree.

### Prefix

A prefix is a valid path down the tree.  A prefix may or may not be a valid 
word.  For the example below, "a" and "ax" are valid prefixes since there 
are words starting with these letters.  However, "aaa" is not a valid prefix.
This because the path ends with a NULL.

## `Basic_Dictionary.cpp`

The `Basic_Dictionary.cpp` can be used for development.  It will not be used 
for grading. I suggest using this program first before running the 
`Dictionary_tests`.  

## `struct Node`

Your `Node` structure should contain an array of pointers.  The node can be 
a struct or class. The size of the array should be NUM_CHARS (ie 26). The 
struct/class should also contain a boolean flag called `isWord` to indicate 
if the path to this node represents a word.

## `Dictionary() Default Constructor` 

The default constructor should establish a root node and make each 
position of the branch array null.  It should also set the root 
isWord to false. The total number of words should be 0.


## `Dictionary(const Dictionary& otherDict)`

The copy constructor should copy all of the contents of `otherDict` to `this`. 
You should use the `copyOther` function to accomplish this.

## `Dictionary& operator=(const Dictionary& otherDict)`

This overload should copy all of the contents of `otherDict` to `this`.  You 
should use the `copyOther` function to accomplish this.

## `copyOther(const Dictionary& otherDict)`

This function should copy all of the values from `otherDict` to `this` 
instance of the dictionary. It will serve as a wrapper for `copyHelper` 
in a similar way we recursively copied a binary tree in class.  The only 
difference is we have 26 children instead of two. 

## `void MakeEmpty()`

The `MakeEmpty` function should destroy all the nodes in the tree. After 
destroying all the nodes in the tree, the root should be remade and the 
number of words should be set back to 0.  `MakeEmpty` mainly serves as a 
wrapper function for the `destroyHelper`.  The `MakeEmpty` and 
`destroyHelper` functions work very similarly to the binary tree 
deconstructor covered in class.  The only difference is that you 
need to destroy 26 branches before deleting the current node. 

## `Dictionary(string filename)`

This constructor should establish a root node similar to the default 
constructor.  After that, it should open the file `filename` and add all the 
words in this file to the dictionary.

## `void LoadDictionaryFile(string filename)`

This function should open the file `filename` and add all the words in this 
file to the dictionary.  This function does *NOT* reset the words in the 
dictionary.  It just adds to the words already in the tree.

## `void SaveDictionaryFile(string filename)`

The `SaveDictionaryFile` function should use a recursive function to find 
every word in the tree and save it to a file.  This function mainly serves 
as a "Wrapper" for the `SaveDictionaryHelper` function.

## `int WordCount()`

This function returns the total number of words in the dictionary.

## `void AddWord(string word)`

This method adds a word to the tree.  This is accomplished by reading the 
word character by character and creating a path in the tree for the word if it 
doesn't exist.

## `bool IsPrefix(string word)`

This method returns true if a path down the branches exists for a word. This 
method will have an implementation very similar to the AddWord method for 
traveling down the tree. It should return false if it runs into a NULL.  If 
it manages to get through the entire loop without hitting a NULL, it should 
return true.

While processing the characters, if you encounter a character that is not
between 'a' and 'z', it should throw a `DictionaryError` with the message
"Invalid character".

## `bool IsWord(string word)`

This method is very similar to the `AddWord` and `IsPrefix` method. If you have 
already implemented the `IsPrefix` method, then it should be fairly trivial to 
implement `isWord`. The main difference is you should return the `isWord` flag 
found of the node found at the end of the path.

While processing the characters, if you encounter a character that is not
between 'a' and 'z', it should throw a `DictionaryError` with the message
"Invalid character".

## IsPrefix versus IsWord

`IsPrefix` checks to see if at least one word in the dictionary starts with a 
particular prefix.  `IsWord` checks to see if a provided word exists in the 
dictionary.  A word will always be a prefix.  However, a prefix will not 
always be a word.

## `Basic_Boggle_Solver.cpp`

The `Basic_Boggle_Solver` has some testing framework for you to use to 
help develop and debug the `Boggle` class.  A hard-coded board is provided 
as well as a function to get input from the user.

## `Boggle()`

The default constructor should initialize the `dict` with words from 
`dictionary.txt`.  It initialize each entry of `board` to the 
empty string.  It should also initialize each entry of `visited` to `false`.

## `Boggle(filename)`

This constructor should initialize the `dict` with words from
`filename`.  It will use `AddWord` or `LoadDictionaryFile` to help you do 
this. It should also initialize each entry of `board` to the empty string.  It 
should also initialize each entry of `visited` to `false`.

## `SetBoard(string board[BOARD_SIZE][BOARD_SIZE])`

This function should copy each entry of `board` to `this->board`.

## `PrintBoard(ostream& output)`

One of the requirements of the program is that the solver should also show 
the path of the solution.

## `void SolveBoard(bool printBoard, ostream& output)`

This method finds all the words on the current board stored by `board` and 
saves these words to the `wordsFound` dictionary.  The function also outputs 
the values to the `output` `ostream` object.  This `ostream` can be called 
with `cout` or an `ofstream` object (see provided code in `Boggle_Solver.cpp`).
The `SolveBoard` method serves mainly as a wrapper function for the 
`SolveBoardHelper` method. This function should reset the `wordsFound` 
dictionary each time it is run.

## `void SaveSolve(filename)`

This should use the `SaveDictionaryFile` for the wordsFound.
