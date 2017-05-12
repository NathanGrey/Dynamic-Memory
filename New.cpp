#include <iostream> // Starts the preprocessor command including the contents of iostream
using namespace std;   // This eliminates the need to write std::cout so it can just be cout

					   // Declaration of variables
int BoardSize = 0; // Sets the board size to 0 until defined by the user
char** GameBoard = nullptr; // Sets pointer to nothing since size varies
char Player; // Player object

enum SpaceCases { // Sets the spaces to change to X's, O's or *
	PlayerOne = 'X',
	PlayerTwo = 'O',
	Neutral = '*'
};

void PrintBoard() { // Function to print the board spaxes
	for (int i = 0; i < BoardSize; i++) {
		for (int j = 0; j < BoardSize; j++) {
			cout << GameBoard[i][j] << "   ";
		}
		cout << endl << endl;
	}
}

bool CheckIfGameOver() // Function to check for the winner
{
	for (int i = 0; i < BoardSize; ++i)
	{
		for (int j = 0; j < BoardSize; ++j)
		{
			if (GameBoard[i][j] != '*') // If a space is not neutral the checking begins
			{
				if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < BoardSize && (j + 1) < BoardSize)
				{
					// Checks the diagonal down
					if (GameBoard[i - 1][j - 1] == GameBoard[i][j] && GameBoard[i + 1][j + 1] == GameBoard[i][j])
						return true;
					// Checks the diagonal up
					if (GameBoard[i + 1][j - 1] == GameBoard[i][j] && GameBoard[i - 1][j + 1] == GameBoard[i][j])
						return true;
				}
				if ((i - 1) >= 0 && (i + 1) < BoardSize)
				{
					// Checks the columns
					if (GameBoard[i - 1][j] == GameBoard[i][j] && GameBoard[i + 1][j] == GameBoard[i][j])
						return true;
				}
				if ((j - 1) >= 0 && (j + 1) < BoardSize)
				{
					// Checks the rows
					if (GameBoard[i][j - 1] == GameBoard[i][j] && GameBoard[i][j + 1] == GameBoard[i][j])
						return true;
				}
			}
		}
	}
	return false;
}

void PlayerOneMove() { // Player One's movement

	int i, j;
	bool Valid = false;

	while (!Valid) {
		cout << "Player One | Choose a space." << endl;
		cin >> i;
		while (cin.fail()) // Checks if input is an integer 
		{
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> i;
		}

		cin >> j;

		while (cin.fail()) // Checks if input is an integer 
		{
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> j;
		}
		if (GameBoard[i - 1][j - 1] == '*') {
			Valid = true;
		}
		else {
			cout << "This space is already taken." << endl;
		}


	}
	cout << endl;
	GameBoard[i - 1][j - 1] = static_cast<char>(Player);
}

void PlayerTwoMove() { // Player Two's movement

	int i, j;
	bool Valid = false;

	while (!Valid) {
		cout << "Player Two | Choose a space." << endl;

		cin >> i;

		while (cin.fail()) // Checks if input is an integer 
		{
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> i;
		}

		cin >> j;

		while (cin.fail())
		{
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> j;
		}
		if (GameBoard[i - 1][j - 1] == '*') {
			Valid = true;
		}
		else {
			cout << "This space is already taken." << endl;
		}


	}
	cout << endl;
	GameBoard[i - 1][j - 1] = static_cast<char>(Player);
}

bool BoardFull() // Checks if the board is filled
{
	for (int i = 0; i < BoardSize; ++i)
	{
		for (int j = 0; j < BoardSize; ++j)
		{
			if (GameBoard[i][j] == '*')
			{
				return false;
			}
		}
	}
	return true;
}

void DeleteBoard() // Deletes the board that was dynamically allocated
{
	for (int i = 0; i < BoardSize; ++i)
	{
		delete[] GameBoard[i];
	}
	delete[] GameBoard;
}

int main() // Main program
{
	bool GameOver = false;

	do
	{
		cout << "---------------------------------------------------------" << endl << endl;
		cout << "             Welcome to Mega Tic Tac Toe!" << endl << endl;
		cout << "---------------------------------------------------------" << endl << endl;
		cout << "Choose a board size that is greater than or equal to 3." << endl << endl;

		cin >> BoardSize; // Declares the board's size 
		while (cin.fail()) // Checks if input is an integer 
		{
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> BoardSize;
		}
	} while (BoardSize < 3);
	// Allocates the board size dynamically
	GameBoard = new char*[BoardSize];
	for (int i = 0; i < BoardSize; ++i)
	{
		GameBoard[i] = new char[BoardSize];
	}
	// Initializes the board
	for (int i = 0; i < BoardSize; i++)
	{
		for (int j = 0; j < BoardSize; j++)
		{
			GameBoard[i][j] = static_cast<char>(Neutral);
		}
	}

	cout << endl << "You board will be " << BoardSize << " x " << BoardSize << endl << endl;

	PrintBoard(); // Prints the board size

	while (!GameOver) // Loop to keep playing until game over
	{
		Player = static_cast<char>(PlayerOne);
		PlayerOneMove();
		PrintBoard();
		GameOver = CheckIfGameOver();
		if (!GameOver && BoardFull())
		{
			cout << "It's a tie!" << endl;
			break;
			system("pause");
			return 0;
		}
		else if (GameOver)
		{
			if (GameOver && Player == PlayerOne)
			{
				cout << "Player One wins!" << endl;
				system("pause");
				return 0;
			}
			else
			{
				cout << "Player Two wins!" << endl;
				system("pause");
				return 0;
			}
		}

		Player = static_cast<char>(PlayerTwo);
		PlayerTwoMove();
		PrintBoard();
		GameOver = CheckIfGameOver();

		if (!GameOver && BoardFull())
		{
			cout << "It's a tie!" << endl;
			system("pause");
			break;
			return 0;
		}
		else if (GameOver)
		{
			if (GameOver && Player == PlayerOne)
			{
				cout << "Player One wins!" << endl;
				system("pause");
				return 0;
			}
			else
			{
				cout << "Player Two wins!" << endl;
				system("pause");
				return 0;
			}
		}
	}
	DeleteBoard(); // Manages the memory by deleting the board

	system("pause");
	return 0;
}
