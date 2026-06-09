#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char put_num[105],num[105];
    gets(put_num);
    int i1,i2,len=strlen(put_num);
    if(put_num[0]=='0' && put_num[1]=='.')
    {
        for(i1=2;put_num[i1]=='0';i1++)
        {
            i1++;
        }
        if(i1+1==len)
        {
            printf("%c",put_num[i1]);
            printf("e-%d",i1-1);
        }
        else
        {
            printf("%c.",put_num[i1-1]);
            for(i2=i1;i2<len;i2++)
            {
                printf("%c",put_num[i2]);
            }
            printf("e-%d",i1-2);
        }
    }
    else
    {
        i2=0;
        printf("%c.",put_num[0]);
        for(i1=1;put_num[i1]!='.';i1++)
        {
            printf("%c",put_num[i1]);
            i2++;
        }
        for(i1++;i1<len;i1++)
        {
            printf("%c",put_num[i1]);
        }
        printf("e%d",i2);
    }
    return 0;
}
