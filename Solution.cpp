#include <iostream>

using namespace std;

int boardSize = 0;
char** board = nullptr;
bool keepPlaying = true;

void allocateBoard()
{
	board = new char*[boardSize];
	for (int i = 0; i < boardSize; ++i)
	{
		board[i] = new char[boardSize];
	}
}

void initalizeBoard()
{
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++ j)
		{
			board[i][j] = ' ';
		}
	}
}

void printBoard()
{
	// print column heading
	cout << " ";
	for (int i = 0; i < boardSize; ++i)
	{
		cout << i + 1 << " ";
	}
	cout << endl;

	// print board contents
	for (int i = 0; i < boardSize; ++i)
	{
		// print row number
		cout << i + 1 << " ";

		for (int j = 0; j < boardSize; ++j)
		{
			if (board[i][j] == ' ')
			{
				cout << (char)254 << " ";
			}
			else
			{
				cout << board[i][j] << " ";
			}

		}
		cout << endl;
	}
}

bool checkBoard()
{
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			if (board[i][j] != ' ')
			{
				if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < boardSize && (j + 1) < boardSize)
				{
					// Diagonal down
					if (board[i - 1][j - 1] == board[i][j] && board[i + 1][j + 1] == board[i][j])
						return true;
					// Diagonal up
					if (board[i + 1][j - 1] == board[i][j] && board[i - 1][j + 1] == board[i][j])
						return true;
				}
				if ((i - 1) >= 0 && (i + 1) < boardSize)
				{
					// Vetical
					if (board[i - 1][j] == board[i][j] && board[i + 1][j] == board[i][j])
						return true;
				}
				if ((j - 1) >= 0 && (j + 1) < boardSize)
				{
					// Horizontal
					if (board[i][j - 1] == board[i][j] && board[i][j + 1] == board[i][j])
						return true;
				}
			}
		}
	}

	return false;
}

bool isBoardFull()
{
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

void runGame()
{
	bool playerXTurn = true;
	bool gameOver = false;

	do
	{
		int x, y;
		if (playerXTurn)
		{
			cout << "Player X, please enter your coordinates: ";
		}
		else
		{
			cout << "Player O, please enter your coordinates: ";
		}
		cin >> x >> y;

		--x;
		--y;

		if (x >= 0 && y >= 0 &&
			x < boardSize && y < boardSize &&
			board[y][x] == ' ')
		{
			if (playerXTurn)
			{
				board[y][x] = 'x';
			}
			else
			{
				board[y][x] = 'o';
			}
			playerXTurn = !playerXTurn;
		}
		else
		{
			cout << "Invalid input" << endl;
		}

		printBoard();

		gameOver = checkBoard();

		if (!gameOver && isBoardFull())
		{
			cout << "ITS A TIE" << endl;
			break;
		}
		else if (gameOver)
		{
			if (playerXTurn)
			{
				cout << "Player o WINS!!!" << endl;
			}
			else
			{
				cout << "Player x WINS!!!" << endl;
			}
		}
	} while (!gameOver);
}

void deleteBoard()
{
	for (int i = 0; i < boardSize; ++i)
	{
		delete[] board[i];
	}
	delete[] board;
}

void playAgain()
{
	bool validInput = false;
	char again;
	do
	{
		cout << endl << "Do you want to play again (y/n)?";
		cin >> again;

		if (again == 'y' || again == 'Y')
		{
			validInput = true;
		}
		else if (again == 'n' || again == 'N')
		{
			validInput = true;
			keepPlaying = false;
		}
	} while (!validInput);
}

int main()
{

	do
	{

		do
		{
			cout << "Please enter a valid square board size." << endl;
			cout << "The minimum size is 3." << endl;
			cout << "Size: ";
			cin >> boardSize;
		} while (boardSize < 3);

		cout << endl << "You board will be (" << boardSize << ", " << boardSize << ")" << endl;

		allocateBoard();
		initalizeBoard();
		printBoard();
		runGame();
		deleteBoard();
		playAgain();

	} while (keepPlaying);

	system("pause");
	return 0;
}
