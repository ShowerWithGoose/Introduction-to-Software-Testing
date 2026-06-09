#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{  char s[1100];  int a[110] = {0};
   gets(s);
   int i,len = strlen(s);

for( i = 1; i <= len - 2; i++ )
  {
	if(s[i] == '-' )
	{
	   if(isdigit(s[i - 1]) != 0&&isdigit(s[i + 1]) != 0&&s[i + 1] > s[i - 1]  )
	   {  a[i] = 2;
	   }
		 if(isupper(s[i - 1]) != 0&&isupper(s[i + 1]) != 0&&s[i + 1] > s[i - 1] )
	     {  a[i] = 2;
	     }
		if(islower(s[i - 1]) != 0&&islower(s[i + 1]) != 0&&s[i + 1] > s[i - 1])
	    {  a[i] = 2;
	    }

	}
  }
for(i = 0; i <= len - 1; i++)
{
	if(a[i] == 0) printf("%c",s[i]);
  else	if(a[i] == 2)
	{
        int j;
		for(j = 1; s[i-1]+j < s[i+1]; j++)
		{
		printf("%c",s[i-1]+j );
		}

	}

}


    return 0;
}

