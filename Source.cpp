#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;
const int col = 8;
const int row = 8;
void chessboard(char board[][8])
{
	cout << "\t A\t B\t C\t D\t E\t F\t G\t H \n";
	cout << "---------------------------------------------------------------------\n";
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1;
		for (int j = 0; j < 8; j++)
		{
			cout << "\t|" << board[i][j];
		}
		cout << endl << "---------------------------------------------------------------------" << endl;
	}
	
}
int select(char board[][8],char& sel, int& Row, int& ind)
{
	char Col;
	cout << "Select Row number: ";
	cin >> Row;
	cout << "Select Column number: ";
	cin >> Col;
	if (Col == 'A')
		ind = 0;
	else if (Col == 'B')
		ind = 1;
	else if (Col == 'C')
		ind = 2;
	else if (Col == 'D')
		ind = 3;
	else if (Col == 'E')
		ind = 4;
	else if (Col == 'F')
		ind = 5;
	else if (Col == 'G')
		ind = 6;
	else if (Col == 'H')
		ind = 7;
	else
	{
		cout << "Invalid input";
		return -1;
	}
	sel = board[Row - 1][ind];
	cout << "Selected element= " << sel << endl;
	return 0;
}
int swap(char board[][8],char sel, int Row, int ind)
{
	char temp = '\0';
	if (Row == 1 )
	{
		if (sel == 'P')
		{
			if (board[Row + 2][ind] == '\0')
			{
				temp = board[Row + 2][ind];
				board[Row + 2][ind] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else
			{
				board[Row + 2][ind] = board[Row][ind];
			}
		}

	}
	else
	{
		if (sel == 'P')
		{
			if (board[Row + 1][ind] == '\0')
			{
				temp = board[Row + 1][ind];
				board[Row + 1][ind] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else
			{
				board[Row + 1][ind] = board[Row][ind];
			}
		}
	}
	if (Row == 6)
	{
		if (sel == 'p')
		{
			if (board[Row -2 ][ind] == '\0')
			{
				temp = board[Row - 2][ind];
				board[Row - 2][ind] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else
			{
				board[Row - 2][ind] = board[Row][ind];
			}
		}
	}
	else
	{
		if (sel == 'p')
		{
			if (board[Row - 1][ind] == '\0')
			{
				temp = board[Row - 1][ind];
				board[Row - 1][ind] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else
			{
				board[Row - 1][ind] = board[Row][ind];
			}
		}
	}
	Sleep(1000);
	system("cls");
	return 0;
}
int main()
{
	char board[8][8] = { { 'C', 'N', 'B', 'Q', 'K', 'B', 'N', 'C' },
{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
{ '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' },
{ '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' },
{ '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' },
{ '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' },
{ 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
{ 'c', 'n', 'b', 'q', 'k', 'b', 'n', 'c' } };
	int Row=0 , ind = 0;
	char sel = '\0';
	chessboard(board);
	select(board , sel, Row, ind);
	swap(board, sel, Row-1, ind);
	chessboard(board);
	system("pause");
	return 0;
}