#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

void suite_syracuse(int n){
	int j,m;
	for(j=1;j<n;j++){
		int i=0;
		m=j;
		while (m!=1){
			if (m%2==0){
				m=m/2;
				i++;
				//printf("%d\n",n);
			}
			else{
				m=3*m+1;
				i++;
				//printf("%d\n",n);
			}
		}
		printf("Itération = %d\n",i);
	}
}
int factorielle(int n){
	int f;
	if (n<=1){
		f=1;
	}
	else{
		f=n*factorielle(n-1);
	}
	printf("%d\n",f);
	return f;
}
void calcule_suite(int n){
	int i;
	float m;
	m=0.0;
	for (i=n;i>0;i--){
		m=sqrt(m+i);
	}
	printf("%f\n",m);
}
void init_tab(int n,int* T){
	int i;
	for (i=0;i<n;i++) T[i]=rand()%10;
}
void multip_tableau(int n, int *T){
	int i,m=1;
	for(i=0;i<n;i++){
		m=m*T[i];
	}
	printf("Le produit de tout les termes du tableau est : %d\n",m);
}
void min_tableau(int n, int *T){
	int min=T[0];
	int indice=0;
	int i;
	for (i=0;i<n;i++){
		if (T[i]<min){
			min=T[i];
			indice=i;
		}
	}
	printf("La valeur minimale est %d et se trouve à la position %d\n",min,indice);
}
void decalage_droite(int n, int *T){
	int i;
	for (i=n-2;i>=0;i--){
		T[i+1]=T[i];
	}
	T[0]=0;
}

int main(){
	//int n;
	int i;
	//int f;
	
	//suite_syracuse(n);
	
	//f=factorielle(n);
	//printf("%d\n",f);
	
	//calcule_suite(n);
	
	//char c='A';
	//printf("%d\n",c);
	
	int T[N];
	init_tab(N,T);
	for(i=0;i<N;i++) printf("Position %d : %d\n",i,T[i]);
	multip_tableau(N,T);
	min_tableau(N,T);
	decalage_droite(N,T);
	//for(i=0;i<N;i++) printf("Position %d : %d\n",i,T[i]);
	
}
