#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

bool Guess(vector<char> &letters, vector<char> &lettersFound, vector<char> &lettersGuessed, int guessTypes[2])
{
    char letter = ' ';
    cout << "Please guess a letter" << endl;
    cin >> letter;

    system("CLS");
    for (int i = 0; i < letters.size(); i++)
    {
        if (letter == letters.at(i))
        {
            lettersFound.at(i) = letters.at(i);
            letters.at(i) = ' ';
            guessTypes[0]++;
            cout << letter << " is in the word" << endl;
            return true;
        }
    }
    lettersGuessed.push_back(letter);
    guessTypes[1]++;
    cout << letter << " isn't in the word \nGuess again" << endl;

    return false;
}

void PrintCorrect(vector<char> lettersFound)
{
    cout << "Letters guessed: ";
    for (int i = 0; i < lettersFound.size(); i++)
    {
        cout << lettersFound.at(i);
    }
    cout << endl;
}

void PrintFalse(vector<char> lettersGuessed)
{
    cout << "Bad guesses: ";
    for (int i = 0; i < lettersGuessed.size(); i++)
    {
        cout << lettersGuessed.at(i);
    }
    cout << endl;
}

bool CheckGameOver(vector<char> lettersFound)
{
    for (int i = 0; i < lettersFound.size(); i++)
    {
        if (lettersFound.at(i) == '_')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<string> words = {"Apple", "Hippocampus", "Computer", "Horse", "Pancake", "Rioting", "Monarch", "Liver", "Backpack", "Leaves"};
    vector<char> lettersFound;
    vector<char> letters;
    vector<char> lettersGuessed;

    int guessTypes[2] = {0, 0};

    bool gameOver = false;
    bool guessTrue = false;
    int randWord = 0;
    string word = " ";
    string tryAgain = "yes";

    while (tryAgain == "yes" || tryAgain == "Yes")
    {
        //reset all variables
        lettersFound.clear();
        letters.clear();
        lettersGuessed.clear();
        guessTypes[0] = 0;
        guessTypes[1] = 0;
        gameOver = false;
        guessTrue = false;
        randWord = 0;
        word = " ";

        system("CLS");
        cout << "Welcome to hangman!" << endl;

        srand(time(NULL));
        randWord = rand() % 10;
        word = words.at(randWord);

        //fill letters with words letters
        for (int i = 0; i < word.size(); i++)
        {
            letters.push_back(word.at(i));
            lettersFound.push_back('_');
        }

        cout << "There are " << word.size() << " letters in the word \n\n";
        cout << "DEBUGG: " << word << endl;

        while (!gameOver)
        {
            //system("CLS");
            cout << "Guesses made: " << guessTypes[0] + guessTypes[1] << "\nGood guesses: " << guessTypes[0] << "\tBad guesses: " << guessTypes[1] << "\n\n";
            guessTrue = Guess(letters, lettersFound, lettersGuessed, guessTypes);
            if (guessTrue)
            {

                PrintCorrect(lettersFound);
                if (CheckGameOver(lettersFound))
                {
                    cout << "You have correctly guessed the word! \nIt took you " << guessTypes[0] << " guesses \n\nWould you like to try again?" << endl;
                    cout << "Type yes to play again or quit to quit" << endl;
                    cin >> tryAgain;

                    gameOver = true;
                }
            }
            else
            {
                PrintFalse(lettersGuessed);
            }
        }
    }
}
