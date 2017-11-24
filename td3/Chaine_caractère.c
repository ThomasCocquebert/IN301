#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct ListeC{
	char car;
	struct ListeC* suiv;
};
typedef struct ListeC* Liste;


int is_float(char* s){
	int i=0;
	if(s[i]=='-')i++;
	if(!isdigit(s[i])) return 0;
	i++;
	while (isdigit(s[i])) i++;
	if(s[i]=='\0') return 1;
	if(s[i]!='.') return 0;
	i++;
	if(!isdigit(s[i])) return 0;
	while(isdigit(s[i])) i++;
	if(s[i]=='\0') return 1;
	return 0;
}
Liste creer_liste(){
	return NULL;
}
int est_vide(Liste l){
	return l==NULL;
}
Liste creer_carac(char c){
	Liste l;
	l=malloc(sizeof(struct ListeC));
	if(l==NULL){
		printf("Allocation mémoire échouée \n");
		exit(EXIT_FAILURE);
	}
	l->car=c;
	l->suiv=NULL;
	return l;
}
Liste inser_fin_R(Liste l, char c){
	Liste lres;
	if(est_vide(l)){
		lres=creer_carac(c);
		return lres;
	}
	l->suiv=inser_fin_R(l->suiv,c);
	return l;
}


int main(int argc, char** argv){
	int i;
	double s=0.0;
	for(i=1; i<argc; i++){
		if (!is_float(argv[i])){
			printf("Arguments non valides\n");
			return -1;
		}
		s+=atof(argv[i]);
	}
	printf("%f\n",s);
	return 0;
}