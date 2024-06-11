#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


//fonction dech
	 int chercher_dich(int tab[],int n,int cle)
	{
		int i;
		int d=1;
		int f=n;
		int trouve=0;
		do{
			i=((d+f)/2);
			if (tab[i]==cle)
			{
				trouve=1;
			}
			else if(tab[i]<cle)   
				{
					d=i+1;
				}
				else {
					f=i-1;
				}
			
		}while(trouve==0);
		return i;
	}
int main(int argc, char *argv[]) {
	
	int tab[10]={1,7,8,9,12,15,18,22,30,31};
	printf("la cle 30 se trouve a la position %d du tab ",chercher_dich(tab,10,30));
	
	

	return 0;
}
