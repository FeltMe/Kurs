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
	list <string> str;
	int dmg;

	void SetColors()
	{
		for (auto it = str.begin(); it != str.end(); it++)
		{
			for (int i = 0; i <= (*it).size(); i++)
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
			}
		}
	}
public:
	Game()
	{

	}

};
class Tanks : public Game
{
private:
	int dmg;
	int hp;
	string tank;
public:
	Tanks()
	{

	}
	virtual void Set_tank(int dmg, int hp, string tank) = 0;

};
class YourTank : public Tanks
{
private:
	int dmg;
	int hp;
	string tank;
public:
	void Set_tank(int dmg, int hp, string tank)
	{
		this->dmg = dmg;
		this->hp = hp;
		this->tank = tank;
	}
};
class EnemyTank : public Tanks
{
private :
	int dmg;
	int hp;
	string tank;
public:
	void Set_tank(int dmg, int hp, string tank)
	{
		this->dmg = dmg;
		this->hp = hp;
		this->tank = tank;
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
		int dmg;
		int hp;
		string tank;
		switch (menu)
		{
		case 1:
		{
		
		}
		}
	}
	else
	{
		cout << "Eror input " << endl;
		goto Restart;
	}






	_gettch();
	return 0;

}