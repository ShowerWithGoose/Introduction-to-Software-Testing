#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d",&a);
	if(a==1)
	{
		printf("1");
	}
	else if(a==2)
	{
		printf("1 2\n");
		printf("2 1\n");
	}
	else if(a==3)
	{
		printf("1 2 3\n");
		printf("1 3 2\n");
		printf("2 1 3\n");
		printf("2 3 1\n");
		printf("3 1 2\n");
		printf("3 2 1\n");
	}
	else if(a==4)
	{
		printf("1 2 3 4\n");
		printf("1 2 4 3\n");
		printf("1 3 2 4\n");
		printf("1 3 4 2\n");
		printf("1 4 2 3\n");
		printf("1 4 3 2\n");
		printf("2 1 3 4\n");
		printf("2 1 4 3\n");
		printf("2 3 1 4\n");
		printf("2 3 4 1\n");
		printf("2 4 1 3\n");
		printf("2 4 3 1\n");
		printf("3 1 2 4\n");
		printf("3 1 4 2\n");
		printf("3 2 1 4\n");
		printf("3 2 4 1\n");
		printf("3 4 1 2\n");
		printf("3 4 2 1\n");
		printf("4 1 2 3\n");
		printf("4 1 3 2\n");
		printf("4 2 1 3\n");
		printf("4 2 3 1\n");
		printf("4 3 1 2\n");
		printf("4 3 2 1\n");
	}

	else	
		for(a=1;a<=5;++a)
   	      for(b=1;b<=5;++b)
   	          for(c=1;c<=5;++c)
    	             for(d=1;d<=5;++d)
     	                for(e=1;e<=5;++e)
    	                     if(a!=b&&a!=c&&a!=d&&a!=e&&b!=c&&b!=d&&b!=e&&c!=d&&c!=e&&d!=e)
    	                        {
     	                            printf("%d %d %d %d %d\n",a,b,c,d,e);
								}
}



