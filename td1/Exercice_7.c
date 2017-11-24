#include <stdio.h>
int main(){
	double eps=0.000000000001;
	double s1=0;
	double s2;
	int i=1;
	do{
		s2=s1;
		s1=s1+1.0/(i*i);
		i++;
	}while (s1-s2>eps);
	printf("Sn = %f \n",s1);
}
