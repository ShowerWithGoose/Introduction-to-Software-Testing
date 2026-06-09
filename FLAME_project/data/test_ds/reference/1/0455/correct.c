#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int expand(char c, char d){
    if(c>='a'&&c<='z'&&d>='a'&&d<='z'&&d-c>0)
	{
		return 1;
	}
	else if(c>='A'&&c<='Z'&&d>='A'&&d<='Z'&&d-c>0)
	{
		return 1;
	}
	else if(c>='0'&&c<='9'&&d>='0'&&d<='9'&&d-c>0){
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(){
    int i=0,j=0,k=0;
    char s[500];
    char *a=NULL,*b=NULL;
    gets(s);
    char *c=s;
    a=strchr(s,'-');
    if(a==NULL){
        puts(s);
    }
else
	{
		for(; (b=strchr(c,'-'))!=NULL&&(b+1)!=NULL;)
		{
			if(expand(*(b-1),*(b+1))==1)
			{
				for(i=0;i<b-c;i++)
				{
					printf("%c",*(c+i));
				}
				for(i=1;i<=*(b+1)-*(b-1);i++)
				{
					printf("%c",*(b-1)+i);
				}
			}
			else
			{
				for(i=0;i<b-c+2;i++)
				{
					printf("%c",*(c+i));
				}
			}
			c=b+2;
		}
		for(i=0;i<strlen(s)-(c-s);i++)
		{
			printf("%c",*(c+i));
		}
	}


    return 0;
            }

