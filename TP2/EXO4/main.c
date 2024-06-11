#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *multichar(char *s, int n){
int i,j;
int l=strlen(s);
char *NVS;
NVS=(char*)calloc(n*l,sizeof(char));
for(i=0;i<l;i++)
{
for(j=0;j<n;j++)
{
NVS[n*i+j]=s[l-1-i];
}
}
NVS[n*l]='\0';
return NVS;
}
int  main()
{
char *multichar(char *s, int n);
int n;
char *s;
s=(char*)calloc(1,sizeof(s));
printf(" Saisissez une chaine de caracteres: ");
scanf("%s",s);
printf(" Saisissez un nombre de repetition de caractere: ");
scanf("%d",&n);
printf(" %s",multichar(s,n));
}


