#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int cha(char b);
char ch[1000];
char be[1000];
int main()
{
    int a,high,low;
    int i=0,j=0;
    scanf("%s",ch);
    int n=strlen(ch);
    while(i<n)
    {
    if(ch[i]!='-')
        be[j]=ch[i];
    else if(cha(ch[i-1])&&cha(ch[i+1])&&cha(ch[i-1])==cha(ch[i+1])&&ch[i-1]<ch[i+1])
        {
            low=ch[i-1]+1;
            high=ch[i+1];

        for(a=low;a<high;a++)
        {
        be[j]=a;
        j++;
        }
        j--;
       }
    else
        be[j]=ch[i];
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

