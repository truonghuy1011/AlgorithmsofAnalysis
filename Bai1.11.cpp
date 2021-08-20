#include <iostream>
#include <Windows.h>
using namespace std;

class Phanso{
public:
	Phanso();
	Phanso(int, int);
	Phanso(const Phanso &tmp);
	~Phanso();
	friend istream &operator >> (istream &input, Phanso &tmp);
	friend ostream &operator << (ostream &output, const Phanso &tmp);
	friend void Rutgon(Phanso &tmp);
	friend int UCLN(Phanso &tmp);
private:
	int tu, mau;
};

Phanso::Phanso(){
	tu = 0;
	mau = 1;
}

Phanso::Phanso(int x, int y){
	tu = x;
	mau = y;
}

Phanso::Phanso(const Phanso &tmp){
	this->tu = tmp.tu;
	this->mau = tmp.mau;
}

Phanso::~Phanso(){
}

void NhapSL(int *SL){
	do
	{
		cout << "Nhap so luong: ";
		cin >> *SL;
		if (*SL <= 0)
		{system("cls");
			cout << "Phai lon hon 0 va la so nguyen!! " << endl;
		}
	} while (*SL <= 0);
}

istream &operator >> (istream &input, Phanso &tmp){
	do {

		cout << "Tu so: ";
		input >> tmp.tu;
		cout << "Mau so: ";
		input >> tmp.mau;
		if (tmp.mau == 0)
		{
			cout << "Phan mau so phai khac 0" << endl;
		}

	} while (tmp.mau == 0);


	return input;
}

ostream &operator << (ostream &output, const Phanso &tmp){
	output << tmp.tu << "/" << tmp.mau;
	return output;
}

int main(){
	int SL;
	Phanso *A, tong, hieu, tich, thuong;
	NhapSL(&SL);
	A = new Phanso[SL];

	for (int i = 0; i < SL; i++)
	{
		cout << "Nhap phan so thu " << i + 1 << " : " << endl;
		cin >> A[i];
		Rutgon(A[i]);
	}

	for (int j = 0; j < SL; j++)
	{
		cout << "Phan so thu " << j + 1 << " : ";
		cout << A[j];
		cout << endl;
	}
	
	
	system("pause");
	return 0;
}

int UCLN(Phanso &tmp){
	int dem = 0;
	for (int  i = 1; i <= tmp.tu; i++)
	{
		if (tmp.tu % i == 0 && tmp.mau % i == 0)
		{
			dem = i;
		}
	}
	return dem;
}

void Rutgon(Phanso &tmp){
	Phanso kq, dem, tmp1(tmp);
	

	if (abs(tmp1.tu)> abs(tmp1.mau))
	{
		dem.mau = tmp1.tu;
		tmp1.tu = tmp1.mau;
		tmp1.mau = dem.mau;
	}

	kq.tu = tmp.tu / UCLN(tmp1);
	kq.mau = tmp.mau / UCLN(tmp1);
	tmp = kq;
}
