#include<stdio.h>
#include<string.h>
int main() 
{
    char s[105];
    gets(s);
    int l=strlen(s);
    if(s[0]=='0')
    {   int i,j;
    	for(i=2;i<l;i++) if(s[i]!='0') break;
    	printf("%c",s[i]);
    	if(i+1==l) printf("e-%d",i-1);
    	else
		{   printf(".");
			for(j=i+1;j<l;j++) printf("%c",s[j]);
    	    printf("e-%d",i-1);	
		}
	}
	else
	{
		int i,j,k;
		for(i=0;i<l;i++) if(s[i]=='.') break;
		printf("%c.",s[0]);
		for(j=1;j<i;j++) printf("%c",s[j]);
		for(k=i+1;k<l;k++) printf("%c",s[k]);
		printf("e%d",i-1);
		
	}

	return 0;
}


