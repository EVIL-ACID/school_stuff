#include <iostream>
#include <limits>

#define ROWS 3
#define COLS 3
#define TIE 9


bool checkWin(char board[][COLS], char c)
{
	// First row win	
	if(board[0][0] == c && board[0][1] == c && board[0][2] == c) return true;

	// Second row win
	if(board[1][0] == c && board[1][1] == c && board[1][2] == c) return true;

	// Third row win
	if(board[2][0] == c && board[2][1] == c && board[2][2] == c) return true;

	// First column win
	if(board[0][0] == c && board[1][0] == c && board[2][0] == c) return true;

	// Second column win
	if(board[0][1] == c && board[1][1] == c && board[2][1] == c) return true;

	// Third column win
	if(board[0][2] == c && board[1][2] == c && board[2][2] == c) return true;

	// First diagonal win
	if(board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;

	// Second diagonal win
	if(board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
	
	// no win
	return false;
}


void initBoard(char board[][COLS])
{
	for(int i = 0; i < ROWS; ++i)
	{
		for(int j = 0; j < COLS; ++j)
		{
			board[i][j] = '.';	
		}	
	}

}


void displayBoard(char board[][COLS])
{
	for(int i = 0; i < ROWS; ++i)
	{
		for(int j = 0; j < COLS; ++j)
		{
			std::cout << " " << board[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}



void setPlay(char board[][COLS], char play,  int row, int col)
{
	if(play == 'X' || play == 'O')
		board[row - 1][col - 1] = play;
}


void changePlay(int& play)
{
	play = play == 1 ? 0 : 1; 

}


bool checkPlay(char board[][COLS], int row, int col)
{

	//out of range
	if(row <= 0 || row > 3)
        {
                std::cout << "Invalid input\n";
                return false;
        }

        if(col <= 0 || col > 3)
        {
                std::cout << "Invaid input\n";
                return false;
        }

	//position already used
       if(board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O')
        {
                std::cout << "Position used\n";
                return false;	
        }
	return true;
}


int getInput()
{
	do
	{	
		int input;
		std::cout << "Enter a row and column : " << std::endl;
		std::cin >> input;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter a valid number" << std::endl;
		} else {

			return input;
		}
	}while(true);
}


void runGame()
{
	
	char xo[2] = {'X', 'O'};
	char board[ROWS][COLS];
	int rowInput, colInput;
	int turn = 1;
	int numberOfPlays = 0;
	bool win = false;
	
	initBoard(board);

	do
	{
		if(numberOfPlays == TIE)
		{
			std::cout << "Tie!\n" << std::endl;
			return;
		}

		rowInput = getInput();
		colInput = getInput();
		if(checkPlay(board, rowInput, colInput))
		{
			changePlay(turn);
			setPlay(board, xo[turn], rowInput, colInput);
			displayBoard(board);
			if(checkWin(board, xo[turn]))
			{
				std::cout << "Player " << xo[turn] << " wins!!\n";
				win = true;
			}

			numberOfPlays += 1;
		}
	}while(win != true);
}



int main()
{
	runGame();
	return 0;
}
