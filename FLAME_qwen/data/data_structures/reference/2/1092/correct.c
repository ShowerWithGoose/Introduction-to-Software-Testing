#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    int i,j=0,k=0,m=0,ans=0,n[81]={0};
    char *p,c='+';
    char s[81],s1[81];
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(isspace(s[i])==0)
        s1[j++]=s[i];
    }
   p=s1;
   for (p=s1;*p!='\0';p++)
   {
        if(*p>='0'&&*p<='9')
           m=m*10+*p-'0';
        else 
        {
            if(c=='+')  n[k++]=m;
            else if(c=='-')  n[k++]=-m;
            else if(c=='*')  n[k-1]*=m;
            else if(c=='/')  n[k-1]/=m;
            c=*p;
            m=0;
        }   
   }
   for(i=0;i<k;i++) ans+=n[i];
   printf("%d\n",ans);
   return 0;
}
