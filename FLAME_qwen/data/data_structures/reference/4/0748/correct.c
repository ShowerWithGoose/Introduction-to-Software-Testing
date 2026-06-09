#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct word{
	char alpha[80];
	int num;
};
typedef struct word strw;

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	if((in=fopen("article.txt","r"))==NULL)
	{
		printf("Can't find this file!");
		return -1;
	}
	else
	{
		int i=0,j=0,k,m,n,flag;
		char tap;
		strw a[10000];
		char temp[10000];
		tap=fgetc(in);

		while(tap!=EOF){
		if(isalpha(tap))
		{
			tap=tolower(tap);
			a[i].alpha[j]=tap;
			j++;
		}
		else if(ispunct(tap)||isspace(tap)||isblank(tap))
		{
			i++;
			j=0;
		}
			tap=fgetc(in);
		}
		for(m=0;m<i;m++){
			for(n=m+1;n<i;n++){
				if(strcmp(a[m].alpha,a[n].alpha)>0){
					strcpy(temp,a[m].alpha);
					strcpy(a[m].alpha,a[n].alpha);
					strcpy(a[n].alpha,temp);
				}
				else
					continue;
			}
		}
		for(m=0;m<i;m++){
			a[m].num=1;
			for(n=m+1;n<i;n++){
				if(strcmp(a[m].alpha,a[n].alpha)==0){
					a[m].num++;
					strcpy(a[n].alpha,"\0");
				}
			}
		}
		for(m=0;m<i;m++){
			if(strcmp(a[m].alpha,"\0")!=0){
				printf("%s %d\n",a[m].alpha,a[m].num);
			}
			else
				continue;
		}
	}
	fclose(in);
	return 0;
 }



