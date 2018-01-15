#include <stdlib.h>
#include <stdio.h>
#include "Structure.h"

LISTE creer_liste()
{
	return NULL;
}

int est_vide(LISTE l)
{
	return l == NULL;
}

LISTE creer_mur(int L, int H, int sens)
{
	LISTE l;
	l = malloc(sizeof(struct elem));
	if (l == NULL) {
		printf("Allocaton mémoire échouée");
		exit(EXIT_FAILURE);
	}
	l->L = L;
	l->H = H;
	l->sens = sens;
	l->suiv = NULL;
	return l;
}

LISTE inser_mur(LISTE l, int L, int H, int sens)
{
	LISTE lres = creer_mur(L, H, sens);
	lres->suiv = l;
	return lres;
}

LISTE libere_mem_liste(LISTE l)
{
	if (!est_vide(l)) {
		l->suiv = libere_mem_liste(l->suiv);
		free(l);
	}
	return NULL;
}

PILE creer_pile()
{
	return NULL;
}

int est_vide_p(PILE p)
{
	return p == NULL;
}

PILE creer_coup(int x, int y)
{
	PILE p;
	p = malloc(sizeof(struct pile));
	if (p == NULL) {
		printf("Allocaton mémoire échouée");
		exit(EXIT_FAILURE);
	}
	p->j.x = x;
	p->j.y = y;
	p->prec = NULL;
	return p;
}

PILE inser_coup(PILE p, int x, int y)
{
	PILE pres = creer_coup(x, y);
	pres->prec = p;
	return pres;
}

PILE libere_mem_pile(PILE p)
{
	if (!est_vide_p(p)) {
		p->prec = libere_mem_pile(p->prec);
		free(p);
	}
	return NULL;
}

PILE pile_pop(PILE p, POS * jprec)
{
	PILE psuiv = creer_pile();
	if (!est_vide_p(p)) {
		jprec->x = p->j.x;
		jprec->y = p->j.y;
		psuiv = p->prec;
		free(p);
		return psuiv;
	}
	return p;
}

//Le joueur remporte la ictoire si la position du joueur et de la sortie concordent
int victoire(SLIDER S)
{
	int win = 0;
	if (S.joueur.x == S.sortie.x && S.joueur.y == S.sortie.y) {
		win = 1;
	}
	return win;
}

SLIDER init_slider()
{
	SLIDER S;
	S.L = 0;
	S.H = 0;
	S.joueur.x = 0;
	S.joueur.y = 0;
	S.sortie.x = 0;
	S.sortie.y = 0;
	S.nombre_murs = 0;
	S.murs = creer_liste();
	S.coups = creer_pile();
	return S;
}

//Cette fonction parcour la liste et vérifie si un mur est déjà présent en L*H
int control_liste(LISTE l, int L, int H)
{
	int ctrl = 0;
	if (l == NULL)
		return ctrl;
	while (l->suiv != NULL) {
		if (l->L == L && l->H == H)
			return ctrl = 1;
		l = l->suiv;
	}
	if (l->L == L && l->H == H)
		return ctrl = 1;
	return ctrl;
}

//Cette fonction supprime le mur si il est sur la position 9
LISTE changer_mur(LISTE l, int L, int H)
{
	if (l == NULL)
		return NULL;
	if (l->L == L && l->H == H && l->sens == 9) {
		LISTE tmp = l->suiv;
		free(l);
		tmp = changer_mur(tmp, L, H);
		return tmp;
	} else {
		l->suiv = changer_mur(l->suiv, L, H);
		return l;
	}
}

//Et cette fonction change le sens du mur si celui si n'est pas sur la position 9
LISTE changer_sens(LISTE l, int L, int H)
{
	LISTE ldeb = l;
	while (l->suiv != NULL) {
		if (l->L == L && l->H == H && l->sens != 9) {
			l->sens = l->sens + 3;
			return ldeb;
		}
		if (l->L == L && l->H == H && l->sens == 9) {
			ldeb = changer_mur(ldeb, L, H);
			return ldeb;
		}
		l = l->suiv;
	}
	if (l->L == L && l->H == H && l->sens != 9) {
		l->sens = l->sens + 3;
		return ldeb;
	}
	if (l->L == L && l->H == H && l->sens == 9) {
		ldeb = changer_mur(ldeb, L, H);
		return ldeb;
	}
	return ldeb;
}

int cpt_liste(LISTE l)
{
	int nb = 0;
	if (l == NULL)
		return nb;
	while (l->suiv != NULL) {
		l = l->suiv;
		nb++;
	}
	return nb + 1;
}
