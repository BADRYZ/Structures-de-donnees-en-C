#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void inverser(int t[],int n){
	int i,temp;
	 while(i<n/2)
 {
 temp = t[i];
 //n-1 parce que le tableau commence par 0
 t[i]=t[n-1-i];
 t[n-1-i]=temp;
 i++;
 }
}
int main(int argc, char *argv[]) {
	
	int i,n,temp;
 
 	printf("Taille du tableau "); 
 	scanf("%d",&n);
 	int t[n];
 
 	for(i=0;i<n;i++)
 	{
 	printf("t[%d]=",i);
 	scanf("%d",&t[i]);
 	}
 	i=0;
 	//
 	inverser(t,n);
 	printf("\nTableau inverse: \n");
 	for(i=0;i<n;i++)
	 {
 	printf("\nt[%d]=%d",i,t[i]);
 	}
	
	
	
	
	
	
	
	
	
	return 0;
}
