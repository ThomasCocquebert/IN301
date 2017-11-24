#include <stdio.h>

int main(){
	int z=0;
	int x=87;
	int y=23;
		printf("%d x %d \n",x,y);
		while(x>=1){
			if(x%2==0){
				x=x/2;
				y=2*y;
			}
			else{
				x--;
				z+=y;
			}
			printf("= %d x %d + %d \n",x,y,z);
		}
	printf("= %d \n",z);
}
