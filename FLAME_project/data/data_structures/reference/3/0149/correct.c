//
//  main.c
//  科学技术法
//
//  Created by  on 2022/3/7.
//

#include <stdio.h>
#include <string.h>
char num[1000];
int main(int argc, const char * argv[])
{
    scanf("%s",num);
    int i=0, j=0, k=0, l=0, m=0, n=0;
    char *p1, *p2, *p3, *p4;
    p1=strchr(num, '.');
    p2=num;
    //printf("%c %c %c %ld\n",*p1,*p2,*(p1+1),p1-p2);
    if (p1==NULL)
    {
        printf("%se0\n",num);
    }
    else
    {
        if (p1-p2>1)
        {
            printf("%c.",num[0]);
            for (i=1; i<strlen(num); i++)
            {
                if (num[i]=='.')
                {
                    l=i;
                    i++;
                }
                printf("%c",num[i]);
            }
            printf("e%d\n",l-1);
        }
        if ((p1-p2)==1)
        {
            if (num[0]>'0')
            {
                printf("%c.",num[0]);
                for (i=2; i<strlen(num); i++)
                {
                    printf("%c",num[i]);
                }
                printf("e0\n");
            }
            if (num[0]=='0')//0.00011型
            {
                for (i=2; i<strlen(num); i++)
                {
                    if (num[i]!='0')
                    {
                        j=i;
                        break;
                    }
                }
                if (j==strlen(num)-1)
                {
                    printf("%ce-%lu\n",num[j],strlen(num)-2);
                }
                else
                {
                    printf("%c.",num[j]);
                    for (k=j+1; k<strlen(num); k++)
                    {
                        printf("%c",num[k]);
                    }
                    printf("e-%d\n",j+1-2);
                }
            }
        }
    }
    return 0;
}

