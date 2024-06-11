#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
fusion(int n1,int n2,int tab3[],int tab1[],int tab2[]){
	int i;
	for(i=0;i<n1;i++){
		tab3[i]=tab1[i];
	}
	for(i=0;i<n2;i++){
		tab3[i+n1]=tab2[i];
	}
	

}
int main(int argc, char *argv[]) {
	int n1,n2,n3,i;
	printf("donner le nombre n 1 tab1 \n");
	printf("n1=");
	scanf("%d",&n1);
	int tab1[n1];
	for(i=0;i<n1;i++){
		printf("T[%d]=",i);
		scanf("%d",&tab1[i]);
	}
	
	
	int ech=0;
	do{
		int ech=0;
		for(i=0;i<n1-1;i++)
		{
			if(tab1[i]>tab1[i+1])
			{
				int tmp;
				tmp=tab1[i];
				tab1[i]=tab1[i+1];
				tab1[i+1]=tmp;
				ech++;
	} } } while(ech>0);
		
		
		for(i=0;i<n1;i++)
	{
		printf("%d \t",tab1[i]);
	}
		printf("\n");


	printf("donner le nombre n 2 tab1 \n");
	printf("n2=");
	scanf("%d",&n2);
	int tab2[n2];
	for(i=0;i<n2;i++){
		printf("T[%d]=",i);
		scanf("%d",&tab2[i]);
	}
	
	
	do{
		int ech=0;
		for(i=0;i<n2-1;i++)
		{
			if(tab2[i]>tab2[i+1])
			{
				int tmp;
				tmp=tab2[i];
				tab2[i]=tab2[i+1];
				tab2[i+1]=tmp;
				ech++;
	} } } while(ech>0);
		
		
		for(i=0;i<n2;i++)
	{
		printf("%d \t",tab2[i]);
	}
	printf("\n");
	
	
	n3=n1+n2;
	int tab3[n3];
	fusion(n1,n2,tab3,tab1,tab2);
	do{
		int ech=0;
		for(i=0;i<n3-1;i++)
		{
			if(tab3[i]>tab3[i+1])
			{
				int tmp;
				tmp=tab3[i];
				tab3[i]=tab3[i+1];
				tab3[i+1]=tmp;
				ech++;
	} } } while(ech>0);
		
		
		for(i=0;i<n3;i++)
	{
		printf("%d \t",tab3[i]);
	}
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
