#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , i , j , k , len = 1 , len_flag = 1 , flag , x1[120] , x2[120] , y1[120] , y2[120];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &x1[i] , &y1[i] , &x2[i] , &y2[i]);
    }
    for (i = 0; i <= n; i++)
    {
    	j = n;
    	while(j--)
            {
                if (x2[i] != x1[j] || y2[i] != y1[j]) continue;
                len++;
                k = n;
                while(k--){
                    if (x2[j] !=  x1[k] ||  y2[j] !=  y1[k]) continue;
                    len++;
                    j = k;
                    k = n;
                }
                if (len > len_flag) {
                    len_flag = len;
                    flag = i;
                }
                len = 1;
                break;
            }
    }
    printf ("%d %d %d" , len_flag , x1[flag] , y1[flag]) ;
}

