#include <stdio.h>

struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int num;
} seq[105];

int n, i, j, k, r, type, max;
int preline[105][4];
void record(int preline[][4], struct line seq[])
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            if (preline[i][0] == preline[j][2] && preline[i][1] == preline[j][3])
            {
                type = 1;
                break;
            }
        }
        if (type == 0)
        {
            seq[k].x1 = preline[i][0];
            seq[k].y1 = preline[i][1];
            seq[k].x2 = preline[i][2];
            seq[k].y2 = preline[i][3];
            k++;
        }
        type = 0;
    }
}

void count(int preline[][4], struct line seq[], int k)
{
    for (i = 0; i < k; i++)
    {
        seq[i].num = 1;
        for (j = 0; j < n; j++)
        {
            if (seq[i].x2 == preline[j][0] && seq[i].y2 == preline[j][1])
            {
                seq[i].x2 = preline[j][2];
                seq[i].y2 = preline[j][3];
                seq[i].num++;
                j = -1;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
            scanf("%d", &preline[i][j]);
    }
    record(preline, seq);
    count(preline, seq, k);
    /*for( i=0;i<k;i++){
        printf("%d %d %d %d\n",seq[i].lpointx,seq[i].lpointy,seq[i].rpointx,seq[i].rpointy);
    }*/

	for (i = 0; i < k; i++)
    {
        if (max < seq[i].num)
        {
            max = seq[i].num;
            r = i;
        }
    }
    //printf("   1%d%d1   ", k, r);
	printf("%d %d %d\n", seq[r].num, seq[r].x1, seq[r].y1);

    return 0;
}





