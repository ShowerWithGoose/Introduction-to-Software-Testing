#include<stdio.h>
#include<string.h>
#define M 10000
int main()
{
    int i=0,j=0,k=0;
    char *p,*q;
    char a[M],s[M],s1[M];
    gets(a);
    q=a;
    while(*q!='\0')
    {       
        if((*q=='-')&&((*(q-1)>='a'&&*(q+1)<='z'&&*(q-1)<*(q+1))||(*(q-1)>='A'&&*(q+1)<='Z'&&*(q-1)<*(q+1))||(*(q-1)>='0'&&*(q+1)<='9'&&*(q-1)<*(q+1))))
            {
                p=q+2;
                *q='\0';
                s[0]=*(q-1)+1;
                for(j=1;j<*(q+1)-*(q-1);j++)
                s[j]=s[j-1]+1;
                s[j]='\0';
                strcat(s,p);
                strcat(a,s);
                q+=(j-1);
            }
        else q++;
    }
   
    puts(a);
    return 0;
}
