#include <iostream> // Preprossesor
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std; // Declaring namespace

enum SpaceCases {
        PLAYER_ONE = 'O',
        PLAYER_TWO = 'X',
        NEUTRAL    = '*'
    };

void PrintBoard(char [][20], int);
void PlayerMove(char [][20], int, char);
bool CheckIfGameOver(char [][20], char, int, int);


int main()
{
	// Declaration of variables
	
	srand(time(NULL));
	int Decide = rand();
	bool GameOver = false;
	int BoardSize = 3;
	int WinningScore = 3;
	char Player;

	char GameBoard[20][20]; // Tic Tac Toe Gameboard

	cout << "Welcome to Mega Tic Tac Toe!\n";
	cout << "Choose your board size:\n";
	cin >> BoardSize;

	// Computes the board size
	    for (int i = 0; i < BoardSize; i++){ 
	        for (int j = 0; j < BoardSize; j++){
	        	GameBoard[i][j] = static_cast<char>(NEUTRAL);
	        }
	    }

	// Function call to print game board
	PrintBoard(GameBoard, BoardSize); 

	// Loop to keep playing until game over
	while (!GameOver){

        if (Decide % 2 == 0){
            Player = static_cast<char>(PLAYER_ONE);
            PlayerMove(GameBoard, BoardSize, Player);
            PrintBoard(GameBoard, BoardSize);
            GameOver = CheckIfGameOver(GameBoard, Player, BoardSize, WinningScore);
        }

        else{
            Player = static_cast<char>(PLAYER_TWO);
            PlayerMove(GameBoard, BoardSize, Player);
            PrintBoard(GameBoard, BoardSize);
            GameOver = CheckIfGameOver(GameBoard, Player, BoardSize, WinningScore);
        }
        Decide+=2;
    }
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


void PlayerMove(char GameBoard[][20], int BoardSize, char Player){

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


// Function to check if the game is over
bool EndGame(char GameBoard[][20], char Player, int BoardSize, int WinningScore){

    //create a score matrix
    int n = BoardSize;
    int **Score = new int*[n];
    for (int i = 0; i < n; i++){
        Score[i] = new int[n]();
    }

    //compute first row
    for (int i = 0; i < n; i++){
        if (GameBoard[0][i] == Player)
            Score[0][i] = 1;
    }

    int Max = 1; //counter for diagonal
    //compute the longest diagonal
    for (int i = 1; i < n; i++){
        if (GameBoard[i][0] == Player) //compute most left column
            Score[i][0] = 1 + Score[i - 1][1];
        for (int j = 1; j < n - 1 ; j++){
            if (GameBoard[i][j] == Player){
                Score[i][j] = 1 + n (Score[i - 1][j - 1], Score[i - 1][j + 1]); //select longest current diagonal
                if (Score[i][j] > Max)
                    Max = Score[i][j];
            }       
        }
        if (GameBoard[i][n - 1] == Player) //compute most right column
            Score[i][n - 1] = 1 + Score[i - 1][n - 2];

                //here we compute the maximum from the most left and right colums
        if (n(Score[i][n - 1], Score[i][0]) > Max)
            Max = n(Score[i][n - 1], Score[i][0]);
    }

    //delete score matrix
    for (int i = 0; i < BoardSize; i++){
        delete[] Score[i];
    }
    delete[] Score;

    if (Max == WinningScore)
        return true;
    return false;
}
