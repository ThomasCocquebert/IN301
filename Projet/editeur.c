#include <stdio.h>
#include <stdlib.h>
#include "Structure.h"
#include "uvsqgraphics.h"
#include "fct_jeu.h"
#include "graphisme_jeu.h"

int test_arg_L_H(char *argv[])
{
	int test = 1;
	if (atoi(argv[2]) > 20) {
		printf("Erreur arguments L\n");
		return test = 0;
	}
	if (atoi(argv[3]) > 20) {
		printf("Erreur arguments H\n");
		return test = 0;
	}
	return test;
}

SLIDER recup_pos(char *argv[])
{
	SLIDER S = init_slider();
	S.L = atoi(argv[2]);
	S.H = atoi(argv[3]);
	return S;
}

SLIDER placer_joueur(SLIDER S)
{
	SLIDER SJ = S;
	int a = 0;
	int arrow = 0;
	char c = 'c';
	POINT clic;
	while (a != 3) {
		a = wait_key_arrow_clic(&c, &arrow, &clic);
	}
	SJ.joueur.x = clic.x / 30;
	SJ.joueur.y = clic.y / 30;
	fill_screen(black);
	affichage(SJ);
	return SJ;
}

SLIDER placer_sortie(SLIDER S)
{
	SLIDER SS = S;
	int a = 0;
	int arrow = 0;
	char c = 'c';
	POINT clic;
	while (a != 3) {
		a = wait_key_arrow_clic(&c, &arrow, &clic);
	}
	SS.sortie.x = clic.x / 30;
	SS.sortie.y = clic.y / 30;
	fill_screen(black);
	affichage(SS);
	return SS;
}

SLIDER ajout_mur(SLIDER S, POINT clic)
{
	int L = clic.x / 30;
	int H = clic.y / 30;
	if (control_liste(S.murs, L, H) == 0) {
		if(L<=S.L && H<=S.H){
			S.murs = inser_mur(S.murs, L, H, 0);
		}
	} else {
		S.murs = changer_sens(S.murs, L, H);
	}
	fill_screen(black);
	affichage(S);
	return S;
}

//La fin de l'éditeur s'effectue si le joueur appuie sur S pour enregistré le niveau. De base, cliquer sur la grille ajoute un mur. La touche J permet de placer le personnage
//et la touche E la sortie
SLIDER editeur(char *argv[])
{
	int a = 0;
	int arrow = 0;
	int save = 0;
	char c = 'c';
	POINT clic;
	SLIDER S = init_slider();
	S = recup_pos(argv);
	affichage(S);
	while (save == 0) {
		a = wait_key_arrow_clic(&c, &arrow, &clic);
		if (a == 2) {
			if (c == 'J')
				S = placer_joueur(S);
			if (c == 'E')
				S = placer_sortie(S);
			if (c == 'S') {
				save = 1;
				S.nombre_murs = cpt_liste(S.murs);
			}
		}
		if (a == 3) {
			S = ajout_mur(S, clic);
		}
	}
	return S;
}
