#include<stdio.h>     
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h> 
#include<limits.h>


main()
{
    char c[1000],d[1000];
    gets(c);
    char a,b,i;
    int j,k,m;                                      
    for(j=0;j<=strlen(c);j++)
    {
        if(c[j]!='-')
        {
            d[m]=c[j];
            m++;
        }
        if(c[j]=='-') 
        {   
            a=c[j-1],b=c[j+1];
            if(((b<='z'&&a>='a')||(b<='Z'&&a>='A')||(b<='9'&&a>='0'))&&a<b)
            {
            for(k=a+1;k<b;k++)
            {
                d[m]=k;
                m++;
            }
            }
            else 
            {
                d[m]='-';
                m++;
            }
        }
    }
     puts(d);
     return 0;   
}

