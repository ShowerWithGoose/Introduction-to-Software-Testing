#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct word
{
	char a[30];
	int time;
}w[600];
int i,j,k,n,l,flag=0;
char c,str[40];

int cmp(const void*aa,const void*bb)
{
    struct word *a1=(struct word*)aa;
    struct word *b1=(struct word*)bb;
    if(strcmp(a1->a,b1->a)<0)
        return -1;
    return 1;
}
int main()
{
	
	FILE *fp1;
	fp1 = fopen("article.txt","r");
	i=0;
	j=0;
	while((c=fgetc(fp1))!=EOF)
	{
		if(c>='A'&&c<='Z')
		{
			c = c - 'A' + 'a';
		}
		if(c>='a'&&c<='z')
		{
			str[i] = c;
			l = i;
			//printf("%c",str[i]);
			i++;
		}
		else
		{
			str[i] = '\0';
			//printf("%s",str);
			flag = 0;
			
			for(j=0;j<=n;j++)//±éÀú 
			{
				if(strcmp(w[j].a,str)==0)
				{
					flag = 1;
					w[j].time++;
					break;
				}
			}
			//printf("  flag = %d\n",flag);
			if(flag==0)
			{
				j=n+1;
				for(i=0;i<=l;i++)//´æ´¢ 
				{
					w[j].a[i] = str[i];
					n = j;
				}
				w[j].time = 1;
			}
			i = 0;	
		}
	}
	qsort(w,n+1,sizeof(struct word),cmp);
	for(j=1;j<=n;j++)
	{
		printf("%s %d\n",w[j].a,w[j].time);
	}
	return 0;
} 

