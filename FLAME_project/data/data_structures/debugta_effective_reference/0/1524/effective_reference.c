#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int cha(char b);
char s[1000];
char be[1000];
int main()
{
    int k,high,low;
    int i=0,j=0;
    scanf("%s",s);
    int n=strlen(s);
    while(i<n)
    {
    if(s[i]!='-')
        be[j]=s[i];
    else if(cha(s[i-1])&&cha(s[i+1])&&cha(s[i-1])==cha(s[i+1])&&s[i-1]<s[i+1])
        {
            low=s[i-1]+1;
            high=s[i+1];

        for(k=low;k<high;k++)
        {
        be[j]=k;
        j++;
        }
        j--;
       }
    else
        be[j]=s[i];
i++;
j++;
    }
    be[j]='\0';
    printf("%s\n",be);
   return 0;
}

int cha(char b)
{
    if(b>='0'&&b<='9')
        return 1;
    if(b>='a'&&b<='z')
        return 2;
    if(b>='A'&&b<='Z')
        return 3;
        return 0;
}

