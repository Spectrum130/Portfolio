#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <time.h>
#include "AnimText_V1.h"
using namespace std;

int Random(int min, int max)
{
	return (min + rand() % (max - min + 1));
}
short Random(short min, short max)
{
	return (min + rand() % (max - min + 1));
}

class IMenu
{
public:
	virtual void ShowMenu() = 0;

protected:
	virtual void Input() = 0;
}; 


class Player
{
public:
	Player()
		:_maxHealth(100),
		_health(100),
		_damage(10),
		_level(1)
	{

	}

	short getHealth()
	{
		return _health;
	}
	short getMaxHealth()
	{
		return _maxHealth;
	}
	short getDamage()
	{
		return _damage;
	}
	short getLevel()
	{
		return _level;
	}

	void LevelUp()
	{
		_maxHealth += 10;
		_health = _maxHealth;
		_damage += 10;
		_level++;
	}

private:
	short _health;
	short _maxHealth;
	short _damage;
	short _level;


protected:
	void PlayerStatisticsMenu()
	{
		AnimText out = AnimText(15);
		for (;;)
		{
			system("cls");
			out.Print("----------------------\n");
			out.Print("\tМаксимальное здоровье: "); out.Print(to_string(_health));
			out.Print("\n\tУрон: "); out.Print(to_string(_damage));
			out.Print("\n\tУровень:"); out.Print(to_string(_level));
			out.Print("\n----------------------\n");
			out.Print("1) Выход\n");
			out.Print("----------------------\n");
			out.Print("Выбор: ");
			char input;
			input = _getch();
			if (input == 49)
			{
				return;
			}
			out.SetDelay(0);
		}
	}
};


class MainMenu : public IMenu, private Player
{
public:

	void ShowMenu() override
	{
		AnimText out = AnimText(15);
		for (;;) {
			system("cls");
			out.Print("----------------------\n");
			out.Print("\t1) В поход!\n");
			out.Print("\t2) Персонаж\n");
			out.Print("\t3) Настройки\n");
			out.Print("\t4) Выход\n");
			out.Print("----------------------\n");
			out.Print("Выбор: ");
			Input();
		}
	}

private:

	void Input() override
	{
		short input;
		for (;;) {
			input = _getch();
			switch (input)
			{
			case 49:
				expedition.ShowMenu();
				return;
				break;
			case 50:
				PlayerStatisticsMenu();
				return;
				break;
			case 51:
				Settings();
				return;
				break;
			case 52:
				ConfirmExit();
				return;
				break;
			default:
				break;
			}
		}
	}


	class Expedition : public IMenu
	{
	public:
		Expedition()
		{
			location = Locations::BigHouse;
		}

		void ShowMenu() override
		{
			system("cls");
			AnimText out = AnimText(33);
			out.Print("Путник собрал силы и отправился в путь...\n");
			
#ifndef DEBUG
			Sleep(3000);
#endif // !DEBUG

			out.Print("Он решил, что будет хорошей идеей ");
			out.Print(RandomiseLocation());

#ifndef DEBUG
			Sleep(5000);
#endif // DEBUG
			
			system("cls");

			PrintStatistics(true);

			out.SetDelay(33);
			out.Print("Прийдя на место, путник видит перед собой "); 
			out.Print(EnterLocation());

#ifndef DEBUG
			Sleep(5000);
#endif // !DEBUG

			Input();
			
		}

	private:

		void Input() override
		{
			AnimText out = AnimText(15);
			for (;;) {
				system("cls");
				PrintStatistics(false);
				out.Print("\t1) Уйти обратно\n");
				out.Print("\t2) Осмотреться\n");
				out.Print("\t3) Пойти лутаться\n");
				out.Print("\t4) Ворваться с атакой\n\n");
				out.Print("------------------------------------\n");
				out.Print("Путник решает: ");

				short input;
				input = _getch();

				switch (input)
				{
				case 49:
					return;
					break;
				case 50:
					LookAround();
					break;
				default:
					break;
				}
				out.SetDelay(0);

			}

			system("pause");
		}

		void LookAround()
		{
			short randResult = Random(1, 3);
			string message;
			switch (randResult)
			{
			case 1:
				message = "Путник обошел комнату и, возможно, к счастью, или, к сожалению, \nникого живого не нашел\n";
			case 2:
				break;
			default:
				break;
			}
		}

		void PrintStatistics(bool ShowAnim)
		{
			AnimText out;
			if (!ShowAnim) {
				out.SetDelay(0);
			}
			else {
				out.SetDelay(15);
			}
			out.Print("------------------------------------\n");
			out.Print("|=======|\n");
			out.Print("Здоровье: ");
			out.Print(to_string(Gamer.getHealth()));

			out.Print("\nМакс здоровье: ");
			out.Print(to_string(Gamer.getDamage()));

			out.Print("\nУрон: ");
			out.Print(to_string(Gamer.getDamage()));
			out.Print("\n|=======|\n");
			out.Print("------------------------------------\n\n");
		}

		string EnterLocation()
		{
			switch (location)
			{
			case Locations::BigHouse:
				return "большую чистую комнату, набитой хламом и мебелью так, \nчто не видно конца комнаты. На стенах висят факелы, на \nполках стоят свечи, которые помогают видеть происходящее в комнате.\n";
				break;
			case Locations::SmallHouse:
				return "грязный зал, с слегка прогнившими стенами. Видимо, эту \nкомнату используют, как хранилище всякого хлама.\n";
				break;
			case Locations::BigStreet:
				return "большую длинную улицу, на которой стоят много тканевых \nшатров, возле домов растут деревья и кусты.\n";
				break;
			case Locations::SmallStreet:
				return "совсем маленькую улочку, на которой есть несколько \nповоротов, ящиков и сундуков.\n";
				break;
			case Locations::BigHill:
				return "огромные холмы, которые загораживают горизонт. На них \nрастет множество деревьев, травы, кустов и всякой другой зелени. \nОднако в этой зелени путник замечает маленькую хижину.\n";
				break;
			case Locations::SmallHill:
				return "небольшую неровность в местности, заросшую травой и \nкустарниками. Здесь, видимо, обитают мелкие звери. \nЗа одним холмиком проглядывается палатка.\n";
				break;
			case Locations::Plain:
				return "самую обыкновенную равнину с невысокой травой, изредка \nрастущими деревьями и каким-то забором.\n";
				break;
			}
		}

		enum class Locations{
			BigHouse, SmallHouse, BigStreet, SmallStreet, BigHill, SmallHill, Plain
		};

		string RandomiseLocation()
		{
			short randResult = Random(0, 6);

			switch (randResult)
			{
			case 0:
				location = Locations::BigHouse;
				return "сгонять в большое здание.";
			case 1:
				location = Locations::SmallHouse;
				return "зайти в маленький домик.";
			case 2:
				location = Locations::BigStreet;
				return "выйти на улицу и поискать полезности.";
			case 3:
				location = Locations::SmallStreet;
				return "заглянуть в закоулок деревни.";
			case 4:
				location = Locations::BigHill;
				return "отправится покорять холмы.";
			case 5:
				location = Locations::SmallHill;
				return "поискать что-нибудь на природе.";
			case 6:
				location = Locations::Plain;
				return "прогуляться по равнине.";
			default:
				location = Locations::BigHouse;
				return "сгонять в большое здание.";
			}
		}

		Locations location;
		Player Gamer;

	};

	Expedition expedition;


	void Settings()
	{
		AnimText out = AnimText(15);
		
		for (;;) {
			system("cls");
			out.Print("----------------------\n");
			out.Print("\t1) Назад\n");
			out.Print("\t2) Ситхи\n");
			out.Print("\t3) Джедаи\n");
			out.Print("----------------------\n");
			out.Print("Выбор: ");
			out.SetDelay(0);
			short input;
			input = _getch();
			switch (input)
			{
			case 49:
				return;
				break;
			case 50:
				system("color 07");
				break;
			case 51:
				system("color F0");
				break;
			default:
				break;
			}
		}
	}

	void ConfirmExit()
	{
		AnimText out = AnimText(15);
		for (;;) {
			system("cls");
			out.Print("Действительно ли хотите выйти?\n");
			out.Print("----------------------\n");
			out.Print("\t1) Нет\n");
			out.Print("\t2) Да\n");
			out.Print("----------------------\n");
			out.Print("Выбор: ");

			short input;
			for (;;) {
				input = _getch();
				switch (input)
				{
				case 49:
					return;
					break;
				case 50:
					exit(0);
				default:
					break;
				}
			}
		}
	}

};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	system("mode con cols=120 lines=30");
	system("title DnD Alpha");

	MainMenu Mainmenu;
	Mainmenu.ShowMenu();


}