#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct list
{
	int n;
	int n1;
};
int a;
int num=0;
void sort(struct list array[],int );
void vio(struct list array[],int );
int main()
{
     char c;
     int i=0;
     int k;
     int m;
     int a;
     int j;
     int b=0;
     struct list l1[200],l2[200],l3[200];
     while(scanf("%d %d%c",&l1[i].n,&l1[i].n1,&c)!=EOF)
     {
        if(c=='\n')
        {
        	break;
		}
		
		 i++;
	 }
	 k=i;
	 i=0;
	 while(scanf("%d %d%c",&l2[i].n,&l2[i].n1,&c)!=EOF)
	 {
	    if(c=='\n')
	    {
	    	break;
		}
	 	i++;
	 }
	 m=i;
	 a=(m+1)*(k+1);
	 for(i=0;i<=k;i++)
	 {
	 	for(j=0;j<=m;j++)
	 	{
	 		l3[b].n=l1[i].n*l2[j].n;
	 		l3[b].n1=l1[i].n1+l2[j].n1;
	 		b++;
		 }
	 }
	 vio(l3,a);
	 return 0;
}

void sort(struct list array[],int p)
{
	int i,j;
	struct list temp;
	for(i=0;i<p;i++)
	{
		for(j=i+1;j<p;j++)
		{
			if(array[i].n1<array[j].n1)
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
}
void vio(struct list array[],int p)
{
	int i,j;
	int k;
	for(i=0;i<p;i++)
	{
		for(j=i+1;j<p;j++)
		{
			if(array[i].n1==array[j].n1)
			{
				array[i].n=array[i].n+array[j].n;
				for(k=j+1;k<p;k++)
				{
					array[k-1]=array[k];
				}
			p=p-1;	
			}
		}
	}
	sort(array,p);
	for(i=0;i<p;i++)
	{
		printf("%d %d ",array[i].n,array[i].n1);
	}
}



