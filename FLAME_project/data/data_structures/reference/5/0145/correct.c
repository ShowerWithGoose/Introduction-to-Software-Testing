#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

int main()
{
	int a[6],index[6],b[6],index1[6],c[30],index2[30];
	int i=0,j=0,t=0,k=0,n,m,flag,hold=0;
	char ch;
	do{
		scanf("%d%d%c",&a[i],&index[i],&ch);
		i++;
	}while(ch!='\n');
	
	n=i;
	i=0;
	do{
		scanf("%d%d%c",&b[i],&index1[i],&ch);
		i++; 
	}while(ch!='\n');
	m=i;
	
	for(i=0;i<n;i++)
	for(j=0;j<m;j++){

			c[t]=a[i]*b[j];
			index2[t]=index[i]+index1[j];	
			t++;	
	}
	
	for(i=0;i<t;i++)
		for(j=0;j<i;j++){
			if(index2[i]>index2[j]){
				hold=c[i];
				c[i]=c[j];
				c[j]=hold;
				hold=index2[i];
				index2[i]=index2[j];
				index2[j]=hold;
			}
		} 
	
	
	for(i=0;i<t;i++)
	{
		if(index2[i]==index2[i+1])
		{
			c[i+1]+=c[i];
		}
		else
		printf("%d %d ",c[i],index2[i]);
	}
	
	return 0;
}



