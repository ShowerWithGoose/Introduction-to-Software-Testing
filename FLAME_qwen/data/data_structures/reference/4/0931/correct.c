#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct node{
	char s[20];
	int sum;
}z[1000]; 
int dcs=0;
char b[1000],a[1000];
int cmp(const void *p,const void *q)
{
	struct node *x,*y;
	x=(struct node*)p;
	y=(struct node *)q;
	return strcmp(x->s,y->s);
}
int main()
{
	int i,j,k,pd=0;
	FILE *fp;
	fp=fopen("article.txt","r");
	while (fgets(a,10000,fp)!=NULL)
	{
		k=0;
		for (i=0;i<strlen(a);i++)
		{
			if (a[i]>='A'&&a[i]<='Z')
		 {
			  	a[i]=a[i]-'A'+'a';
			  }
		}
		for (i=0;i<strlen(a);i++)
		{
			if (a[i]<'a'||a[i]>'z')
			{
				b[k]='\0';
				if (k==0) continue;
				k=0;
				pd=0;
				for (j=1;j<=dcs;j++)
				{
					if (strcmp(b,&z[j].s[0])==0&&b[0]!='\0')
					{
						pd=1;
						z[j].sum++;
						break;
					}
				}
				if (pd==0) {
					dcs++;
					strcpy(z[dcs].s,b);
					z[dcs].sum++;
					for (j=0;j<strlen(b);j++)
					b[j]='\0';
				}
			}
		  else b[k++]=a[i];
		}
	}
	qsort(&z[1],dcs,sizeof(z[0]),cmp);
	for (i=1;i<=dcs-1;i++)
	{
		printf("%s %d\n",z[i].s,z[i].sum);
	}
	printf("%s %d",z[dcs].s,z[dcs].sum);
	close(fp);
	return 0;
}


