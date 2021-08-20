#include <iostream.h>
#include <math.h>
using namespace std;
const long n=60000;


void diChuyen(long a[],long n,long k){
	long b[k+1];
	long dem=k;
	long d=1;
	for(long i=1;i<=n;i++){
		if(i<=dem){
			b[i]=a[i];
		}
		if(i<=n-dem){
			a[i]=a[++k];
		    cout<<a[i]<<"  ";
		}else{
			a[i]=b[d];
			cout<<a[i]<<"  ";
			d++;
		} 
		
	}
}
int main()
{
	long a[n];
	for(long i=1;i<=n;i++){
		a[i]=i;
	}
	diChuyen(a,n,100);
    return 0;
}
