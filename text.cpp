/*
Author: Kenneth Guillont

Implementation of Text.cpp

*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Skip the header line

    while (getline(file, line))
    {
        size_t pos = line.find(" : ");
        if (pos != string::npos)
        {
            g_words[g_word_count] = line.substr(0, pos);
            size_t end_pos = line.find(" : ", pos + 1);
            if (end_pos != string::npos)
            {
                g_pos[g_word_count] = line.substr(pos + 3, end_pos - pos - 3);
                g_definitions[g_word_count] = line.substr(end_pos + 3);
                g_word_count++;
            }
        }
    }

    file.close();
}
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

int main()
{
    string filename = "example.txt"; // Replace with your file path
    readWords(filename);

    cout << "g_MAX_WORDS: " << g_MAX_WORDS << endl;
    cout << "g_word_count: " << g_word_count << endl;

    cout << "g_words: [";
    for (int i = 0; i < g_word_count; i++)
    {
        cout << "\"" << g_words[i] << "\"";
        if (i < g_word_count - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    cout << "g_pos: [";
    for (int i = 0; i < g_word_count; i++)
    {
        cout << "\"" << g_pos[i] << "\"";
        if (i < g_word_count - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    cout << "g_definitions: [" << endl;
    for (int i = 0; i < g_word_count; i++)
    {
        cout << "    \"" << g_definitions[i] << "\"";
        if (i < g_word_count - 1)
            cout << "," << endl;
    }
    cout << endl << "]" << endl;

    return 0;
}
}
