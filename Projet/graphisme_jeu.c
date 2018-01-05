#include <stdlib.h>
#include <stdio.h>
#include "Structure.h"
#include "uvsqgraphics.h"
#include "fct_jeu.h"

void affichage_grille(SLIDER S){
	POINT a,b;
	int i;
	a.x=0; a.y=0;
	b.x=0; b.y=30*S.H;
	for(i=0;i<=S.L;i++){
		draw_line(a,b,blanc);
		a.x+=30; b.x+=30;
	}
	a.x=0; a.y=0;
	b.x=30*S.L; b.y=0;
	for(i=0;i<=S.H;i++){
		draw_line(a,b,blanc);
		a.y+=30; b.y+=30;
	}
}
void affichage_joueur(SLIDER S){
	POINT a;
	a.x=S.joueur.x*30-15; a.y=S.joueur.y*30-15;
	draw_fill_circle(a,15,bleu);
}
void affichage_sortie(SLIDER S){
	POINT a;
	a.x=S.sortie.x*30-15; a.y=S.sortie.y*30-15;
	draw_circle(a,15,rouge);
}
void calcul_murs(SLIDER S, POINT *a, POINT *b){
	if(S.murs->sens==0){
		a->x=S.murs->L*30; a->y=S.murs->H*30;
		b->x=S.murs->L*30-30; b->y=S.murs->H*30;
	}
	if(S.murs->sens==3){
		a->x=S.murs->L*30; a->y=S.murs->H*30;
		b->x=S.murs->L*30; b->y=S.murs->H*30-30;
	}
	if(S.murs->sens==6){
		a->x=S.murs->L*30; a->y=S.murs->H*30-30;
		b->x=S.murs->L*30-30;b->y=S.murs->H*30-30;
	}
	if(S.murs->sens==9){
		a->x=S.murs->L*30-30; a->y=S.murs->H*30;
		b->x=S.murs->L*30-30; b->y=S.murs->H*30-30;
	}
}
void affichage_mur(SLIDER S){
	POINT a,b;
	if(S.murs!=NULL){
		while(S.murs->suiv!=NULL){
			calcul_murs(S,&a,&b);
			draw_line(a,b,rouge);
			S.murs=S.murs->suiv;
		}
		calcul_murs(S,&a,&b);
		draw_line(a,b,rouge);
	}
}
void affichage(SLIDER S){
	affichage_grille(S);
	affichage_joueur(S);
	affichage_sortie(S);
	affichage_mur(S);
}