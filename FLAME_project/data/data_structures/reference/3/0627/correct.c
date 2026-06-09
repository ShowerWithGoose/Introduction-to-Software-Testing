#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char str[110],str1[110];
	gets(str);
	memset(str1,0,sizeof(str1));
	int i,j=0;
	int a;
	int k;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='.')
		{
			j=i;
		}
	}
	if(j==1)
	{
		if(str[0]<='9'&&str[0]>='1')
		{
			a=0;
			for(i=0;str[i]!='\0';i++)
	        printf("%c",str[i]);
			printf("e%d",a);
		    printf("\n");
		}
		else
		{
		    for(i=2;str[i]!='\0';i++)
		    {
			   if(str[i]>='1'&&str[i]<='9'&&str[i+1]!='\0')
			   {
			   a=i-1;
			   str1[0]=str[a+1]; 
			   str1[1]='.'; 
			   for(k=2;str[k+a]!='\0';k++)
		       {
		    	str1[k]=str[k+a];
			   }
			   for(k=0;str1[k]!='\0';k++)
	           printf("%c",str1[k]);
			   printf("e-%d",a);
		       printf("\n");
		       break;
			   } 
			   if(str[i]>='1'&&str[i]<='9'&&str[i+1]=='\0')
			   {
			   	a=i-1;
			   	str1[0]=str[a+1];
	            printf("%c",str1[0]);
			    printf("e-%d",a);
		        printf("\n");
			   }
		    }
	    }
	}
	if(j>1)
	{
		a=j-1;
		str1[0]=str[0];
		str1[1]='.';
		for(i=2;str[i-1]!='.';i++)
		{
			str1[i]=str[i-1];
		}
		for(i=j+1;str[i]!='\0';i++)
		{
			str1[i]=str[i];
		}
		for(i=0;str1[i]!='\0';i++)
	    printf("%c",str1[i]);
		printf("e%d",a);
		printf("\n"); 
	}
	return 0;
	
}

