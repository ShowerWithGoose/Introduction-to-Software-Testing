#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct danci{
	char a[1000];
	int num;
}; 
typedef struct danci node;
typedef struct danci *nodeptr;
int cmp(const void *p1,const void *p2)
{
	nodeptr w1=(nodeptr)p1;
	nodeptr w2=(nodeptr)p2;
	int ans,anx=0;
	while(1)
	{
	if(w1->a[anx]<w2->a[anx])
	{
	ans=-1;
	break;
	}
	else if(w1->a[anx]>w2->a[anx])
	{
	ans=1;
	break;
	}
	anx++;
	}
	return ans;
}
int main()
{
	FILE *fp;
	node a[1000];
	int i=0,j=0,k,l=0,n=0,m=0,o=0,p=0;
	char b[1000],c;
	fp=fopen("article.txt","r");
	for(k=0;k<999;k++)
	{
		a[k].num=0;
	}
	//printf("%d\n",a[0].num);
	while(1)
	{
		c=fgetc(fp);
		c=tolower(c);
		if(c>='a'&&c<='z')
		{
			l=1;
			m=1;
			b[i]=c;
			i++;
			b[i]='\0';
		}
		else
		{
		l=2;
		}
		if(l==2&&m==1)
		{
			
			//puts(b);
			if(j==0)
			{
				strcpy(a[j].a,b);
				a[j].num++;
				j++;
			}
			else
			{
				for(k=0;k<j;k++)
				{
					if(strcmp(a[k].a,b)==0&&strlen(a[k].a)==strlen(b))
					{
						a[k].num++;
						n=1;
						break;
					}
					else
					n=2;
				 } 
				if(n==2)
				{
					strcpy(a[j].a,b);
					a[j].num++;
					j++;
				}
			}
			i=0;
			l=1;
			m=0;
		}
		if(c==EOF)
		break;
	}
	//printf("%d\n",j);
	qsort(a,j,sizeof(node),cmp);
/**/for(k=0;k<j;k++)
{
	printf("%s %d\n",a[k].a,a[k].num);
}
	
	
	
	
	
	
	
	
	
	
	
	
	fclose(fp);
	return 0;
}



