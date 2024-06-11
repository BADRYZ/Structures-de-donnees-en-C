#include<stdio.h>
#include<stdlib.h>
#include <math.h> 
#include "arbre.h"
#include "liste.h"




Noeud* cNd(objet* objet,Noeud* gauche,Noeud* droite){
	Noeud* nouveau= (Noeud*) malloc(sizeof(Noeud));
	nouveau->reference=objet;
	nouveau->gauche=gauche;
	nouveau->droite=droite;
	return nouveau;
}

Noeud* cF (objet* objet){
	return cNd(objet,NULL,NULL);
}

void initArbre (Arbre* arbre,Noeud* racine,char* (*afficher) (objet*),int (*comparer)(objet*,objet*)){
	arbre->racine=racine;
	arbre->afficher=afficher;
	arbre->comparer=comparer;
}
Arbre* creeArbre (Noeud* racine, char* (*afficher)(objet*),int (*comparer)(objet*,objet*)){
	Arbre* arbre=(Arbre*) malloc(sizeof(Arbre));
	initArbre(arbre,racine,afficher,comparer);
	return arbre;
}

void prefixe (Noeud* racine,char* (*afficher)(objet*)){
	if(racine != NULL){
		printf("%s",afficher(racine->reference));
		prefixe(racine->gauche,afficher);
		prefixe(racine->droite,afficher);
	}
}


void infixe (Noeud* racine,char*(*afficher)(objet*)){
	if(racine != NULL){
		infixe(racine->gauche,afficher);
		printf("%s",afficher(racine->reference));
		infixe(racine->droite,afficher);
	}
}

void postfixe(Noeud* racine , char* (*afficher)(objet*)){
	if(racine != NULL){
		postfixe(racine->gauche,afficher);
		postfixe(racine->droite,afficher);
		printf("%s",afficher(racine->reference));
	}
}

Noeud* trouverNoeud (Noeud* racine, Objet* objet,int(*comparer)(Objet*,Objet*))
{
	Noeud* pNom;
	if (racine==NULL){
		pNom=NULL;
	}
	else if(comparer(racine->reference,objet)==0){
		pNom=racine;
	}
	else{
		pNom=trouverNoeud(racine->droite,objet,comparer);
	}
	return pNom;
}

void enLargeur(Noeud* racine,char* (*afficher) (objet*)){
	Liste* li=creerListe(0,NULL,NULL);
	insererEnFinDeListe(li,racine);
	while(!listevide(li)){
		Noeud* extrait=(Noeud*)extraireEnTeteDeListe(li);
		printf("%s",afficher (extrait->reference));
		if(extrait->gauche!=NULL)insererEnFinDeListe(li,extrait->gauche);
		if(extrait->droite!=NULL)insererEnFinDeListe(li,extrait->droite);
	}
		}
	
	int taille(Noeud* racine){
		if(racine==NULL){	
		return 0;
		}
		
		
		
		else{
				return 1+taille(racine->gauche)+taille(racine->droite);
		}
		
	}
	
		
		
	
		

	
	booleen estFeuille (Noeud* racine){
		return (racine->gauche==NULL) && (racine->droite==NULL);
	}
	
	int nbFeuilles (Noeud* racine){
		if(racine==NULL){
			return 0;
		}
		else if(estFeuille(racine)){
			return 1;
		}
		else {
			return nbFeuilles (racine->gauche)+nbFeuilles (racine->droite);
		}
	}
	
	void listerFeuilles (Noeud* racine,char* (*afficher)(objet*)){
		if (estFeuille (racine)){
			printf("%s",afficher(racine->reference));
		}
		else{
			listerFeuilles(racine->gauche,afficher);
			listerFeuilles(racine->droite,afficher);
			
		}
	}
	
	
	int hauteur (Noeud* racine){
		if(racine==NULL){
			return 0;
		}
		else{
			return 1+fmax(hauteur(racine->gauche),hauteur(racine->droite));
		}
	}
	




booleen egaliteArbre (Noeud* racine1,Noeud* racine2,int (*comparer)(objet*,objet*)){
	booleen resu=faux;
	if((racine1==NULL) && (racine2==NULL)){
		resu=vrai;
	}
	else if((racine1!=NULL)&&(racine2!=NULL)){
		if(comparer(racine1->reference,racine2->reference)==0){
			if(egaliteArbre(racine1->gauche,racine2->gauche,comparer)){
				resu=egaliteArbre(racine1->droite,racine2->droite,comparer);
			}
		}
	}
	return resu;
}
