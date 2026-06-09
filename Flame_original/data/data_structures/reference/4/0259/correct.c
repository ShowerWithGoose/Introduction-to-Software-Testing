#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
void bubbleSort(char a[][105], int n);
int main()
{
	int i=0,j=0,l=0,k,p;
	char ch;
	char a[105][105]={};
	int n[105]={};
	FILE *fr;
	fr=fopen("article.txt","r");
	ch=fgetc(fr);
	while(ch!=EOF)
	{
		if(isalpha(ch))
		{
		a[i][j]=tolower(ch);
		j++;
		}
		else
		{
		a[i][j]='\0';
		i+=1;
		j=0;	
		}
	ch=fgetc(fr);
	}
l=i+1;
bubbleSort(a,l);
for(i=j=0;i<=l;i++)
{
	if(a[i][j]=='\0')
	continue;
	else
	break;}
printf("%s",a[i]);
k=1;	
p=i;
for(i=p+1;i<=l;i++)
{

	if(strcmp(a[i],a[i-1])==0)
	k+=1;
	else if(strcmp(a[i],a[i-1])!=0){
	printf(" %d\n",k);
	k=1;
	printf("%s",a[i]);	
	}
}
fclose(fr); 
return 0;
}


void bubbleSort(char a[][105], int n)
{ int i,j;
char hold1[105]={};
for( i = 0; i < n-1; i++)
 {
 for(j = i+1; j < n; j++)
 {
 if(strcmp(a[i],a[j])>0)
 { strcpy(hold1,a[j]);
   strcpy(a[j],a[i]);  
   strcpy(a[i],hold1);
 }}	
  }} 
 



