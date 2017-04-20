#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum TicTacToeCases {
        PLAYER_ONE = 'O',
        PLAYER_TWO = 'X',
        NEUTRAL    = '*'
    };

void printGame(char [][20], int);
void makeMove(char [][20], int, char);
bool checkIfGameOver(char [][20], char, int, int);

int main(){

    srand(time(NULL));
    int decide = rand();
    bool over = false;
    int boardSize = 3;
    int toWin = 3;
    char player;

    char ticTacToe[20][20];

    cout<< "Choose the size of the board: ";
    cin>> boardSize;
    cout<< "Choose the amount of character in a row in order to win: ";
    cin>> toWin;

    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            ticTacToe[i][j] = static_cast<char>(NEUTRAL);
        }
    }
    printGame(ticTacToe, boardSize);

    while (!over){

        if (decide % 2 == 0){
            player = static_cast<char>(PLAYER_ONE);
            makeMove(ticTacToe, boardSize, player);
            printGame(ticTacToe, boardSize);
            over = checkIfGameOver(ticTacToe, player, boardSize, toWin);
        }

        else{
            player = static_cast<char>(PLAYER_TWO);
            makeMove(ticTacToe, boardSize, player);
            printGame(ticTacToe, boardSize);
            over = checkIfGameOver(ticTacToe, player, boardSize, toWin);
        }
        decide+=2;
    }
}

void printGame(char ticTacToe[][20], int boardSize){
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            cout<< ticTacToe[i][j]<< "   ";
        }
        cout<< "\n\n";
    }
}

void makeMove(char ticTacToe[][20], int boardSize, char player){

    int i;
    int j;
    bool valid = false;

    while (!valid){
        cout<< "Player one decide position\n";
        cin>> i;
        cin>> j;
        if (ticTacToe[i-1][j-1] == '*'){
            valid = true;
        }
        else{
            cout<< "This position is already taken\n";
        }
    }
    cout<< "\n";
    ticTacToe[i-1][j-1] = static_cast<char>(player);
}

bool checkIfGameOver(char ticTacToe[][20], char player, int boardSize, int toWin){

    //create a score matrix
    int n = boardSize;
    int **score = new int*[n];
    for (int i = 0; i < n; i++){
        score[i] = new int[n]();
    }

    //compute first row
    for (int i = 0; i < n; i++){
        if (ticTacToe[0][i] == player)
            score[0][i] = 1;
    }

    int max = 1; //counter for diagonal
    //compute the longest diagonal
    for (int i = 1; i < n; i++){
        if (ticTacToe[i][0] == player) //compute most left column
            score[i][0] = 1 + score[i - 1][1];
        for (int j = 1; j < n - 1 ; j++){
            if (ticTacToe[i][j] == player){
                score[i][j] = 1 + (score[i - 1][j - 1], score[i - 1][j + 1]); //select longest current diagonal
                if (score[i][j] > max)
                    max = score[i][j];
            }       
        }
        if (ticTacToe[i][n - 1] == player) //compute most right column
            score[i][n - 1] = 1 + score[i - 1][n - 2];

                //here we compute the maximum from the most left and right colums
        if ((score[i][n - 1], score[i][0]) > max)
            max = (score[i][n - 1], score[i][0]);
    }

    //delete score matrix
    for (int i = 0; i < boardSize; i++){
        delete[] score[i];
    }
    delete[] score;

    if (max == toWin)
        return true;
    return false;
}

// http://www.cplusplus.com/forum/beginner/193682/
