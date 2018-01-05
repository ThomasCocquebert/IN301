#include <stdio.h>
#include <stdlib.h>
#include "uvsqgraphics.h"
#include "Structure.h"
#include "fct_jeu.h"
#include "graphisme_jeu.h"

int main(){
	init_graphics(700,700);
	SLIDER S;
	S.L=7; S.H=10; S.joueur.x=1; S.joueur.y=1; S.sortie.x=7; S.sortie.y=10;
	S.murs=creer_liste();
	S.murs=inser_mur(S.murs,3,6,0);
	S.murs=inser_mur(S.murs,7,5,9);
	affichage(S);
	wait_escape();
	libere_mem(S.murs);
	exit(0);
}