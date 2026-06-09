#include <stdio.h>
struct linexy
{
    int orix;
    int oriy;
    int finx;
    int finy;
    int cnt;
} line[1000];
struct lineOri
{
    int x1;
    int y1;
    int x2;
    int y2;
} lineori[1000];
int n;
void bubble();
int main()
{
    // freopen("line.txt", "r", stdin);
    int i = 0, j = 0, k = 0, flg = 0, supcnt = 0, supnum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &lineori[i].x1, &lineori[i].y1);
        scanf("%d%d", &lineori[i].x2, &lineori[i].y2);
    }
    bubble();
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            line[++j].orix = lineori[i].x1;
            line[j].oriy = lineori[i].y1;
            line[j].finx = lineori[i].x2;
            line[j].finy = lineori[i].y2;
        }
        else
        {
            for (k = 1; k <= j; k++)
            {
                if (lineori[i].x1 == line[k].finx && lineori[i].y1 == line[k].finy)
                {
                    flg = k;
                    break;
                }
            }
            if (flg == 0)
            {
                line[++j].orix = lineori[i].x1;
                line[j].oriy = lineori[i].y1;
                line[j].finx = lineori[i].x2;
                line[j].finy = lineori[i].y2;
            }
            else if (flg > 0)
            {
                line[k].finx = lineori[i].x2;
                line[k].finy = lineori[i].y2;
                line[k].cnt++;
            }
            flg = 0;
            k = 0;
        }
    }
    for (i = 1; i <= j; i++)
    {
        if (line[i].cnt > supcnt)
        {
            supnum = i;
            supcnt = line[i].cnt;
        }
    }
    printf("%d %d %d", supcnt + 1, line[supnum].orix, line[supnum].oriy);

    return 0;
}
void bubble()
{
    int j, i, flag;
    struct lineOri tmp;
    for (i = n - 1; i >= 0; i--)
    {
        flag = 0;
        for (j = n - 1; j >= 0; j--)
        {
            if (lineori[j].x1 < lineori[j - 1].x1)
            {
                tmp = lineori[j];
                lineori[j] = lineori[j - 1];
                lineori[j - 1] = tmp;
                flag = 1;
            }
        }
        if (!flag)
            break;
    }
}
