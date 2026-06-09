#include <stdio.h>
#include <stdbool.h>

typedef struct Point
{
    unsigned int x;
    unsigned int y;
} point;

typedef struct Line
{
    point ini;
    point end;
    unsigned int length;
} line;

bool point_equal(point a, point b)
{
    return a.x == b.x && a.y == b.y;
}

int main(void)
{
    line lines[200];
    unsigned int n;
    scanf("%u", &n);
    unsigned int line_count = 0;

    for (unsigned int i = 0; i < n; i++)
    {
        point ini, end;
        scanf("%u %u %u %u", &ini.x, &ini.y, &end.x, &end.y);
        lines[line_count].ini = ini;
        lines[line_count].end = end;
        lines[line_count].length = 1;
        line_count++;
    }

    for (unsigned int i = 0; i < line_count; i++)
    {
        if (lines[i].length == 0)
        {
            continue;
        }
        for (unsigned int j = 0; j < line_count; j++)
        {
            if (i == j || lines[j].length == 0)
            {
                continue;
            }
            // printf("[%u] is %u %u %u %u, [%u] is %u %u %u %u.\n", i, lines[i].ini.x, lines[i].ini.y, lines[i].end.x, lines[i].end.y, j, lines[j].ini.x, lines[j].ini.y, lines[j].end.x, lines[j].end.y);
            if (point_equal(lines[i].ini, lines[j].end))
            {
                lines[i].ini = lines[j].ini;
                lines[i].length += lines[j].length;
                lines[j].length = 0;
            }
            else if (point_equal(lines[i].end, lines[j].ini))
            {
                lines[i].end = lines[j].end;
                lines[i].length += lines[j].length;
                lines[j].length = 0;
            }
        }
    }

    line output = {{0, 0}, {0, 0}, 0};
    for (int i = 0; i < line_count; i++)
    {
        if (lines[i].length > output.length)
        {
            output = lines[i];
        }
    }
    printf("%u %u %u\n", output.length, output.ini.x, output.ini.y);
    return 0;
}
