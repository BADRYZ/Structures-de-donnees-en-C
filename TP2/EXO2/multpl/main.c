#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int l1,c1,c2,l2;
void	multimat(int l1,int c2,int l2,int c1,int m1[l1][c1],int m2[l2][c2],int m3[l1][c2]){
	int i,j,k;
	
	for(i=0;i<l1;i++){
		for(j=0;j<c2;j++){
			m3[i][j]=0;
			for(k=0;k<c1;k++){
				m3[i][j]+=m1[i][k]*m2[k][j];
			}
				}
	}
	

	
	}

int main(int argc, char *argv[]) {
int l1,c1,c2,l2,i,j;
	printf("donner l1=");
	scanf("%d",&l1);
	
	printf("donner c1=");
	scanf("%d",&c1);
	
	
	
	
	printf("\n Matrice 1 \n");
	int m1[l1][c1];
	for(i=0; i < l1; ++i){  
	for(j = 0; j < c1; ++j){
			printf("T[%d][%d]=",i,j);
		      scanf("%d",&m1[i][j]);       

	}
	}
	
	//--------------------------------------------------
	
	printf("donner l2=");
	scanf("%d",&l2);
	
	printf("donner c2=");
	scanf("%d",&c2);
	
	if(c1!=l2){
		printf("-----");
		return 0;
		
	}
	
	
	printf("\n Matrice 2 \n");
	int m2[l2][c2];
	for(i=0; i < l2; ++i){  
	for(j = 0; j < c2; ++j){
			printf("T[%d][%d]=",i,j);
		      scanf("%d",&m2[i][j]);
		}
	}
	
	printf("\n Matrice 1 * Matrice 2 \n");
	int m3[l1][c2];
	multimat(l1,c2,l2,c1,m1,m2,m3);
	int k;
	
	
	
	for(i = 0; i < l1; i++)
  {
    for(j = 0; j < c2; j++) 
    {
      printf("%d\t",m3[i][j]);
    } }
	

	return 0;
}
