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
    for (i=0; s[i]!='\0'; i++)//what if - is the last in the string? @@ [Error: Accessing s[i-1] when i=0 causes out-of-bounds access; also s[i+1] may be out-of-bounds if '-' is at the end.]
    {
        if (s[i]=='-')
        {
            if (s[i-1]>='0' && s[i-1]<='9') @@ [Error: s[i-1] is out of bounds when i=0.]
            {
                if (s[i+1]>s[i-1] && s[i+1]<='9') @@ [Error: s[i+1] may be out of bounds if '-' is the last character.]
                {
                    for (j=1; s[i-1]+j<s[i+1]; j++) @@ [Error: Loop condition should be <= to include the end character of the expansion range.]
                        printf("%c", s[i-1]+j);
                }
                else
                    printf("%c", s[i]);
            }
            else if (s[i-1]>='A' && s[i-1]<='Z') @@ [Error: s[i-1] is out of bounds when i=0.]
            {
                if (s[i+1]>s[i-1] && s[i+1]<='Z') @@ [Error: s[i+1] may be out of bounds.]
                {
                    for (j=1; s[i-1]+j<s[i+1]; j++) @@ [Error: Loop condition should be <=.]
                        printf("%c", s[i-1]+j);
                }
                else
                    printf("%c", s[i]);
            }
            else if (s[i-1]>='a' && s[i-1]<='z') @@ [Error: s[i-1] is out of bounds when i=0.]
            {
                if (s[i+1]>s[i-1] && s[i+1]<='z') @@ [Error: s[i+1] may be out of bounds.]
                {
                    for (j=1; s[i-1]+j<s[i+1]; j++) @@ [Error: Loop condition should be <=.]
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