#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define maxint 2147483647
#define eps 1e-10
#define ll long long
void fuc(char str[])
{
    char *p1, *p2, *p3;
    p1 = str;
    p2 = str+1;
    p3 = str+2;
    int bool = 0;
    while(*p1 != '\0')
    {
        if(isdigit(*p1) && *p2 == '-' && isdigit(*p3) && *p1 < *p3)
        {
            for(int i = (*p1-'0'); i < (*p3-'0'); ++i)
            {
                printf("%d", i);
            }
            bool = 1;
        }
        else if(islower(*p1) && *p2 == '-' && islower(*p3) && *p1 < *p3)
        {
            for(char i = *p1; i < *p3; ++i)
            {
                printf("%c", i);
            }
            bool = 1;
        }
        else if(isupper(*p1) && *p2 == '-' && isupper(*p3) && *p1 < *p3)
        {
            for(char i = *p1; i < *p3; ++i)
            {
                printf("%c", i);
            }
            bool = 1;
        }
        if(bool)
        {
            p1 += 2;
            p2 += 2;
            p3 += 2;
            bool = 0;
        }
        else
        {
            printf("%c", *p1);
            p1++;
            p2++;
            p3++;
        }
    }
}
int main()
{
    char str[100];
    scanf("%s", str);
    fuc(str);

    return 0;
}



