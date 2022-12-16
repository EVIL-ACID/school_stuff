#include <iostream>
#include <limits>

#define ROWS 8
#define COLS 6


bool checkWin(char board[][COLS], int rowSearch, int colSearch, char play)
{

	// Check row
	int win = 0;
	std::cout << "Checking row " << rowSearch << " Column " << colSearch << std::endl;
	for(int i = 0; i < ROWS; ++i)
	{
		if(board[rowSearch][i] == play)
			win++;
		else
			win = 0;

		if(win == 4) 
			return true;
	}
	std::cout << "\n";


	// Check column
	win = 0; 
	for(int i = 0; i < ROWS; ++i)
	{
		if(board[i][colSearch] == play)
			win++;
		else
			win = 0;

		if(win == 4) 
			return true;
	}
	return false;
}	

void initBoard(char board[][COLS]){

	for(int i = 0; i < ROWS; ++i)
	{
		for(int j = 0; j < COLS; ++j){
			board[i][j] = '-';
		}
	}

}

void displayBoard(char board[][COLS])
{
	for(int i = 0; i < ROWS; ++i)
	{
		for(int j = 0; j < COLS; ++j){
			std::cout << "|" << board[i][j] << "|";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}

int findPosition(char board[][COLS], int col){


	// return row where index does not have either X or O. We Start from ROW - 1 because that is where the bottom of the grid starts and we subtract(Which grows upwards) when searching 
	// untill The row and col are empty.
	int startingRow = ROWS - 1;
	while(board[startingRow][col] == 'X' || board[startingRow][col] == 'O')
	{
		startingRow--;
	}

	return startingRow;
}


void setPlay(char board[][COLS], char play, int row, int col)
{
	board[row][col] = play;
}

void changePlayer(int& player)
{
	player = player == 1 ? 2 : 1; 
}	

bool checkPlay(int col, int row)
{
	//out of range plays

	if(col < 0 || col >= COLS)
    {
        std::cout << "Column out of range\n";
        return false;
    }

    if(row < 0 || row >= ROWS)
    {
    	std::cout << "Choose a different column\n";
    	return false;

    }

   	 return true;
}

int getInput(int player)
{
	do
	{	
		int input;
		std::cout << "Enter a column player  " << player << std::endl;
		std::cin >> input;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input " << std::endl;
		} else {

			return (input - 1);
		}
	}while(true);
}


void runGame(){
	char board[ROWS][COLS];
	char xo[2] = {'X', 'O'};
	int player = 2;
	int col = 0;
	int row = 0;
	int endGame = ROWS * COLS;
	int endGameCounter = 0;

	initBoard(board);
	
	while(true)
	{
		if(endGameCounter == endGame)
		{
			std::cout << "Tie!" << std::endl;
			return;
		}

		col = getInput(player);
		row = findPosition(board, col);
		if(checkPlay(col, row)){
			setPlay(board, xo[player - 1], row, col);
			displayBoard(board);
			if(checkWin(board, row, col, xo[player - 1]))
			{
				std::cout << "Player " << player << " won\n";
				return;
			}

			changePlayer(player);
			endGameCounter += 1;
		}
	}	
}

int main(){
	runGame();
	return 0;
}