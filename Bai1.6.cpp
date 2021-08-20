#include <iostream>
using namespace std;

class Phanso{
public:
	Phanso();
	Phanso(int, int);
	~Phanso();
	friend istream &operator >> (istream &input, Phanso &tmp);
	friend ostream &operator << (ostream &output, const Phanso &tmp);
	friend void Rutgon(Phanso &tmp);
	bool operator > (Phanso &tmp);
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

Phanso::~Phanso(){
}

void NhapSL(int *SL){
	cout << "Nhap so luong: ";
	cin >> *SL;
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

	// Sap xep tang dan
	Phanso hoandoi;
	for (int z = 0; z < SL; z++)
	{
		for (int c = z + 1; c < SL; c++)
		{
			if (A[z] > A[c] == true)
			{
				hoandoi = A[z];
				A[z] = A[c];
				A[c] = hoandoi;
			}

		}
	}
	cout << "Phan so tang dan la: ";
	for (int  b = 0; b < SL; b++)
	{
		cout << A[b] << ", ";
	}

	system("pause");
	return 0;
}

bool Phanso::operator > (Phanso &tmp){
	Phanso kq;
	if (this->tu*tmp.mau > tmp.tu*this->mau)
	{
		return true;
	}
	else
	{
		return false;
	}

	
}


void Rutgon (Phanso &tmp){
	Phanso kq, dem, tmp1;
	tmp1 = tmp;
	if (abs(tmp1.tu)> abs(tmp1.mau))
	{
		dem.mau = tmp1.tu;
		tmp1.tu = tmp1.mau;
		tmp1.mau = dem.mau;
	}
	for (int i = 1; i <= tmp1.tu; i++)
	{
		if (tmp.tu % i == 0 && tmp.mau % i == 0)
		{
			dem.tu = i;
		}
	}
	kq.tu = tmp.tu / dem.tu;
	kq.mau = tmp.mau / dem.tu;
	tmp = kq;
}
