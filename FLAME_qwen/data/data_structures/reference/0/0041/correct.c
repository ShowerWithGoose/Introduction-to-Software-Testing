#include <stdio.h>
#include <stdlib.h>
char ch[10];

int main()
{
    int i=1;
    char j, k;
    while(scanf("%c",&ch[i])!= -1)
    {
        if(ch[i] == '-')
        {
            scanf("%c",&ch[i+1]);
            if(ch[i-1] < ch[i+1] && ( ( ch[i-1] >= '0' && ch[i-1] <= '9' && ch[i+1] >= '0' && ch[i+1] <= '9' ) || ( ch[i-1] >= 'a' && ch[i-1] <= 'z' && ch[i+1] >= 'a' && ch[i+1] <= 'z' ) || ( ch[i-1] >= 'A' && ch[i-1] <= 'Z' && ch[i+1] >= 'A' && ch[i+1] <= 'Z' ) ) )
            {
                j = ch[i-1]+1;
                k = ch[i+1]-1;
                while(j<=k)
                {
                    printf("%c",j);
                    j++;
                }
            }
            else
                printf("-");
            printf("%c",ch[i+1]);
            i++;
        }
        else
            printf("%c",ch[i]);
        i++;
    }
    return 0;
}

