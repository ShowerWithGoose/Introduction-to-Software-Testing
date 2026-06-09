#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct point_{
	int x;
	int y;
}point,*pointptr;
typedef struct line_{
	point start;
	point final;
}line,*lineptr;
typedef struct sum_{
	int s;
	point start;
}sum,*sumptr;
int cmp1(const void *p1,const void *p2);
int cmp2(const void *p1,const void *p2);
int main()
{
    sum summary[105];
	line l[105];
	int n,i,j,k=0,t,z;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d %d %d %d",&l[i].start.x,&l[i].start.y,&l[i].final.x,&l[i].final.y);
	qsort(l,n,sizeof(line),cmp1);
	for(t=0;t<n;t++)
	{
		summary[k].s=1;
		summary[k].start=l[k].start;
		z=n;
		for(i=t;i<z;i++)
		  {
		  	for(j=i+1;j<n;j++)
		  	  {
		  	  	if((l[i].final.x)<(l[j].start.x)) break;
		  	  	if(((l[i].final.x)==(l[j].start.x))&&((l[i].final.y)==(l[j].start.y)))
		  	  	    {
		  	  	    	i=j-1;z=j+1;
		  	  	    	(summary[k].s)++;
		  	  	    	break;
					}
				}
		  }
		k++;
	}
	qsort(summary,n,sizeof(sum),cmp2);
	for(i=0;i<1;i++) printf("%d %d %d",summary[i].s,summary[i].start.x,summary[i].start.y);
	
/*	FILE *fp1,*fp2;
	fp1=fopen("books.txt","r");
	fp2=fopen("ordered.txt","w");	
	if(fp1==NULL) 
	  {
	  	printf("Can't open the scanffile!\n'");
	   	return -1;
	  }
	if(fp2==NULL)
	   {
	   	printf("Can't open the printffile!\n'");
	   	return -2;
	   }
	memset(c,'\0',sizeof(c));	
	fclose(fp1);
	fclose(fp2);
	if(freopen("books.txt","r",stdin)==NULL)
	   {
	   	printf("Can't open the scanffile!\n'");
	   	return -1;
	   }
	if(freopen("output.txt","w",stdout)==NULL)
	   {
	   	printf("Can't open the printffile!\n'");
	   	return -2;
	   }
	fclose(stdin);
	fclose(stdout);*/
	return 0;
}

int cmp1(const void *p1,const void *p2)
{
	lineptr w1=(lineptr)p1;
	lineptr w2=(lineptr)p2;
	int ans;
	if((w1->start.x)<(w2->start.x)) ans=-1;
	  else ans=1;
	return ans;
}
int cmp2(const void *p1,const void *p2)
{
	sumptr w1=(sumptr)p1;
	sumptr w2=(sumptr)p2;
	int ans;
	if((w1->s)>(w2->s)) ans=-1;
	  else ans=1;
	return ans;
}


