#include<iostream.h>
#include<string>
#include<string.h>
#include "BigInt.h"
using namespace std;

void nhan(string &str, string str1, string str2 ){
	int *res;
	res = new int[str1.size() + str2.size()];
	for(int i = 0; i<= str1.size() + str2.size(); i++) res[i] = 0;
	
	for( int i = str1.size() - 1; i >= 0; i-- ){
		for( int j = str2.size() - 1; j >= 0; j-- )
			res[i+1+j] += ( str1[i] - '0' ) * ( str2[j] - '0' );
	}
	
	for(int i = str1.size() + str2.size(); i>= 0 ; i-- ) 
		if(res[i] > 9){
			res[i-1] += res[i]/10;
			res[i] %= 10;
		}
	for( int i = 0; i< str1.size() + str2.size(); i++ )
		str+= (res[i] + '0');
}



BigInt::BigInt(){
	for (int i = 0; i < 100; ++i) {
        number[i] = '0';
    }
    number[100] = '\0';
}
BigInt::BigInt(char *v) {
    int len = strlen(v);
    for (int i = 0; i < len; i++) {
        number[100 - i] = v[len - 1 - i];
    }
}
bool BigInt::lonHon(BigInt d){
	string a=string(number);
	string b=string(d.number);
	return a.compare(b)>0 ? true:false;
}
istream& operator>> (istream& is,BigInt &d){
	int len;
    char x[101];
    is>> x;
    len = strlen(x);
    for (int i = 0; i < len; ++i) {
        d.number[100-len+i] = x[i];
    }
    return is;
}
ostream& operator<< (ostream& os,const BigInt &d){
	int pos = 0;
    for (int i = 0; i < 100; ++i) {
        if(d.number[i] != '0'){
            pos = i;
            break;
        }
    }

    for (int j = pos; j < 100; ++j) {
        os<< d.number[j];
    }
    os<< endl;
    return os;
}
BigInt BigInt::operator+(BigInt d){
	BigInt kq;
	int nho=0 ;
	for(int i=99;i>=0;i--){
		int sum=(number[i] -'0')+(d.number[i]-'0')+nho;
		if(sum>9) {
			nho=1;
			kq.number[i]=(sum-10+'0');
		}
		else{
			nho=0;
			kq.number[i]=(sum+'0');
		}
	}
	return kq;
}
BigInt BigInt::operator-(BigInt d){
	BigInt kq;
	int muon=0;
	bool greater=lonHon(d);
	if(greater){
		for(int i=99;i>=0;i--){
		int sub=(number[i]+muon -'0')-(d.number[i]-'0');
		if(sub<0){
			muon=1;
			kq.number[i]=((sub+10)+'0');
		}else{
			muon=0;
			kq.number[i]=(sub+'0');	
		}
	}
	}
	else{
		for(int i=99;i>=0;i--){
			if(d.number[i]=='0'){
				kq.number[i]='-';
				break;
			}
			int sub=(d.number[i]+muon -'0')-(number[i]-'0');
     		if(sub<0){
				muon=1;
				kq.number[i]=((sub+10)+'0');
			}
			else{
				muon=0;
				kq.number[i]=(sub+'0');	
			}
		}
		
	}
	
	return kq;
	
}
BigInt BigInt::operator *(BigInt d){
	BigInt kq;
    return kq;
	
}
BigInt BigInt::operator /(int a){
	BigInt kq;
    return kq;
	
}

int main(){
	BigInt a,b,c;
	cout<<"Nhap so nguyen lon a: ";
	cin>>a;
	cout<<"Nhap so nguyen lon b: ";
	cin>>b;
	
	cout<<"Tong hai so nguyen lon a,b la: ";
	c=a+b;
	cout<<c<<endl;
	cout<<"Hieu hai so nguyen lon a,b la: ";
	c=a-b;
	cout<<c<<endl;
	
	string str = "";
	string so1,so2,so3;
	getline(cin,so3);
	getline(cin, so1);
	getline(cin, so2);
	nhan(str,so1,so2);
	cout<<"Tich hai so nguyen lon so1,so2 la:  "<<str;
	
	
	return 0;
	
}
