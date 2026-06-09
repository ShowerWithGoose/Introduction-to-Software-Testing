#include <stdio.h>

int dotcmp(int x1, int y1, int x2, int y2)
{
    if (((x1==x2)&&(y1==y2))==1)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct line
    {
    int x1;
    int y1;
    int x2;
    int y2;
    int len;
    };

    struct line seg[n];

    for (int i=0; i<n; i++)
    {
        scanf("%d%d%d%d", &seg[i].x1, &seg[i].y1, &seg[i].x2, &seg[i].y2);
        seg[i].len = 1;
    }

    int num = n;

    for (int i=0; i<num-1; i++)
    {
        for (int j=i+1; j<num; j++)
        {
            if (dotcmp(seg[i].x1, seg[i].y1, seg[j].x1, seg[j].y1)==1)//seg[i](x1, y1) cmp seg[j](x1, y1)
            {
                if (seg[i].x2<=seg[j].x2)
                {
                    seg[i].x1=seg[i].x2;
                    seg[i].y1=seg[i].y2;

                    seg[i].x2=seg[j].x2;
                    seg[i].y2=seg[j].y2;
                }
                else
                {
                    seg[i].x1=seg[j].x2, seg[i].y1=seg[j].y2;
                    //seg[i].x2=seg[i].x2, seg[i].y2=seg[i].y2;
                }
                for (int k=j; k<num-1; k++)
                {
                    seg[k]=seg[k+1];
                }
                seg[num-1].x1=0, seg[num-1].y1=0, seg[num-1].x2=0, seg[num-1].y2=0;
                seg[i].len++;
                num--;
                j=i;
            }
            else if (dotcmp(seg[i].x1, seg[i].y1, seg[j].x2, seg[j].y2)==1)//seg[i](x1, y1) cmp seg[j](x2, y2)
            {
                seg[i].x1=seg[j].x1;
                seg[i].y1=seg[j].y1;
                //seg[i].x2=seg[j].x2, seg[i].y2=seg[j].y2;
                for (int k=j; k<num-1; k++)
                {
                    seg[k]=seg[k+1];
                }
                seg[num-1].x1=0, seg[num-1].y1=0, seg[num-1].x2=0, seg[num-1].y2=0;
                seg[i].len++;
                num--;
                j=i;
            }
            else if (dotcmp(seg[i].x2, seg[i].y2, seg[j].x1, seg[j].y1)==1)//seg[i](x2, y2) cmp seg[j](x1, y1)
            {
                //seg[i].x1=seg[i].x1, seg[i].y1=seg[i].y1;
                seg[i].x2=seg[j].x2;
                seg[i].y2=seg[j].y2;
                for (int k=j; k<num-1; k++)
                {
                    seg[k]=seg[k+1];
                }
                seg[num-1].x1=0, seg[num-1].y1=0, seg[num-1].x2=0, seg[num-1].y2=0;
                seg[i].len++;
                num--;
                j=i;
            }
            else if (dotcmp(seg[i].x2, seg[i].y2, seg[j].x2, seg[j].y2)==1)//seg[i](x2, y2) cmp seg[j](x2, y2)
            {
                if (seg[i].x1>=seg[j].x1)
                {
                    //seg[i].x1=seg[i].x1, seg[i].y1=seg[i].y1;
                    seg[i].x2=seg[j].x1;
                    seg[i].y2=seg[j].y1;
                }
                else
                {
                    seg[i].x2=seg[i].x1;
                    seg[i].y2=seg[i].y1;

                    seg[i].x1=seg[j].x1;
                    seg[i].y1=seg[j].y1;
                }
                for (int k=j; k<num-1; k++)
                {
                    seg[k]=seg[k+1];
                }
                seg[num-1].x1=0, seg[num-1].y1=0, seg[num-1].x2=0, seg[num-1].y2=0;
                seg[i].len++;
                num--;
                j=i;
            }
            /*for (int i=0; i<num; i++)
            {
               printf("//%d %d %d %d %d\n", seg[i].x1, seg[i].y1, seg[i].x2, seg[i].y2, seg[i].len);
            }
            printf("\n");*/
        }
    }

    /*for (int i=0; i<num; i++)
    {
       printf("//%d %d %d %d %d\n", seg[i].x1, seg[i].y1, seg[i].x2, seg[i].y2, seg[i].len);
    }*/

    //printf("%d\n", num);

    int maxlen;
    maxlen = seg[0].len;
    int flag = 0;


    for (int i=1; i<num; i++)
    {
        if (seg[i].len>=maxlen)
        {
            maxlen=seg[i].len;
            flag = i;
        }
    }

    printf("%d %d %d\n", maxlen, seg[flag].x1, seg[flag].y1);
    //printf("%d ", maxlen);
    //printf("%d ", seg[flag].x1);
    //printf("%d", seg[flag].y1);


    return 0;
}

