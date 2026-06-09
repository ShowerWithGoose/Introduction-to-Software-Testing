#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100000

int main()
{
   int a[250];
   int op=0;
   int i=-1;
   int f=0;
   while(1){
   	scanf("%d",&op);
   	switch(op){
   		case 1:{
   			i++;
			   scanf("%d",&a[i]);
			break;
		   }
		case 0:{
			if(i==-1){
				printf("error ");
				break;
			}
			printf("%d ",a[i]);
			i--;
			break;
		} 
		case -1:{
			f=1;
			break;
		}  
	   }
	   if(f==1)  break;
   }
   
   return 0;
} 

