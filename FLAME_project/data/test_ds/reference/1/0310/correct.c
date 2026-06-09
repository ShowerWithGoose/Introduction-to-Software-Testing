#include<stdio.h>
#include<string.h>
int fun(char a,char b);
int main()
{
    char c[1010];
    gets(c);
    char *p=NULL,*q=NULL;
    int i,j;
    j=strlen(c);
    p=strchr(c,'-');
    if(p==NULL)
    	puts(c);
    else
    {
    	q=c;
    	while((p+1)!=NULL&&(p=strchr(q,'-'))!=NULL)
    	{
    		if(fun(*(p-1),*(p+1))==1)
    		{
    		    for(i=0;i<p-q;i++)
    				printf("%c",*(q+i));
    			for(i=1;i<=*(p+1)-*(p-1);i++)
    				printf("%c",*(p-1)+i);
			}
			else
			{
				for(i=0;i<p-q+2;i++)
					printf("%c",*(q+i));
			}
			q=p+2;
		}
		for(i=0;i<j-(q-c);i++)
			printf("%c",*(q+i));
	}
    return 0;
} 
int fun(char a,char b)
{
	if(a>='a'&&b<='z'&&b-a>0)
		return 1;
	else if(a>='A'&&b<='Z'&&b-a>0)
		return 1;
	else if(a>='0'&&b<='9'&&b-a>0)
		return 1;
	else
		return 0;
}


