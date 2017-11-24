#include <stdlib.h>
#include <stdio.h>
struct element{
	int val;
	struct element* suiv;
};

typedef struct element* Liste;

Liste creer_liste(){
	return NULL;
}
int est_vide(Liste l){
	return l==NULL;
}
void affiche(Liste l){
	while(!est_vide(l)){
		printf("%d \n", l->val);
		l=l->suiv;
		//Valeur du 2ème élem: (*(*l).suiv).val = l->suiv->val
	}
}
void affiche_R(Liste l){
	if(!est_vide(l)){
		printf("%d \n",l->val);
		affiche_R(l->suiv);
		//Si on inverse les deux instructions, on affiche la liste dans l'ordre inverse de lecture
	}
}
Liste creer_element(int n){
	Liste l;
	l=malloc(sizeof(struct element));
	if(l==NULL){
		printf("Allocation mémoire échouée \n");
		exit(EXIT_FAILURE);
	}
	l->val=n;
	l->suiv=NULL;
	return l;
}
Liste inser_deb(Liste l, int n){
	Liste lres=creer_element(n);
	lres->suiv=l;
	return lres;
}
Liste libere(Liste l){
	if(!est_vide(l)){
		l->suiv=libere(l->suiv);
		free(l);
	}
	return NULL;
}
Liste inser_fin(Liste l, int n){
	Liste lres=creer_element(n), ldeb=l;
	if (est_vide(l)){
		return lres;
	}
	while(!est_vide(l->suiv)){
		l=l->suiv;
	}
	l->suiv=lres;
	return ldeb;
}
Liste inser_fin_R(Liste l, int n){
	Liste lres;
	if(est_vide(l)){
		lres=creer_element(n);
		return lres;
	}
	l->suiv=inser_fin_R(l->suiv,n);
	return l;
}
int est_tri(Liste l){
	int tri=1;
	while (l->suiv!=NULL){
		if ((l->val) > ((l->suiv)->val)){
			tri=0;
		}
		l=l->suiv;
	}
	return tri;
}
Liste inser_tri(Liste l, int n){
	Liste lres;
	if(est_vide(l)||n<l->val) return inser_deb(l,n);
	while(!est_vide(l->suiv)&&l->suiv->val<n){
		l=l->suiv;
	}
	lres=creer_element(n);
	lres=l->suiv;
	l->suiv=lres;
	return lres;
}
Liste inser_tri_R(Liste l, int n){
	if(est_vide(l) || n<l->val){
		return inser_deb(l,n);
	}
	l->suiv=inser_tri_R(l->suiv,n);
	return l;
}
int nb_elem(Liste l){
	int nb=1;
	if (est_vide(l)){
		nb=0;
	}
	while (l->suiv!=NULL){
		l=l->suiv;
		nb++;
	}
	return nb;
}
int recherche_elem(Liste l, int n){
	int i=0,pos=-1;
	while (l->suiv!=NULL){
		if (l->val==n){
			pos=i;
		}
		l=l->suiv;
		i++;
	}
	return pos;
}
Liste suppr_elem(Liste l, int n){
	printf("Nouvelel Liste: \n");
	Liste lback=l, lprec=l;
	int i=0, test=0;
	while(l->suiv!=NULL){
		if(l->val==n){
			test=1;
			if(l->suiv==lback->suiv){
				l=l->suiv;
				lback=l;
			}
			lprec->suiv=l->suiv;
			printf("L'élément %d a été supprimé \n",n);
		}
		if(i==1){
			lprec=lback;
		}
		if(i>1){
			lprec=l;
		}
		l=l->suiv;
		i++;
	}
	if(test==0){
		printf("Aucun élément n'a été supprimé \n");
	}
	return lback;
}
Liste concatenation(Liste l, Liste m){
	printf("Concaténation des listes \n");
	Liste lback=l;
	while(l->suiv!=NULL){
		l=l->suiv;
	}
	l->suiv=m;
	return lback;
}
Liste fusion_tri(Liste l, Liste m){
	printf("Fusion de listes \n");
	while(m->suiv!=NULL){
		inser_tri_R(l, m->val);
		m=m->suiv;
	}
	inser_tri_R(l,m->val);
	return l;
}
Liste tri_bulle(Liste l){
	int exch=0;
	Liste lpos=l;
	while(l->suiv!=NULL){
		while(lpos->suiv!=NULL){
			if (lpos->val > lpos->suiv->val){
				exch=lpos->val;
				lpos->val=lpos->suiv->val;
				lpos->suiv->val=exch;
			}
			lpos=lpos->suiv;
		}
		l=l->suiv;
		lpos=l;
	}
	return l;
}

/* 
 malloc(nbr octets): adresse ==> Si renoie NULL, allocation à échoué, sinon adresse bien mémorisé
 */
int main(){
	Liste l=creer_liste();
	Liste m=creer_liste();
	int n=10;
	
	l=inser_fin_R(l,32);
	l=inser_deb(l,5);
	l=inser_fin_R(l,64);
	l=inser_deb(l,19);
	l=inser_fin_R(l,57);
	l=inser_fin_R(l,59);
	l=inser_fin_R(l,2);
	l=inser_fin_R(l,167);
	l=inser_fin_R(l,13);
	//affiche_R(l);
	//tri_bulle(l);
	affiche_R(l);
	/*if(est_tri(l)){
		printf("La liste est triée \n");
	}
	else{
		printf("La liste n'est pas triée \n");
	}
	printf("Nombre d'éléments: %d \n",nb_elem(l));
	if(recherche_elem(l,n)==-1){
		printf("L'élément n'est pas dans la liste \n");
	}
	else{
		printf("L'élément se trouve à la position %d \n",recherche_elem(l,n));
	}
	l=suppr_elem(l,n);
	affiche_R(l);
	
	m=inser_fin_R(m,13);
	m=inser_deb(m,7);
	m=inser_fin_R(m,45);
	m=inser_fin_R(m,19);
	concatenation(l,m);
	affiche_R(l);
	fusion_tri(l,m);
	affiche_R(l);
	affiche_R(tri_bulle(l));
	Libération de mémoire: free(adresse)
	l=libere(l);
	m=libere(m);
	*/
	
}
