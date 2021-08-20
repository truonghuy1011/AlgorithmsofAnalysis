#include <iostream>
#include <stdlib.h>
using namespace std;
void dayConDD(int a[],int DD[],int n,int &d){
	int b[100];
	int l[100];
	int lmax;	
	b[0]=1;
	for(int i=1;i<=n+1;i++){
		lmax=0;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				if(b[j]>lmax){
					lmax=b[j];
					l[i]=j;
				}
			}
		}
		b[i]=lmax+1;
			
	}
	
	

	int k=l[n+1];
	d=0;
	while(k>0){
		
		DD[d]=a[k];
		k=l[k];
		d++;
	}

}


int main(){
	int a[100],n,l[100],m;
	cout<<"Nhap n: ";
	cin>>n;
	long max,min=99999999;

	max=-min;

	for(int i=1;i<=n;i++){
		a[i]=rand()%15;
  		
		if(a[i]>max)max =a[i];
		if(a[i]<min)min=a[i];
	}
	a[0]=min-1;
	a[n+1]=max+1;

	for(int i=1;i<=n;i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	dayConDD(a,l,n,m);
	for(int i=m-1;i>=0;i--){
		cout<<l[i]<<"\t";
	}
	
	
	
	
}