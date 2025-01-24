#include "Dictionary.h"

// Your code here

Dictionary::Dictionary() {
    root = new Node;
    numWords = 0;
}

Dictionary::~Dictionary() {
    destroyHelper(root);
}

Dictionary::Dictionary(const Dictionary &otherDict) {
    root = new Node;
    numWords = 0;
    copyOther(otherDict);
}

Dictionary::Dictionary(string filename) {
    string word;
    ifstream dFile;
    dFile.open(filename);
    if(dFile.fail()){
        throw DictionaryError("Invalid character");
    }
    root = new Node;
    numWords = 0;
    while(dFile >> word){
        AddWord(word);
    }
}

Dictionary &Dictionary::operator=(const Dictionary &otherDict) {
    if(this != &otherDict){
        copyOther(otherDict);
    }
    return *this;
}

void Dictionary::LoadDictionaryFile(string filename) {
    ifstream dFile;
    dFile.open(filename);
    if(dFile.fail()){
        throw DictionaryError(filename + "failed to open");
    }
    string tWord;
    while (dFile >> tWord){
        AddWord(tWord);
    }
    dFile.close();
}

void Dictionary::SaveDictionaryFile(string filename) {
    ofstream oFile;
    oFile.open(filename);
    if(oFile.fail()){
        throw DictionaryError(filename + "failed to open");
    }
    SaveDictionaryHelper(root, "", oFile);
}

void Dictionary::AddWord(string word) {
    int index = 0;
    Node *cNode = root;
    for(int i = 0; i < word.length(); i++){
        index = word[i]  - 'a';
        if(word[i] < 97 || word[i] > 122){
            throw DictionaryError("Invalid character");
        }
        if(cNode->letter[index] == nullptr ){
            cNode->letter[index] = new Node;
        }
        cNode = cNode->letter[index];
    }
    cNode->isWord = true;
    numWords++;
}

void Dictionary::MakeEmpty() {
    if( root == nullptr){
        return;
    }
    destroyHelper(root);
    root = new Node;
    numWords = 0;
}

bool Dictionary::IsWord(string word) {
    int index = 0;
    Node *cNode = root;
    for(int i = 0; i < word.length(); i++){
        index = word[i]  - 'a';
        if(word[i] < 97 || word[i] > 122){
            throw DictionaryError("Invalid character");
        }
        if(cNode-> letter[index] == nullptr ){
            return false;
        }

        cNode = cNode->letter[index];
    }
    return cNode-> isWord ;
}

bool Dictionary::IsPrefix(string word) {
    int index = 0;
    Node *cNode = root;
    for(int i = 0; i < word.length(); i++){
        index = word[i]  - 'a';
        if(word[i] < 97 || word[i] > 122){
            throw DictionaryError("Invalid character");
        }

        if(cNode->letter[index] == nullptr ){
            return false;
        }
        cNode = cNode->letter[index];
    }
    return true ;
}

int Dictionary::WordCount() {
    return numWords;
}

void Dictionary::copyOther(const Dictionary &otherDict) {
    this->numWords = otherDict.numWords;
    for(int i = 0; i < NUM_CHARS; i++){
        copyHelper(this->root->letter[i] , otherDict.root->letter[i]);
    }
}

void Dictionary::destroyHelper(Dictionary::Node *thisTree) {
    if(thisTree == nullptr){
        return;
    }
    for(int i = 0; i < NUM_CHARS; i++){
        destroyHelper(thisTree->letter[i]);
    }
    delete thisTree;
}

void Dictionary::copyHelper(Dictionary::Node *&thisTree, Dictionary::Node *otherTree) {
    if (otherTree == nullptr) {
        thisTree = nullptr;
        return;
    }
    thisTree = new Node;
    thisTree->isWord = otherTree->isWord;
    for (int i = 0; i < NUM_CHARS; i++) {
        copyHelper(thisTree->letter[i], otherTree->letter[i]);
    }
}

void Dictionary::SaveDictionaryHelper(Dictionary::Node *curr, std::string currPrefix, std::ofstream &outFile) {
    if (curr == nullptr){
        return;
    }
    if (curr->isWord){
        outFile << currPrefix <<endl;
    }
    char CValue;
    for (int i = 0; i < NUM_CHARS; i++) {
        if (curr->letter[i] != nullptr) {
            CValue = i + 'a';
            SaveDictionaryHelper(curr->letter[i], currPrefix + CValue, outFile);
        }
    }
}