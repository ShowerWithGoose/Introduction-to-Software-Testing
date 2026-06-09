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
    while(~scanf("d", &op)) // @@ [The format string "d" is missing the percent sign; it should be "%d". This causes scanf to not read integers properly, leading to undefined behavior and likely infinite loop or incorrect parsing.]
    {
        if(op==-1)
        {
            break;
        }
        if(op==1)
        {
            if(s.ztq==100)
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