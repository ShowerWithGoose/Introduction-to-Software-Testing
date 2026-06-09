#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int str[101] = {0}, n, i = 0;
    scanf("%d", &n);

    while( n != -1 )
    {
        if( n == 1 )
        {
            scanf("%d", &n);
            while( n != 1 && n != 0 && n != -1)
            {
                str[i++] = n;
                scanf("%d", &n);
            }
        }
        else if( n == 0 )
        {
            i--;
            if( i < 0 )
            {
                printf("error ");
                i = 0;
            }
            else{
                printf("%d ", str[i]);
                str[i] = 0;
            }
            scanf("%d", &n);
            while( n != 1 && n != 0 && n != -1)
            {
                i--;
                if( i < 0 )
            {
                printf("error ");
                i = 0;
            }
            else{
                printf("%d ", str[i]);
                str[i] = 0;
            }
                scanf("%d", &n);
            }
        }
    }
}

