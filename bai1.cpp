#include <iostream>
#include <conio.h>
#define MAX 100
using namespace std;
class vector{
	private:
		int p[MAX];
	public:
		khoitao();
		friend istream& operator >> (istream &nhap,vector &v);
		friend ostream& operator << (ostream &xuat,const vector &v);
		vector operator+(const vector &v);
		vector operator-(const vector &v);
		vector operator*(const vector &v);
		vector tichvohuong(const vector &v);
		doidau();
};
int n;
vector::khoitao(){
	for(int i=1;i<=MAX;i++){
		p[i]=0;
	}
}

istream& operator >> (istream &nhap,vector &v){
	for (int i=1;i<=n;i++){
		cout<< "Toa do thu " << i << " : ";
		nhap>> v.p[i];
	}
}

ostream& operator << (ostream &xuat,const vector &v){
	xuat<< "( ";
	for (int i=1;i<=n;i++){
		xuat<<v.p[i];
		if(i<n){
			xuat<<", ";
		}
	}
	xuat<< " )";
}

vector vector::operator+(const vector &v){
	vector kq;
	for (int i=1;i<=n;i++){
		kq.p[i]=p[i]+v.p[i];
	}
	return kq;
}

vector vector::operator-(const vector &v){
	vector kq;
	for ( int i=1;i<=n;i++){
		kq.p[i] =p[i]-v.p[i];
	}
	return kq;
}

vector vector::operator*(const vector &v){
	vector kq;
	for ( int i=1;i<=n;i++){
		kq.p[i] =p[i]*v.p[i];
	}
	return kq;
}

vector vector::tichvohuong(const vector &v){
	int tichvh=0;
	for(int i=1;i<=n;i++){
		tichvh=tichvh + v.p[i];
	}
	cout<<tichvh;
}

vector::doidau(){
	for(int i=1;i<=n;i++){
		p[i]=-p[i];
	}
}

int main (){
	vector v1, v2, v3, v4, v5, v6;
	cout<<"Moi Nhap Vao So Chieu: ";cin>>n;
	cout<<"\nMoi Nhap Toa Do 1==>\n";
	cin >> v1;cout << v1;
	cout<<"\nMoi Nhap Toa Do 2==>\n";
	cin >> v2;cout << v2;
	v3=v1+v2;
	cout<<"\nTong 2 Vector==>: "<<v3;
	v4=v1-v2;
	cout<<"\nHieu 2 Vector==>: "<<v4;
	v5=v1*v2;
	cout<<"\nTich Vo Huong 2 Vector==>: ";
	v6.tichvohuong(v5);
	v1.doidau();
	v2.doidau();
	cout<<"\nDoi Dau 2 VecTor\n"<<"Vector Thu 1: "<<v1<<"\nVector Thu 2: "<<v2;
	
}

