#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
	int num1 = 0,num2,num3;
	char fh1 = '+',fh2,fh3;
while(fh1 != '=')
{
  scanf("%d %c",&num2,&fh2);
  while(fh2 == '*' || fh2 == '/')
  {
  	switch (fh2)
    {
  	case '*' :
  	   scanf("%d %c",&num3,&fh3);
	   num2 *= num3; fh2 = fh3;
	   break;
  	case '/' :
  	    scanf("%d %c",&num3,&fh3);
	    num2 /= num3;  fh2 = fh3;
	    break;
    }
  }
  
switch (fh1)
    {
  	case '+' :
  	   num1 += num2; fh1 = fh2;
	   break;
  	case '-' :
       num1 -= num2; fh1 = fh2;
	    break;
    }
}

printf("%d",num1);

	return 0;
}




