#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct tableau{
	int tab[100];
	int taille;
	//Taille de représentation=404 (4*100+4)
};
typedef struct tableau TABLEAU;

void taille_type(){
	int x;
	//x=sizeof(int[]);
	//printf("%d\n",x);
	//char=1
	//int=4
	//double=8
	//char*=8
	//void*=8
	//int*=8
	//double*=8
	//int**=8
	//int[10]=4*10=40
	//char[7][3]=7*3*1=21
	//int[]=Erreur
	
	char tab[10];
	//printf("%d\n",x=sizeof(*&tab[0]));
	//tab=10
	//tab[0]=1
	//*&tab=10
	//*&tab[0]=1
	
	char (*p)[10]=&tab;
	printf("%d\n",x=sizeof(&(*p)[2]));
	//p=8
	//*p=10
	//(*p)[2]=1
	//&(*p)[2]=8
}
void permute(int *a, int *b){
	int c;
	c=*b;
	*b=*a;
	*a=c;
}
void reinit_pointeur(int **p){
	*p=NULL;
}
int alea(int n){
	return rand()%(n+1);
}
void init_tab(TABLEAU *T){
	(*T).taille=10; //Autre écriture: T->taille
	int i;
	for(i=0;i<10;i++){
		(*T).tab[i]=alea(20);//Autre écriture: T->tab[i]
	}
}
void affichage_tab(TABLEAU *T){
	int i;
	for (i=0;i<10;i++){
		printf("Position %d : %d\n",i,T->tab[i]);
	}
}
void multiplication_tableau(TABLEAU *T){
	int i;
	int produit=1;
	for (i=0;i<10;i++){
		produit=produit*(T->tab[i]);
	}
	printf("Le produit de tous les éléments du tableau est: %d\n",produit);
}
void min_tableau(TABLEAU *T){
	int min=T->tab[0];
	int i;
	for (i=0;i<10;i++){
		if (T->tab[i]<=min) min=T->tab[i];
	}
	printf("Le minimum du tableau est: %d\n",min);
}
void decalage_droite(TABLEAU *T){
	int i;
	for (i=T->taille-1;i>=0;i--){
		T->tab[i+1]=T->tab[i];
	}
	T->taille=T->taille+1;
	T->tab[0]=0;
}

int main(){
	//int a=5,b=2;
	//taille_type();
	//permute(&a,&b);
	//printf("a=%d et b=%d\n",a,b);
	
	/*int a=1;
	int *p=&a;
	reinit_pointeur(&p);
	printf("%d\n",p);
	*/
	srand(time(NULL));
	TABLEAU t;
	int i;
	init_tab(&t);
	affichage_tab(&t);
	multiplication_tableau(&t);
	min_tableau(&t);
	decalage_droite(&t);
	for (i=0;i<t.taille;i++){
		printf("La position %d après tri est : %d\n",i,t.tab[i]);
	}
	
}
