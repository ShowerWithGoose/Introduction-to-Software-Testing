#include <stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define arraynum(x)  (sizeof(x)/sizeof(x[o])
#define eps (1*10^-9)
int main()
{
    char a[150];
    int i,j;
    gets(a);
    if(a[0]=='0')
    {
        for(i=2;a[i]=='0';i++);

        if(a[i+1]=='\0') printf("%ce-%d",a[i],i-1);
        else
        {
            printf("%c%c",a[i],'.');
            for(j=i+1;a[j]!='\0';j++) printf("%c",a[j]);

            printf("e-%d",i-1);
        }

    }

    else if(a[0]!='0'&&a[1]=='.'){
     for(i=0;a[i]!='\0';i++)
      printf("%c",a[i]);
      printf("e0");}

    else
    {
        for(i=0;a[i]!='.';i++);

        printf("%c.",a[0]);
        for(j=1;a[j]!='\0';j++)
          if(a[j]!='.')
            printf("%c",a[j]);
            printf("e%d",i-1);
    }

    return 0;
}

