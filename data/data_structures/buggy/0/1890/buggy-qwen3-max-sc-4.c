//
//  main.c
//  expand
//
//  Created by  on 2022/3/3.
//

/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 105
#define array_num(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-10
int main ()
{
    char s[MAXN];
    int i, j;
    scanf("%s", s);
    for (i=0; s[i]!='\0'; i++)//what if - is the last in the string?
    {
        if (s[i]=='-')
        {
            if (i == 0 || s[i+1] == '\0') // @@ [If '-' is at the start or end of string, accessing s[i-1] or s[i+1] leads to undefined behavior (out-of-bounds access).]
            {
                printf("%c", s[i]);
                continue;
            }
            if (s[i-1]>='0' && s[i-1]<='9')
            {
                if (s[i+1]>s[i-1] && s[i+1]<='9')
                {
                    for (j=1; s[i-1]+j<s[i+1]; j++)
                        printf("%c", s[i-1]+j);
                }
                else
                    printf("%c", s[i]);
            }
            else if (s[i-1]>='A' && s[i-1]<='Z')
            {
                if (s[i+1]>s[i-1] && s[i+1]<='Z')
                {
                    for (j=1; s[i-1]+j<s[i+1]; j++)
                        printf("%c", s[i-1]+j);
                }
                else
                    printf("%c", s[i]);
            }
            else if (s[i-1]>='a' && s[i-1]<='z')
            {
                if (s[i+1]>s[i-1] && s[i+1]<='z')
                {
                    for (j=1; s[i-1]+j<s[i+1]; j++)
                        printf("%c", s[i-1]+j);
                }
                else
                    printf("%c", s[i]);
            }
            else
                printf("%c", s[i]);
        }
        else
            printf("%c", s[i]);
    }
    
    return 0;
}