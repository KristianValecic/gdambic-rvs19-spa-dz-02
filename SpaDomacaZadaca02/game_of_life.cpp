#include"game_of_life.h"
#include <SFML/Graphics.hpp>
#include<ctime>

bool game_of_life::slucajna_vrijednost()
{
	int provjera = rand() % (10); 
	if (provjera > 0)
	{
		return 0;
	}
	else {
		return 1;
	}
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return _sljedeca_generacija[i][j];
}

game_of_life::game_of_life() {
	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
			_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}
}
void game_of_life::sljedeca_generacija() {

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int susjedi = celija_zauzeta(i - 1, j - 1) + celija_zauzeta(i - 1, j) + celija_zauzeta(i - 1, j + 1) +
				celija_zauzeta(i, j - 1) + celija_zauzeta(i, j + 1) +
				celija_zauzeta(i + 1, j - 1) + celija_zauzeta(i + 1, j) + celija_zauzeta(i + 1, j + 1);

			if (celija_zauzeta(i, j))
			{
				_sljedeca_generacija[i][j] = susjedi == 2 || susjedi == 3;
			}
			else if (susjedi < 2 || susjedi > 3)
			{
				_sljedeca_generacija[i][j] = 0;
			}
			else {
				_sljedeca_generacija[i][j] = susjedi == 3;
			}
		}
	}
}

void game_of_life::iscrtaj() {
	system("cls");
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_sljedeca_generacija[i][j])
			{
				cout << "*";
			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}

}