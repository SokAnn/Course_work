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
public:
	string model;	//������ ����������
	int year;	//��� �������
	string color;	//����
	string eng_cap;	//����� ���������
	string transmis;	//��� ���
	string eng_power;	//�������� ���������
	int fuel_tank;	//��������� ���
	string fuel_cons;	//������ �������
	string ov_dim;	//�������� �*�*�
	int heat_st_w;	//�������� ����
	int ABS;	//���
	int EDS;	//���
	int nav_syst;	//������� ���������
	int on_bor_comp;	//�������� ���������
	int heat_seats;	//�������� �������
	int roof_rack;	//�������� �� �����
	int airbags;	//���������� ������� ������������
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

//����� ������ � ������� � ���������
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
		cout << "������ �����������:" << endl;
		for(int i = 0; i < max; ++i)
		{
			cout << i + 1 << "\)";
			cout << "������ ����������:" << car[i].model << endl;
			cout << '	' << "��� �������:" << car[i].year << endl;
			cout << '	' << "����:" << car[i].color << endl;
			cout << '	' << "����� ���������:" << car[i].eng_cap << endl;
			cout << '	' << "��� ���:" << car[i].transmis << endl;
			cout << '	' << "�������� ���������:" << car[i].eng_power << endl;
			cout << '	' << "������ ���������� ����:" << car[i].fuel_tank << endl;
			cout << '	' << "������ ������� (�� 100 ��):" << car[i].fuel_cons << endl;
			cout << '	' << "�������� (�*�*�):" << car[i].ov_dim << endl;
			cout << '	' << "�������� ���� (1-����, 0-���):" << car[i].heat_st_w << endl;
			cout << '	' << "ABS (1-����, 0-���):" << car[i].ABS << endl;
			cout << '	' << "EDS (1-����, 0-���):" << car[i].EDS << endl;
			cout << '	' << "������� ��������� (1-����, 0-���):" << car[i].nav_syst << endl;
			cout << '	' << "�������� ��������� (1-����, 0-���):" << car[i].on_bor_comp << endl;
			cout << '	' << "�������� ������� (1-����, 0-���):" << car[i].heat_seats << endl;
			cout << '	' << "�������� �� ����� (1-����, 0-���):" << car[i].roof_rack << endl;
			cout << '	' << "���������� ������� ������������:" << car[i].airbags << endl;
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

//����� ���������� ���� (���������), � ������� ����� ���������� ������ (��� �������������)
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
		cout << "�����: " << address << endl;
		cout << "������ ����������? (�-�)" << endl;
		cin >> c;
		if (c == '�' || c == '�' || c == '�' || c == '�')
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
				cout << "�� �������" << endl;
				Sleep(3000);
			}
		}
		else
			buy(ID);
	}
};

//����� ���������, � ������� ��� ��������� ������� ������
class Dealer:public House
{
public:
	Dealer(string file, Salon salon) { read(file, salon); address = "Dealer"; }
};

//����� ������������, �� ������� ���������� ������ (��� �� ��� ������, �� �� ���������� � ������)
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
	cout << "����� ���������� � ����� Hyundai!" << endl;
	Sleep(1000);
	while (1)
	{
		system("cls");
		cout << "	1.����� ������ ������" << endl;
		cout << "	2.����� ����������" << endl;
		cout << "	0.�����" << endl;
		cin >> cymb;
		switch (cymb)
		{
		case '0':
			//���� �����!
			system("cls");
			printf("GOOD BYE!!!");
			Sleep(3000);
			exit(1);
			break;
		case '1':
			//�������� �������
			system("cls");
			salon.read();
			salon.show();
			Sleep(3000);
			break;
		case '2':
			//���������� ������� ������������
			system("cls");
			salon.show();
			cout << endl << "������� ����� ������������ ������: ";
			cin >> c;
			if (c > salon.get_max())
			{
				system("cls");
				cout << "���������� � ����� ������� � �������� �� ����������" << endl;
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