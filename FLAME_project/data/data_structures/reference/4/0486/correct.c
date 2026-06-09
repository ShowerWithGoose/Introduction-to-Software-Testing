#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void*p1,const void*p2);
struct wordnum{
	char word[100];
	int num;
};
typedef struct wordnum wn;

int main()
{
	FILE * in;
	wn x[1000];
	int i=0,k=0,t=0,flag=0,list=-1;
	char c[50000],str[100];
	
	in=fopen("article.txt","r");
	while(fscanf(in,"%c",&c[i] )!=EOF)
	{
		if(c[i]>='A'&&c[i]<='Z')
		{
			c[i]+='a'-'A';
		}
		i++;
	}
	for(k=0;k<i;k++)
	{
		if(c[k]>='a'&&c[k]<='z')
		{
			t=0;
			str[t]=c[k];
			k++;
			t++;
			while(c[k]>='a'&&c[k]<='z')
			{
				str[t]=c[k];
				t++;
				k++;
			}
			str[t]='\0';
			
			for(t=0;t<=list;t++)
			{
				if(strcmp(str,x[t].word )==0)
				{
					x[t].num ++;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				list++;
				strcpy(x[list].word ,str);
				x[list].num ++;
				
			}
			flag=0;
			memset(str, '\0', sizeof(str));
		}
	}
	list++;
    qsort(x,list,sizeof(wn),cmp);	
	for(i=0;i<list;i++)
	{
		printf("%s %d\n",x[i].word ,x[i].num );
	}
	
	return 0;
}
int cmp(const void*p1,const void*p2)
{
	wn *a=(wn*)p1;
	wn *b=(wn*)p2;
	return strcmp(a->word ,b->word );
}

