#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]="\0";
    int i,x=0,temp,ans=0,k,m=0,j;
    gets(s);
    k=strlen(s);
    if(s[0]==48)
    {
        for(i=1;s[i-1]==48;i++)
        {
            temp=s[i];
            s[i]=s[i+1];
            s[i+1]=temp;
            x++;
        }
        for(i=0;s[i]==48;i++)
        {
                s[i]='\0';
        }
       for(i=0;i<=k;i++)
       {
           if(s[i]=='\0')
           {
               m++;
               continue;

           }
           if(k-m==2)
           {
               for(i=0;i<=k;i++)
               {
                   if(s[i]==46)
                   {
                       s[i]='\0';
                   }
               }
           }
       }
       for(i=0;i<=k;i++)
       {
           if(s[i]=='\0')
           {
               continue;
           }
           printf("%c",s[i]);
       }
       printf("e-%d",x);
    }
    else
    {
        for(i=0;s[i]!=46;i++)
        {
        }
        j=i;
        for(i=j;i>1;i--)
        {
                temp=s[i-1];
                s[i-1]=s[i];
                s[i]=temp;
                x++;
        }
        for(i=0;i<k;i++)
        {
            printf("%c",s[i]);
        }
        printf("e%d",x);

    }
    return 0;
}

