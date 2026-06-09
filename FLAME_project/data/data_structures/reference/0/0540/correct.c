#include <stdio.h>

int main()
{
int i=0,j;
char s[200]={'\0'},n;


while ((n=getchar())!=EOF)
{
    s[i]=n;
    i++;

}
for (j=0;j<i;j++)
{


    if ((s[j]=='-')&&(s[j-1]>='a')&&(s[j+1]<='z')&&(s[j+1]>'a')&&(s[j-1]<'z')&&(s[j-1]<s[j+1]))
    {
        char j1;
        for (j1=s[j-1]+1;j1<s[j+1];j1++)
        {
            printf("%c",j1);
        }
    }
    else if ((s[j]=='-')&&(s[j-1]>='A')&&(s[j-1]<'Z')&&(s[j+1]<='Z')&&(s[j+1]>'A')&&(s[j-1]<s[j+1]))
    {
         char j2;
        for (j2=s[j-1]+1;j2<s[j+1];j2++)
          {
             printf("%c",j2);
          }
     }
     else if ((s[j]=='-')&&(s[j-1]>='0')&&(s[j-1]<'9')&&(s[j+1]<='9')&&(s[j+1]>'0')&&(s[j-1]<s[j+1]))
     {
         char j3;
         for (j3=s[j-1]+1;j3<s[j+1];j3++)
         {
             printf("%c",j3);
         }
     }
     else
     {
         printf("%c",s[j]);
     }


}

printf("\n");
return 0;


}
