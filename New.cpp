#include <iostream> // Preprossesor
#include <string>
#include <ctime>
using namespace std; // Declaring namespace

enum SpaceCases {
        Player_one = 'X',
        Player_two = 'O',
        Neutral    = '*'
    };

int main()
{
    // Declaration of variables
    int Order = 0;
    bool GameOver = false;
  
    char Player;
 
    char** GameBoard = nullptr;
    // Declares the board's size and points to the user inputted size
    int BoardSize;


    cout << "Welcome to Mega Tic Tac Toe!\n";
    cout << "Choose your board size:\n";
    cin >> BoardSize;

  // Computes the board size dynamically


    GameBoard = new char*[BoardSize];
    for (int i = 0; i < BoardSize; ++i)
    {
        GameBoard[i] = new char[BoardSize];
    }
}
       
    // Function call to print game board
    void PrintBoard()
{
    for (int i = 0; i < BoardSize; ++i)
    {
        for (int j = 0; j < BoardSize; ++ j)
        {
            GameBoard[i][j] = ' ';
        }
    }
}

void deleteBoard()
{
    for (int i = 0; i < BoardSize; ++i)
    {
        delete[] GameBoard[i];
    }
    delete[] GameBoard;
}
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
bool CheckIfGameOver(){

    for (int i = 0; i < BoardSize; ++i)
    {
        for (int j = 0; j < BoardSize; ++j)
        {
            if (GameBoard[i][j] != ' ')
            {
                if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < BoardSize && (j + 1) < BoardSize)
                {
                    // Diagonal down
                    if (GameBoard[i - 1][j - 1] == GameBoard[i][j] && GameBoard[i + 1][j + 1] == GameBoard[i][j])
                        return true;
                    // Diagonal up
                    if (GameBoard[i + 1][j - 1] == GameBoard[i][j] && GameBoard[i - 1][j + 1] == GameBoard[i][j])
                        return true;
                }
                if ((i - 1) >= 0 && (i + 1) < BoardSize)
                {
                    // Vetical
                    if (GameBoard[i - 1][j] == GameBoard[i][j] && GameBoard[i + 1][j] == GameBoard[i][j])
                        return true;
                }
                if ((j - 1) >= 0 && (j + 1) < BoardSize)
                {
                    // Horizontal
                    if (GameBoard[i][j - 1] == GameBoard[i][j] && GameBoard[i][j + 1] == GameBoard[i][j])
                        return true;
                }
            }
        }
    }

    return false;
}

