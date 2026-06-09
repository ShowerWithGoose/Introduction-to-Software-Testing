#include <stdio.h>
int caozuo,num=0;
int zhan[105];

int main()
{
    while(scanf("%d",&caozuo))
    {
        if(caozuo == 1)
        {
            scanf("%d",&zhan[num]);
            if(num >=100)
            {
                printf("error ");
                continue;
            }
            num++;
        }
        else if(caozuo == 0)
        {
            if(num == 0)
            {
                printf("error ");
                continue;
            }
            num--;
            printf("%d ",zhan[num]);
        }
        else
            break;
    }
    return 0;
}

