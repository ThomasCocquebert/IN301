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
	a.x=S.joueur.x*30+15; a.y=S.joueur.y*30+15;
	draw_fill_circle(a,15,bleu);
}
void masque_joueur(SLIDER S){
	POINT a;
	a.x=S.joueur.x*30+15; a.y=S.joueur.y*30+15;
	draw_fill_circle(a,15,black);
}
void affichage_sortie(SLIDER S){
	POINT a;
	a.x=S.sortie.x*30+15; a.y=S.sortie.y*30+15;
	draw_circle(a,15,rouge);
}
void masque_sortie(SLIDER S){
	POINT a;
	a.x=S.sortie.x*30+15; a.y=S.sortie.y*30+15;
	draw_circle(a,15,black);
}

//Le but de la fonction calcul_murs est de calculer les deux points qui vont servir à afficher le mur. C'est deux points sont calculés en fonction
//du sens du mur
void calcul_murs(SLIDER S, POINT *a, POINT *b){
	if(S.murs->sens==0){
		a->x=S.murs->L*30+30; a->y=S.murs->H*30+30;
		b->x=S.murs->L*30; b->y=S.murs->H*30+30;
	}
	if(S.murs->sens==3){
		a->x=S.murs->L*30+30; a->y=S.murs->H*30+30;
		b->x=S.murs->L*30+30; b->y=S.murs->H*30;
	}
	if(S.murs->sens==6){
		a->x=S.murs->L*30+30; a->y=S.murs->H*30;
		b->x=S.murs->L*30;b->y=S.murs->H*30;
	}
	if(S.murs->sens==9){
		a->x=S.murs->L*30; a->y=S.murs->H*30+30;
		b->x=S.murs->L*30; b->y=S.murs->H*30;
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
int collision_bords(SLIDER S, POINT *a){
	int hit=0;
	if (a->x==0) hit=1;
	if (a->x==S.L*30){ 
		hit=1;
		a->x+=-1;
	}
	if (a->y==0) hit=1;
	if (a->y==S.H*30){
		hit=1;
		a->y+=-1;
	}
	return hit;
}

//Pour respecter au mieux la consigne de l longeur des fonctions, j'ai décidé de découper ma fonction testant la collision avec les murs en quatre sous fonctions
//C'est fonction prennent en compte la direction de la flèche appuyée pour un calcul correct de la position du jouer
int collision_mur_vrt_d(SLIDER S, POINT *a){
	int hit=0;
	POINT h,b;
	if(S.murs!=NULL){
		while(S.murs->suiv!=NULL){
			calcul_murs(S,&h,&b);
			if(S.murs->sens==9 || S.murs->sens==3){
				if(a->y==h.y-15 && a->x==h.x){
					hit=1;
					a->x+=-1;
				}
			}
			S.murs=S.murs->suiv;
		}
		calcul_murs(S,&h,&b);
		if(S.murs->sens==9 || S.murs->sens==3){
			if(a->y==h.y-15 && a->x==h.x){
				hit=1;
				a->x+=-1;
			}
		}
	}
	return hit;
}
int collision_mur_vrt_g(SLIDER S, POINT *a){
	int hit=0;
	POINT h,b;
	if(S.murs!=NULL){
		while(S.murs->suiv!=NULL){
			calcul_murs(S,&h,&b);
			if(S.murs->sens==9 || S.murs->sens==3){
				if(a->y==h.y-15 && a->x==h.x){
					hit=1;
					a->x+=1;
				}
			}
			S.murs=S.murs->suiv;
		}
		calcul_murs(S,&h,&b);
		if(S.murs->sens==9 || S.murs->sens==3){
			if(a->y==h.y-15 && a->x==h.x){
				hit=1;
				a->x+=1;
			}
		}
	}
	return hit;
}
int collision_mur_hrz_h(SLIDER S, POINT *a){
	int hit=0;
	POINT g,d;
	if(S.murs!=NULL){
		while(S.murs->suiv!=NULL){
			calcul_murs(S,&d,&g);
			if(S.murs->sens==0 || S.murs->sens==6){
				if(a->x==g.x+15 && a->y==g.y){
					hit=1;
					a->y+=-1;
				}
			}
			S.murs=S.murs->suiv;
		}
		calcul_murs(S,&d,&g);
		if(S.murs->sens==0 || S.murs->sens==6){
			if(a->x==g.x+15 && a->y==g.y){
				hit=1;
				a->y+=-1;
			}
		}
	}
	return hit;
}
int collision_mur_hrz_b(SLIDER S, POINT *a){
	int hit=0;
	POINT g,d;
	if(S.murs!=NULL){
		while(S.murs->suiv!=NULL){
			calcul_murs(S,&d,&g);
			if(S.murs->sens==0 || S.murs->sens==6){
				if(a->x==g.x+15 && a->y==g.y){
					hit=1;
					a->y+=1;
				}
			}
			S.murs=S.murs->suiv;
		}
		calcul_murs(S,&d,&g);
		if(S.murs->sens==0 || S.murs->sens==6){
			if(a->x==g.x+15 && a->y==g.y){
				hit=1;
				a->y+=1;
			}
		}
	}
	return hit;
}
int collision_mur(SLIDER S, POINT *a, int dir){
	int hit=0;
	if(dir==FLECHE_GAUCHE) hit=collision_mur_vrt_g(S,&(*a));
	if(dir==FLECHE_DROITE) hit=collision_mur_vrt_d(S,&(*a));
	if(dir==FLECHE_HAUT) hit=collision_mur_hrz_h(S,&(*a));
	if(dir==FLECHE_BAS) hit=collision_mur_hrz_b(S,&(*a));
	return hit;
}

//Les cases de la grille faisant 30*30 pixels, je déplace mon personnage de 15 en 15 et teste à chaque déplacement si celui ci est entré en collision avec un mur ou
//un bord
SLIDER deplacements_perso(SLIDER S, int dir){
	POINT j;
	S.coups=inser_coup(S.coups,S.joueur.x,S.joueur.y);
	j.x=(S.joueur.x)*30+15; j.y=(S.joueur.y)*30+15;
	masque_joueur(S);
	while(!collision_bords(S,&j) && !collision_mur(S,&j,dir)){
		if(dir==FLECHE_GAUCHE) j.x+=-15;
		if(dir==FLECHE_HAUT) j.y+=15;
		if(dir==FLECHE_DROIT) j.x+=15;
		if(dir==FLECHE_BAS) j.y+=-15;
	}
	S.joueur.x=j.x/30; S.joueur.y=j.y/30;
	return S;
}
SLIDER undo(SLIDER S,char touche){
	POS jprec;
	if(touche=='U' && !est_vide_p(S.coups)){
		S.coups=pile_pop(S.coups,&jprec);
		masque_joueur(S);
		S.joueur.x=jprec.x; S.joueur.y=jprec.y;
	}
	return S;
}
void jouer(SLIDER S){
	int a=-1;
	int arrow=0;
	char touche='c';
	POINT clic;
	while(!victoire(S)){
		a=wait_key_arrow_clic(&touche,&arrow,&clic);
		if(a==1){
			attendre(500);
			S=deplacements_perso(S,arrow);
			affichage(S);
			affiche_all();
		}
		if(a==2){
			S=undo(S,touche);
			affichage(S);
			affiche_all();
		}
	}
}

//Pour bien expliquer les règles, j'ai décidé de faire plusieurs écran avant le jeu qui expliquent au joueur comment jouer
void carton_joueur(){
	POINT a;
	POINT b;
	char *msg="C'est vous";
	char *clic="Cliquez pour continuer";
	a.x=200; a.y=350;
	draw_fill_circle(a,25,blue);
	b.x=250; b.y=360;
	aff_pol(msg,25,b,blanc);
	b.x=350; b.y=50;
	aff_pol_centre(clic,25,b,blanc);
	wait_clic();
	fill_screen(noir);
}
void carton_sortie(){
	POINT a;
	POINT b;
	char *msg="C'est la sortie";
	char *clic="Cliquez pour continuer";
	a.x=200; a.y=350;
	draw_circle(a,25,red);
	b.x=250; b.y=360;
	aff_pol(msg,25,b,blanc);
	b.x=350; b.y=50;
	aff_pol_centre(clic,25,b,blanc);
	wait_clic();
	fill_screen(noir);
}
void carton_mur(){
	POINT a;
	POINT b;
	POINT c;
	char *msg="C'est un mur";
	char *clic="Cliquez pour continuer";
	a.x=200; a.y=375;
	b.x=200; b.y=325;
	draw_line(a,b,red);
	c.x=350; c.y=360;
	aff_pol(msg,25,c,blanc);
	c.x=350; c.y=50;
	aff_pol_centre(clic,25,c,blanc);
	wait_clic();
	fill_screen(noir);
}
void carton_instruction(){
	POINT a;
	POINT b;
	char *msg="Le but: atteindre la sortie";
	char *msg2="Les murs et les bords du terrain bloquent le personnage";
	char *msg3="U=Undo et les fleches pour deplacer le personnage";
	char *clic="Cliquez pour continuez";
	a.x=350; a.y=350;
	aff_pol_centre(msg,25,a,blanc);
	a.x=350; a.y=320;
	aff_pol_centre(msg2,20,a,blanc);
	a.x=350; a.y=290;
	aff_pol_centre(msg3,25,a,blanc);
	b.x=350; b.y=50;
	aff_pol_centre(clic,25,b,blanc);
	wait_clic();
	fill_screen(noir);
}
void carton_debut(){
	carton_joueur();
	carton_sortie();
	carton_mur();
	carton_instruction();
}
void partie(SLIDER S){
	carton_debut();
	affichage(S);
	affiche_auto_off();
	jouer(S);
	libere_mem_liste(S.murs);
	libere_mem_pile(S.coups);
	affiche_auto_on();
}