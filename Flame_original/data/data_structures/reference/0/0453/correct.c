#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int isnumber(char l)
{
    if(l<='9'&&l>='0')
        return 1;
    else
        return 0;
}
int isupper(char l)
{
    if(l<='Z'&&l>='A')
        return 1;
    else
        return 0;
}
int islower(char l)
{
    if(l<='z'&&l>='a')
        return 1;
    else
        return 0;
}
int main()
{
char s[101],b[101];
char a,c;
gets(s);
int lens=strlen(s);
for(int i=0;s[i]!='\0';i++)
{
    if(s[i]=='-')
    {
        strcpy(b,s+i+2);
        b[lens-i-2]='\0';
        a=s[i-1],c=s[i+1];
        if((isupper(a)==1&&isupper(c)==1)||(islower(a)==1&&islower(c)==1)||(isnumber(a)==1&&isnumber(c)==1)){
        while(a<c)
        {

          s[i]=a+1;
          a=a+1;
          i++;
        }
        strcpy(s+i,b);
        i--;
        }
    }
}
printf("%s",s);
  return 0;
}


