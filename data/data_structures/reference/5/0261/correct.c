#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

void bubbleSort(int a[], int b[], int n)
{ 
int i,j;
int hold=0;
 for( i = 0; i < n-1; i++) 
 for(j = 0; j < n-1-i; j++)
 {
 if(a[j]<a[j+1])
 { hold=a[j];
   a[j]=a[j+1];  
   a[j+1]=hold;
   hold = b[j]; 
   b[j] = b[j+1]; 
   b[j+1] = hold;
 }
 }
 }

int main()
{
	int i=0,j=0,l1=0,l2=0,k,xs1[105]={},zs1[105]={},xs2[105]={},zs2[105]={},xs3[105]={},zs3[105]={},xs4[105]={},zs4[105]={};
	char c;
	do{
			scanf("%d%d%c",&xs1[i],&zs1[i],&c);
			i++;
		}while(c!='\n');
		l1=i;
		i=0;
	   do{
			scanf("%d%d%c",&xs2[i],&zs2[i],&c);
			i++;
		}while(c!='\n');
	   l2=i;
	   k=0;
	for(i=0;i<l1;i++)
   {
   		for(j=0;j<l2;j++)
   		{
   			xs3[k]=xs1[i]*xs2[j];
			zs3[k]=zs1[i]+zs2[j];	
			k++;
		}
   }
   
bubbleSort(zs3,xs3,k);

for(i=j=0;i<k;i++)
{
    if(i==0)
    {
    	xs4[j]=xs3[i];
    	zs4[j]=zs3[i];
	}
    else
    {
    	if(zs3[i]==zs3[i-1])
    	{
    		xs4[j]+=xs3[i];
    	
		}
		else
		{
			j+=1; 
		xs4[j]=xs3[i];
		zs4[j]=zs3[i];	
		}
	}
    
	
 } 
 for(i=0;i<=j;i++)
    {
    	printf("%d %d ",xs4[i],zs4[i]);
	}
	return 0;	   
	   
}

