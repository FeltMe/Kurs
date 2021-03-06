#include "stdafx.h"

int x = 0;
int y = 0;

class Game
{
private:

	int dmg;
	vector <vector <string>> map;
	const int size = 25;
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
		string enemy_tank = "*";
		int enemy_hp;
		int tanks;
	};

	YourTank A;
	EnemyTanks B;

	bool End_game()
	{
		if (B.tanks <= 0)
		{
			system("cls");
			cout << "\t\tWin" << endl;
			return true;
		}
		else if (A.your_hp <= 0)
		{
			system("csl");
			cout << "\t\tGG" << endl;
			return false;
		}
		return false;
	}
	void GoToXY(int column, int line)
	{

		COORD coord;
		coord.X = column;
		coord.Y = line;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (!SetConsoleCursorPosition(hConsole, coord))
		{

		}
	}

public:
	Game()
	{

	}
	void Set_map(int size)
	{

		for (int i(0); i < size; i++)
		{
			vector <string> vec;
			for (int j(0); j < size; j++)
			{
				int temp;
				temp = rand() % 6;
				if (temp == 2)
				{
					vec.push_back("#");
				}
				else vec.push_back("-");
			}
			map.push_back(vec);
		}
	}
	void Get_map()
	{
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD m_currentConsoleAttr;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		if (GetConsoleScreenBufferInfo(hwnd, &csbi))
		{
			m_currentConsoleAttr = csbi.wAttributes;
		}

		for (int i(0); i < map.size(); i++)
		{
			for (int j(0); j < map.size(); j++)
			{
				if (map[i][j] == string("@"))
				{
					SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				else if (map[i][j] == string("*"))
				{
					SetConsoleTextAttribute(hwnd, FOREGROUND_RED | FOREGROUND_INTENSITY);
				}
				else if (map[i][j] == string("#"))
				{
					SetConsoleTextAttribute(hwnd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				}
				cout << map[i][j] << setw(2);
				SetConsoleTextAttribute(hwnd, m_currentConsoleAttr);
			}
			cout << endl;

		}
	}
	void Spawn_your_tank()
	{
		map[0][0] = A.your_tank;
	}
	void Set_lvl(int lvl)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		int temp_x;
		int temp_y;
		int temp_move;
		this->lvl = lvl;
		switch (lvl)
		{
		case 1:
		{
			B.tanks = 2;
			B.enemy_hp = 2;
			for (us i(0); i < B.tanks; i++)
			{
				temp_x = rand() % 10 + 1;
				temp_y = rand() % 10 + 1;
				if (map[temp_x][temp_y] == string("*"))
				{
					--i;
				}
				map[temp_x][temp_y] = string("*");
			}

		}break;
		case 2:
		{
			B.enemy_hp = 5;
			B.tanks = 3;
			for (us i(0); i < B.tanks; i++)
			{
				temp_x = rand() % 10 + 1;
				temp_y = rand() % 10 + 1;
				if (map[temp_x][temp_y] == string("*"))
				{
					--i;
				}
				map[temp_x][temp_y] = string("*");
			}

		}break;
		case 3:
		{
			B.enemy_hp = 7;
			B.tanks = 4;
			for (us i(0); i < B.tanks; i++)
			{
				temp_x = rand() % 10 + 1;
				temp_y = rand() % 10 + 1;
				if (map[temp_x][temp_y] == string("*"))
				{
					--i;
				}
				map[temp_x][temp_y] = string("*");
			}

		}break;
		case 4:
		{
			B.enemy_hp = 10;
			B.tanks = 5;
			for (us i(0); i < B.tanks; i++)
			{
				temp_x = rand() % 10 + 1;
				temp_y = rand() % 10 + 1;
				if (map[temp_x][temp_y] == string("*"))
				{
					--i;
				}
				map[temp_x][temp_y] = string("*");
			}

		}break;
		}
	}
	void Move()
	{

		while (End_game() != true)
		{
			char q = _getch();
			system("cls");
			switch (q)
			{
			case 72:
			{
				x--;
				if (x < 0) x = 0;
				GoToXY(x, y);

			}break;
			case 80:
			{
				x++;
				if (x >= size) x = size - 1;
				GoToXY(x, y);

			}break;
			case 75:
			{
				y--;
				if (y < 0) y = 0;
				GoToXY(x, y);

			}break;
			case 77:
			{
				y++;
				if (y >= size) y = size - 1;
				GoToXY(x, y);

			}break;
			}

		}
	}
};


int main()
{


	srand(static_cast<unsigned int>(time(NULL)));
	setlocale(LC_ALL, "rus");
	system("mode con cols=53 lines=25");
	Game G;
	int lvl;
	const int size = 25;
Restart:
	cout << "\t\t Its tanks from Dendy to Pc " << endl;
	cout << "Enter lvl of hard: " << endl;
	cout << "Enter 1 to chose ez lvl" << endl;
	cout << "Enter 2 to chose midl lvl " << endl;
	cout << "Enter 3 to  hard lvl " << endl;
	cout << "Enter 4 to chose very hard lvl" << endl;
	cin >> lvl;
	if (lvl >= 1 && lvl <= 4)
	{
		G.Set_lvl(lvl);
	}
	else
	{
		cout << "Eror input " << endl;
		goto Restart;
	}
	G.Set_lvl(lvl);
	G.Set_map(size);
	G.Get_map();
	G.Spawn_your_tank();
	G.Move();
	


		
	_gettch();
	return 0;

}