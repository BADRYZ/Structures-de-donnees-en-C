#include<stdio.h>
#include<stdlib.h>
#include "liste.h"

#define faux  0
#define vrai 1
typedef void objet;
typedef int booleen;

//initialiser la liste pointee pa li 
void initListe (Liste * li,int type,char* (*afficher)(objet*),int(*comparer)(objet*,objet*)){
	li->premier=NULL;
	li->dernier=NULL;
	li->courant=NULL;
	li->nbElt=0;
	li->type=type;
	li->afficher=afficher;
	li->comparer=comparer;
}


//CREATION DUNE LISTE


Liste* creerListe(int type,char* (*afficher)(objet*),int (*comparer)(objet*,objet*)){
	Liste* li=(Liste*)malloc(sizeof(Liste));
	initListe(li,type,afficher,comparer);
	return li;
}



// vérifier si la liste est vide
booleen listevide(Liste* li){
return li-> nbElt == 0;
}






int nbElement(Liste * li){
	return li->nbElt;
}


//AJOUT EN TETE DE LISTE
static Element* creerElement(){
	return (Element *)malloc(sizeof(Element));
}


void insererEnTeteDeListe(Liste * li,objet * objet){
	Element * nouveau=creerElement();
	nouveau->reference=objet;
	nouveau->suivant=li->premier;
	li->premier=nouveau;
	if(li->dernier==NULL) li->dernier=nouveau;
	li->nbElt++;
}



//ajout apres lelement precedent
// insert dans la liste li,objet apres precendent
//si precedent est NULL,inserer en tet de liste
static void insererApres(Liste *li,Element *precedent,objet* objet){
	if(precedent==NULL){
		insererEnTeteDeliste(li,objet);
	}
	else{
		Element* nouveau=creerElement();
		nouveau->reference=objet;
		nouveau->suivant=precedent->suivant;
		precedent->suivant=nouveau;
		if(precedent==li->dernier) li->dernier=nouveau;
		li->nbElt++;
	}
}
//ajout en fin de liste
void insererEnFinDeListe(Liste *li,void *obj){
	insererApres(li,li->dernier,obj);
}

//void insererEnFinDeListe(Liste *li,objet *objet){
//	insererApres(li,li->dernier,objet);
//}


//se positionner sur le premier element de la liste li
void ouvrireListe(Liste * li){
	li->courant=li->premier;
}





booleen finListe(Liste *li){
	return li->courant==NULL;
}




//courant elemt
static Element* elementCourant (Liste* li){
	Element *ptc=li->courant;
	if(li->courant != NULL){
		li->courant=li->courant->suivant;
	}
	return ptc;
}



//objet courant
objet* objetCourant (Liste *li){
	Element *ptc = elementCourant(li);
	return ptc==NULL ? NULL : ptc->reference;
}


//lister liste(liste* li)
void listerListe(Liste* li){
	ouvrireListe(li);
	while(!finListe(li)){
		objet* objet=objetCourant(li);
		printf("%s\n",li->afficher(objet));
	}
}



//chercher un objet
objet* chercherUnobjet(Liste* li,objet* objetCherche){
	booleen trouve = faux;
	objet* objet;
	ouvrirListe(li);
	while(!finListe(li) && !trouve){
		objet=objetCourant(li);
		trouve =li->comparer(objetCherche,objet)==0;
	}
	return trouve ? objet:NULL;
} 




//retrait  en tete de liste
objet* extraireEnTeteDeListe (Liste* li){
	Element* extrait=li->premier;
	if(!listeVide(li)){
		li->premier=li->premier->suivant;
		if(li->premier==NULL) li->dernier=NULL;
		li->nbElt--;
		
	}
	return extrait !=NULL ? extrait->reference : NULL;
}
//retrait de elt qui suit elet precedent 

static objet* extraireApres(Liste* li, Element *precedent){
	if(precedent==NULL){
		return extraireEnTeteDeListe(li);
	}else{
        Element *extrait=precedent->suivant;
		if(extrait != NULL){
			precedent->suivant=extrait->suivant;
			if(extrait==li->dernier) li->dernier=precedent;
			li->nbElt--;
		}
		return extrait !=NULL ? extrait->reference :NULL;
	}
}




// retrait de lobjet en fin de liste
objet* extraireEnFinDeListe(Liste *li ){
	objet *extrait;
	if(listeVide(li)){
		extrait=NULL;
	}else if (li->premier==li->dernier){
		extrait = extraireEnTeteDeListe(li);
	}else {
		Element *ptc = li->premier;
		while(ptc->suivant !=li->dernier) ptc=ptc->suivant;
		extrait=extraireApres (li,ptc);
	}
	return extrait;
}



//retrait dun objet a partir de sa reference
booleen extraireUnobjet (Liste *li,objet *objet){
	Element* precedent=NULL;
	Element* ptc =NULL;
	booleen trouve = faux;
	
	ouvrireListe(li);
	while(!finListe(li) && !trouve){
		precedent =ptc;
		ptc=elementCourant(li);
		trouve=(ptc->reference==objet) ? vrai:faux;
	}
	if(!trouve) return faux;
    void* extrait = extraireApres(li,precedent);
  	return vrai;
}


void detruireListe(Liste *li){
	ouvrirListe(li);
	while(!finListe(li)){
		Element *ptc =elementCourant(li);
		free(ptc);
	}
	initListe(li,0,NULL,NULL);
}
//////////////////////////
int comparer (objet* objet1, objet* objet2){
return strcmp ((char*)objet1,(char*)objet2);
}

char* afficher (objet* objet){
return (char*)objet;
}
//////////////////////////////
//////////////////////////////////

