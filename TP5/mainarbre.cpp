#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <math.h> 
#include "arbre.h"
#include "liste.h"
typedef void objet;
typedef int booleen;
//////////////
char* afficher (objet* objet){
return (char*)objet;
}

int comparer(Objet* objet1, Objet* objet2 )
{
	char* p1=(char*) objet1;
	char* p2=(char*) objet2;
return strcmp (p1,p2);
}


Arbre* creeArbre (Noeud* racine, char* (*afficher)(objet*),int (*comparer)(objet*,objet*)){
	Arbre* arbre=(Arbre*) malloc(sizeof(Arbre));
	initArbre(arbre,racine,afficher,comparer);
	return arbre;
}

void initArbre (Arbre* arbre,Noeud* racine,char* (*afficher) (objet*),int (*comparer)(objet*,objet*)){
	arbre->racine=racine;
	arbre->afficher=afficher;
	arbre->comparer=comparer;
}

Noeud* cF (objet* objet){
	return cNd(objet,NULL,NULL);
}

Noeud* cNd(objet* objet,Noeud* gauche,Noeud* droite){
	Noeud* nouveau= (Noeud*) malloc(sizeof(Noeud));
	nouveau->reference=objet;
	nouveau->gauche=gauche;
	nouveau->droite=droite;
	return nouveau;
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

int taille(Noeud* racine){
		if(racine==NULL){	
		return 0;
		}
		
		
		
		else{
				return 1+taille(racine->gauche)+taille(racine->droite);
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
		
Liste* creerListe(int type,char* (*afficher)(objet*),int (*comparer)(objet*,objet*)){
	Liste* li=(Liste*)malloc(sizeof(Liste));
	initListe(li,type,afficher,comparer);
	return li;
}

void insererEnFinDeListe(Liste *li,void *obj){
	insererApres(li,li->dernier,obj);
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


booleen listevide(Liste* li){
return li-> nbElt == 0;
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


void initListe (Liste * li,int type,char* (*afficher)(objet*),int(*comparer)(objet*,objet*)){
	li->premier=NULL;
	li->dernier=NULL;
	li->courant=NULL;
	li->nbElt=0;
	li->type=type;
	li->afficher=afficher;
	li->comparer=comparer;
}


	

////////////////////
int menu () {
printf ("\n\n GESTION D'ARBRES \n\n");
printf ("\n\n ARBRES BINAIRES \n\n");
printf (" 0 - Fin du programme\n");
printf ("\n");
printf (" 1 - Création de l'arbre généalogique\n");
printf (" 2 - Création de l'arbre de l'expression arithmétique\n");
printf ("\n");
printf (" 3 - Parcours préfixé\n");
printf (" 4 - Parcours infixé\n");
printf (" 5 - Parcours postfixé\n");
printf (" 6 – Trouver Noeud \n");
printf (" 7 - Taille \n");
printf (" 8 - Hauteur \n");
printf (" 9 - Parcours en Largeur \n");
printf ("\n");
printf ("Votre choix ? ");
int cod; scanf ("%d", &cod); getchar();
printf ("\n");
return cod;
}

int main(){
	///////////////////////////// 

	
	Arbre *arbregen,*arbreari;
	Noeud *rgen=cNd((char*)"samir\n",cNd((char*)"kamal\n",cNd((char*)"yassine\n",NULL,cNd((char*)"hind\n",NULL,cF((char*)"yasmine\n"))),cNd((char*)"sarah\n",cF((char*)"karim\n"),NULL)),NULL);
	Noeud* rari=cNd((char*)"-\n",cNd((char*)"*\n",cNd((char*)"+\n",cF((char*)"a\n"),cF((char*)"b\n")),cNd((char*)"-\n",cF((char*)"c\n"),cF((char*)"d\n"))),cF((char*)"e\n"));

	
	/////////////////////////////
	
	int cod;
	do{
		cod=menu();
		switch(cod){
			case 0:
   				break ;
   			case 1 ://creation de l’arbre genealogique 
   				arbregen=creeArbre(rgen,afficher,comparer);
   			    break;
			case 2://Création de l'arbre de l'expression arithmétique
				arbreari=creeArbre(rari,afficher,comparer);
				break;
			case 3 ://préfixé
				printf("1-pour afficher arbre genealogique / 2-pour afficher arbre arithmétique ");
				int cpr; scanf("%d",&cpr);
				switch(cpr){
					case 1:
						prefixe(rgen,afficher);
						break;
					case 2:
						prefixe(rari,afficher);
						break;	}
						
			case 4 ://infixé
			{
				printf("1-pour afficher arbre genealogique / 2-pour afficher arbre arithmétique");
				int cin;scanf("%d",&cin);
				switch(cin){
					case 1:
						infixe(rgen,afficher);
					case 2:
						infixe(rari,afficher);
				}
				}
				break;
			case 5:
				{
				printf("1-pour afficher arbre genealogique / 2-pour afficher arbre arithmétique");
				int cpo;scanf("%d",&cpo);
				switch(cpo){
					case 1:
						postfixe(rgen,afficher);
					case 2:
						postfixe(rari,afficher);
						
				}
				break;
			}
			
			case 6:{
				printf("1-rechercher un noeud ds arbre genealogique/2-rechercher un noeud ds arbre arithmétique");
				int cre;scanf("%d",&cre);
				switch(cre){
					case 1:
						{
							printf("donner le noeud chercher");
							char* ng=(char*)malloc(sizeof(char));scanf("%s",ng);
							Noeud* trouve;
							trouve=trouverNoeud(rgen,ng,comparer);
							if(trouve==NULL){
								printf("noeud n existe pas");
							}
							else {
								printf("noeud trouver  ");
							}
							break;
						}
					case 2:{
					    	printf("donner le noeud chercher");
							char* na=(char*)malloc(sizeof(char));scanf("%s",na);
							Noeud* trouve;
							trouve=trouverNoeud(rari,na,comparer);
							if(trouve==NULL){
								printf("noeud n existe pas");
							}
							else {
								printf("noeud trouver  ");
							}
						
						break;
					}
				}
				break;  
			}
			case 7://taille
				{
					printf("1-TAILLE arbre genealogique/2-TAILLE arbre arithmétique");
				int ct;scanf("%d",&ct);
				switch(ct){
					case 1:
						printf("la taille est %d",taille(rgen));
						break;
					case 2:
				  		 printf("la taille est %d",taille(rari));
				 	     break;
				}
	
				}break;
			
			case 8:{
				printf("1-Hauteur arbre genealogique/2-Hauteur arbre arithmétique");
				int ch;scanf("%d",&ch);
				switch(ch){
					case 1:
						printf("la hauteur est %d",hauteur(rgen));
						break;
					case 2:
				  		 printf("la hauteur est %d",hauteur(rari));
				 	     break;
				}
				
				
			}break;
			 case 9://Largeur
			 {
			 	printf("1-parcours arbre genealogique en largeur/2-parcours arbre arithmétique en largeur");
				int cl;scanf("%d",&cl);
				switch(cl){
					case 1: {
						enLargeur(rgen,afficher);
						break;
					}
					
						case 2:{
						enLargeur(rari,afficher);
						break;
					}
			 	
				}
				
			 	
				break;
			 }

				
				}
			
			
				
	}while(cod!=0);
		
	
	
}
