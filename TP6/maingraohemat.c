#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "graphemat.h"

/////////////////////////
int i,j;


static void razMarque (GrapheMat* graphe){
	for( i=0;i<graphe->n;i++) graphe->marque[i]=faux;
}


GrapheMat* creerGrapheMat(int nMax,int value){
	//allocation de graphe
	GrapheMat* graphe=(GrapheMat*)malloc (sizeof(GrapheMat));
	graphe->n=0;
	graphe->nMax;
	graphe->value;
	graphe->nomS=(NomSom*)malloc(sizeof(NomSom) *nMax);
	graphe->marque=(booleen*)malloc(sizeof(booleen) *nMax);
	graphe->element=(int*)malloc(sizeof(int)*nMax*nMax);
	graphe->valeur=(int*)malloc(sizeof(int)*nMax*nMax);
	//initialisation par defaut
	
	for ( i=0; i<nMax; i++){
		for( j=0;j<nMax;j++){
			graphe->element[i*nMax+j]=faux;
			graphe->valeur[i*nMax+j]=INFINI;
			
		}
	}
	razMarque(graphe);
	return graphe;
}

void deteruireGraphe(GrapheMat* graphe){
	free (graphe->nomS);
		free (graphe->marque);
			free (graphe->element);
				free (graphe->valeur);
					free (graphe);
}


static int rang (GrapheMat* graphe,NomSom nom){
	int i=0;
	booleen trouve=faux;
	while((i<graphe->n) && !trouve){
		trouve=strcmp(graphe->nomS[i],nom)==0;
		if(!trouve) i++;
	}
	return trouve ? i : -1;
}



void ajouterUnSommet(GrapheMat* graphe,NomSom nom){
	if(rang (graphe,nom)==-1){
		if(graphe->n < graphe->nMax){
			strcpy(graphe->nomS[graphe->n++],nom);
			
		}else{
			printf("\nNombre de sommets > %d\n",graphe->nMax);
		}
	}else {
		printf("\n%s deja defini\n",nom);
	}
}

void ajouterUnArc(GrapheMat* graphe,NomSom somD,NomSom somA,int cout){
	int nMax=graphe->nMax;
	int rd=rang(graphe,somD);
	int rg=rang(graphe,somA);
	graphe->element[rd*nMax+rg] = vrai;
	graphe->valeur[rd*nMax+rg] = cout;
}

void ecrireGraphe(GrapheMat* graphe){
	int nMax= graphe->nMax;
	for ( i=0;i<graphe->n;i++) printf("%s",graphe->nomS[i]);
	printf(";\n");
	for( i=0;i<graphe->n;i++){
		printf("\n%s:",graphe->nomS[i]);
		for( j=0;j<graphe->n;j++){
			if(graphe->element[i*nMax+j]==vrai){
							printf("%s",graphe->nomS[j]);
										if(graphe->value){
															printf("(%d)",graphe->valeur[i*nMax+j]);




			};
			}
		}
		printf(";");
	}
	
}
//////////////////////////////
/*static void profondeur(GrapheMat* graphe, int numSommet) {
int nMax = graphe->nMax;
graphe->marque [numSommet] = vrai;
printf ("%s\n", graphe->nomS [numSommet]);

for ( i=0; i<graphe->n; i++) {
if ( (graphe->element [numSommet*nMax+i] == vrai)
&& !graphe->marque [i] ) {
profondeur(graphe, i);
}
}
}

static void initMarque(GrapheMat* graphe) {
for ( i=0; i<graphe->n; i++) graphe->marque [i] = faux;
}

void parcoursProfond(GrapheMat* graphe) {
initMarque (graphe);
for ( i=0; i<graphe->n; i++) {
if (!graphe->marque [i]) profondeur (graphe, i);
}
}*/



int menu(){
	printf("*******************>>>>>GRAPHES<<<<<*******************");
	printf ("\n \n");
	printf("0-Fin\n");
	printf("1- Creer graphe\n");
	printf("2-Detruire graphe\n");
	printf("3-Ajouter un sommet\n");
	printf("4-Ajouter un arc\n");
	printf("5-Ecrire graphe\n");
	printf("6-Parcourir en profondeur\n");
	printf ("\n \n");
	printf("votre choix?");
	int cod; scanf("%d",&cod);
	return cod;
	
	
}


int main(){
	GrapheMat* G1;
	int cod;
	do{
		cod=menu();
		switch(cod){
			case 0:
				break;
			case 1:{
				G1=creerGrapheMat(4,0);
				
				break;
			}
			
			case 2:
				{
					deteruireGraphe(G1);
					break;
				}
			case 3:{
				printf("donner som ajoute\n");
				NomSom S;
				scanf("%d",S);
				ajouterUnSommet(G1,S);
				break;
			}
			
			case 4:{
				NomSom S1,S2;
				int arc;
				printf("donner som 1==");
				scanf("%d",&S1);
				printf("donner som 2==");
				scanf("%d",&S2);
				printf("donner arc==");
				scanf("%d",&arc);
				ajouterUnArc(G1,S1,S2,arc);
				break;
			}
			case 5:{
				ecrireGraphe(G1);
				break;
				
			}
			case 6:{
				printf("fonction n existe pas\n");
			//	parcoursProfond(G1);
				break;
			}
			
		}
	}while(cod!=0);
	
	
	
	
	
	
	
	
	
	
}
