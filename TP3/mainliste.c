#include<stdio.h>
#include<stdlib.h>
#include "liste.h"

//////////////////////////////////////////////////////////////////////////////////
int comparer (objet* objet1, objet* objet2){
return strcmp ((char*)objet1,(char*)objet2);
}

char* afficher (objet* objet){
return (char*)objet;
}
char * ecrireEntier(void* obj){
	int *entier = (int*) obj;
	char * output = (char*) malloc (sizeof(int));
	snprintf(output,sizeof(int),"%d \n", *entier);
	return output;
}
int comparerInt(void *obj1, void *obj2){
	int *b =(int*) obj2;
	int *a =(int*) obj1;
	if(*a>*b) return 1;
	else if(*a==*b) return 0;
	else return -1;
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

///////////////////////////////////////////////////////////////////////////////////
int menu () {
 printf ("\n\n GESTION D UNE LISTE D ENTIERS \n\n");
 printf ("1 - Creer une liste\n");
 printf ("2 - Insertion en tete de liste \n");
 printf ("3 - Insertion en fin de liste \n");
 printf ("4 - Retrait en tete de liste \n");
 printf ("5 - Retrait en fin de liste \n");
 printf ("6 - Retrait d un objet à partir de sa reference\n");
 printf ("7 - Afficher les objets de la liste \n");
 printf ("8 - Chercher Un objet \n");
 printf ("9 - Destruction de la liste \n");
 printf ("10 - Fin\n");
 printf ("\n");
 printf ("Votre choix ? ");
 int cod;  scanf ("%d", &cod); getchar();
 printf ("\n");
 return cod;
}
int main()
{
	Liste * li=NULL;
	int cod;
	do {
		cod=menu();
		switch(cod){
			case 1:
				li=creerListe(0,afficher,comparer);
			//	li=creerListe(0,ecrireEntier,comparerInt);

				break;
				
				
			case 2:
			
			
				printf("Tapez l'entier a inserer : ");
 				int* itete;
 				itete = (int*) malloc(sizeof(int));
 				scanf("%d",itete);
 				insererEnTeteDeListe(li,itete);
 				break;
			
 				
 				
 				
 			case 3:
 			
 				printf("Tapez l'entier a inserer : ");
 				int* ifin;
 				ifin = (int*) malloc(sizeof(int));
 				scanf("%d",ifin);
 				insererEnFinDeListe(li,ifin);
 				break;
			 
 			
 			
 			case 4 :
 				{
 				int* extete;
				extete = (int*)extraireEnTeteDeListe(li);
				printf("l'objet extrait en tete de liste  est                                             %d\n",*extete);
				break;
				 }
 			
				 
 				
 				
 				
 				
 			case 5:
 				{
 				int* exfin;
 				exfin = (int*)extraireEnFinDeListe(li);
 				if(exfin == NULL) printf("Liste Vide !");
 				else printf("L'element extrait : %d",*exfin);
 				break;
				 }
 			
 			
			 
 			
 			
 			case 6 :
 			
 				printf("Tapez le nombre que vous voulez extraire : "); 
				int objext;
				scanf("%d",&objext);
 				if(extraireUnobjet(li,&objext)==vrai) printf("Le nombre est extrait !!");
 				else printf("L'element n'est pas trouve");
 				break;
			 
 				
 				
 			case 7 :
 				 listerListe(li);
				 break;
				  
				 
			case 8 : 
			    
			    printf("Tapez le nombre a chercher : "); 
				int* objrech; 
				objrech = (int*) malloc(sizeof(int));
				scanf("%d",objrech);
 			    if(chercherUnobjet(li,objrech)) printf("Le nombre est trouve !!");
 				else printf("Le nombre n est trouve !!");
 				break;	
				
 			
 			case 9:
 				
 				detruireListe(li);
				printf("Liste est detruite .");
 				break;

				 
 				
 				

 				
				
		}
	}while(cod!=10);
		
}

