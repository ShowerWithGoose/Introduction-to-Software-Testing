#include <stdio.h>
#include <string.h>
int line[100][4];
int mark[100]={0};
int left[2];
int right[2];
int leftdef[2];
int rightdef[2];
int main()
{
    int n,maxdef=0,max;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d",&line[i][0],&line[i][1],&line[i][2],&line[i][3]);
    }
    for (int i = 0; i < n; i++)
    {
        max = 1;
        //if(mark[i]) continue;
        left[0] = line[i][0];
        left[1] = line[i][1];
        right[0] = line[i][2];
        right[1] = line[i][3];
        for (int j = 0; j < n; j++)
        {
            if(j == i) continue;
            if(mark[j]) continue;
            if(line[j][0] == left[0] && line[j][1] == left[1])
            {
                max++;
                left[0] = line[j][2];
                left[1] = line[j][3];
                mark[j]++;
                j = 0;
                continue;
            }
            if(line[j][2] == left[0] && line[j][3] == left[1])
            {
                max++;
                left[0] = line[j][0];
                left[1] = line[j][1];
                mark[j]++;
                j = 0;
                continue;
            }
            if(line[j][0] == right[0] && line[j][1] == right[1])
            {
                max++;
                right[0] = line[j][2];
                right[1] = line[j][3];
                mark[j]++;
                j = 0;
                continue;
            }
            if(line[j][2] == right[0] && line[j][3] == right[1])
            {
                max++;
                right[0] = line[j][0];
                right[1] = line[j][1];
                mark[j]++;
                j = 0;
                continue;
            }
        }
        memset(mark,0,sizeof(mark));
        if(max > maxdef)
        {
            maxdef = max;
            leftdef[0] = left[0];leftdef[1] = left[1];rightdef[0]=right[0];rightdef[1]=right[1];
        }
    }

    if(rightdef[0] < leftdef[0])
    {
        int temp = leftdef[0];
        leftdef[0] = rightdef[0];
        rightdef[0] = temp;
        
        temp = leftdef[1];
        leftdef[1] = rightdef[1];
        rightdef[1] = temp;
    }
    
    printf("%d %d %d",maxdef,leftdef[0],leftdef[1]);
    return 0;
}

