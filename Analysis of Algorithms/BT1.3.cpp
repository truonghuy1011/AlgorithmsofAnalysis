#include <iostream.h>
using namespace std;
double tinh(int n){
	
	double gt=1;
	double s=0;
	for(int i=1;i<=n;i++){	
		gt*=i;	
		s+=(2*i-1 )/gt;
	}
	return s;
	
}
int main()
{
   cout<<tinh(4);
 
   return 0;
}
