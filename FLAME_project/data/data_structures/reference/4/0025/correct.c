#include <stdio.h>
#include <string.h>
#include <ctype.h>

FILE *pin;
int n=0, i=0, m, h, j=0;
char c, d;

struct lnode 
{
    char word[36];
    int count;
};

struct lnode list[1024], b;

int main()
{
	pin=fopen("article.txt","r");
	
	c = fgetc(pin);
	while(c != EOF)
    {
    	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    	{
    		list[i].word[n]=tolower(c);
    		n++;
		}
		else if((d >= 'A' && d <= 'Z') || (d >= 'a' && d <= 'z'))
		{
			i++;
			n=0;
		}
    	d = c;
		c = fgetc(pin);
	}
	
/*	for(n=0;n<i;n++)
	{
		printf("%s\n", list[n].word );
	}*/
	
	for(n=0;n<i;n++)
	{
		for(m=n+1;m<i;m++)
		{
			if(strcmp(list[n].word,list[m].word) == 0)
			{
				for(h=m;h<i;h++)
				{
					list[h]=list[h+1];
				}	
				list[n].count++;
				i--;
				m--;
			//	printf("%d %s %s\n", j, list[m].word, list[n].word );
			}
			
		}
	}
	
	for(n=0;n<i;n++)
	{
		for(m=n+1;m<i;m++)
		{
			if(strcmp(list[n].word ,list[m].word ) > 0)
			{
				b=list[n] ;
				list[n] =list[m] ;
				list[m] =b;
			}
		}
	}
	
//	printf("%d %d\n", i, j);
	for(n=0;n<i;n++)
	{
		printf("%s %d\n", list[n].word ,list[n].count+1 );
	}
	
	return 0;
}





