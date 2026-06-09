#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct node{
	char s[20];
	int sum;
}a[1000]; 
int i=0;
char z[1000],y[1000];
int cmp(const void *p,const void *q)
{
	struct node *x,*y;
	x=(struct node*)p;
	y=(struct node *)q;
	return strcmp(x->s,y->s);
}
int main()
{
	int p,l,e,k=0;
	FILE *fp;
	fp=fopen("article.txt","r");
	while (fgets(y,10000,fp)!=NULL)
	{
		e=0;
		for (p=0;p<strlen(y);p++)
		{
			if (y[p]>='A'&&y[p]<='Z')
		 {
			  	y[p]=y[p]-'A'+'a';
			  }
		}
		for (p=0;p<strlen(y);p++)
		{
			if (y[p]<'a'||y[p]>'z')
			{
				z[e]='\0';
				if (e==0) continue;
				e=0;
				k=0;
				for (l=1;l<=i;l++)
				{
					if (strcmp(z,&a[l].s[0])==0&&z[0]!='\0')
					{
						k=1;
						a[l].sum++;
						break;
					}
				}
				if (k==0) {
					i++;
					strcpy(a[i].s,z);
					a[i].sum++;
					for (l=0;l<strlen(z);l++)
					z[l]='\0';
				}
			}
		  else z[e++]=y[p];
		}
	}
	qsort(&a[1],i,sizeof(a[0]),cmp);
	for (p=1;p<=i-1;p++)
	{
		printf("%s %d\n",a[p].s,a[p].sum);
	}
	printf("%s %d",a[i].s,a[i].sum);
	close(fp);
	return 0;
}


