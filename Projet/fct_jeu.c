#include <stdlib.h>
#include <stdio.h>
#include "Structure.h"

LISTE creer_liste(){
	return NULL;
}
int est_vide(LISTE l){
	return l==NULL;
}
LISTE creer_mur(int L, int H, int sens){
	LISTE l;
	l=malloc(sizeof(struct elem));
	if(l==NULL){
		printf("Allocaton mémoire échouée");
		exit(EXIT_FAILURE);
	}
	l->L=L;
	l->H=H;
	l->sens=sens;
	l->suiv=NULL;
	return l;
}
LISTE inser_mur(LISTE l, int L, int H, int sens){
	LISTE lres=creer_mur(L,H,sens);
	lres->suiv=l;
	return lres;
}
LISTE libere_mem(LISTE l){
	if(!est_vide(l)){
		l->suiv=libere_mem(l->suiv);
		free(l);
	}
	return NULL;
}