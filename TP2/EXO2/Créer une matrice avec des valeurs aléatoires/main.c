#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void remplissage(int n,int m){
	int i,j,matrice[n][m];
		for(i=0;i<n;i++)
				{	for(j=0;j<m;j++)
								{
									matrice[i][j]=rand() ;	}	}	}

int main(int argc, char *argv[]) {
	int n,m,i,j;
	printf("donner n lignes");
	scanf("%d",&n);
	printf("donner m colomnes");
	scanf("%d",&m);
    int *mat=malloc(sizeof(int [n][m]));
//	int mat[n][m];
	remplissage(n,m);	
	
	for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
	 	printf("\n matrice[%d][%d]= %d",i,j,(mat+i,mat+j));
		}
	}
	
	
	return 0;
}
