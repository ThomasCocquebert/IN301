#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "uvsqgraphics.h"
#include "Structure.h"
#include "fct_jeu.h"
#include "graphisme_jeu.h"
#include "editeur.h"

SLIDER lecture_fichier(char *nom_niv)
{
	FILE *niveau = NULL;
	SLIDER S = init_slider();
	int m_x = 0, m_y = 0, m_s = 0;
	int ccarac = 0;
	printf("Ouverture de %s...\n", nom_niv);
	niveau = fopen(nom_niv, "r");

	if (niveau != NULL) {
		fscanf(niveau, "%d	%d", &S.L, &S.H);
		fscanf(niveau, "%d	%d", &S.joueur.x, &S.joueur.y);
		fscanf(niveau, "%d	%d", &S.sortie.x, &S.sortie.y);
		fscanf(niveau, "%d", &S.nombre_murs);
		for (ccarac = 0; ccarac < S.nombre_murs; ccarac++) {
			fscanf(niveau, "%d	%d	%d", &m_x, &m_y, &m_s);
			S.murs = inser_mur(S.murs, m_x, m_y, m_s);
		}
	} else {
		printf("Impossible d'ouvrir le fichier(lecture)\n");
		wait_escape();
		exit(0);
	}
	fclose(niveau);
	return S;
}

void ecriture_fichier(char *argv, SLIDER S)
{
	FILE *niveau = NULL;
	int x, y, s;
	LISTE lres = creer_liste();
	niveau = fopen(argv, "w");
	if (niveau != NULL) {
		fprintf(niveau, "%d	%d\n", S.L, S.H);
		fprintf(niveau, "%d	%d\n", S.joueur.x, S.joueur.y);
		fprintf(niveau, "%d	%d\n", S.sortie.x, S.sortie.y);
		fprintf(niveau, "%d\n", S.nombre_murs);
		lres = S.murs;
		if (!est_vide(S.murs)) {
			while (S.murs->suiv != NULL) {
				x = S.murs->L;
				y = S.murs->H;
				s = S.murs->sens;
				fprintf(niveau, "%d	%d	%d\n", x, y, s);
				S.murs = S.murs->suiv;
			}
			x = S.murs->L;
			y = S.murs->H;
			s = S.murs->sens;
			fprintf(niveau, "%d	%d	%d", x, y, s);
			S.murs = lres;
		}
	} else {
		printf("Impossible d'ouvrir le fichier(ecriture)\n");
		wait_escape();
		exit(0);
	}
	fclose(niveau);
}

//L'idée de cette fonction est de tester l'ouverture du fichier jusqu'à ce que le ficier ne s'ouvre pas, "normalement" parcequ'il n'existe pas. Seul les fichiers nommés
//"niv_x.slider" seront ouvert.
void lancement_rep()
{
	char chaine_slider[9] = ".slider";
	int i = 1;
	SLIDER S;
	while (i < 99) {
		char chaine_niv[15] = "niv_";
		sprintf(chaine_slider, "%d.slider", i);
		strcat(chaine_niv, chaine_slider);
		S = lecture_fichier(chaine_niv);
		partie(S);
		fill_screen(noir);
		affiche_all();
		i++;
	}
}

void lancement_niv(char *argv)
{
	SLIDER S;
	S = lecture_fichier(argv);
	if(S.L<20 && S.H<20){
		partie(S);
	}
}

void lancement_edit(char *argv[])
{
	SLIDER S = init_slider();
	S = editeur(argv);
	ecriture_fichier(argv[4], S);
	libere_mem_liste(S.murs);
}

int test_argv(char *argv)
{
	int result = 2;
	char test[] = "dir_slider";
	if (strcmp(test, argv) == 0) {
		result = 1;
	}
	return result;
}

int test_argv_edit(char *argv[])
{
	int result = 0;
	char test_c[] = "-c";
	if (strcmp(test_c, argv[1]) != 0) {
		printf("Erreur arguments\n");
		return result;
	}
	if (test_arg_L_H(argv) == 0) {
		printf("Dimension trop grande");
		return result;
	}
	return 3;
}

int test_arg(int argc, char *argv[])
{
	int test = 0;
	if (argc == 2) {
		test = test_argv(argv[1]);
	}
	if (argc == 5) {
		test = test_argv_edit(argv);
	}
	if (argc != 2 && argc != 5) {
		printf("Erreur arguments\n");
	}
	return test;
}

//C'est la fonction "principale" du programme. C'est elle qui lance l'édieur, ou tout le répertoir de niveaux, ou bien juste un niveau spécifique
void slider(int argc, char *argv[])
{
	int test = 0;
	test = test_arg(argc, argv);
	if (test == 1) {
		lancement_rep();
	}
	if (test == 2) {
		lancement_niv(argv[1]);
	}
	if (test == 3) {
		lancement_edit(argv);
	}
}
