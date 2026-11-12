#include <iostream>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <thread>
using namespace std;
char board[8][8] = { { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' },
{ 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' },
{ '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' },
{ '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' },
{ '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' },
{ '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' },
{ 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' },
{ 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' } };
bool turn = 0;
int tim = 0, hr = 0, m = 0, sec = 0, indi = 0, indj = 0;
/*clock_t timer;
void classic()
{
	timer = clock();
	cout << "Time: " << endl;
	while (tim >= 0 && !_kbhit() )
	{
		if (sec == 60 && m == 60)
		{
			m = 0;
			hr++;
		}
		if (sec == 60)
		{
			sec = 0;
			m++;
		}
        cout << hr << ":"<< m << ":" << sec;
		sec++;
		cout << '\r';
		Sleep(1000);
		timer++;

	}
	cout << '\n';
}
void rapid()
{
	m = 0, sec = 0;
	timer = clock();
	cout << "Time Remaining: " << endl;
	do {

		m = tim / 60;
		sec = tim % 60;
		if (sec == 0)
		{
			sec = 60;
			m--;
		}
		cout << m << ":" << sec;
		cout << '\r';
		Sleep(1000);
		tim--;
		if ((m == 0 && sec == 0) || ((clock() - timer) / CLOCKS_PER_SEC) > 600)
		{
			system("cls");
			cout << "Time over\n";
			if (turn == 0)
				cout << "White lost\n";
			else
				cout << "Black lost\n";
			exit(0);
		}
	} while (tim >= 0 && !_kbhit());
	cout << '\n';
}
void blitz()
{
	m = 0, sec = 0;
	timer = clock();
	cout << "Time Remaining: " << endl;
	do{

		m = tim / 60;
		sec = tim % 60;
		if (sec == 0)
		{
			sec = 60;
			m--;
		}
		cout << m << ":"<< sec;
		cout << '\r';
		Sleep(1000);
		tim--;
		if ((m == 0 && sec == 0) || ((clock() - timer) / CLOCKS_PER_SEC) > 300)
		{
			system("cls");
			cout << "Time over\n";
			if (turn == 0)
				cout << "White lost\n";
			else
				cout << "Black lost\n";
			exit(0);
		}
	} while (tim >= 0 && !_kbhit());
	cout << '\n';
}
void lightning()
{
	timer = clock();
	sec = 15;
	cout << "Time Remaining: " << endl;
	do{
		cout << sec;
		Sleep(1000);
		sec--;
		if (((clock() - timer) / CLOCKS_PER_SEC) > 15)
		{
			system("cls");
			cout << "Time over\n";
			if (turn == 0)
				cout << "White lost\n";
			else
				cout << "Black lost\n";
			exit(0);
		}
	} while (tim >= 0 && !_kbhit());
	cout << '\n';
}*/
void printBoard()
{
	for (int i = 0; i < 8; i++)
	{
		cout << 8-i;
		for (int j = 0; j < 8; j++)
		{
			cout << "\t|" << board[i][j];
		}
		cout << endl << "---------------------------------------------------------------------" << endl;
	}
	cout << "\t a\t b\t c\t d\t e\t f\t g\t h \n";
}
int findK(char& sel2, int Row, int Row2, int ind, int ind2)
{
	bool king;
	if (turn == 0)
	{
		king = 0;
		for (int i = 0; i < 8 && king == 0; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'K')
				{
					indi = i;
					indj = j;
					king = 1;
					break;
				}
			}
		}
	}
	else
	{
		king = 0;
		indi = 0, indj = 0;
		for (int i = 0; i < 8 && king == 0; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 'k')
				{
					indi = i;
					indj = j;
					king = false;
					break;
				}
			}
		}
	}
	return 0;
}
int select(char& sel, int& Row, int& ind, char Col)
{
	if (Row == 8)
		Row = 1;
	else if (Row == 7)
		Row = 2;
	else if (Row == 6)
		Row = 3;
	else if (Row == 5)
		Row = 4;
	else if (Row == 4)
		Row = 5;
	else if (Row == 3)
		Row = 6;
	else if (Row == 2)
		Row = 7;
	else if (Row == 1)
		Row = 8;
	else
		return -3;
		if (Col == 'a')
			ind = 0;
		else if (Col == 'b')
			ind = 1;
		else if (Col == 'c')
			ind = 2;
		else if (Col == 'd')
			ind = 3;
		else if (Col == 'e')
			ind = 4;
		else if (Col == 'f')
			ind = 5;
		else if (Col == 'g')
			ind = 6;
		else if (Col == 'h')
			ind = 7;
		else
			return -1;
		sel = board[Row - 1][ind];
		if (sel == '\0')
			return -2;
	return 0;
}
int validInput(char sel)
{
	if (turn == 1)
	{
		if (sel == 0)
			return 0;
		else if (sel == 'p')
			return 0;
		else if (sel == 'r')
			return 0;
		else if (sel == 'n')
			return 0;
		else if (sel == 'b')
			return 0;
		else if (sel == 'q')
			return 0;
		else if (sel == 'k')
			return 0;
		else return -1;
	}
	else if (turn == 0)
	{
		if (sel == 0)
			return 0;
		else if (sel == 'P')
			return 0;
		else if (sel == 'R')
			return 0;
		else if (sel == 'N')
			return 0;
		else if (sel == 'B')
			return 0;
		else if (sel == 'Q')
			return 0;
		else if (sel == 'K')
			return 0;
		return -1;
	}
}
int validSelection(char sel2)
{
		if (turn == 0)
		{
			if (sel2 == '\0')
				return 0;
			else if (sel2 == 'p')
				return 0;
			else if (sel2 == 'r')
				return 0;
			else if (sel2 == 'n')
				return 0;
			else if (sel2 == 'b')
				return 0;
			else if (sel2 == 'q')
				return 0;
			else if (sel2 == 'k')
				return 123;
			else
				return -1;
		}
		else if (turn == 1)
		{
			if (sel2 == 0)
				return 0;
			else if (sel2 == 'P')
				return 0;
			else if (sel2== 'R')
				return 0;
			else if (sel2 == 'N')
				return 0;
			else if (sel2 == 'B')
				return 0;
			else if (sel2 == 'Q')
				return 0;
			else if (sel2 == 'K')
				return 321;
			else
			   return -1;
		}
}
int checkmate(char sel2)
{
	if (validSelection(sel2) == 123)
		return 1;
	else if (validSelection(sel2) == 321)
		return 2;
	else
	   return 0;
}
int input(char& sel, int& Row, int& ind, char Col, int& Row2, int& ind2, char Col2)
{
	char sel2 = 0;
	bool check,check2 ;
		do {
			check = 1;
			cout << "Select Row and column: ";
			cin >> Row >> Col;
			int selection = select(sel, Row, ind, Col);
			if (selection == -3)
			{
				cout << "Invalid row please enter again \n";
				check = 0;
				continue;
			}
			if (selection == -1)
			{
				cout << "Invalid column please enter again \n";
				check = 0;
				continue;
			}
		    if (selection == -2)
			{
				cout << "Nothing is selected please select again \n";
				check = 0;
				continue;

			}
			if (validInput(sel) == -1)
			{
				cout << "Invalid selection please enter again \n";
				check = 0;
				continue;
			}
		} while (check != 1);
		cout << "Selected element= " << sel << endl;
		do {
			check2 = 1;
			cout << "Enter destination Row and column: ";
			cin >> Row2 >> Col2;
			int selection1 = select(sel2, Row2, ind2, Col2);
			if (selection1 == -3)
			{
				cout << "Invalid row please enter again \n";
				check2 = 0;
				continue;
			}
			 if (selection1 == -1)
			{
				cout << "Invalid column please enter again \n";
				check2 = 0;
				continue;
			}
			if (validSelection(sel2) == -1)
			{
				cout << "Invalid move please enter again \n";
				check2 = 0;
				continue;
			}
			if (selection1 == -2)
			{
				return -1;
			}
		} while (check2 != 1);
	return 0;
}
int swapP(char sel, char& sel2, int Row, int Row2, int ind, int ind2, bool empty)
{
	char temp = '\0';
	sel2 = board[Row2][ind2];
	int selection = validSelection(sel2);
	if (selection == -1)
		return -1;
	else if (selection == 123 || selection == 321)
		checkmate(sel2);
	if (Row == 1 )
	{
		if (sel == 'P')
		{
			if (Row2 == Row + 2 || Row2 == Row + 1)
			{
				if (empty == 1)
				{
					temp = board[Row2][ind2];
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = temp;
				}
				else
				{
					cout << board[Row2][ind2] << " have died\n";
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = '\0';
				}
			}
			else
			{
				return -1;
			}
		}
	}
	else
	{
		if (sel == 'P')
		{
			if (Row2 == Row + 1)
			{
				if (empty == 1)
				{
					temp = board[Row2][ind2];
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = temp;
				}
				else
				{
					cout << board[Row2][ind2] << " have died\n";
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = '\0';
				}
			}
			else
			{
				return -1;
			}
			int promote = 0, check = 0;
			do {
				if (Row2 == 7)
				{
					cout << "Promote pawn to \n1.Queen:\n2.Bishops:\n3.Knights:\n4.Rooks:\n";
					cin >> promote;
					if (promote == 1)
						board[Row2][ind2] = 'Q';
					else if (promote == 2)
						board[Row2][ind2] = 'B';
					else if (promote == 3)
						board[Row2][ind2] = 'K';
					else if (promote == 4)
						board[Row2][ind2] = 'R';
					else
					{
						cout << "Invalid input\n";
						check = 1;
					}
				}
			} while (check != 0);
		}
	}
	if (Row == 6)
	{
		if (sel == 'p')
		{
			if (Row2 == Row - 2 || Row2 == Row - 1)
			{
				if (empty == 1)
				{
					temp = board[Row2][ind2];
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = temp;
				}
				else
				{
					cout << board[Row2][ind2] << " have died\n";
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = '\0';
					Sleep(1000);
				}
			}
			else
			{
				return -1;
			}
		}
	}
	else
	{
		if (sel == 'p')
		{
			if (Row2 == Row - 1)
			{
				if (empty == 1)
				{
					temp = board[Row2][ind2];
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = temp;
				}
				else
				{
					cout << board[Row2][ind] << " have died\n";
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = '\0';
				}
			}
			else
			{
				return -1;
			}
			int promote = 0, check = 0;
			do {
				if (Row2 == 0)
				{
					cout << "Promote pawn to \n1.Queen:\n2.Bishops:\n3.Knights:\n4.Rooks:\n";
					cin >> promote;
					if (promote == 1)
						board[Row2][ind2] = 'q';
					else if (promote == 2)
						board[Row2][ind2] = 'b';
					else if (promote == 3)
						board[Row2][ind2] = 'k';
					else if (promote == 4)
						board[Row2][ind2] = 'r';
					else
					{
						cout << "Invalid input\n";
						check = 1;
					}
				}
			} while (check != 0);
		}
	}
	findK(sel, Row, ind, Row2, ind2);
	if (Row2 + 1 == indi)
		cout << "Check\n";
	Sleep(1000);
	system("cls");
	return 0;
}
int swapR(char& sel2, int Row, int Row2, int ind, int ind2)
{
	int temp = 0, count = 0, i = 0, j = 0;
	sel2 = board[Row2][ind2];
	if (validSelection(sel2) == -1)
		return -1;
	else if (validSelection(sel2) == 123 || validSelection(sel2) == 321)
		checkmate(sel2);
	if (Row == Row2 && ind == ind2)
		return -1;
	if (Row == Row2)                // Horizontal move
	{
		if (ind < ind2) 
		{
			for (i = ind + 1; i <= ind2; i++)  // Right move
			{
				if (board[Row2][i] = 0)
					count++;
				else
					break;
			}
			if (count == ind2 - ind)
			{
				temp = board[Row2][ind2];
				board[Row2][ind2] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else if (ind2 == count+1)
			{
				if (board[Row2][ind2] != 0)
				{
					if (validSelection(sel2) == 0)
					{
						cout << board[Row2][i] << " have died\n";
						board[Row2][i] = board[Row][ind];
						board[Row][ind] = '\0';
					}
					else if (validSelection(sel2) == -1)
						return -1;
				}
			}
			else
				return -1;
		}
		else
		{	
			for (int j = ind - 1; j >= ind2; j++)     // Move left
			{
				if (board[Row2][j] = 0)
					count++;
				else
					break;
			}
			if (count == ind - ind2)
			{
				temp = board[Row2][ind2];
				board[Row2][ind2] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else if (ind2 == count+1)
			{
				if (board[Row2][ind2] != 0)
				{
					if (validSelection(sel2) == 0)
					{
						cout << board[Row2][j] << " have died\n";
						board[Row2][j] = board[Row][ind];
						board[Row][ind] = '\0';
					}
					else if (validSelection(sel2) == -1)
						return -1;
				}
			}
			else 
				return -1;
		}
	}
	else if (ind == ind2)
	{
		if (Row < Row2)          // Vertical move
		{
			for (int i = Row + 1; i <= Row2; i++)    // Move down
			{
				if (board[i][ind2] == '\0')
					count++;
				else
					break;
			}
			if (count == Row2 - Row)
			{
				temp = board[Row2][ind2];
				board[Row2][ind2] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else if (Row2 == count+1)
			{ 
				if (board[Row2][ind2] != 0)
				{
					if (validSelection(sel2) == 0)
					{
						cout << board[Row2][i] << " have died\n";
						board[Row2][i] = board[Row][ind];
						board[Row][ind] = '\0';
					}
					else if (validSelection(sel2) == -1)
						return -1;
				}
			}
			else
				return -1;
		}
		else {
			
			for (int j = Row - 1; j >= Row2; j--)   // Move up
			{
				if (board[j][ind2] = 0)
					count++;
				else
					break;
			}
			if (count == Row - Row2)
			{
				temp = board[Row2][ind2];
				board[Row2][ind2] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else if (Row2 == count+1)
			{
				if (board[Row2][ind2] != 0)
				{
					if (validSelection(sel2) == 0)
					{
						cout << board[Row2][j] << " have died\n";
						board[Row2][j] = board[Row][ind];
						board[Row][ind] = '\0';
					}
					else if (validSelection(sel2) == -1)
						return -1;
				}
			}
			else
				return -1;
		}
	}
	else 
		return -1;
	Sleep(1000);
	system("cls");
	return 0;
}
int swapN(char& sel2, int Row, int Row2, int ind, int ind2)
{
	int temp = 0;
	sel2 = board[Row2][ind2];
	if (validSelection(sel2) == -1)
		return -1;
	else if (validSelection(sel2) == 123 || validSelection(sel2) == 321)
		checkmate(sel2);
	if (Row2 == Row + 1 || Row2 == Row - 1)                //horizontal L
	{
		if (ind2 == ind + 2 || ind2 == ind - 2)
		{
			if (sel2 == '\0')
			{
				temp = board[Row2][ind2];
				board[Row2][ind2] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else
			{
				cout << board[Row2][ind2] << " have died\n";
				board[Row2][ind2] = board[Row][ind];
				board[Row][ind] = '\0';
			}
		}
		else
			return -1;
	}
	else if (ind2 == ind + 1 || ind2 == ind - 1)       //vertical L
	{
		if (Row2 == Row + 2 || Row2 == Row - 2)
		{
			if (sel2 == '\0')
			{
				temp = board[Row2][ind2];
				board[Row2][ind2] = board[Row][ind];
				board[Row][ind] = temp;
			}
			else
			{
				cout << board[Row2][ind2] << " have died\n";
				board[Row2][ind2] = board[Row][ind];
				board[Row][ind] = '\0';
			}
		}
		else
			return -1;
	}
	else
		return -1;
	Sleep(1000);
	system("cls");
	return 0;
}
int swapB(char& sel2, int Row, int Row2, int ind, int ind2) 
{
	int count = 0, temp = 0;
	sel2 = board[Row2][ind2];
	if (validSelection(sel2) == -1)
		return -1;
	else if (validSelection(sel2) == 123 || validSelection(sel2) == 321)
		checkmate(sel2);
	bool found = true;
	if (Row2 > Row && ind2 > ind)              //Right down diagonal
	{								
		for (int i = Row + 1, j = ind + 1; i < Row2 && j < ind2; i++, j++)
		{
			if (board[i][j] = '\0')
				count++;
			else
				break;
		}
		if (count == ind2 - ind && count== Row2 - Row)
		{
			temp = board[Row2][ind2];
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = temp;
		}
		else if (ind2 == count + 1 && Row2 == count + 1)
		{
			if (board[Row2][ind2] != 0)
			{
				if (validSelection(sel2) == 0)
				{
					cout << board[Row2][ind2] << " have died\n";
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = '\0';
				}
				else if (validSelection(sel2) == -1)
					return -1;
			}
		}
		else
			return -1;
	}
	else if (Row2 > Row && ind2 < ind)       //Left down diagonal
	{							
		for (int i = Row, j = ind; i < Row2 && j >= ind2; i++, j--) 
		{
			if (board[i][j] = '\0')
				count++;
			else
				break;
		}
		if (count == ind - ind2 && count == Row2 - Row)
		{
			temp = board[Row2][ind2];
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = temp;
		}
		else if (ind == count + 1 && Row2 == count + 1)
		{
			if (board[Row2][ind2] != 0)
			{
				if (validSelection(sel2) == 0)
				{
					cout << board[Row2][ind2] << " have died\n";
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = '\0';
				}
				else if (validSelection(sel2) == -1)
					return -1;
			}
		}
		else
			return -1;
	}
	else if (Row2 < Row && ind2 > ind)       //right up diagonal
	{							
		for (int i = Row, j = ind; i >= Row2 && j < ind2; i--, j++)
		{
			if (board[i][j] = '\0')
				count++;
			else
				break;
		}
		if (count == ind2 - ind && count == Row - Row2)
		{
			temp = board[Row2][ind2];
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = temp;
		}
		else if (ind2 == count + 1 && Row == count + 1)
		{
			if (board[Row2][ind2] != 0)
			{
				if (validSelection(sel2) == 0)
				{
					cout << board[Row2][ind2] << " have died\n";
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = '\0';
				}
				else if (validSelection(sel2) == -1)
					return -1;
			}
		}
		else
			return -1;
	}
	else if (Row2 < Row && ind2 < ind)     //left up diagonal
	{							
		for (int i = Row, j = ind; i >= Row2 && j >= ind2; i--, j--) 
		{
			if (board[i][j] = '\0')
				count++;
			else
				break;
		}
		if (count == ind - ind2 && count == Row - Row2)
		{
			temp = board[Row2][ind2];
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = temp;
		}
		else if (ind == count + 1 && Row == count + 1)
		{
			if (board[Row2][ind2] != 0)
			{
				if (validSelection(sel2) == 0)
				{
					cout << board[Row2][ind2] << " have died\n";
					board[Row2][ind2] = board[Row][ind];
					board[Row][ind] = '\0';
				}
				else if (validSelection(sel2) == -1)
					return -1;
			}
		}
		else
			return -1;
	}
	Sleep(1000);
	system("cls");
	return 0;
}
int swapQ(char& sel2, int Row, int Row2, int ind, int ind2)
{
	if (swapR(sel2, Row, Row2, ind, ind2) == -1)
		if (swapB(sel2, Row, Row2, ind, ind2) == -1)
			return -1;
}
int swapK(char& sel2, int Row, int Row2, int ind, int ind2)
{
	int temp = 0;
	sel2 = board[Row2][ind2];
	if (validSelection(sel2) == -1)
		return -1;
	else if (validSelection(sel2) == 123 || validSelection(sel2) == 321)
		checkmate(sel2);
	if (ind2 == ind && (Row2 == Row + 1 || Row2 == Row - 1))
	{
		if (sel2 == '\0')
		{
			temp = board[Row2][ind2];
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = temp;
		}
		else
		{
			cout << board[Row2][ind2] << " have died\n";
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = '\0';
		}
	}
	else if (Row2 == Row && (ind2 == ind + 1 || ind2 == ind - 1))
	{
		if (sel2 == '\0')
		{
			temp = board[Row2][ind2];
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = temp;
		}
		else
		{
			cout << board[Row2][ind2] << " have died\n";
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = '\0';
		}
	}
	else if (Row2 == Row + 1 && (ind2 == ind + 1 || ind2 == ind - 1))
	{
		if (sel2 == '\0')
		{
			temp = board[Row2][ind2];
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = temp;
		}
		else
		{
			cout << board[Row2][ind2] << " have died\n";
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = '\0';
		}
	}
	else if (Row2 == Row - 1 && (ind2 == ind + 1 || ind2 == ind - 1))
	{
		if (sel2 == '\0')
		{
			temp = board[Row2][ind2];
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = temp;
		}
		else
		{
			cout << board[Row2][ind2] << " have died\n";
			board[Row2][ind2] = board[Row][ind];
			board[Row][ind] = '\0';
		}
	}
	else
		return -1;
	Sleep(1000);
	system("cls");
	return 0;
}
void save(char end)
{
	ofstream saveFile;
	if (end == '1')
	{
		saveFile.open("saved1.txt");
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				saveFile << board[i][j];
		saveFile << turn;
	}
	else if (end == '2')
	{
		saveFile.open("saved2.txt");
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				saveFile << board[i][j];
	}
	else if (end == '3')
	{
		saveFile.open("saved3.txt");
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				saveFile << board[i][j];
		saveFile << turn;
	}
}
void load(char game)
{
	ifstream loadFile;
	if (game == '1')
	{
		loadFile.open("saved1.txt");
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				loadFile >> board[i][j];
		loadFile >> turn;
	}
	else if (game == '2')
	{
		loadFile.open("saved2.txt");
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				loadFile >> board[i][j];
		loadFile >> turn;
	}
	else if (game == '3')
	{
		loadFile.open("saved3.txt");
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				loadFile >> board[i][j];
		loadFile >> turn;
	}
}
void welcome()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n------------------------------------------------------------------------------------------------------------------------"
		<<"\t\t\t\t\t\t\t  WELCOME TO CHESS\n"
		<< "------------------------------------------------------------------------------------------------------------------------ ";
	Sleep(2000);
	system("cls");
}
int main()
{
    char game;
	int Row = 0, ind = 0, Row2 = 0, ind2 = 0;
	char sel = 0, sel2 = 0, Col = 0, Col2 = 0, end = 0, mode, temp = 0;
	welcome();
	/*cout << "To play in Classic mode press 1:\nTo play in Rapid mode press 2:\nTo play in Blitz mode press 3:\nTo play in lightning mode press 4:\n";
	cin >> mode;
	if (mode != '1' && mode != '2' && mode != '3' && mode != '4')
	{
		cout << "Invalid input";
		return -1;
	}*/
	cout << "To start a new game press any key: \nTo load the previous games press 1: \n";
	cin >> game;
	if (game == '1')
	{
		cout << "To load file 1 press 1:\nTo load file 2 press 2:\nTo load file 3 press 3:\nPress any other key to cancel and continue:\n";
		cin >> game;
		if(game=='1'||game=='2'||game=='3')
		load(game);
	}
	Sleep(500);
	system("cls");
	cout << "Capitals Letters = White\n\n" << "Small Letters = Black\n";
	Sleep(2000);
	system("cls");
	/*	if (mode == '1')
			classic();
		else if (mode == '2')
			rapid();
		else if (mode == '3')
			blitz();
		else if (mode == '4')
			lightning();*/
	do
	{
		int checkmate(sel2);
		if (turn==0)
		{
			turn = 0;
			cout << "White turn:\n";
		}
		else
		{
			turn = 1;
			cout << "Black turn:\n";
		}
		printBoard();
		cout << "To Resign the game press r: \nTo Handshake press h: \nTo Save and Quit press s: \nTo Continue press any key: \n";
		cin >> end;
		if (end == 'h')
		{
			cout << "The other player wants to shake hands\nPress h to shake hands: ";
			cin >> end;
			if (end == 'h')
				break;
			else
				cout << "Game Continues\n";
		}
		if (end == 'r' || end=='s')
			break;
		bool check2, empty;
		do {
			empty = 0;
			check2 = 1;
			if (input(sel, Row, ind, Col, Row2, ind2, Col2) == -1)
				empty = 1;
			sel = board[Row-1][ind];
			if (sel == 'P' || sel == 'p')
			{
				if (empty == 1 && ind2 != ind)
				{
					cout << "Invalid move\n";
					check2 = 0;
					continue;
				}
				if (swapP(sel, sel2, Row - 1, Row2 - 1, ind, ind2, empty) == -1)
				{
					cout << "Invalid move\n";
					check2 = 0;
					continue;
				}
			}
			else if (sel == 'R' || sel == 'r')
			{
				if (swapR(sel2, Row - 1, Row2 - 1, ind, ind2) == -1)
				{
					check2 = 0;
					cout << "Invalid move\n";
					continue;
				}
			}
			else if (sel == 'N' || sel == 'n')
			{
				if (swapN(sel2, Row - 1, Row2 - 1, ind, ind2) == -1)
				{
					check2 = 0;
					cout << "Invalid move\n";
					continue;
				}
			}
			else if (sel == 'B' || sel == 'b')
			{
				if (swapB(sel2, Row - 1, Row2 - 1, ind, ind2) == -1)
				{
					check2 = 0;
					cout << "Invalid move\n";
					continue;
				}
			}
			else if (sel == 'Q' || sel == 'q')
			{
				if (swapQ(sel2, Row - 1, Row2 - 1, ind, ind2) == -1)
				{
					check2 = 0;
					cout << "Invalid move\n";
					continue;
				}
			}
			else if (sel == 'K' || sel == 'k')
			{
				if (swapK(sel2, Row - 1, Row2 - 1, ind, ind2) == -1)
				{
					check2 = 0;
					cout << "Invalid move\n";
					continue;
				}
			}
			else
			{
				cout << "Invalid\n";
				check2 = 0;
			}
		} while (check2 != 1);
		if (turn == 0)
		{
			turn = 1;
		}
		else
		{
			turn = 0;
		}
	} while (checkmate(sel2) == 0);
	if (end == 'r')
	{
		if(turn == 0)
		   cout << "White resigned\nBlack won\n";
		else
			cout << "Black resigned\nWhite won\n";
		return 0;
	}
	else if (end == 'h')
	{
		cout << "Game has drawed\n";
		return 0;
	}
	else if (end == 's')
	{
		cout << "To save the game in file 1 press 1:\nTo save the game in file 2 press 2:\nTo save the game in file 3 press 3:\n";
		cin >> end;
		if (end == '1' || end == '2' || end == '3')
		{
			save(end);
			cout << "Game have been saved\n";
		}
		else
			cout << "Invalid input";
		return 0;
	}
		if (checkmate(sel2) == 1)
			cout << "White won\n";
		else if(checkmate(sel2) == 2)
			cout << "Black won\n";
		return 0;
}
