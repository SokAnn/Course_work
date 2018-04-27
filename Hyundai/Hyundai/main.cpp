#include<iostream>
#include<Windows.h>
#include<fstream>

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

//класс салона с адресами и названиями
class Salon
{
	string name;
	string address;
};

//класс некоторого дома (помещения), в котором может находиться машина (или производиться)
class House
{};

//класс помещения, в котором уже находится готовая машина
class Dealer
{};

//класс производства, на котором собираются машина (она мб уже готова, но не определена к дилеру)
class Manufactury
{};

int main()
{}