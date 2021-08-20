#include <iostream>
using namespace std;

class Complex{
public:
	Complex();
	~Complex();
	friend Complex operator + (const Complex &x, const Complex &y);
	friend Complex operator - (const Complex &x, const Complex &y);
	friend ostream &operator << (ostream &output, const Complex &tmp);
	friend istream &operator >> (istream &input, Complex &tmp);
private:
	float a;
	float b;
};

void Nhap_Xuat(Complex &x, Complex &y){
	Complex tmp;

	cout << "Nhap phan so thu nhat: " << endl;
	cin >> x;
	cout << "Nhap phan so thu hai:" << endl;
	cin >> y;

	cout << "Phan so thu nhat la:";
	cout << x;
	cout << "Phan so thu hai la: ";
	cout << y;

	cout << "Tong hai so phuc la: ";
	tmp = x + y;
	cout << tmp;

	cout << "Hieu hai so phuc la: ";
	cout << (x - y);

}

int main(){
	Complex x, y;

	Nhap_Xuat(x, y);

	system("pause");
		return 0;
}

Complex operator - (const Complex &x, const Complex &y){
	Complex tmp;
	tmp.a = x.a - y.a;
	tmp.b = x.a - y.b;

	return tmp;
}

Complex operator + (const Complex &x, const Complex &y){
	Complex tmp;
	tmp.a = x.a + y.a;
	tmp.b = x.b + y.b;

	return tmp;
}

istream &operator >> (istream &input, Complex &tmp){
	cout << "Nhap phan thuc: ";
	input >> tmp.a;
	cout << "Nhap phan ao:";
	input >> tmp.b;
	return input;
}

ostream &operator << (ostream &output, const Complex &tmp){
	if (tmp.a != 0)
	{
		if (tmp.b > 0)
		{
			output << tmp.a << "+" << tmp.b << "i" << endl;
		}
		else if (tmp.b < 0)
		{
			output<< tmp.a << tmp.b << "i" << endl;
		}
		else if (tmp.b == 0)
		{
			output << tmp.a << endl;
		}
	}
	else if (tmp.a == 0)
	{
		if (tmp.b > 0)
		{
			output << tmp.b << "i" << endl;
		}
		else if (tmp.b < 0)
		{
			output << tmp.b << "i" << endl;
		}

	}
	return output;
}

Complex::Complex(){
}

Complex::~Complex(){
}
