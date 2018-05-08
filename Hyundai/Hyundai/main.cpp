#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string>

#define FILEsalon "salon.txt"
#define FILEdealer "dealer.txt"
#define FILEmanufacture "manufacture.txt"

using namespace std;

//����� ���������� � ���������� �������������
class Car
{
	friend class Salon;	//����� ����� ���������� � ������
	friend class House;	//��� ����� ������ � �������

	string model;	//������ ����������
	int year;	//��� �������
	string color;	//����
	float eng_cap;	//����� ���������
	string transmis;	//��� ���
	float eng_power;	//�������� ���������
	int fuel_tank;	//��������� ���
	float fuel_cons;	//������ �������
	string ov_dim;	//�������� �*�*�
	bool heat_st_w;	//�������� ����
	bool ABS;	//���
	bool EDS;	//���
	bool nav_syst;	//������� ���������
	bool on_bor_comp;	//�������� ���������
	bool heat_seats;	//�������� �������
	bool roof_rack;	//�������� �� �����
	int airbags;	//���������� ������� ������������
public:
	Car() {};
	~Car() {};
};

Car* renew(Car** mas, int size, int size_new)
{
	//"�����" ����������
	if ((size < 0) || (size_new < 0)) { throw 1; }
	if (size == size_new) { return false; }
	int i = 0;
	Car* temp = new Car[size];
	for (i = 0; i < size; ++i) { temp[i] = (*mas)[i]; }
	delete[](*mas);
	if (size_new == 0) { return false; }
	(*mas) = new Car[size_new];
	if (size > size_new)
	{
		for (i = 0; i < size_new; ++i) { (*mas)[i] = temp[i]; }
	}
	else
	{
		for (i = 0; i < size; ++i) { (*mas)[i] = temp[i]; }
	}
	return false;
}

//����� ������ � �������� � ����������
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
			cout << i + 1 << '\)';
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

//����� ���������� ���� (���������), � ������� ����� ���������� ������ (��� �������������)
class House
{
protected:
	int max;
	string address;
	Car* car = NULL;
	House* next;
};

//����� ���������, � ������� ��� ��������� ������� ������
class Dealer
{};

//����� ������������, �� ������� ���������� ������ (��� �� ��� ������, �� �� ���������� � ������)
class Manufactury
{};

int main()
{}