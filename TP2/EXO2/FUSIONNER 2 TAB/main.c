#include <stdio.h>
#include <stdlib.h>
#define taille1  10
#define taille2  10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void fusi(int fus[],int t1[],int t2[],int n1,int n2){
int m=n1+n2,i;
fus[m];
for(i=0;i<n1;i++) { fus[i]=t1[i];}
for(i=0;i<n2;i++) { fus[i+n1]=t2[i];}
}

/*void tri(int tab[],int taille){	
    int cmp;
	do{
		int i;
		int cmp=0;
		for(i=0;i<taille-1;i++)
		{
			if (tab[i]>tab[i+1])
			{
				int tmp;
				tmp=tab[i];
				tab[i]=tab[i+1];
				tab[i+1]=tmp;
				cmp++;
			}
		}
		
	}while(cmp!=0);
}*/



int main(int argc, char *argv[]) {
	
  int i,n1,n2,m,cmp;
 
  int t1[taille1],t2[taille2];
 
  printf("saisir la taille tu premier tableau.\n");
 
  scanf("%d",&n1);
 
  printf("saisir la taille du 2eme tableau.\n");
 
  scanf("%d",&n2);
 
  printf("saisir les elements du 1er tableau.\n");
 
  for(i=0;i<n1;i++) {
                              scanf("%d",&t1[i]);
                   }
  printf("saisir les elements du 2eme tableau.\n");
 
  for(i=0;i<n2;i++) {
                              scanf("%d",&t2[i]);
                    }
//tri(t1,n1);

	do{
		int i;
		int cmp=0;
		for(i=0;i<n1-1;i++)
		{
			if (t1[i]>t1[i+1])
			{
				int tmp;
				tmp=t1[i];
				t1[i]=t1[i+1];
				t1[i+1]=tmp;
				cmp++;
			}
		}
		
	}while(cmp!=0);
 
//tri(t2,n2);
	do{
		int i;
		int cmp=0;
		for(i=0;i<n2-1;i++)
		{
			if (t2[i]>t2[i+1])
			{
				int tmp;
				tmp=t2[i];
				t2[i]=t2[i+1];
				t2[i+1]=tmp;
				cmp++;
			}
		}
		
	}while(cmp!=0);
 
printf("le 1er tableau trié.\n");
 
for(i=0;i<n1;i++) printf("d\n",t1[i]);
 
printf("le 2eme tableau trie.\n");
 
for(i=0;i<n2;i++) printf("d\n",t2[i]);

int fus[m];

fusi(fus,t1,t2,n1,n2);
 
//m=n1+n2;
//int fus[m];
//for(i=0;i<n1;i++) { fus[i]=t1[i];
//                    }
//for(i=0;i<n2;i++) { fus[i+n1]=t2[i];
//                  }

//tri(fus,m);
	do{
		int i;
		int cmp=0;
		for(i=0;i<m-1;i++)
		{
			if (fus[i]>fus[i+1])
			{
				int tmp;
				tmp=fus[i];
				fus[i]=fus[i+1];
				fus[i+1]=tmp;
				cmp++;
			}
		}
		
	}while(cmp!=0);


 
printf("Tableau fusionne\n");
 
for(i=0;i<m;i++) printf("d",fus[i]);
 
printf("\n");

 

 

	return 0;
}
