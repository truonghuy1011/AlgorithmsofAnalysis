#include <iostream>
#include <stdlib.h>
using namespace std;

void SapXep(int a[],int b[],int c[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[i]>b[j]){
				int t=b[i];
				b[i]=b[j];
				b[j]=t;
				
				int t1=a[i];
				a[i]=a[j];
				a[j]=t1;
				
				int t2=c[i];
				c[i]=c[j];
				c[j]=t2;
			}
		}
	}
	
}
void choThueMay(int a[],int b[],int c[],int &tongtien,int DD1[],int DD2[],int DD3[],int n,int &m){
	SapXep(a,b,c,n);
	int d[100],e[1000],l[100],lmax;
	
	for(int i=0;i<=n+1;i++){
		lmax=0;
		e[i]=c[i];
		for(int j=0;j<i;j++){
			if(b[j]<=a[i] && e[i]<e[j]+c[i]){
				if(d[j]>lmax){
					lmax=d[j];
					l[i]=j;
					e[i]=e[j]+c[i];
				}
			}
		}
		d[i]=lmax+1;
			
	}

	
	tongtien=e[n+1]-(c[0]+c[n+1]);
	
	int k=l[n+1];
	m=0;
	while(k>0){
		DD1[m]=a[k];
		DD2[m]=b[k];
		DD3[m]=c[k];
	
		k=l[k];
		m++;
	}
	
		
}



int main(){
	int a[100],b[100],c[100],x[100],y[100],z[100],n,m,tongtien;
	cout<<"Nhap so khach hang: ";
	cin>>n;
	long max,min=99999999;
	max=-min;
	
	long max1,min1=99999999;
	max1=-min1;
	
	long max2,min2=99999999;
	max2=-min2;

	for(int i=1;i<=n;i++){
		a[i]=rand()%10;
		b[i]=rand()%13;
		c[i]=rand()%25*1000;
  		
		
		if(a[i]>max)max =a[i];
		if(a[i]<min)min=a[i];
		
		if(b[i]>max1)max1 =b[i];
		if(b[i]<min1)min1=b[i];
		
		if(c[i]>max2)max2 =c[i];
		if(c[i]<min2)min2=c[i];
		
	
	}
	a[0]=min-10;
	a[n+1]=max+10;
	
	b[0]=min1-20;
	b[n+1]=max1+20;
	
	c[0]=min2-1000;
	c[n+1]=max2+1000;
	
	for(int i=1;i<=n;i++){
		cout<<"( "<<a[i]<<";"<<b[i]<<" ) Gia tien:  "<<c[i]<<endl;
	}
	choThueMay(a,b,c,tongtien,x,y,z,n,m);
	cout<<endl<<endl;
	
	for(int i=1;i<=n;i++){
		cout<<"( "<<a[i]<<";"<<b[i]<<" ) Gia tien:  "<<c[i]<<endl;
	}
	
	cout<<endl<<endl;
	for(int i=m-1;i>=0;i--){
		cout<<"( "<<x[i]<<";"<<y[i]<<" ) Gia tien:  "<<z[i]<<endl;
	}
	cout<<"Tong tien lon nhat va phu hop voi thoi gian la: "<<tongtien;
	
	

	
	
}