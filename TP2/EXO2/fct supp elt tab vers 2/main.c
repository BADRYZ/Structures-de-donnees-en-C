#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int i;
void supp (int tab[],int position,int nbr){
	for (i = position - 1; i < nbr - 1; i++)
         tab[i] = tab[i+1];
}
int main(int argc, char *argv[]) {
	int position, i, nbr,v;
   int tab[100];
 
   printf(" Entrez le nombre des éléments dans le tableau : ");
   scanf("%d", &nbr);
 
   printf(" Entrez les %d éléments : ", nbr);
 
   for (i = 0; i < nbr; i++)
      scanf("%d", &tab[i]);
 
   printf(" Entrez l'emplacement où vous souhaitez supprimer l'élément: ");
   scanf("%d", &position);
   if (position >= nbr+1)
      printf("Suppression impossible.\n");
   else
   {
   	supp (tab,position,nbr);
	   }
   	for (i = 0; i < nbr - 1; i++)
         printf("%4d", tab[i]);
   	
	return 0;
}
