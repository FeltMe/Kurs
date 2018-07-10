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

using namespace std;

typedef unsigned short us;
typedef unsigned long long ull;

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
	list <string> str = {"#", "@", "#", "+"};
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

class Tanchiki_na_8_bitke
{
private:
	int dmg = 1; // урон танка = 1 (буду змінювати лише здоровя)
	int your_hp;
	string your_tank = "@@--";

	int size;
	int enemy_hp;
	string enemy_tank = "++-";

	int lvl;

public:
	Tanchiki_na_8_bitke()
	{

	}
	void Set_your_tank(int hp)
	{
		this->your_hp = hp;
	}
	void Set_enemy_tank( int hp, int lvl_of_hard)
	{
		this->enemy_hp = hp;
		this->lvl = lvl_of_hard;
	}
	

};


int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	setlocale(LC_ALL, "rus");
	Game Sm;
	int menu;
	Restart:
	cout << "\t\t Its tanks from Dendy to Pc " << endl;
	cout << "Enter lvl of hard: " << endl;
	cout << "Enter 1 to chose ez lvl" << endl;
	cout << "Enter 2 to chose midl lvl " << endl;
	cout << "Enter 3 to chose hard lvl " << endl;
	cout << "Enter 4 to chose very hard lvl" << endl;
	cin >> menu;
	if (menu >= 1 && menu <= 4)
	{
		int dmg = 1; // урон
		int your_hp = 3; // Здоров"я
		int enemy_hp; // Здоров"я вражин
		switch (menu)
		{
		case 1:
		{
			enemy_hp = 2;

		
		}
		case 2:
		{
			enemy_hp = 4;

		}
		case 3:
		{
			enemy_hp = 6;

		}
		case 4:
		{
			enemy_hp = 10;

		}
		}
	}
	else
	{
		cout << "Eror input " << endl;
		goto Restart;
	}
	cout << "Enter size = ";
	int size;
	cin >> size;
	Sm.Set_map(size);
	Sm.Get_map();





	_gettch();
	return 0;

}