#include <stdio.h>
#include <string.h>
#include "personne.h"
#include "liste.h"
typedef int booleen;

int comparerPersonne(Objet* objet1,Objet* objet2){
	Personne* p1=(Personne*)objet1;
	Personne* p2=(Personne*)objet2;
	return strcmp(p1->nom,p2->nom);
}
char* ecrirePersonne(Objet* objet){
	Personne* p =(Personne*) objet;
	char* output =(char*)malloc (sizeof(Personne));
	
	snprintf(output,sizeof(Personne),"%s %s\n",p->nom,p->prenom);
	return output;
	
}
Personne* creerPersonne(char* nom,char* prenom){
	Personne* p= malloc (sizeof(Personne));
	strcpy(p->nom, nom);
	strcpy(p->prenom,prenom);
	return p;
}
Liste* creerListe(int type,char* (*afficher)(objet*),int (*comparer)(objet*,objet*)){
	Liste* li=(Liste*)malloc(sizeof(Liste));
	initListe(li,type,afficher,comparer);
	return li;
}
void initListe (Liste * li,int type,char* (*afficher)(objet*),int(*comparer)(objet*,objet*)){
	li->premier=NULL;
	li->dernier=NULL;
	li->courant=NULL;
	li->nbElt=0;
	li->type=type;
	li->afficher=afficher;
	li->comparer=comparer;
} 
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
static void insererApres(Liste *li,Element *precedent,objet* objet){
	if(precedent==NULL){
		insererEnTeteDeListe(li,objet);
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

void insererEnFinDeListe(Liste *li,void *obj){
	insererApres(li,li->dernier,obj);
}

objet* extraireEnTeteDeListe (Liste* li){
	Element* extrait=li->premier;
	if(!listevide(li)){
		li->premier=li->premier->suivant;
		if(li->premier==NULL) li->dernier=NULL;
		li->nbElt--;
		
	}
	return extrait !=NULL ? extrait->reference : NULL;
}

booleen listevide(Liste* li){
return li-> nbElt == 0;
}

static void * extraireApres(Liste *li,Element *precedent){
	if (precedent ==NULL){
		return extraireEnTeteDeListe(li);
	}
	else{
		Element *extrait=precedent->suivant;
		if (extrait!=NULL){
			precedent->suivant=extrait->suivant;
			if(extrait==li->dernier) li->dernier=precedent;
			li->nbElt--;
		}
		return extrait != NULL? extrait->reference :NULL;
	}
}

objet* extraireEnFinDeListe(Liste *li ){
	objet *extrait;
	if(listevide(li)){
		extrait=NULL;
	}else if (li->premier==li->dernier){
		extrait = extraireEnTeteDeListe(li);
	}else {
		Element *ptc = li->premier;
		while(ptc->suivant !=li->dernier) ptc=ptc->suivant;
		extrait = extraireApres(li,ptc);
	}
	return extrait;
}

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
static Element* elementCourant (Liste* li){
	Element *ptc=li->courant;
	if(li->courant != NULL){
		li->courant=li->courant->suivant;
	}
	return ptc;
}
void ouvrireListe(Liste * li){
	li->courant=li->premier;
}
booleen finListe(Liste *li){
	return li->courant==NULL;
}
void listerListe(Liste* li){
	ouvrireListe(li);
	while(!finListe(li)){
		objet* objet=objetCourant(li);
		printf("%s\n",li->afficher(objet));
	}
}

objet* objetCourant (Liste *li){
	Element *ptc = elementCourant(li);
	return ptc==NULL ? NULL : ptc->reference;
}

objet* chercherUnobjet(Liste* li,objet* objetCherche){
	booleen trouve = faux;
	objet* objet;
	ouvrireListe(li);
	while(!finListe(li) && !trouve){
		objet=objetCourant(li);
		trouve =li->comparer(objetCherche,objet)==0;
	}
	return trouve ? objet:NULL;
} 

void detruireListe(Liste *li){
	ouvrireListe(li);
	while(!finListe(li)){
		Element *ptc =elementCourant(li);
		free(ptc);
	}
	initListe(li,0,NULL,NULL);
}





///////////////////////////////////////////////////////
int menu () {
 printf ("\n\nGESTION D'UNE LISTE DE PERSONNES\n\n");
 printf ("0 - Fin\n");
 printf ("1 - Insertion en tête de liste\n");
 printf ("2 - Insertion en fin de liste\n");
 printf ("3 - Retrait en tête de liste\n");
 printf ("4 - Retrait en fin de liste\n");
 printf ("5 - Retrait d'un élément à partir de son nom\n");
 printf ("6 - Parcours de la liste\n");
 printf ("7 - Recherche d'un élément à partir de son nom\n");
 printf ("8 - Destruction de la liste\n");
 printf ("\n");
 printf ("Votre choix ? ");
 int cod; scanf ("%d", &cod);
 printf ("\n");
 return cod;
}
int main(){
	Liste* lp=creerListe(0,ecrirePersonne,comparerPersonne);
	booleen fini=faux;
	while(!fini){
		switch(menu()){
			case 0:
				fini=vrai;
				break;
			
			case 1:{
				printf("nom de la personne a creer?");
				ch15 nom ;
				scanf("%s",nom);
				printf("prenom de la personne a creer?");
				ch15 prenom;
				scanf("%s",prenom);
				Personne* nouveau = creerPersonne(nom,prenom);
				insererEnTeteDeListe(lp,nouveau);
				break;
			}
			
			case 2:
				{
				printf("nom de la personne a creer?");
				ch15 nom ;
				scanf("%s",nom);
				printf("prenom de la personne a creer?");
				ch15 prenom;
				scanf("%s",prenom);
				Personne* nouveau= creerPersonne(nom,prenom);
				insererEnFinDeListe(lp,nouveau);
				break;
				}
				
			case 3:
				{
					Personne* extrait=(Personne*) extraireEnTeteDeListe(lp);
					if(extrait != NULL){
						printf("element %s %s extrait en tete de liste",	extrait->nom,extrait->prenom);
						
					}
					else{
						printf("liste vide");
					}
					break;
				}
				
						
			case 4:
				{
					Personne* extrait=(Personne*) extraireEnFinDeListe(lp);
					if(extrait != NULL){
						printf("element %s %s extrait en fin de liste",	extrait->nom,extrait->prenom);
						
					}
					else{
						printf("liste vide");
					}
					break;
					
				}
				
			case 5:
				{
					printf("nom de la personne a extraire?");
					ch15 nom;scanf("%s",nom);
					Personne* cherche=creerPersonne(nom,"?");
					Personne* pp=(Personne*) chercherUnobjet(lp,cherche);
					if(extraireUnobjet(lp,pp)){
						printf("element %s %s extrait de la liste",pp->nom,pp->prenom);
					}
					break;
					
				}
			case 6 :
				listerListe(lp);
				break;
			
			case 7:
				{
					printf("nom de la personne recherchee?");
					ch15 nom;scanf("%s",nom);
					Personne* cherche=creerPersonne(nom,"?");
					Personne* pp=(Personne*) chercherUnobjet(lp,cherche);
					if(pp != NULL){
						printf("%s %s trouvee dans la liste\n",pp->nom,pp->prenom);
						
					}else{
						printf("%s innconnue dans la liste\n",nom);
					}
					break;
				}
				
			case 8:
				detruireListe(lp);
				break;
				
				
			
			
		}
	}
}
