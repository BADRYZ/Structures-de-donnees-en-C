#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

      

int main(int argc, char *argv[]) {
  int n,m;
  int matx1[n][m], matx2[n][m], matx3[n][m];
  int i,j;
  
  printf("les matrices de taille nxm\n");
  printf("n=\n");
  scanf("%d",&n);
  printf("m=\n");
  scanf("%d",&m);
  
  
  printf("\nEntrez la premiere matrice:\n");
  for(i=0; i < n; ++i)
    for(j = 0; j < m; ++j){
    	scanf("%d",&matx1[i][j]);
	}
      
      
  printf("\nEntrez la deuxieme matrice:\n");
  for(i = 0; i < n; ++i)
    for(j = 0; j < m; ++j){
    	scanf("%d",&matx2[i][j]);
	}
      
  
  printf("\n********* Matrice 1 + Matrice 2 *********\n");
  int matrid[n][m];
//  add_mat(n,m,matx1,matx2,matrid);
add_mat( n, m, matx1[n][m], matx2[n][m], matrid[n][m])
{
	
	for(i = 0; i < n; ++i)
  {
  	for(j=0; j < m; ++j){
  		matrid[i][j] = matx1[i][j] + matx2[i][j];
  		
	  }
    
      
  }
  printf("%d ",matrid[i][j]);

  
	return 0;
}
