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
int cnt_left(int i, int n);
int cnt_right(int i, int n);
int find(int i, int n);
int main()
{
    FILE *in = fopen("filein.txt", "r"), *out = fopen("fileout.txt", "w"); // @@ [Opens files that may not exist; does not check NULL; program reads from stdin, making this redundant and potentially causing undefined behavior.]
    int n, i;
    scanf("%d", &n);
    for ( i = 0;i <= n - 1;i++ )
    {
        scanf("%d %d %d %d", &l[i].x, &l[i].y, &l[i].x2, &l[i].y2);
    }
    for ( i = 0;i <= n - 1;i++ )
    {
        if ( flag[i] == 0 )
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



    fclose(in); // @@ [Closing potentially NULL file pointer if fopen failed.]
    fclose(out); // @@ [Same as above.]
    system("pause"); // @@ [Non-standard system call; may cause compilation error or halt unexpectedly.]
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