#include <iostream> // Preprossesor
#include <string>
#include <ctime>
using namespace std; // Declaring namespace

enum SpaceCases {
        Player_one = 'X',
        Player_two = 'O',
        Neutral    = '*'
    };

void PrintBoard(char [][20], int);
void PlayerOneMove(char [][20], int, char);
void PlayerTwoMove(char [][20], int, char);
bool CheckIfGameOver(char [][20], char, int, int);

int main()
{
    // Declaration of variables
    int Order = 0;
    bool GameOver = false;
    int WinningScore = 3;
    char Player;
    char GameBoard[20][20]; // Tic Tac Toe Gameboard

    // Declares the board's size and points to the user inputted size
    int BoardSize;
    int * ActualSize;

    cout << "Welcome to Mega Tic Tac Toe!\n";
    cout << "Choose your board size:\n";
    cin >> BoardSize;

  // Computes the board size dynamically
  ActualSize= new (nothrow) int[BoardSize];
  if (ActualSize == nullptr)
    cout << "Error: memory could not be allocated";
  else
  {
     for (int i = 0; i < BoardSize; i++){ 
            for (int j = 0; j < BoardSize; j++){
                GameBoard[i][j] = static_cast<char>(Neutral);
            }
        }
       
    // Function call to print game board
    PrintBoard(GameBoard, BoardSize); 

    // Loop to keep playing until game over
    while (!GameOver){

        if (Order % 2 == 0){
            Player = static_cast<char>(Player_one);
            PlayerOneMove(GameBoard, BoardSize, Player);
            PrintBoard(GameBoard, BoardSize);
            GameOver = CheckIfGameOver(GameBoard, Player, BoardSize, WinningScore);
        }

        else{
            Player = static_cast<char>(Player_two);
            PlayerTwoMove(GameBoard, BoardSize, Player);
            PrintBoard(GameBoard, BoardSize);
            GameOver = CheckIfGameOver(GameBoard, Player, BoardSize, WinningScore);
        }
        Order++;
    }
}
  delete[] ActualSize;
  }

// Function to print the game board based on the user's input
void PrintBoard(char GameBoard[][20], int BoardSize){
    for (int i = 0; i < BoardSize; i++){
        for (int j = 0; j < BoardSize; j++){
            cout<< GameBoard[i][j]<< "   ";
        }
        cout<< "\n\n";
    }
}

void PlayerOneMove(char GameBoard[][20], int BoardSize, char Player){

    int i;
    int j;
    bool valid = false;

    while (!valid){
        cout<< "Player one decide position\n";
        cin>> i;
        cin>> j;
        if (GameBoard[i-1][j-1] == '*'){
            valid = true;
        }
        else{
            cout<< "This position is already taken\n";
        }
    }
    cout<< "\n";
    GameBoard[i-1][j-1] = static_cast<char>(Player);
}

void PlayerTwoMove(char GameBoard[][20], int BoardSize, char Player){

    int i;
    int j;
    bool valid = false;

    while (!valid){
        cout<< "Player two decide position\n";
        cin>> i;
        cin>> j;
        if (GameBoard[i-1][j-1] == '*'){
            valid = true;
        }
        else{
            cout<< "This position is already taken\n";
        }
    }
    cout<< "\n";
    GameBoard[i-1][j-1] = static_cast<char>(Player);
}
// Function to check if the game is over
bool CheckIfGameOver(char GameBoard[][20], char Player, int BoardSize, int WinningScore){

    int n = BoardSize;
    int **Score = new int*[n];
    for (int i = 0; i < n; i++){
        Score[i] = new int[n]();
    }

    //First row
    for (int i = 0; i < n; i++){
        if (GameBoard[0][i] == Player)
            Score[0][i] = 1;
    }

    int Max = 1; // Counts diagonal
    // Longest diagonal
    for (int i = 1; i < n; i++){
        if (GameBoard[i][0] == Player) //Left column
            Score[i][0] = 1 + Score[i - 1][1];
        for (int j = 1; j < n - 1 ; j++){
            if (GameBoard[i][j] == Player){

                if (Score[i][j] > Max)
                    Max = Score[i][j];
            }       
        }
        if (GameBoard[i][n - 1] == Player) // Right column
            Score[i][n - 1] = 1 + Score[i - 1][n - 2];
    }

    // Deletes score matrix
    for (int i = 0; i < BoardSize; i++){
        delete[] Score[i];
    }
    delete[] Score;

    if (Max == WinningScore)
        return true;
    return false;
}
