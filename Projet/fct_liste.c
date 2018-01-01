#include <stdlib.h>
#include <stdio.h>
#include "Structure.h"

LISTE creer_elem(int L, int H, int sens){
	LISTE m;
	malloc(sizeof(struct elem));
	if(m==NULL){
		printf("Allocation mémoire échouée\n");
		exit(EXIT_FAILURE);
		
	}
	m->L=L;
	m->H=H;
	m->sens=sens;
	return m;
}

LISTE inser(LISTE m, int L, int H, int sens){
	LISTE mres = creer_elem(L,H,sens);
	mres->suiv=m;
	return mres;
}