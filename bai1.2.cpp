#include <iostream>
using namespace std;

class Complex{
public:
	Complex();
	~Complex();
	friend istream &operator >> (istream &input, Complex &tmp);
	friend ostream &operator << (ostream &output,const Complex &tmp);
	Complex operator + (const Complex &x);
	Complex operator = (const Complex &x);
private:
	float a, b;
};

Complex::Complex(){
	a = 0;
	b = 0;
}

Complex::~Complex(){
}

int main(){
	Complex *A, tong;
	int GH;
	cout << "Nhap gioi han: ";
	cin >> GH;
	A = new Complex[GH];
	for (int i = 0; i < GH; i++)
	{
		cout << "Nhap so phuc thu " << i + 1 << " : " << endl;
		cin >> A[i];
	}
	for (int j = 0; j < GH; j++)
	{
		cout << "So phuc thu " << j + 1 << " : ";
		cout << A[j] << endl;
	}

	for (int e = 0; e < GH; e++)
	{
		tong = tong + A[e];
	}
	cout << endl << "Tong cua cac so phuc la: ";
	cout << tong << ">>>";
	system("pause");
}

Complex Complex::operator = (const Complex &x){
	Complex Equal;
	this->a = x.a;
	this->b = x.b;
	Equal.a = this->a;
	Equal.b = this->b;
	return Equal;
}

Complex Complex::operator + (const Complex &x){
	Complex Add;
	Add.a = this->a + x.a;
	Add.b = this->b + x.b;

	return Add;
}

ostream &operator << (ostream &output, const Complex &tmp){
	if (tmp.a != 0)
	{
		if (tmp.b != 0)
		{
			if (tmp.b > 0)
			{
				output << tmp.a << "+" << tmp.b << "i";
			}
			else
			{
				output << tmp.a << tmp.b << "i";
			}
		}
		else
		{
			output << tmp.a;
		}
		
	}
	else
	{
		if (tmp.b != 0)
		{
			if (tmp.b > 0)
			{
				output << tmp.b << "i";
			}
			else
			{
				output << tmp.b << "i";
			}
		}
	}
	
	return output;
}

istream &operator >> (istream &input, Complex &tmp){
	cout << "Phan thuc: ";
	input >> tmp.a;
	cout << "Phan ao: ";
	input >> tmp.b;
	return input;
}
