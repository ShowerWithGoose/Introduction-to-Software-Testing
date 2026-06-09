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
            room[++flag] = num; // @@ Error: The stack capacity is 100, but room has size 110. However, the main issue is that the push operation does not check if the stack is full (flag >= 100). According to the problem, if a push is attempted when the stack is full, "error" should be output. This code will overwrite memory beyond the intended stack size without reporting an error.
        }
        else if (op == 0)
        {
            flag--;
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); // @@ Error: When flag is decremented before accessing the element, the element at index flag+1 is the one that was just popped. However, the logic is flawed because if the stack is empty (flag == 0) and a pop is attempted, flag becomes -1, and the error is correctly printed. But if the stack is not empty, the pop should first check if the stack is empty (flag >= 0 before decrement), then decrement and print. The current code decrements first, then checks if flag < 0, which is incorrect because it modifies the stack state before validating the operation. Additionally, the pop operation should output the element at the top of the stack before decrementing, not after.
            }
        }
    }
    return 0;
}