#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
  char a,b;
  int i=0,k,j=1;
  char s[100];
  scanf("%s",s);
  while(i<strlen(s))
  {
  	if(s[i]!='-')
  	{
  		a=s[i];
		printf("%c",a);
		i++; 
	}
	else if((isupper(s[i-1])&&isupper(s[i+1]))||(islower(s[i+1])&&islower(s[i-1]))||(isdigit(s[i+1])&&isdigit(s[i-1])))
	{
		k=s[i+1]-s[i-1];
		while(j<k)
		{
			printf("%c",s[i-1]+j);
			j++;
		}
		j=1;
		i++;
	}
	else
	{printf("-");
	i++;
	}
  }
return 0;
}




