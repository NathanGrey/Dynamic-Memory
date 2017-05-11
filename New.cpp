#include <iostream> // Starts the preprocessor command including the contents of iostream
using namespace std;   // This eliminates the need to write std::cout so it can just be cout

int BoardSize = 0;
char** GameBoard = nullptr;
char Player;

enum SpaceCases {
        Player_one = 'X',
        Player_two = 'O',
        Neutral    = '*'
    };

 
void PrintBoard(){
    for (int i = 0; i < BoardSize; i++){
        for (int j = 0; j < BoardSize; j++){
            cout<< GameBoard[i][j]<< "   ";
        }
        cout<< "\n\n";
    }
}
bool CheckIfGameOver() // Function to check if the game is over
{
    for (int i = 0; i < BoardSize; ++i)
    {
        for (int j = 0; j < BoardSize; ++j)
        {
            if (GameBoard[i][j] != '*')
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


void PlayerOneMove(){

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
void PlayerTwoMove(){

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
bool isBoardFull()
{
    for (int i = 0; i < BoardSize; ++i)
    {
        for (int j = 0; j < BoardSize; ++j)
        {
            if (GameBoard[i][j] == Player)
            {
                return false;
            }
        }
    }
    return true;
}

void deleteBoard()
{
    for (int i = 0; i < BoardSize; ++i)
    {
        delete[] GameBoard[i];
    }
    delete[] GameBoard;
}


int main()
{
        int Order = 0;
        bool GameOver = false;
           
        do
        {
        cout << "Welcome to Mega Tic Tac Toe!" << endl;
        cout << "Choose your board size:" << endl;

        cin >> BoardSize; // Declares the board's size 
        
        } while (BoardSize < 3);
// Computes the board size dynamically
    GameBoard = new char*[BoardSize];
    for (int i = 0; i < BoardSize; ++i)
    {
        GameBoard[i] = new char[BoardSize];
    }



  for (int i = 0; i < BoardSize; i++)
     { 
            for (int j = 0; j < BoardSize; j++)
            {
                GameBoard[i][j] = static_cast<char>(Neutral);
            }
        }


        cout << endl << "You board will be (" << BoardSize << ", " << BoardSize << ")" << endl;

        PrintBoard();
            // Loop to keep playing until game over
    while (!GameOver){

        if (Order % 2 == 0){
            Player = static_cast<char>(Player_one);
            PlayerOneMove();
            PrintBoard();
            GameOver = CheckIfGameOver();
           if (!GameOver && isBoardFull())
                    {
                        cout << "ITS A TIE" << endl;
                        break;
                        return 0;
                    }
                    else if (GameOver)
                    {
                        if (PlayerOneMove)
                        {
                            cout << "Player X WINS!!!" << endl;
                            return 0;
                        }
                        else
                        {
                            cout << "Player O WINS!!!" << endl;
                            return 0;
                        }
                    }

        }

        else{
            Player = static_cast<char>(Player_two);
            PlayerTwoMove();
            PrintBoard();
            GameOver = CheckIfGameOver();
            
                if (!GameOver && isBoardFull())
                    {
                        cout << "ITS A TIE" << endl;
                        break;
                        return 0;
                    }
                    else if (GameOver)
                    {
                        if (PlayerOneMove)
                        {
                            cout << "Player X WINS!!!" << endl;
                            return 0;
                        }
                        else
                        {
                            cout << "Player O WINS!!!" << endl;
                            return 0;
                        }
                    }
        }
        Order++;
    }
        PlayerOneMove();
        PlayerTwoMove();
        CheckIfGameOver();

        deleteBoard();
        
    system("pause");
    return 0;
}
