#include<stdio.h>

int box[100] = {0},card[100] = {0};
int j,k,n;

void quanpai(int step)
{
    int i;
    if(step == n)
    {
        printf("%d",box[0]);
        for(i = 1;i < n;i++)
        {
            printf(" %d",box[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(i = 0;i < n;i++)
        {
            if(card[i] == 0)
            {
                box[step] = i+1;
                card[i] = 1;
                quanpai(step+1);
                card[i] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    quanpai(0);
    return 0;
}



