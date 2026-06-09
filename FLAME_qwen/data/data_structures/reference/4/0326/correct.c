#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct word{
char w[100];
int num;
}a[5000]; 

void sort( int cnt)
{
    int k, j;
    struct word tmp;
    for(k=0; k<cnt-1; k++)
        for(j=0; j<cnt-1-k; j++){
                 if(strcmp(a[j].w,a[j+1].w)>0){
                tmp = a[j];
	           a[j] = a[j+1];
                a[j+1] = tmp;        //小的前移
            }
        }
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char c;
	int i=0,j=0,k=0;
	while((c=fgetc(in))!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			a[i].w[j]=c-'A'+'a';
			a[i].num=1;
			j++;
		}
		else if(c>='a'&&c<='z')
		{
			a[i].w[j]=c;
			a[i].num=1;
			j++;
		}
		else 
		{
			i++;
			j=0;
		}
	}
	sort(i);
j=1;
	while(j<i)
	{
		if(a[k].w[0]<'a'||a[k].w[0]>'z')
		{
			a[k].num=0;
			k++;
			j=k+1;
		}
		if(strcmp(a[k].w,a[j].w)==0)
		{
			a[k].num++;
			a[j].num=0;
		}
		else
		{
			k=j;}
			j++;
	}
	for(j=0;j<=i-1;j++)//有空的结构体 
	{
		if(a[j].num!=0)
		{ 
			printf("%s %d\n",a[j].w,a[j].num);
		}
	}
	return 0;
 } 

