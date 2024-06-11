#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void	addmat(int l,int c,int m1[l][c],int m2[l][c],int m3[l][c]){
	int i,j;
	for(i=0;i<l;i++)
	{
	for(j=0;j<c;j++)
	{
	m3[i][j]=m1[i][j]+m2[i][j];
	}
	}

}

int main(int argc, char *argv[]) {
	int l,c,i,j;
	printf("donner l=");
	
	scanf("%d",&l);
	printf("donner c=");
	
	scanf("%d",&c);
	
	
	
	
	printf("\n Matrice 1 \n");
	int m1[l][c];
	for(i=0; i < l; ++i){  
	for(j = 0; j < c; ++j){
			printf("T[%d][%d]=",i,j);
		      scanf("%d",&m1[i][j]);       

	}
	}
	printf("\n Matrice 2 \n");
	int m2[l][c];
	for(i=0; i < l; ++i){  
	for(j = 0; j < c; ++j){
			printf("T[%d][%d]=",i,j);
		      scanf("%d",&m2[i][j]);
		}
	}
	
	printf("\n Matrice 1 + Matrice 2 \n");
	int m3[l][c];
	addmat(l,c,m1,m2,m3);
   for(i=0;i<l;i++)
	{
	for(j=0;j<c;j++)
	{
	printf("%d ",m3[i][j]);
	}
	}
	
	

	
	
	
	
	
	
	
	
	
	return 0;
}
