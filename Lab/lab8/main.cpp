#include <iostream>
#include <cstring>
#include <string>

#include "WordGame.h"

using namespace std;

const int testLen = 10;
const string gameSession1[testLen] = {
    "hello", "onion", "never", "reset", "tiger",
    "reach", "honey", "yield", "demon", "night"};

const string gameSession2[testLen] = {
    "world", "diner", "route", "err", "error",
    "round", "diner", "delay", "yield", "belly"};

const string gameSession3[testLen] = {
    "happy", "young", "great", "throw", "whose",
    "exist", "tense", "exact", "teach", "house"};

const string gameSession4[testLen] = {
    "dizzy", "young", "grate", "essay", "youth",
    "hetch", "hatch", "hound", "dizzy", "young"};

int main(int argc, char *argv[])
{
    // Play by yourself
    if (argc >= 2 && strcmp(argv[1], "play") == 0)
    {
        string alg_choice;
        CRAlg alg;
        cout << "Choose CR algorithm (0: Linear, 1: Quadratic): ";
        cin >> alg_choice;
        switch (stoi(alg_choice))
        {
        case 0:
            alg = LINEAR;
            cout << "Using Linear" << endl;
            break;
        case 1:
            alg = QUADRATIC;
            cout << "Using Quadratic" << endl;
            break;
        default:
            alg = LINEAR;
            cout << "Using Linear" << endl;
            break;
        }

        WordGame *game = new WordGame(TABLE_SIZE, alg);
        cout << "===== Game Start ========" << endl;
        game->init();
        while (true)
        {
            string word;
            cout << "Your word: ";
            cin >> word;
            game->queryWord(word);
        }
        cout << "===== Game Finished =====" << endl;
        return 0;
    }

    // Pre-configured tests
    WordGame *game = new WordGame(TABLE_SIZE, CRAlg::LINEAR);

    // Test 1
    cout << "===== Game session 1: Start ========" << endl;
    cout << "Using Linear Probing CR" << endl;
    game->init();
    for (int i = 0; i < testLen; i++)
    {
        game->queryWord(gameSession1[i]);
    }
    cout << "===== Game session 1: Finished =====" << endl;

    // Test 2
    cout << "===== Game session 2: Start ========" << endl;
    cout << "Using Linear Probing CR" << endl;
    game->init();
    for (int i = 0; i < testLen; i++)
    {
        game->queryWord(gameSession2[i]);
    }
    cout << "===== Game session 2: Finished =====" << endl;

    delete game;
    game = new WordGame(TABLE_SIZE, CRAlg::QUADRATIC);

    // Test 3
    cout << "===== Game session 3: Start ========" << endl;
    cout << "Using Quadratic Probing CR" << endl;
    game->init();
    for (int i = 0; i < testLen; i++)
    {
        game->queryWord(gameSession3[i]);
    }
    cout << "===== Game session 3: Finished =====" << endl;

    // Test 4
    cout << "===== Game session 4: Start ========" << endl;
    cout << "Using Quadratic Probing CR" << endl;
    game->init();
    for (int i = 0; i < testLen; i++)
    {
        game->queryWord(gameSession4[i]);
    }
    cout << "===== Game session 4: Finished =====" << endl;

    delete game;
    return 0;
}