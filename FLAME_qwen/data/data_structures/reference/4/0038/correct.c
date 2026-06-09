#include <stdio.h>
#include <ctype.h>
#include <string.h>
struct X
{
	char c[100];
	int b;
}x[100],temp;
int main()
{
	char a[1001];
	FILE *in;
	int i,j=0,b,d=0,e=1,f=0;
	in = fopen("article.txt", "r");
	while(fgets(a,1000,in)!=NULL)
	{
		b=strlen(a);
		for(i=0;i<b;i++)
		{
			if('A'<=a[i]&&a[i]<='Z')
			{
				a[i]=a[i]+32;
			}
		}
		for(i=0;i<b;i++)
		{
			if((a[i]<='z'&&a[i]>='a')||(a[i]<='Z'&&a[i]>='A'))
			{
				x[j].c[d]=a[i];
				e=0;
				d++;
			}
			else if(e!=1)
			{
				j++;
				e=1;
				f++;
				d=0;
			}
		}
	}
	 for(i=0;i<f;i++)
    {
        for(j=i+1;j<f;j++)
        {
            if(strcmp(x[i].c,x[j].c)>0 )
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    } 
	 for(i=0;i<f;i++)
    {
    	x[i].b=1;
        for(j=i+1;j<f;j++)
        {
			if(strcmp(x[i].c,x[j].c)==0)
			{
				x[i].b++;
				strcpy(x[j].c, "\0");
			}
		}		
	}
	for(i=0;i<f;i++)
	{
		if(strlen(x[i].c)!=0)
		{
			printf("%s %d\n",x[i].c,x[i].b);
		}
	}
	return 0;
}



