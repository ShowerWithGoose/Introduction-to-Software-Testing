#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int i,j,k,l,m,n;
	gets(str);
	if(str[0]=='0')
	{
		for(i=2;str[i]=='0';i++);
		//printf("%d",i);
		for(j=i;str[j]!='\0';j++)
		{
			j==i+1 ? printf(".%c",str[j]):printf("%c",str[j]);
		}
		//printf("%d",j);
		//printf("%c",str[j]);
		printf("e-%d",i-1);
	}
	else if(str[strlen(str)-1]=='0')
	{
		for(k=0;str[k]!='0';k++)
		{
			k==1?printf(".%c",str[k]):printf("%c",str[k]);
		}
		for(l=k;str[l]!='\0';l++);
		
		printf("e%d",l-1);	
	}
	else
	{
		if(str[1]=='.')
		{
		    printf("%s",str);
		    printf("e0");
	    }
	    else{
		
		for(m=0;str[m]!='.';m++)
		{
			if(m==1) printf(".%c",str[m]);
			else printf("%c",str[m]);		
		}
		for(n=m+1;str[n]!='\0';n++)
		{
			printf("%c",str[n]);
		}
		printf("e%d",2*m-n+1);
	        }
	}
	return 0;
}

