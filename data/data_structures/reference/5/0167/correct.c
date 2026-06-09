#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct num1{
	int xi;
	int ci;
}digit1[100];
struct num2{
	int xi;
	int ci;
}digit2[100];
struct last{
	int xi;
	int ci;
}digit3[10000];
int cmp(const void*a,const void*b)
{ 
   struct last *c=(struct last *)a;
   struct last *d=(struct last *)b;
   if(c->ci<d->ci)return 1;
   else if(c->ci==d->ci)return 0;
   else return -1;
}

int main()
{  int i=0,j=0,num1,num2,flag[10000]={0},k=0,p=0;
   char ch;
      	while(1)
      	{
      		scanf("%d%d",&digit1[i].xi,&digit1[i].ci);
		   if(getchar()=='\n') 
		    {break;
		}
		    i++; 
	    }
	   
	    num1=i;
	    while(1)
      	{ 
      		scanf("%d%d",&digit2[j].xi,&digit2[j].ci);
		   if(getchar()=='\n') 
		    {break;}
		    j++;
	    }
	    num2=j;
	    for(i=0;i<=num1;i++)
	    {
	    	for(j=0;j<=num2;j++)
	    	{
	    		digit3[k].ci=digit1[i].ci+digit2[j].ci;
	    		digit3[k].xi=digit1[i].xi*digit2[j].xi;
	    		k++;
			}
		}
	    qsort(digit3,k,sizeof(digit3[0]),cmp);
	    for(i=0;i<k;i++)
	    {
	    	if(digit3[i].ci==digit3[i-1].ci)
	    	{
	    		digit3[i].xi+=digit3[i-1].xi;
	    		flag[i-1]=1;
			}
		}
		for(i=0;i<k;i++)
		{
			if(flag[i]==0&&digit3[i].xi!=0)
			{
				printf("%d %d ",digit3[i].xi,digit3[i].ci);
			}
		}
} 

