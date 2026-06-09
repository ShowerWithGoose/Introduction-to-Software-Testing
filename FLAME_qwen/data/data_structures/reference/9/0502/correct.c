//1. 连续线段
#include <stdio.h>
#define SIZE 105

typedef struct S_LINE
{
    int x1; //start
    int y1;
    int x2; //end
    int y2;
} LINE;

int main()
{
    LINE line[SIZE];
    LINE temp;
    int num;
    int i, j;
    int max_len = 0; //max length
    int cur_len;     //current length
    int cur_pos;     //current position
    int max_x1, max_y1;
    //read number of lines
    scanf("%d", &num);
    //read start & end point of lines
    for (i = 0; i < num; i++)
    {
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1,
              &line[i].x2, &line[i].y2);
    }
    //sort by x1 <
    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (line[i].x1 > line[j].x1)
            {
                temp = line[i];
                line[i] = line[j];
                line[j] = temp;
            }
        }
    }
    //count
    for (i = 0; i < num; i++)
    {
        cur_len = 1;
        cur_pos = i;
        for (j = i + 1; j < num; j++)
        {
            if (line[cur_pos].x2 == line[j].x1 &&
                line[cur_pos].y2 == line[j].y1)
            //end of current line == start of j
            {
                cur_len++;
                cur_pos = j;
            }
        }
        //if find new max length
        if (cur_len > max_len)
        {
            max_len = cur_len;
            max_x1 = line[i].x1;
            max_y1 = line[i].y1;
        }
    }
    printf("%d %d %d", max_len, max_x1, max_y1);
    return 0;
}

