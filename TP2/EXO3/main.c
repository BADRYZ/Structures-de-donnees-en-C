#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void suite(int n){
	int k[n],i;
	printf("%d",k[0]=0);
	for (i=0;i<n;i++){
		k[i+1]=3*k[i]*k[i]+2*k[i]+1;
		printf("%d\n",k[i+1]);
		
	}
}





int main(int argc, char *argv[]) {
	int n;
	printf("donner n= ");
	scanf("%d",&n);
	suite(n);
	
	
	
	
	return 0;
}
