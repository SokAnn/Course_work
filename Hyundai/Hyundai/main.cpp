#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>
#include<Windows.h>

#define FILEsalon "salon.txt"
#define FILEdealer "dealer.txt"
#define FILEmanufacture "manufacture.txt"

using namespace std;

//класс автомобиля с различными модификациями
class Car
{
	friend class Salon;	//салон имеет информацию о машине
	friend class House;	//дом имеет доступ к машинам

	string model;	//модель автомобиля
	int year;	//год выпуска
	string color;	//цвет
	float eng_cap;	//объем двигателя
	string transmis;	//тип КПП
	float eng_power;	//мощность двигателя
	int fuel_tank;	//топливный бак
	float fuel_cons;	//расход топлива
	string ov_dim;	//габариты д*ш*в
	bool heat_st_w;	//подогрев руля
	bool ABS;	//АБС
	bool EDS;	//ЕДС
	bool nav_syst;	//система навигации
	bool on_bor_comp;	//бортовой компьютер
	bool heat_seats;	//подогрев сидений
	bool roof_rack;	//багажник на крышу
	int airbags;	//количество подушек безопасности
public:
	Car() {};
	~Car() {};
};

Car* renew(Car** mas, int size, int size_new)
{
	//"ловим" исключение
	if ((size < 0) || (size_new < 0))  
		throw 1; 
	if (size == size_new) 
		return false; 
	int i = 0;
	Car* temp = new Car[size];
	for (i = 0; i < size; ++i) 
		temp[i] = (*mas)[i];
	delete[](*mas);
	if (size_new == 0) 
		return false;
	(*mas) = new Car[size_new];
	if (size > size_new)
		for (i = 0; i < size_new; ++i) 
			(*mas)[i] = temp[i];
	else
		for (i = 0; i < size; ++i) 
			(*mas)[i] = temp[i];
	return false;
}

//класс салона с адресом и названием
class Salon
{
	string name;
	string address;
	Car *car = NULL;
	int max = 0;
public:
	int get_max() { return max; }
	void show()
	{
		cout << "List cars:" << endl;
		for(int i = 0; i < max; ++i)
		{
			cout << i + 1 << "\)";
			cout << car[i].model << endl;
		}
	}
	bool read()
	{
		int count;
		ifstream file(FILEsalon);
		while (file)
		{
			renew(&car,count+1,count);
			getline(file, car[count].model);
		}
	}
};

//класс некоторого дома (помещения), в котором может находиться машина (или производиться)
class House
{
protected:
	int max;
	string address;
	Car* car = NULL;
	int *count;
	House* next;

	void buy()
	{}

public:
	virtual ~House()
	{
		if (next)
			delete next;
	}

	bool read(string File, Salon salon)
	{
		count = NULL;
		next = NULL;
		int c = salon.get_max();
		ifstream file(File);
		string str;
		count = new int(c);
		c = 0;

		while (file)
		{
			getline(file, str);
			if (!file)
				break;
			count[c++] = atoi(str.c_str());
		}
	}

	House* setnext(House* house)
	{
		next = house;
		return next;
	}

	/*void check(int)
	{}*/
};

//класс помещения, в котором уже находится готовая машина
class Dealer:public House
{
public:
	Dealer(string file, Salon salon) { read(file, salon); address = "Dealer"; }
};

//класс производства, на котором собираются машина (она мб уже готова, но не определена к дилеру)
class Manufactury :public House
{
public:
	Manufactury(string file, Salon salon) { read(file, salon); address = "Manufactury"; }
};

int main()
{
	int cymb;
	cout << "Hello word!" << endl;
	setlocale(LC_ALL, "rus");
	Sleep(1000);
	while (1)
	{
		system("cls");
		cout << "	1.Ввод данных о машине" << endl;
		cout << "	2.Просмотр" << endl;
		cout << "	3." << endl;
		cout << "	0.Выход" << endl;
		cin >> cymb;
		switch (cymb)
		{
		case '0':
			system("cls");
			printf("GOOD BYE!!!");
			Sleep(1000);
			exit(1);
			break;
		case '1':

			break;
		}
	}
	return 0;
}