#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//variable
	int i=0,n,ech=0;
	//declaration
	printf("donner le nombre n des entiers\n");
	printf("n=");
	scanf("%d",&n);
	int *p=(int*)malloc(n*sizeof(int));
	// remplisage
	while(i<n){
	*(p+i)=rand();
	i++;
	}
	printf("affichage avant tri\n");
	printf("\n");
	// affichage avant tri
	for(i=0;i<n;i++)
	{
		printf("%d \t",*(p+i));
	}
	
	//tri a bulle
	do{
		int ech=0;
		for(i=0;i<n-1;i++)
		{
			if(*(p+i)>*(p+i+1))
			{
				int tmp;
				tmp=*(p+i);
				*(p+i)=*(p+i+1);
				*(p+i+1)=tmp;
				ech++;
			}
		}
		
	}while(ech>0);
	printf("\n");
	printf("affichage apres tri\n");
	printf("\n");
	
	// affichage apres tri
	for(i=0;i<n;i++)
	{
		printf("%d \t",*(p+i));
	}
	
	
	
	
	
	
	
	return 0;
}
