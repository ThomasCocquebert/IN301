#include <stdlib.h>
#include <stdio.h>
#include "Structure.h"
#include "uvsqgraphics.h"

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

int main(){
	SLIDER S;
	S.L=5;
	S.H=5;
	S.joueur.x=3; S.joueur.y=2;
	S.sortie.x=4; S.sortie.y=1;
	init_graphics(700,700);
	affichage_grille(S);
	affichage_joueur(S);
	affichage_sortie(S);
	wait_escape();
	exit(0);
}