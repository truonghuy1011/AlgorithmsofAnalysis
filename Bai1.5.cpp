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
	Phanso operator + (const Phanso &tmp);
	Phanso operator - (const Phanso &tmp);
	Phanso operator * (const Phanso &tmp);
	Phanso operator / (const Phanso &tmp);
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
	// tinh tong cac phan so
	for (int  e = 0; e < SL; e++)
	{
		tong = tong + A[e];
	}
	Rutgon(tong);
	cout << tong << endl;
	//tinh hieu cac phan so
	hieu = A[0];
	for (int e = 1; e < SL; e++)
	{
		hieu = hieu - A[e];
	}
	//Rutgon(hieu);
	cout << hieu << endl;
	//tinh tich cac phan so
	tich = A[0];
	for (int e = 1; e < SL; e++)
	{
		tich = tich * A[e];
	}
	Rutgon(tich);
	cout << tich << endl;
	// thuong tich cac phan so
		thuong = A[0];
	for (int e = 1; e < SL; e++)
	{
		thuong = thuong / A[e];
	}
	Rutgon(thuong);
	cout << thuong << endl;
	system("pause");
	return 0;
}

Phanso Phanso::operator + (const Phanso &tmp){
	Phanso kq;
	kq.tu = this->tu*tmp.mau + this->mau*tmp.tu;
	kq.mau = this->mau*tmp.mau;
	return kq;
}

Phanso Phanso::operator - (const Phanso &tmp){
	Phanso kq;
	kq.tu = this->tu*tmp.mau - this->mau*tmp.tu;
	kq.mau = this->mau*tmp.mau;
	//cout << "KQ:" << kq << endl;
	return kq;
}

Phanso Phanso::operator * (const Phanso &tmp){
	Phanso kq;
	kq.tu = this->tu*tmp.tu;
	kq.mau = this->mau*tmp.mau;
	//cout << "KQ:" << kq << endl;
	return kq;
}

Phanso Phanso::operator / (const Phanso &tmp){
	Phanso kq;
	kq.tu = this->tu*tmp.mau;
	kq.mau = this->mau*tmp.tu;
	//cout << "KQ:" << kq << endl;
	return kq;
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
