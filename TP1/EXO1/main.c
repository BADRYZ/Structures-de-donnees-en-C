

//  exercice 1  TP 1 // recherche du max

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
//	variables
int n,i=0,max;
// declaration 
printf("donner le nombre n des entiers\n");
printf("n=");
scanf("%d",&n);
int *p=(int*)malloc(n*sizeof(int));
// remplisage
while(i<n){
	*(p+i)=rand();
	i++;
}
//tri le max
max=*p;
for(i=1;i<n;i++)
{
	if (*(p+i)>max){
		max=*(p+i);
	}
	
}
printf("le max des entiers est :%d",max);
free(p);

	return 0;
}
