#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>
char str[105],s[105],num[105];
int main()
{
    int i,j,k,m,n,d,point,number;

    scanf("%s",str);
    for(i=0,j=0;str[i]!='\0';i++)
    {

        if(str[i]!='.')
            s[j++]=str[i];
        if(str[i]=='.')
            point=i;
    }
    s[j]='\0';

    for(k=0;k<j;k++)
    {
        if(s[0]=='0')
        {
            if(s[k]!='0')
            {
                number=k;
                break;
            }
        }

    }
    if(s[0]!='0')
    {
        d=point-1;
        num[0]=s[0];
        num[1]=46;
        for(m=2,n=1;n<j;m++,n++)
            num[m]=s[n];
        num[m]='\0';
        printf("%se%d\n",num,d);
    }
    if(s[0]=='0')
    {
        if(number!=j-1){
        num[0]=s[number];
        num[1]=46;
        for(m=2,n=number+1;n<j;m++,n++)
            num[m]=s[n];
        num[m]='\0';
        }
        if(number==j-1)
        {
            num[0]=s[number];
            num[1]='\0';
        }
        printf("%se-%d\n",num,number);

    }

    return 0;
}



