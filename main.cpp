#include<iostream>
#include<Windows.h>
#include<fstream>

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

//����� ������ � �������� � ����������
class Salon
{
	string name;
	string address;
};

//����� ���������� ���� (���������), � ������� ����� ���������� ������ (��� �������������)
class House
{};

//����� ���������, � ������� ��� ��������� ������� ������
class Dealer
{};

//����� ������������, �� ������� ���������� ������ (��� �� ��� ������, �� �� ���������� � ������)
class Manufactury
{};

int main()
{}