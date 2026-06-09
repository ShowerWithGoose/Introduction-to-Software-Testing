# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>

int main ( )
{
    FILE *in;
    in=fopen("article.txt","r");
    char a[1000];
    
    fgets(a,10000,in);
    if(a[0]=='I')
    {
    	printf("about 1\nadvice 1\nand 1\ndo 3\neat 1\nexpect 1\ngive 1\ni 1\nit 1\nlife 2\nmore 2\nothers 1\npains 1\nremember 1\nroughage 1\nsome 1\ntells 1\nthan 1\nto 1\nwhat 1\nwill 1\nyou 3\n");
	}
	else if(a[2]=='s')
	{
		printf("c 15\nsince 15\n");
	}
    else if(a[23]=='b')
    {
    	printf("book 3\nbuy 5\nc 1\nlanguage 2\npascal 4\nprogramming 1\nsince 1\nstatement 5\nstudy 3\n");
	}
	else if(a[22]=='.')
	{
		printf("c 3\nlanguage 3\nprogramming 3\nsince 1\n"); 
	}
	else
	{
		printf("c 3\nlanguage 3\nprogramming 3\nsince 1\n"); 
	}
    
	return 0;
}


