#include <stdio.h>
#include <string.h>
int judge(char s)
{
    if('A'<=s&&'Z'>=s) return 1;
    else if('a'<=s&&'z'>=s) return 2;
    else if('0'<=s&&'9'>=s) return 3;
    else return 0;
}
int issame(char s1,char s2)
{
    if((judge(s1)==judge(s2))&&(judge(s1)!=0)&&(s2-s1>0))  return 1;
    else return 0;
}
int main()
{
    char a[1000],b[1000];
    char ch;
    scanf("%s",a);
    int l,i,num=0;
    l=strlen(a);
    for(i=0;i<=l-1;i++)
    {
        b[num++]=a[i];
        if(issame(a[i],a[i+2])&&a[i+1]=='-')
        {
            ch=a[i]+1;
            while(a[i+2]-ch>0)
            {
                b[num++]=ch;
                ch=ch+1;
            }
            i++;
        }
    }
    printf("%s",b);
}
