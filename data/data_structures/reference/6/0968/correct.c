#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <malloc.h>
int main()
{
    int stack[100], flag, top = -1;
    while (scanf("%d", &flag) != EOF)
    {
        switch (flag)
        {
            case 1:
            top++;
            int temp;
            scanf("%d",&temp);
            if(top>99)
            {
                printf("error ");
                break;
            }
            stack[top]=temp;
            break;
            case 0:
            if(top<0) 
            {
                printf("error ");
                break;
            }
            else{
                printf("%d ",stack[top]);
                top--;
            }
            break;
            case -1:
            return 0;
        }
    }
    return 0;
}

