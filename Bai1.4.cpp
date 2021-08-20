#include <iostream>
using namespace std;

class Vector{
public:
	Vector(const Vector &vt);
	Vector(int a);
	Vector();
	~Vector();
	friend istream &operator >> (istream &input, Vector &tmp);
	friend ostream &operator << (ostream &output, const Vector &tmp);
	Vector operator = (const Vector &tmp);
	friend Vector operator + (const Vector &tmp1, const Vector &tmp2);
private:
	int n;
	float *v;
};

Vector::Vector(){

}

Vector::Vector(const Vector &vt){		//ham tao sao chep
	this->n = vt.n;
	this->v = new float[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->v[i] = vt.v[i];
	}
	
}

Vector::Vector(int a){	//ham tao mot toan tu
	this->n = a;
	this->v = new float[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->v[i] = 0;
	}
}

Vector::~Vector(){		//ham huy
}

void Nhap_GH(int &);


int main(){
	int sochieu;
	Nhap_GH(sochieu);
	Vector vt1(sochieu), vt2(vt1), tong(vt1);
	cout << "Nhap toa do vector 1: " << endl;
	cin >> vt1;
	cout << "Nhap toa do vector 2: " << endl;
	cin >> vt2;
	
	cout << "Vector 1: " << "(" << vt1 << ")" << endl;
	cout << "Vector 2: " << "(" << vt2 << ")" << endl;

	cout << "Cong hai vector: ";
	tong = (vt1 + vt2);
	cout << "(" << tong << ")" << endl;


	system("pause");
	return 0;
}

Vector Vector::operator = (const Vector &tmp){
	Vector kq(tmp);
	for (int i = 0; i < tmp.n; i++)
	{
		this->v[i] = tmp.v[i];
	}
	return kq;
}

Vector operator + (const Vector &tmp1, const Vector &tmp2){
	Vector kq(tmp1);
	for (int i = 0; i < tmp1.n; i++)
	{
		kq.v[i] = tmp1.v[i] + tmp2.v[i];
	}

	return kq;
}

ostream &operator << (ostream &output, const Vector &tmp){
	for (int  i = 0; i < tmp.n; i++)
	{
		output << tmp.v[i];
		if(i!=tmp.n-1)
		{
			output << ",";
		}
	}

	return output;
}

istream &operator >> (istream &input, Vector &tmp){
	for (int  i = 0; i < tmp.n; i++)
	{
		cout << "toa do " << i + 1 << " : ";
		input >> tmp.v[i];
	}
	cout << endl;
	return input;
}

void Nhap_GH(int &sochieu){
	cout << "Nhap so chieu: ";
	cin >> sochieu;
	cout << endl;
}
