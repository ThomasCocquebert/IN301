#include <stdio.h>
int main(){
	int nb=53;
	int i;
	for(i=2;i<nb;i++){
		if(nb%i==0) return 0;
	}
	return 1;
}
	
