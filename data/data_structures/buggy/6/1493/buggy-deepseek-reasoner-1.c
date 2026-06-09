/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
typedef struct tfy
{
    int ztq;
    int nxy[1006];
} tfy;

int main()
{
    tfy s;
    s.ztq=0;
    int op;
    while(~scanf("d", &op)) // @@ The format specifier is incorrect; it should be "%d". Also, using '~' on the return value may cause unintended behavior; the loop should continue while the read is successful, e.g., while(scanf("%d",&op)==1). Currently, if no input, scanf returns EOF, ~EOF=0, loop exits correctly, but if invalid input is given, the loop may become infinite.
    {
        if(op==-1)
        {
            break;
        }
        if(op==1)
        {
            if(s.ztq==100) // @@ When the stack is full, the integer to be pushed must still be read from input to keep the operation sequence aligned, but this branch does not read it. The integer should be read before checking the condition, or inside the else branch after printing error.
            {
                printf("error ");
            }
            else
            {
                scanf("%d", &s.nxy[s.ztq++]);
            }
        }
        else if(op==0)
        {
            if(s.ztq==0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ", s.nxy[--s.ztq]);
            }
        }
    }
    return 0;
}