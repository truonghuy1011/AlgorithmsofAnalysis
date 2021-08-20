#include <iostream>
#include <stdlib.h>
using namespace std;
void boTriPhongHop(int a[],int b[],int DD1[],int DD2[],int n,int &d){
	int c[100];
	int l[100];
	int lmax;
	c[0]=1;
	for(int i=1;i<=n+1;i++){
		lmax=0;
		for(int j=0;j<i;j++){
			if(b[j]<=a[i]){
				if(c[j]>lmax){
					lmax=c[j];
					l[i]=j;
				}
			}
		}
		c[i]=lmax+1;
			
	}
	
	
	int k=l[n+1];
	d=0;
	while(k>0){
		DD1[d]=a[k];
		DD2[d]=b[k];
		k=l[k];
		d++;
	}
}
void SapXep(int a[],int b[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[i]>b[j]){
				int t=b[i];
				b[i]=b[j];
				b[j]=t;
				
				int t1=a[i];
				a[i]=a[j];
				a[j]=t1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<"( "<<a[i]<<";"<<b[i]<<" )"<<"  ";
	}
}


int main(){
	int a[100],b[100],x[100],y[100],n,m;
	cout<<"Nhap so cuoc hop: ";
	cin>>n;
	long max,min=99999999;

	max=-min;
	long max1,min1=99999999;

	max1=-min1;

	for(int i=1;i<=n;i++){
		a[i]=rand()%10;
		b[i]=rand()%13;
  		
		if(a[i]>max)max =a[i];
		if(a[i]<min)min=a[i];
		if(b[i]>max1)max1 =b[i];
		if(b[i]<min1)min1=b[i];
	}
	a[0]=min-1;
	a[n+1]=max+1;
	b[0]=min1-1;
	b[n+1]=max1+1;
	
	for(int i=1;i<=n;i++){
		cout<<"( "<<a[i]<<";"<<b[i]<<" )"<<"  ";
	}
	cout<<endl;
	SapXep(a,b,n);
	cout<<endl;
	boTriPhongHop(a,b,x,y,n,m);
	
	for(int i=m-1;i>=0;i--){
		cout<<"( "<<x[i]<<";"<<y[i]<<" )"<<"  ";
	}
	return 0;

	
}