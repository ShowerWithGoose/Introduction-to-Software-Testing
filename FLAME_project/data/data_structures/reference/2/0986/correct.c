# include <stdio.h>
# include <math.h>
# include <string.h>
# include<stdlib.h>
#include <ctype.h>
int calculate(char s[])
{
    int i,a=0,m[10000],j=0,k=0,l,result=0;
    char c[10000];
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            c[j++]=s[i];
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            a=s[i]-'0';
            for(l=i+1;l<strlen(s);l++)
            {
                if(s[l]>='0'&&s[l]<='9')
                {
                    a=a*10+(s[l]-'0');
                }
                else break;
            }
            m[k++]=a;
            i=l-1;
        }
    } 
   for(i=0;i<strlen(s)+1;i++)
   {
       if(c[i]=='-')
       {
           m[i+1]=-m[i+1];
       }
   }
   
   for(i=0;i<strlen(c);i++)
   {
       if(c[i]=='*')
       {
           m[i+1]=m[i]*m[i+1];
           m[i]=0;
       }
       else if(c[i]=='/')
       {
           m[i+1]=m[i]/m[i+1];
           m[i]=0;
       }
		
       else
       continue;
   }
   for(i=0;i<strlen(s)-strlen(c);i++)
   {
		result+=m[i];
	}
    return result;
}
int main()
{
    char a[10000],s[10000];
    int m,i,j=0;
    gets(a);
    for(i=0;i<=strlen(a);i++)
    {
        if(a[i]!=' ')
        s[j++]=a[i];
    }
    m=calculate(s);
    printf("%d",m);
    return 0;
}


