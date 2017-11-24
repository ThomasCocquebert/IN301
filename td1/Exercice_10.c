#include <stdio.h>
#include <math.h>
int main(){
	int n;
	double g=0.0;
	double d=n;
	double m;
	double eps=0.001;
	while (d-g>eps){
		m=(d+g)/2;
		if (m*m>n) d=m
		else if(m*m==n) return m;
		else g=m;
	}
	return (d+g)/2;
}
