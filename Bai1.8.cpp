//Xay dung Class vector
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
	friend Vector operator * (const float &k, const Vector &tmp);
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

Vector::Vector(int a){		//ham tao mot toan tu

	this->n = a;
	this->v = new float[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->v[i] = 0;
	}
}

Vector::~Vector(){		//ham huy

}

void Nhap_dulieu(int &, float &);


int main(){

	int sochieu;
	float k;
	Nhap_dulieu(sochieu,k);
	Vector vt1(sochieu), tich(vt1);
	cout << "Nhap toa do vector 1: " << endl;
	cin >> vt1;
	
	cout << "Vector 1: " << "(" << vt1 << ")" << endl;

	cout << "Tich cua vector voi so thuc k la:";
	tich = (k * vt1);
	cout << "(" << tich << ")" << endl;


	system("pause");
	return 0;
}

Vector operator * (const float &k, const Vector &tmp){
	Vector kq(tmp);
	for (int i = 0; i < tmp.n; i++)
	{
		kq.v[i] = k * tmp.v[i];
	}

	return kq;
}

Vector Vector::operator = (const Vector &tmp){
	Vector kq;
	for (int i = 0; i < tmp.n; i++)
	{
		this->v[i] = tmp.v[i];
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

void Nhap_dulieu(int &sochieu, float &k){
	cout << "Nhap so chieu: ";
	cin >> sochieu;
	cout << "Nhap gia tri so thuc 'K': ";
	cin >> k;
	cout << endl;
}
