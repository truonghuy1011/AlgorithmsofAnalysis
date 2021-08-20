#include <iostream.h>
using namespace std;
double tinh(int n){
	
	double s=1;
	double p=1;
	for(int i=0;i<=n;i++){
		p=p*2*(i+1)/(2*i+3);	
		s+=p;
	}
	return s;
}
int main()
{
   cout<<tinh(2);
 
   return 0;
}
