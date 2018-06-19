#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>

#define FILEsalon "salon.txt"
#define FILEdealer "dealer.txt"
#define FILEmanufacture "manufacture.txt"

using namespace std;

//класс автомобиля с различными модификациями
class Car
{
	friend class Salon;	//салон имеет информацию о машине
	friend class House;	//дом имеет доступ к машинам
public:
	string model;	//модель автомобиля
	int year;	//год выпуска
	string color;	//цвет
	string eng_cap;	//объем двигателя
	string transmis;	//тип КПП
	string eng_power;	//мощность двигателя
	int fuel_tank;	//топливный бак
	string fuel_cons;	//расход топлива
	string ov_dim;	//габариты д*ш*в
	int heat_st_w;	//подогрев руля
	int ABS;	//АБС
	int EDS;	//ЕДС
	int nav_syst;	//система навигации
	int on_bor_comp;	//бортовой компьютер
	int heat_seats;	//подогрев сидений
	int roof_rack;	//багажник на крышу
	int airbags;	//количество подушек безопасности
//public:
	Car() {};
	~Car() {};
};

Car* renew(Car** mas, int size, int size_new)
{
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
public:
	string name;
	string address;
	Car *car = NULL;
	int max = 0;
//public:
	int get_max() { return max; }

	void show()
	{
		cout << "Список автомобилей:" << endl;
		for(int i = 0; i < max; ++i)
		{
			cout << i + 1 << "\)";
			cout << "Модель автомобиля:" << car[i].model << endl;
			cout << '	' << "Год выпуска:" << car[i].year << endl;
			cout << '	' << "Цвет:" << car[i].color << endl;
			cout << '	' << "Объем двигателя:" << car[i].eng_cap << endl;
			cout << '	' << "Тип КПП:" << car[i].transmis << endl;
			cout << '	' << "Мощность двигателя:" << car[i].eng_power << endl;
			cout << '	' << "Размер топливного бака:" << car[i].fuel_tank << endl;
			cout << '	' << "Расход топлива (на 100 км):" << car[i].fuel_cons << endl;
			cout << '	' << "Габариты (д*ш*в):" << car[i].ov_dim << endl;
			cout << '	' << "Подогрев руля (1-есть, 0-нет):" << car[i].heat_st_w << endl;
			cout << '	' << "ABS (1-есть, 0-нет):" << car[i].ABS << endl;
			cout << '	' << "EDS (1-есть, 0-нет):" << car[i].EDS << endl;
			cout << '	' << "Система навигации (1-есть, 0-нет):" << car[i].nav_syst << endl;
			cout << '	' << "Бортовой компьютер (1-есть, 0-нет):" << car[i].on_bor_comp << endl;
			cout << '	' << "Подогрев сидений (1-есть, 0-нет):" << car[i].heat_seats << endl;
			cout << '	' << "Багажник на крышу (1-есть, 0-нет):" << car[i].roof_rack << endl;
			cout << '	' << "Количество подушек безопасности:" << car[i].airbags << endl;
		}
	}

	bool read()
	{
		int count = 0;
		string str;
		ifstream file(FILEsalon);
		while (file)
		{
			renew(&car,count,count+1);
			getline(file, car[count].model);
			if (!file)
			{
				renew(&car, count + 1, count);
				break;
			}
			//getline(file, car[count].model);
			getline(file, str);
			car[count].year = atoi(str.c_str());
			getline(file, car[count].color);
			getline(file, car[count].eng_cap);
			getline(file, car[count].transmis);
			getline(file, car[count].eng_power);
			getline(file, str);
			car[count].fuel_tank = atoi(str.c_str());
			getline(file, car[count].fuel_cons);
			getline(file, car[count].ov_dim);
			getline(file, str);
			car[count].heat_st_w = atoi(str.c_str());
			getline(file, str);
			car[count].ABS = atoi(str.c_str());
			getline(file, str);
			car[count].EDS = atoi(str.c_str());
			getline(file, str);
			car[count].nav_syst = atoi(str.c_str());
			getline(file, str);
			car[count].on_bor_comp = atoi(str.c_str());
			getline(file, str);
			car[count].heat_seats = atoi(str.c_str());
			getline(file, str);
			car[count].roof_rack= atoi(str.c_str());
			getline(file, str);
			car[count].airbags= atoi(str.c_str());
			count++;
		}
		max = count;
		return 0;
	}
};

//класс некоторого дома (помещения), в котором может находиться машина (или производиться)
class House
{
protected:
	int max;
	string address;
	Car* car = NULL;
	int *number;
	House* next;

	void buy(const int ID)
	{
		char c;
		cout << "Адрес: " << address << endl;
		cout << "Хотите приобрести? (д-н)" << endl;
		cin >> c;
		if (c == 'Д' || c == 'д' || c == 'Н' || c == 'н')
			number[ID]--;
		return;
	}

public:
	virtual ~House()
	{
		if (next)
			delete next;
	}

	bool read(string File, Salon salon)
	{
		number = NULL;
		next = NULL;
		int c = salon.get_max();
		ifstream file(File);
		string str;
		number = new int(c);
		c = 0;

		while (file)
		{
			getline(file, str);
			if (!file)
				break;
			number[c++] = atoi(str.c_str());
		}
		return 0;
	}

	House* setnext(House* house)
	{
		next = house;
		return next;
	}

	void check(int ID)
	{
		if (number[ID] < 1)
		{
			if (next)
				next->check(ID);
			else
			{
				cout << "Не найдено" << endl;
				Sleep(3000);
			}
		}
		else
			buy(ID);
	}
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
	char cymb;
	int c;
	Car* car = NULL;

	Salon salon;
	House* house = new Dealer(FILEdealer, salon);
	house->setnext(new Manufactury(FILEmanufacture, salon));
	salon.read();

	setlocale(LC_ALL, "rus");
	cout << "Добро пожаловать в салон Hyundai!" << endl;
	Sleep(1000);
	while (1)
	{
		system("cls");
		cout << "	1.Вывод данных салона" << endl;
		cout << "	2.Поиск автомобиля" << endl;
		cout << "	0.Выход" << endl;
		cin >> cymb;
		switch (cymb)
		{
		case '0':
			//пора домой!
			system("cls");
			printf("GOOD BYE!!!");
			Sleep(3000);
			exit(1);
			break;
		case '1':
			//просмотр машинок
			system("cls");
			salon.read();
			salon.show();
			Sleep(3000);
			break;
		case '2':
			//выполнение запроса пользователя
			system("cls");
			salon.show();
			cout << endl << "Введите номер интересующей машины: ";
			cin >> c;
			if (c > salon.get_max())
			{
				system("cls");
				cout << "Автомобиля с таким номером в каталоге не существует" << endl;
				Sleep(2000);
				continue;
			}
			else
			{
				system("cls");
				house->check(c - 1);
			}
			break;
		}
	}
	return 0;
}