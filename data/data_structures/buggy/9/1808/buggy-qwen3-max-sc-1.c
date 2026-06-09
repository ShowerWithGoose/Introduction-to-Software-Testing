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
    FILE *in = fopen("filein.txt", "r"), *out = fopen("fileout.txt", "w"); // @@ [The program tries to open files that are not part of the input specification; the problem expects input from stdin and output to stdout, not file I/O. This causes runtime issues or undefined behavior when files don't exist.]
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



    fclose(in); // @@ [Attempting to close a file pointer 'in' that may be NULL if "filein.txt" doesn't exist, leading to undefined behavior. Also, file I/O is not required per problem statement.]
    fclose(out); // @@ [Same issue as above; 'out' may be NULL, and file output is not expected.]
    system("pause"); // @@ [This is platform-specific (Windows) and unnecessary; it may cause compilation or runtime errors on non-Windows systems and is not part of the problem requirements.]
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
    flag[i] = 1; // @@ [This line sets flag[i] = 1 even though the function is called recursively and may have already set flags for ancestors; more critically, global 'flag' array is used inconsistently across cnt_left and cnt_right, potentially double-counting or skipping segments.]
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
    flag[i] = 1; // @@ [Same issue as in cnt_left: redundant or conflicting flag setting that interferes with the counting logic in main().]
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