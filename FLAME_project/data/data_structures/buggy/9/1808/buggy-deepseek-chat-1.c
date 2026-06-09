#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLINE 1024
int flag[101];
int cnt[101];
struct line
{
    int x;
    int y;
    int x2;
    int y2;
}l[101];
int cnt_left(int i, int n);//某条线段左边有几条
int cnt_right(int i, int n);//某条线段右边有几条
int find(int i, int n);//找第i条最左边的那一条
int main()
{
    FILE *in = fopen("filein.txt", "r"), *out = fopen("fileout.txt", "w"); // @@ [Error: The program opens files "filein.txt" and "fileout.txt" but the problem requires reading from stdin and writing to stdout. This causes a runtime error when the files don't exist or are not accessible.]
    int n, i;
    scanf("%d", &n);
    for ( i = 0;i <= n - 1;i++ )
    {
        scanf("%d %d %d %d", &l[i].x, &l[i].y, &l[i].x2, &l[i].y2);
    }
    for ( i = 0;i <= n - 1;i++ )
    {
        if ( flag[i] == 0 )//没数过这条
        {
            cnt[i] = cnt_left(i, n) + cnt_right(i, n) + 1;
            flag[i] = 1;
        }
    }
    int max_line = 0, max_tiao = 0;
    for ( i = 0;i <= n - 1;i++ )
    {
        if ( cnt[i] > max_line )
        {
            max_line = cnt[i];
            max_tiao = i;
        }
    }
    printf("%d %d %d\n", max_line, l[find(max_tiao, n)].x, l[find(max_tiao, n)].y);



    fclose(in);
    fclose(out);
    system("pause");
    return 0;
}
int cnt_left(int i, int n)
{
    int j;
    for ( j = 0;j <= n - 1;j++ )
    {
        if ( j == i )
            continue;
        if ( l[j].x2 == l[i].x && l[j].y2 == l[i].y )
        {
            flag[j] = 1;
            return cnt_left(j, n) + 1;
        }
    }
    flag[i] = 1;
    return 0;
}

int cnt_right(int i, int n)
{
    int j;
    for ( j = 0;j <= n - 1;j++ )
    {
        if ( j == i )
            continue;
        if ( l[j].x == l[i].x2 && l[j].y == l[i].y2 )
        {
            flag[j] = 1;
            return cnt_right(j, n) + 1;
        }

    }
    flag[i] = 1;
    return 0;
}

int find(int i, int n)
{
    int j;
    for ( j = 0;j <= n - 1;j++ )
    {
        if ( j == i )
            continue;
        if ( l[j].x2 == l[i].x && l[j].y2 == l[i].y )
            return find(j, n);

    }
    return i;
}