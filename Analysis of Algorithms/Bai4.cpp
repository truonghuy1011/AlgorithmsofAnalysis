#include <iostream>
#include <stdlib.h>
using namespace std;

void chen(int a[],int &n,int vt,int k)
{
 
 for(int i=n+1;i>=vt;i--)
 {
 a[i]=a[i-1];
 }
 a[vt]=k;
 n++;

}
void daySo_WAWIO(int a[],int DD[],int n,int m,int &d){
	int b[100];
	int l[100];
	int lmax;	
	b[0]=1;
	for(int i=1;i<=m;i++){
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

	int k=l[m];
	d=0;
	while(k>0){
		
		DD[d]=a[k];
		k=l[k];
		d++;
	}


}

void daySo_WAWIO1(int a[],int DD[],int n,int m,int &d){
	cout<<endl;
	int b[100];
	int dem=0;
	for(int i=m;i<=n+1;i++){	
		b[dem]=a[i];
		dem++;
	}
	dem--;
	chen(b,dem,1,a[m-2]);

	int c[100];
	int l[100];
	int lmax;	
	c[dem]=1;
	for(int i=dem-1;i>=0;i--){
		lmax=0;
		for(int j=i+1;j<=dem;j++){
			if(b[i]<b[j]){
				if(c[j]>lmax){
				lmax=c[j];
				l[i]=j;
				}	
			}
			
		}
		c[i]=lmax+1;	
	}

	int k=l[0];
	d=0;
	while (k<dem){
		DD[d]=b[k];
		k=l[k];
		d++;
	}
	
}






int main(){
	int a[100],b[100],c[100],n,m,l;
	cout<<"Nhap n: ";
	cin>>n;
	long max,min=99999999;

	max=-min;

	for(int i=1;i<=n;i++){
		a[i]=rand()%15;
  		
		if(a[i]>max)max =a[i];
		if(a[i]<min)min=a[i];
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;

	
	chen(a,n,n/2+1,max+10);
	chen(a,n,n/2+2,min-10);
	a[0]=min-10;
	a[n+1]=max+10;
	
	daySo_WAWIO(a,b,n,n/2,m);
	for(int i=m-1;i>=0;i--){
		cout<<b[i]<<"\t";
	}
	cout<<endl;
	daySo_WAWIO1(a,c,n,n/2+1,l);
	
	for(int i=l-1;i>=0;i--){
		cout<<c[i]<<"\t";
	}
	cout<<endl;

	
	
	
	
	

	
	return 0;
	
	
}