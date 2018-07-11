#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <stdarg.h>
#include <cstdlib>
#include <string>
#include <string.h>
#include <list>
#include <iterator>
#include <array>

using namespace std;

typedef unsigned short us;
typedef unsigned long long ull;

int x = 0;
int y = 0;

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
class Game
{
private:

	int dmg;


public:
	Game()
	{

	}
	void Set_map(int size)
	{
		for (auto it = str.begin(); it != str.end(); it++)
		{
			for (int i = 0; i != (*it).size(); i++)
			{
				int temp;
				temp = rand() % 2;
				if (temp == 1)
				{
					str.push_front("#");
				}
				else str.push_front(" ");

			}
		}
	}
	void Get_map()
	{
		for (auto it = str.begin(); it != str.end(); it++)
		{
			for (int i = 0; i != (*it).size(); i++)
			{
				HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
				if ((*it)[i] == '@')
				{
					SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				else if ((*it)[i] == '+')
				{
					SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				else if ((*it)[i] == '#')
				{
					SetConsoleTextAttribute(hwnd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				}
				str.front();
			}
		}
	}
};

class Tanchiki
{
private:
	int lvl;

	struct YourTank 
	{
		int dmg = 1;
		int your_hp = 3;
		string your_tank = "@";
		
	};
	struct EnemyTanks
	{
		int dmg = 1;
		string enemy_tank = "#";
		int enemy_hp;
		int tanks;
	};

	YourTank A;
	EnemyTanks B;

	bool End_game()
	{
		if(B.tanks <= 0)
		{
			cout << "Win" << endl;
			return true;
		}
		else if (A.your_hp <= 0)
		{
			cout << "GG" << endl;
 			return false;
		}
		else if()
	}

public:
	Tanchiki()
	{

	}
	void Set_lvl(int lvl)
	{
		this->lvl = lvl;
	}
	void GetLvl()
	{
		switch (lvl)
		{
		case 1:
		{
			B->enemy_tank = 2;
			B->enemy_hp = 2;
		}break;
		case 2:
		{
			B->enemy_hp = 5;
			B->tanks = 3;
		}break;
		case 3:
		{
			B->enemy_hp = 7;
			B->tanks = 4;
		}break;
		case 4:
		{
			B->enemy_hp = 10;
			B->tanks = 5;
		}break;
		}
	}
	void Move()
	{

		while (End_game != 0)
		{
			char q = _getch();
			system("cls");
			switch (q)
			{
			case 72:
				x--;
				if (x < 0) x = 0;
				break;
			case 80:
				x++;
				if (x >= row) x = row - 1;
				break;
			case 75:
				y--;
				if (y < 0) y = 0;
				break;
			case 77:
				y++;
				if (y >= col) y = col - 1;
				break;		
			case 32: //Space 
				

			}
		
		}
	}


};


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	setlocale(LC_ALL, "rus");
	Tanchiki Game;
	int lvl;
Restart:
	cout << "\t\t Its tanks from Dendy to Pc " << endl;
	cout << "Enter lvl of hard: " << endl;
	cout << "Enter 1 to chose ez lvl" << endl;
	cout << "Enter 2 to chose midl lvl " << endl;
	cout << "Enter 3 to chose hard lvl " << endl;
	cout << "Enter 4 to chose very hard lvl" << endl;
	cin >> lvl;
	if (lvl >= 1 && lvl <= 4)
	{
		Game.Set_lvl(lvl);
	}
	else
	{
		cout << "Eror input " << endl;
		goto Restart;
	}






	_gettch();
	return 0;

}