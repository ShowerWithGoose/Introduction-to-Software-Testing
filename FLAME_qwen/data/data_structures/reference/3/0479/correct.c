#include <stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char c[200];


int main()
{
    int len,i,j,k;
    int flag1=0,flag2=0,flag3=0;


    gets(c);

    len = strlen(c) - 1;

    for(i=0;c[i]!='.';i++)
    {
        flag1++;
    }
    for(j=i+1;c[j]=='0';j++)
    {
        flag2++;
    }
    flag3=strlen(c)-j-flag1+1;
  //  printf("%d\n%d\n%d\n",flag1,flag2,flag3);

    if(flag1==1&&c[0]=='0'&&flag3==1)
    {
       printf("%c",c[flag1+1+flag2]);
       printf("e-%d",flag2+1);
    }
    else if(flag1==1&&c[0]=='0'&&flag3!=1)
    {
        printf("%c.",c[flag1+1+flag2]);
        for(i=flag1+flag2+2;i<strlen(c);i++)
            printf("%c",c[i]);
        printf("e-");
        printf("%d",flag2+1);
    }
    else if(flag1==1&&c[0]!='0')
    {
        for(i=0;i<strlen(c);i++)
            printf("%c",c[i]);
            printf("e0");
    }
    else if(flag1!=1)
    {
        printf("%c.",c[0]);
        for(i=1;i<strlen(c);i++)
        {
            if(c[i]!='.')
            printf("%c",c[i]);
        }

        printf("e%d",flag1-1);
    }

}


