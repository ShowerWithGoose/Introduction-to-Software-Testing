#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define maxt 1000
 int deep=0;
 	int digit,n; 
  	int i;
typedef struct node
{
	int data;
	int tall;
	int judge;
  } Tree;
  Tree shu[maxt];

 void intree(int j,int digit) 
{
	deep++;
	if(shu[j].data==-1)
	{
	 shu[j].data=digit;
	 shu[j].tall=deep;}
	 else if(digit<shu[j].data)
	 {
	 shu[j].judge=1;
	 intree(2*j,digit);}
	 else if(digit>=shu[j].data)
	 {
	 	 shu[j].judge=1;
	 intree(2*j+1,digit);
}
} 

void ans(int l)
{
	if(shu[l].data!=-1)
	{
		ans(2*l);
		if(shu[2*l].data==-1&&shu[2*l+1].data==-1)
		{
		printf("%d %d\n",shu[l].data,shu[l].tall);
		}
	    ans(2*l+1);
}
}

  int main()
  {
  	for(i=0;i<maxt+9;i++)
  	{
  		shu[i].data=-1;
  		shu[i].tall=0;
  		shu[i].judge=0;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&digit);
		deep=0;
	    intree(1,digit);			
	}
	ans(1);

  }


  

