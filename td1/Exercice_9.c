#include <stdio.h>
#include <math.h>
int somme_div(int n){
	int s=1; int i;
	for (i=2; i<n; i++){
		if(n%i==0) s+=i;
	}
	return s;
}
void nb_ami(int n){
	int a,b;
	for(a=1; a<=n; a++){
		for(b=a+1;b<=n;b++){
			if(somme_div(a)==b && somme_div(b)==a) printf("%d %d \n",a,b);
		}
	}
}
int main(){
}
	
