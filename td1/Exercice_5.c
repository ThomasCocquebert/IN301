#include <stdio.h>

int main (){
	int s=3620;
	printf("%d seconde",s);
	if (s>1) printf("s");
	int m,h;
	h=s/3600;
	s=s%3600;
	m=s/60;
	s=s%60;
	printf(" correspond à %d heure",h);
	if (h>1) printf("s");
	printf(" %d minute",m);
	if (m>1) printf("s");
	printf(" %d seconde",s);
	if (s>1) printf("s");
}
