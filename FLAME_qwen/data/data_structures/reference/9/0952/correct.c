#include<stdio.h>
int flag;
int search(int x, int y, int lin[][4], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(lin[i][0]==x&&lin[i][1]==y)
        {
            flag++;
            search(lin[i][2], lin[i][3], lin, n);
        }
    }
    return flag;
}
int main()
{
    int lin[100][4]={0};
    int n, i, max_len=0, address=0, len=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf(" %d %d %d %d", &lin[i][0], &lin[i][1], &lin[i][2], &lin[i][3]);
    }
    for(i=0; i<n; i++)
    {
        flag=0;
        if((len=search(lin[i][2], lin[i][3], lin, n))!=0)
        {
            if(len>max_len)
            {
                max_len=len;
                address=i;
            }
        }
    }
    printf("%d %d %d", max_len+1, lin[address][0], lin[address][1]);
    return 0;
}
