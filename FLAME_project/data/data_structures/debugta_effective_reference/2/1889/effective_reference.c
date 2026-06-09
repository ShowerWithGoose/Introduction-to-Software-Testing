#include <stdio.h>
int main()
{
    int a1,a2,a3;
    char b1,b2,b3;
    int num[3];
    char pnt[3];
    num[0] = 0;
    pnt[0] = '+';
    while(1)
    {
        scanf("%d %c", &num[1], &pnt[1]);
        while (pnt[1] == '*' || pnt[1] == '/')
        {
            scanf("%d %c", &num[2], &pnt[2]);
            if (pnt[1] == '*') {num[1] = num[1] * num[2];}
            else {num[1] = num[1] / num[2];}
            pnt[1] = pnt[2];
        }
        if (pnt[0] == '+') {num[0] = num[0] + num[1];}
        else if(pnt[0] == '-') {num[0] = num[0] - num[1];}
        pnt[0] = pnt[1];
        if (pnt[0] == '=')
        {
            printf("%d\n", num[0]);
            break;
        }
        
    }
    return 0;
}


