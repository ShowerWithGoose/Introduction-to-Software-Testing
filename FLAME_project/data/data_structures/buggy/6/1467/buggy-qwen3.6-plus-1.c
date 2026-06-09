#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int op,num,flag=0,room[110]={0};
    while (~scanf("%d",&op))
    {
        if (op == -1)
        {
            break;
        }
        else if (op == 1)
        {
            scanf("%d",&num);
            if (flag >= 100) { // @@ [Check for stack overflow before pushing. If stack is full (capacity 100), should output "error " instead of pushing]
                printf("error ");
            } else {
                room[++flag] = num;
            }
        }
        else if (op == 0)
        {
            if (flag == 0) { // @@ [Check for stack underflow before popping. If stack is empty, output "error ". The original code decremented flag first, leading to incorrect index access and logic]
                printf("error ");
            } else {
                printf("%d ",room[flag]);
                flag--;
            }
        }
    }
    return 0;
}