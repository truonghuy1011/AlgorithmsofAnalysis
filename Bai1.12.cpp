#include <iostream>
#include <iomanip>
using namespace std;

class MyTime{
public:
	MyTime();
	MyTime(const MyTime &Time);
	MyTime(int H, int M, int S, int B);
	~MyTime();
	friend istream &operator >> (istream &input, MyTime &tmp);
	friend ostream &operator << (ostream &output, const MyTime &tmp);
	friend int operator >= (const MyTime &tmp1, const MyTime &tmp2);
	friend bool DK_nhap(const MyTime &tmp);
	friend void Gan_thoi_gian(MyTime &tmp1, MyTime &tmp2);
private:
	int H, M, S, B;     // B: la khoang thoi gian neu B=0 :AM, B=1 :PM
};

MyTime::MyTime(){
	this->H = 0;
	this->M = 0;
	this->S = 0;
	this->B = 0;
}

MyTime::MyTime(const MyTime &Time){
	this->H = Time.H;
	this->M = Time.M;
	this->S = Time.S;
	this->B = Time.B;
}

MyTime::MyTime(int H, int M, int S, int B){
	this->H = H;
	this->M = M;
	this->S = S;
	this->B = B;
}

MyTime::~MyTime(){
}

void MAXX(int *Max);

int main(){
	MyTime Time_0, *A;
	int Max = 0;
	MAXX(&Max);
	A = new MyTime[Max];
	
	// nhap thoi gian
	for (int i = 0; i < Max; i++)
	{
		cout << "Nhap thoi gian " << i + 1 << " :" << endl;
		cin >> A[i];
	}
	
	// in thoi gian ra man hinh
	for (int i = 0; i < Max; i++)
	{
		cout << "Thoi gian " << i + 1 << " :";
		cout << A[i];
	}
	
	// Tim thoi gian be nhat
	MyTime Time_1(A[0]);
	for (int  i = 1; i < Max; i++)
	{
		if ((Time_1 >= A[i]) == 1)
		{
			Gan_thoi_gian(Time_1, A[i]);
		}
	}
	cout << "thoi gian nho nhat la: " << Time_1 << endl;

	// Tim thoi gian lon nhat
	MyTime Time_2(A[0]);
	for (int i = 0; i < Max; i++)
	{
		if ((Time_2 >= A[i]) != 1)
		{
			Gan_thoi_gian(Time_2, A[i]);
			cout << Time_2 << endl;
		}
	}
	cout << "thoi gian lon nhat la: " << Time_2 << endl;
	system("pause");
	return 0;
}

void Gan_thoi_gian(MyTime &tmp1, MyTime &tmp2){
	tmp1.H = tmp2.H;

	tmp1.M = tmp2.M;

	tmp1.S = tmp2.S;

	tmp1.B = tmp2.B;
}

int operator >= (const MyTime &tmp1, const MyTime &tmp2){
	if (tmp1.H == tmp2.H || tmp1.H > tmp2.H)
	{
		if (tmp1.M == tmp2.M || tmp1.M > tmp2.M)
		{
			if (tmp1.S == tmp2.S || tmp1.S > tmp2.S)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void MAXX(int *Max){
	cout << "Nhap so luong thoi gian: "; cin >> *Max;
}

ostream &operator << (ostream &output, const MyTime &tmp){
	if(tmp.B == 0)
		output << setfill('0') << setw(2) << tmp.H << "-" << setfill('0') << setw(2) 
		       << tmp.M << "-" << setfill('0') << setw(2) << tmp.S << " AM" << endl;
	if(tmp.B == 1)
		output << setfill('0') << setw(2) << tmp.H << "-" << setfill('0') << setw(2)
		<< tmp.M << "-" << setfill('0') << setw(2) << tmp.S << " PM" << endl;
	return output;
}

istream &operator >> (istream &input, MyTime &tmp){
	do
	{
		if (DK_nhap(tmp) != true)
			cout << "Hay nhap lai: " << endl;
		cout << "Nhap gio: ";	input >> tmp.H;
		cout << "Nhap phut: ";	input >> tmp.M;
		cout << "Nhap giay: ";	input >> tmp.S;
		cout << "Nhap thoi gian (AM: 0, PM: 1) : ";	input >> tmp.B;
	} while (DK_nhap(tmp) != true);

	return input;
}

bool DK_nhap(const MyTime &tmp){
	if (tmp.H >= 0 && tmp.H <= 12)
	{
		if (tmp.M >= 0 && tmp.M <= 59)
		{
			if (tmp.S >= 0 && tmp.S <= 59)
			{
				if (tmp.B == 0 || tmp.B == 1)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}
