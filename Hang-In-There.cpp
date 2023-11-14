/*
Author: Kenneth Guillont
implementation for Hang-In-There
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


const int g_MAX_WORDS = 1000;
int g_word_count = 0;
string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

void readWords(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    int lineCount = 0;

    while (getline(file, line)) {
        int space = line.find(' ');
        string word = line.substr(0, space);
        g_words[g_word_count] = word;

        int posStartPos = line.find(' ') + 1; 
        int posEndPos = line.find(':', posStartPos) - 1;  
        string pos = line.substr(posStartPos, posEndPos - posStartPos); 
        g_pos[g_word_count] = pos;

        int definitionStartPos = line.find(':', posEndPos + 1) + 2;
        string definition = line.substr(definitionStartPos);
        g_definitions[g_word_count] = definition;

        g_word_count++;
    }
}

int getIndex(string word) {
    for (int i = 0; i < g_word_count; i++)
        if (g_words[i] == word) return i;
    return -1;
}

string getDefinition(string word) {
    int indexWord = getIndex(word);
    if (indexWord != -1) return g_definitions[indexWord];
    return "NOT_FOUND";
}

string getPOS(string word) {
    int indexWord = getIndex(word);
    if (indexWord != -1) return g_pos[indexWord];
    return "NOT_FOUND";
}

int countPrefix(string prefix) {
    int counter = 0;
    for (int i = 0; i < g_word_count; i++) {
        if (g_words[i].find(prefix) == 0) {
            counter++;
        }
    }
    return counter;
}

bool addWord(string word, string definition, string pos) {
    if (g_word_count >= g_MAX_WORDS) { return false; }

    if (getIndex(word) != -1) {return false;}

    g_words[g_word_count] = word;
    g_definitions[g_word_count] = definition;
    g_pos[g_word_count] = pos;
    g_word_count++;

    return true;
}

bool editWord(string word, string definition, string pos) {
    int indexWord = getIndex(word);
    if (indexWord == -1) return false;

    g_definitions[indexWord] = definition;
    g_pos[indexWord] = pos;

    return true;
}

bool removeWord(string word) {
    int indexWord = getIndex(word);
    if (indexWord == -1) return false;

    g_words[indexWord] = g_words[g_word_count - 1];
    g_definitions[indexWord] = g_definitions[g_word_count - 1];
    g_pos[indexWord] = g_pos[g_word_count - 1];

    g_words[g_word_count - 1] = "";
    g_definitions[g_word_count - 1] = "";
    g_pos[g_word_count - 1] = "";

    g_word_count--;
    return true;
}

string maskWord(string word) {
    string maskedWord = "";
    for (int i = 0; i < word.length(); i++) {
        maskedWord += "_";
    }
    return maskedWord;
}

int getTries(int difficulty) {
    if (difficulty == 0) {
        return 9;
    } else if (difficulty == 1) {
        return 7;
    } else if (difficulty == 2) {
        return 5;
    } else {
        return 0;
    }
}

void printAttempts(int tries, int difficulty) {
    int totalTries = getTries(difficulty);
    for (int i = 0; i < totalTries; i++) {
        if (i < tries) {
            cout << "O";
        } else {
            cout << "X";
        }
    }
}

bool revealLetter(string word, char letter, string &current) {
    bool letterFound = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            current[i] = letter;
            letterFound = true;
        }
    }
    return letterFound;
}

// game-loop for Hangman
void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}

int main() {
    readWords("dictionary.txt");
    gameLoop();

    return 0;
}