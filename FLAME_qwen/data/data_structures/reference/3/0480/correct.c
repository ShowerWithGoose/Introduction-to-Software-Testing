#include<stdio.h>
#include<string.h>

int main()
{
    char str[10000],deal[10000];
    int i,j,len,pnum = 0,znum = 0,record = 0;
    gets(str);
    len = strlen(str);
    if(str[0] == '0')
    {
        for(i = 0,j = 0;i < len;i++)
        {
            if(str[i] <= '9'&&str[i] >='1')
            {
                record++;
            }
            if(str[i] == '0'&&record == 0)
            {
                znum++;
            }
            if(str[i] <= '9'&&str[i] >='0')
            {
                deal[j] = str[i];
                j++;
            }

        }
        if((len - 2) != znum)
        printf("%c.",deal[znum]);
        else
        printf("%c",deal[znum]);
            for(i = znum+1;i <=len - 2;i++)
            {
                printf("%c",deal[i]);
            }
            printf("e-%d",znum);
    }
    else
    {
        for(i = 0,j = 0;i < len;i++)
        {
            if(str[i] == '.')
            {
                pnum = i;
            }
            if(str[i] <= '9'&&str[i] >='0')
            {
                deal[j] = str[i];
                j++;
            }

        }
        printf("%c.",deal[0]);
        for(i = 1;i < len - 1;i++)
        {
            printf("%c",deal[i]);
        }
        printf("e%d",pnum - 1);
    }
    return 0;
}

