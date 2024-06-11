#include <stdio.h>
#include <stdlib.h>
#define n 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void insr(int tab[],int taille,int pos, int m){
	int i;
	for(i=taille;i>=pos;i--){
			tab[i]=tab[i-1];
		}
		tab[pos-1]=m;
		taille++;
	
	printf("apres ");
	for(i=0;i<taille;i++){
		printf("%d\t",tab[i]);
		
	}
}
int main(int argc, char *argv[]) {
	
	int tab[n],i,pos,m,taille;
	printf("donner la taille du tab");
	scanf("%d",&taille);
	printf("donner les element");
	for(i=0;i<taille;i++){
		printf("tab[%d]=",i+1);
		scanf("%d",&tab[i]);
	}
	printf("la val inserer");
	scanf("%d",&m);
	
	printf("position");
	scanf("%d",&pos);
	
	if(pos<=0 || pos>taille+1){
		printf("errer");
	}
	else {
		insr(tab,taille,pos,m);
	}
		
	
	return 0;
}
