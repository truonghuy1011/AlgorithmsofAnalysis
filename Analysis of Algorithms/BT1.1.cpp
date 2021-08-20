#include <iostream.h>
using namespace std;

double tinh(int n){
	double s=0;
	double p=0;
	double gt=1;
	for(int i=1;i<=n;i++){
		gt*=i;
		p+=i;
		
		s+=p/gt;
	}
	return s;
}
int main()
{
   cout<<tinh(5);
   return 0;
}
