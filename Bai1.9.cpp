#include <iostream>
#include <iomanip>
using namespace std;

class Mydate{
public:
	Mydate();
	~Mydate();
	friend istream &operator >> (istream &input, Mydate &tmp);
	friend ostream &operator << (ostream &output, const Mydate &tmp);
	Mydate operator >= (Mydate &tmp);
	Mydate operator > (Mydate &tmp);
private:
	int date, month, year;
};

void Nhap_xuat(int *SL){
	cout << "Ban muon nhap bao nhieu: ";
	cin >> *SL;
}

int main(){
	Mydate *A, Time_HD;
	int SL;
	Nhap_xuat(&SL);
	A = new Mydate[SL];

	// nhap SL ngay thang nam 
	for (int i = 0; i < SL; i++)
	{
		cout << "Nhap ngay thang thu " << i + 1 << " : " << endl;
		cin >> A[i];
	}

	// in SL ngay thang nam
	for (int j = 0; j < SL; j++)
	{
		cout << "Ngay thang thu " << j + 1 << " : ";
		cout << A[j];
	}

	// tim thoi gian lon nhat
	for (int e = 0; e < SL; e++)
	{
		Time_HD >= A[e];
	}
	cout << "thoi gian lon nhat la: ";
	cout << Time_HD;
	// sap xep thoi gian tang dan
	for (int c = 0; c < SL - 1; c++)
	{
		for (int v = c + 1; v < SL; v++)
		{
			A[c] > A[v];
		}
	}
	cout << "Thoi gian sap xep theo chieu tan dan: " << endl;
	for (int x = 0; x < SL; x++)
	{
		cout << A[x];
	}

	system("pause");
	return 0;
}

Mydate Mydate::operator > (Mydate &tmp){
	Mydate kq, time_tmp;
	if (this->year > tmp.year)
	{
		time_tmp.date = tmp.date;
		tmp.date = this->date;
		this->date = time_tmp.date;

		time_tmp.month = tmp.month;
		tmp.month = this->month;
		this->month = time_tmp.month;

		time_tmp.year = tmp.year;
		tmp.year = this->year;
		this->year = time_tmp.year;
		
	}
	if (this->year == tmp.year)
	{
		if (this->month > tmp.month)
		{
			time_tmp.date = tmp.date;
			tmp.date = this->date;
			this->date = time_tmp.date;

			time_tmp.month = tmp.month;
			tmp.month = this->month;
			this->month = time_tmp.month;

			time_tmp.year = tmp.year;
			tmp.year = this->year;
			this->year = time_tmp.year;
		}
		if (this->month == tmp.month)
		{
			if (this->date > tmp.date)
			{
				time_tmp.date = tmp.date;
				tmp.date = this->date;
				this->date = time_tmp.date;

				time_tmp.month = tmp.month;
				tmp.month = this->month;
				this->month = time_tmp.month;

				time_tmp.year = tmp.year;
				tmp.year = this->year;
				this->year = time_tmp.year;
			}
		}
	}
	
	kq.date = this->date;
	kq.month = this->month;
	kq.year = this->year;
	
	return kq;
}

Mydate Mydate::operator >= (Mydate &tmp){
	Mydate time_tmp;

	if (tmp.year > this->year)
	{
		this->date = tmp.date;
		this->month = tmp.month;
		this->year = tmp.year;
	}
	else
	{
		if (tmp.month > this->month)
		{
			this->date = tmp.date;
			this->month = tmp.month;
			this->year = tmp.year;

		}
		else
		{
			if (tmp.date > this->date)
			{
				this->date = tmp.date;
				this->month = tmp.month;
				this->year = tmp.year;
			}
		}
	}
	time_tmp.date = this->date;
	time_tmp.month = this->month;
	time_tmp.year = this->year;
	return time_tmp;
}

ostream &operator << (ostream &output, const Mydate &tmp){
	output << setfill('0') << setw(2) << tmp.date << "-"
		<< setfill('0') << setw(2) << tmp.month << "-"
		<< setfill('0') << setw(4) << tmp.year << endl;

	return output;
}

istream &operator >> (istream &input, Mydate &tmp){
	cout << "Ngay: ";
	input >> tmp.date;
	cout << "Thang: ";
	input >> tmp.month;
	cout << "Nam: ";
	input >> tmp.year;

	return input;
}

Mydate::Mydate(){
	date = 00;
	month = 00;
	year = 0000;
}

Mydate::~Mydate(){
}
